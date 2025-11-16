#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Point {
  int x;
  int y;
};

void read_file(vector<string>& map) {
  ifstream file("input");
  string buf;
  while(getline(file, buf))
    map.push_back(buf);
}

void find_trail_heads(vector<string>& map, vector<Point>& trail_heads) {
  for(int y = 0; y < map.size(); y++) {
    for(int x = 0; x < map[y].length(); x++) {
      if(map[y][x] == '0') {
        Point th = { x, y };
        trail_heads.push_back(th);
      }
    }
  }
}

void find_peaks(Point cur_point, int prev_value, vector<string>& map, vector<Point>& accessible_peaks) {
  int cur_value = (map[cur_point.y][cur_point.x] - '0');
  if(prev_value + 1 != cur_value)
    return;

  if(map[cur_point.y][cur_point.x] == '9') {
    accessible_peaks.push_back(cur_point);
    return;
  }

  // look left
  if(cur_point.x - 1 >= 0) {
    Point next_point = { cur_point.x - 1, cur_point.y };
    find_peaks(next_point, cur_value, map, accessible_peaks);
  }
  
  // look right
  if(cur_point.x + 1 <  map[cur_point.y].length()) {
    Point next_point = { cur_point.x + 1, cur_point.y };
    find_peaks(next_point, cur_value, map, accessible_peaks);
  }

  // look up
  if(cur_point.y - 1 >= 0) {
    Point next_point = { cur_point.x, cur_point.y - 1 };
    find_peaks(next_point, cur_value, map, accessible_peaks);
  }

  // look down
  if(cur_point.y + 1 < map.size() ) {
    Point next_point = { cur_point.x, cur_point.y + 1 };
    find_peaks(next_point, cur_value, map, accessible_peaks);
  }

}

void allocate_unique_peaks(vector<Point>& accessible_peaks, vector<Point>& unique_peaks) {
  for(const Point& curAccPoint: accessible_peaks) {
    bool unique_peak_found = false;
    for(const Point& currUniqPoint : unique_peaks) {
      if(unique_peak_found)
        break;

      if( curAccPoint.x == currUniqPoint.x && curAccPoint.y == currUniqPoint.y)
        unique_peak_found = true;
    }

    if(!unique_peak_found)
      unique_peaks.push_back(curAccPoint);
  }
}

int count_peaks(vector<string>& map, Point th) {
  vector<Point> accessible_peaks;
  find_peaks(th, -1, map, accessible_peaks);

  //vector<Point> unique_peaks;
  //allocate_unique_peaks(accessible_peaks, unique_peaks);

  //return unique_peaks.size();
  return accessible_peaks.size();
}

int main() {
  vector<string> map;
  read_file(map);

  vector<Point> trail_heads;
  find_trail_heads(map, trail_heads);

  int peak_count = 0;
  for(const Point& trail_head : trail_heads) {
    int num_peaks = count_peaks(map, trail_head);
    peak_count += num_peaks;
  }

  cout << peak_count << endl;

  return 0;
}
