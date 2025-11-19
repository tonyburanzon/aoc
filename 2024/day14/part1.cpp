#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

#define HEIGHT 103
#define WIDTH 101

using namespace std;

struct Point {
  int x;
  int y;
};

struct Robot {
  Point curPos;
  Point velocity;

};

void readFile(vector<Robot>& robots) {
  fstream file("test_input");
  string buf;

  regex pattern(R"(p=(\d+),(\d+).*(-?\d+),(-?\d+))");
  while(getline(file, buf)) {
    smatch matches;

    std::regex_search(buf, matches, pattern);
    robots.push_back({ 
      { stoi(matches[1]), stoi(matches[2]) }, 
      { stoi(matches[3]), stoi(matches[4]) }
    });
  }
}


int main() {
  vector<Robot> robots;
  readFile(robots);

  for(int iteration = 0; iteration < 100; iteration++) {
    for(auto& robot : robots) { 
      robot.curPos.x = ( robot.curPos.x + robot.velocity.x + WIDTH) % WIDTH;
      robot.curPos.y = ( robot.curPos.y + robot.velocity.y + HEIGHT) % HEIGHT;
    }
  }

  int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
  
  for(auto& robot : robots) {
    if(robot.curPos.x < WIDTH / 2 && robot.curPos.y < HEIGHT / 2) q1++;
    if(robot.curPos.x > WIDTH / 2 && robot.curPos.y < HEIGHT / 2) q2++;
    if(robot.curPos.x < WIDTH / 2 && robot.curPos.y > HEIGHT / 2) q3++;
    if(robot.curPos.x > WIDTH / 2 && robot.curPos.y > HEIGHT / 2) q4++;
  }

  cout << (-3 + 20) % 10 << endl;
  cout << q1 << " " << q2 << " " << q3 << " " << q4 << endl;
  cout << q1 * q2 * q3 * q4 << endl;

  return 0;
}
