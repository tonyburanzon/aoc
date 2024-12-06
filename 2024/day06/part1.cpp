#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Guard {
public:
  int row;
  int col;
  char dir;
  Guard(int row, int col, char dir) :
    row(row), col(col), dir(dir)
  {
  };

  pair<int, int> getNextPos()
  {
    switch(dir) 
    {
      case '^': return  make_pair(row-1, col);
      case '>': return make_pair(row, col+1);
      case 'v': return make_pair(row+1, col);
      case '<': return make_pair(row, col-1);
    }
  }

  void changeDir() 
  {
    switch(dir) 
    {
      case '^': {
        dir = '>';
        break;
      }
      case '>': {
        dir = 'v';
        break;
      }
      case 'v': {
        dir = '<';
        break;
      }
      case '<': {
        dir = '^';
        break;
      }
    }
  }

  void move() 
  {
    switch(dir) {
      case '^': {
        this->row--;
        break;
      }
      case '>': {
        this->col++;
        break;
      }
      case 'v': {
        this->row++;
        break;
      }
      case '<': {
        this->col--;
        break;
      }
    };
  }

};

int main()
{
  vector<string> grid;
  string input;
  while(getline(cin, input))
    grid.push_back(input);

  pair<int, int> pos;
  char start = '|';
  for(int row = 0; row < grid.size(); row++)
  {
    for(int col = 0; col < grid[row].length(); col++)
    {
      if(
        grid[row][col] == '^' ||
        grid[row][col] == '>' ||
        grid[row][col] == 'v' ||
        grid[row][col] == '<'
      )
      {
        pos.first = row;
        pos.second = col;
        start = grid[row][col];
        break;
      }
      if(start != '|')
        break;
    }
  }
  int rowSize = grid.size();
  int colSize = grid[0].length();

  Guard g(pos.first, pos.second, start);
  pair<int, int> next_pos = g.getNextPos();
  while(
    next_pos.first >= 0 &&
    next_pos.first < rowSize &&
    next_pos.second >= 0 &&
    next_pos.second < colSize
  )
  {
    grid[g.row][g.col] = 'X';
    while(grid[next_pos.first][next_pos.second] == '#')
    {
      g.changeDir();
      next_pos = g.getNextPos();
    }
    g.move();
    next_pos = g.getNextPos();
  }

  int count = 1;
  for(int row = 0; row < rowSize; row++)
  {
    for(int col = 0; col < colSize; col++)
    {
      cout << grid[row][col];
      if(grid[row][col] == 'X')
        count++;
    }
    cout << endl;
  }

  cout << "Count: " << count << endl;
}
