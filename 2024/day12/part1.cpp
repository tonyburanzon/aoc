#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct Point {
  int x;
  int y;
};

struct Plant {
  char type;
  int fenceCount; 
  bool found;
};

struct Plot {
  char type;
  vector<Plant> plants;
};

void read_file(vector<vector<Plant>>& ranch) {
  ifstream file("input");

  string buf;
  while(getline(file, buf)) {
    vector<Plant> plantRow;
    for(int i = 0; i < buf.length(); i++) {
      Plant plant = { buf[i] , 0, false };
      plantRow.push_back(plant);
    }
    ranch.push_back(plantRow);
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
    curPlant.fenceCount++; 
  }

  // Look right
  if( curPoint.x + 1 < ranch[curPoint.y].size() && ranch[curPoint.y][curPoint.x + 1].type == plot.type ) {
    traverse_plot({ curPoint.x + 1, curPoint.y }, plot, ranch);
  } else {
    curPlant.fenceCount++; 
  }
  
  // Look up
  if( curPoint.y - 1 >= 0 && ranch[curPoint.y - 1][curPoint.x].type == plot.type ) {
    traverse_plot({ curPoint.x, curPoint.y - 1 }, plot, ranch);
  } else {
    curPlant.fenceCount++; 
  }

  // Look down
  if( curPoint.y + 1 < ranch.size() && ranch[curPoint.y + 1][curPoint.x].type == plot.type ) {
    traverse_plot({ curPoint.x, curPoint.y + 1 }, plot, ranch);
  } else {
    curPlant.fenceCount++; 
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

int score_plots(vector<Plot>& plots) {
  int score = 0;
  for(auto plot : plots) {
    int fenceCount = 0;
    for(auto plant : plot.plants) {
      fenceCount += plant.fenceCount;
    }
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
