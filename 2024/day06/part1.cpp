#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Direction 
{
  NORTH,
  EAST,
  SOUTH, 
  WEST
};

Direction getDir(char c) 
{
  switch(c) {
    case '^': return NORTH;
    case '>': return EAST;
    case 'v': return SOUTH;
    case '<': return WEST;
    default: return NORTH;
  }
};

class Guard {
public:
  int row;
  int col;
  Direction dir;
  Guard(int row, int col, char dir) :
    row(row), col(col)
  {
    dir = getDir(dir);
  };

  void move() 
  {
    switch(dir) {
      case NORTH: row--;
      case EAST: col++;
      case SOUTH: row++;
      case WEST: col--;
    };
  }

};

int main()
{
  vector<string> grid;
  string input;
  while(getline(cin, input))
    grid.push_back(input);



}
