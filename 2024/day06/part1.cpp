#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Guard {
public:
  int row;
  int col;
  char dir;
  Guard() : row(0), col(0), dir('^') {};
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

class Game 
{
public:
  vector<string> start_grid;
  int start_row;
  int start_col;
  char start_dir;
  int rowSize;
  int colSize;
  vector<string> grid;
  Guard guard;
  vector<pair<int, int>> found_positions;



  void fillStartPositions() 
  {
    for(int row = 0; row < this->start_grid.size(); row++)
    {
      for(int col = 0; col < this->start_grid[row].length(); col++)
      {
        if(
          this->start_grid[row][col] == '^' ||
          this->start_grid[row][col] == '>' ||
          this->start_grid[row][col] == 'v' ||
          this->start_grid[row][col] == '<' 
        )
        {
          this->start_dir = this->start_grid[row][col];
          this->start_row = row;
          this->start_col = col;
          return;
        }
      }
    }
  }

  void redrawGrid()
  {
    this->grid.clear();
    for(int row = 0; row < this->start_grid.size(); row++)
    {
      string new_input = "";
      for(int col = 0; col < this->start_grid[row].length(); col++)
      {
        new_input += this->start_grid[row][col];
      }
      this->grid.push_back(new_input);
    }
  }

  void init() 
  {
    string input;
    while(getline(cin, input))
    {
      this->start_grid.push_back(input);
    }
    this->fillStartPositions();
    this->redrawGrid();
    this->guard.row = this->start_row;
    this->guard.col = this->start_col;
    this->guard.dir = this->start_dir;
  }

  Game(): start_dir('|') {
    this->init();
    this->rowSize = this->start_grid.size();
    this->colSize = this->start_grid[0].length();
  };

  bool isPosOOB(pair<int, int> pos)
  {
    return pos.first < 0 ||
    pos.first >= this->rowSize || 
    pos.second < 0 ||
    pos.second >= this->colSize;
  }

  bool isNextPosOOB()
  {
    return this->isPosOOB(this->guard.getNextPos());
  }

  bool isNextPosBlocked(pair<int, int> pos)
  {
    return this->grid[pos.first][pos.second] == '#';
  }

  void moveGuard()
  {
    pair<int, int> next_pos = this->guard.getNextPos();
    while(this->isNextPosBlocked(next_pos))
    {
      if(this->isPosOOB(next_pos))
         return;
      this->guard.changeDir();
      next_pos = this->guard.getNextPos();
    }
    this->grid[next_pos.first][next_pos.second] = 'X';
    this->guard.move();
  }

  int countSpaces()
  {
    int count = 0;
    for(int row = 0; row < this->rowSize; row++)
      for(int col = 0; col < this->colSize; col++)
        if(this->grid[row][col] == 'X')
          count++;
    return count;
  }


};

int main()
{
  Game game;
  
  while(!game.isNextPosOOB()) 
  {
    game.moveGuard();
  };
  cout << game.countSpaces() << endl;
}
