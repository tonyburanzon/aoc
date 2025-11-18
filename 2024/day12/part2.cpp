#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Point {
  int x;
  int y;
};

struct FencePositions {
  bool north = false;
  bool south = false;
  bool east = false;
  bool west = false;
};

struct Plant {
  char type;
  //int fenceCount; 
  FencePositions fps;
  bool found;
  Point pt;

  int getFenceCount() {
    int count = 0;
    if( this->fps.north ) count++;
    if( this->fps.south ) count++;
    if( this->fps.east ) count++;
    if( this->fps.west ) count++;

    return count;
  }
};

struct Plot {
  char type;
  vector<Plant> plants;

  void getPerimeterPlants(unordered_map<int, vector<Plant>>& retPlants, string dir) {
    if(dir == "north") {
      for(auto plant : this->plants) {
        if(plant.fps.north) 
          retPlants[plant.pt.y].push_back(plant);
      }
    } 
    if(dir == "south") {
      for(auto plant : this->plants) {
        if(plant.fps.south) 
          retPlants[plant.pt.y].push_back(plant);
      }
    } 
    if(dir == "east") {
      for(auto plant : this->plants) {
        if(plant.fps.east) 
          retPlants[plant.pt.x].push_back(plant);
      }
    } 
    if(dir == "west") {
      for(auto plant : this->plants) {
        if(plant.fps.west) 
          retPlants[plant.pt.x].push_back(plant);
      }
    } 
  }

};

void read_file(vector<vector<Plant>>& ranch) {
  ifstream file("input");

  string buf;
  int lineCount = 0;
  while(getline(file, buf)) {
    vector<Plant> plantRow;
    for(int i = 0; i < buf.length(); i++) {
      Plant plant = { buf[i] , { false, false, false, false }, false, { i, lineCount } };
      plantRow.push_back(plant);
    }
    ranch.push_back(plantRow);
    lineCount++;
  }
}

bool remaining_plots(vector<vector<Plant>> ranch) {
  for(auto row : ranch) {
    for(auto plant : row) {
      if(plant.found == false)
        return true;
    }
  }

  return false;
}

Point get_plot_start(vector<vector<Plant>>& ranch) {
  for(int y = 0; y < ranch.size(); y++) {
    for(int x = 0; x < ranch[y].size(); x++) {
      if( ranch[y][x].found == false ) {
        return { x, y };
      }
    }
  }
}

void traverse_plot(Point curPoint, Plot& plot, vector<vector<Plant>>& ranch) {
  Plant& curPlant = ranch[curPoint.y][curPoint.x];
  if(curPlant.found == true)
    return;

  curPlant.found= true;

  // Look left
  if( curPoint.x - 1 >= 0 && ranch[curPoint.y][curPoint.x - 1].type == plot.type ) {
    traverse_plot({ curPoint.x - 1, curPoint.y }, plot, ranch);
  } else {
    curPlant.fps.west = true;
  }

  // Look right
  if( curPoint.x + 1 < ranch[curPoint.y].size() && ranch[curPoint.y][curPoint.x + 1].type == plot.type ) {
    traverse_plot({ curPoint.x + 1, curPoint.y }, plot, ranch);
  } else {
    curPlant.fps.east = true; 
  }
  
  // Look up
  if( curPoint.y - 1 >= 0 && ranch[curPoint.y - 1][curPoint.x].type == plot.type ) {
    traverse_plot({ curPoint.x, curPoint.y - 1 }, plot, ranch);
  } else {
    curPlant.fps.north = true;
  }

  // Look down
  if( curPoint.y + 1 < ranch.size() && ranch[curPoint.y + 1][curPoint.x].type == plot.type ) {
    traverse_plot({ curPoint.x, curPoint.y + 1 }, plot, ranch);
  } else {
    curPlant.fps.south = true; 
  }

  plot.plants.push_back(ranch[curPoint.y][curPoint.x]);
}

void build_plot(Plot& plot, vector<vector<Plant>>& ranch) {
  Point start = get_plot_start(ranch);
  plot.type = ranch[start.y][start.x].type;
  traverse_plot(start, plot, ranch);
}

void build_plots(vector<vector<Plant>>& ranch, vector<Plot>& plots) {
  while(remaining_plots(ranch)) {
    Plot curPlot;
    build_plot(curPlot, ranch);
    plots.push_back(curPlot);
  }
}

int count_perimeters(Plot& plot) {
  int fenceLengths = 0;

  unordered_map<int, vector<Plant>> northFencePlants;
  unordered_map<int, vector<Plant>> southFencePlants;
  unordered_map<int, vector<Plant>> eastFencePlants;
  unordered_map<int, vector<Plant>> westFencePlants;
  plot.getPerimeterPlants(northFencePlants, "north");
  plot.getPerimeterPlants(southFencePlants, "south");
  plot.getPerimeterPlants(eastFencePlants, "east");
  plot.getPerimeterPlants(westFencePlants, "west");

  // Count north perimeters
  for(auto [_, plants] : northFencePlants) {
    if(plants.size() == 1) {
      fenceLengths++;
    } else {
      sort(plants.begin(), plants.end(), [](Plant& a, Plant& b){ return a.pt.x < b.pt.x; });
      int gaps = 0;
      for(int i = 1; i < plants.size(); i++) {
        if(plants[i].pt.x != plants[i-1].pt.x + 1)
          gaps++;
      }
      fenceLengths += gaps + 1;
    }
  }

  // Count south perimeters
  for(auto [_, plants] : southFencePlants) {
    if(plants.size() == 1) {
      fenceLengths++;
    } else {
      sort(plants.begin(), plants.end(), [](Plant& a, Plant& b){ return a.pt.x < b.pt.x; });
      int gaps = 0;
      for(int i = 1; i < plants.size(); i++) {
        if(plants[i].pt.x != plants[i-1].pt.x + 1)
          gaps++;
      }
      fenceLengths += gaps + 1;
    }
  }
  // Count east perimeters
  for(auto [_, plants] : eastFencePlants) {
    if(plants.size() == 1) {
      fenceLengths++;
    } else {
      sort(plants.begin(), plants.end(), [](Plant& a, Plant& b){ return a.pt.y < b.pt.y; });
      int gaps = 0;
      for(int i = 1; i < plants.size(); i++) {
        if(plants[i].pt.y != plants[i-1].pt.y + 1)
          gaps++;
      }
      fenceLengths += gaps + 1;
    }
  }
  // Count west perimeters
  for(auto [_, plants] : westFencePlants) {
    if(plants.size() == 1) {
      fenceLengths++;
    } else {
      sort(plants.begin(), plants.end(), [](Plant& a, Plant& b){ return a.pt.y < b.pt.y; });
      int gaps = 0;
      for(int i = 1; i < plants.size(); i++) {
        if(plants[i].pt.y != plants[i-1].pt.y + 1)
          gaps++;
      }
      fenceLengths += gaps + 1;
    }
  }

  cout << "A region of " << plot.type << " plants with price " << plot.plants.size() << " * " << fenceLengths << endl;
  return fenceLengths;
}

int score_plots(vector<Plot>& plots) {
  int score = 0;
  for(auto plot : plots) {
    int fenceCount = count_perimeters(plot);
    score += fenceCount * plot.plants.size();
  }

  return score;
}

int main() {
  vector<vector<Plant>> ranch;
  read_file(ranch);

  vector<Plot> plots;
  build_plots(ranch, plots);

  int score = score_plots(plots);
  cout << score << endl;

  return 0;
}
