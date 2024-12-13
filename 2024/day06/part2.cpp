#include <iostream>
#include <utility>
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

  char getRotatedDir() 
  {
    switch(this->dir) 
    {
      case '^': return '>';
      case '>': return'v';
      case 'v':return '<';
      case '<': return '^';
    }
  }

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

  pair<int, int> getStraightBlockPos()
  {
    switch(dir) 
    {
      case '^': return  make_pair(row-2, col);
      case '>': return make_pair(row, col+2);
      case 'v': return make_pair(row+2, col);
      case '<': return make_pair(row, col-2);
    }
  }

  pair<int, int> getNextPos(char dir)
  {
    switch(dir) 
    {
      case '^': return  make_pair(row-1, col);
      case '>': return make_pair(row, col+1);
      case 'v': return make_pair(row+1, col);
      case '<': return make_pair(row, col-1);
    }
  }
  

  pair<int, int> getRotatedPos()
  {
    char rotated_dir = this->getRotatedDir();
    return this->getNextPos(rotated_dir);
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
  vector<pair<int, int>> simulatedPositions;
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

  void reset()
  {
    this->redrawGrid();
    this->guard.row = this->start_row;
    this->guard.col = this->start_col;
    this->guard.dir = this->start_dir;
  }

  void init() 
  {
    string input;
    while(getline(cin, input))
    {
      this->start_grid.push_back(input);
    }
    this->fillStartPositions();
    this->reset();
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
    this->grid[next_pos.first][next_pos.second] = this->guard.dir;
    this->guard.move();
  }

  bool willNextPosCauseLoop()
  {
    pair<int, int> next_pos = this->guard.getNextPos();
    return this->grid[next_pos.first][next_pos.second] == this->guard.getRotatedDir();
  }

  bool willRotatedPosCauseLoop()
  {
    pair<int, int> rotated_pos = this->guard.getRotatedPos();
    return this->grid[rotated_pos.first][rotated_pos.second] == this->guard.getRotatedDir();
  }

  bool hasPositionBeenSimulated(pair<int, int> pos)
  {
    for(int i = 0; i < this->simulatedPositions.size(); i++)
      if(this->simulatedPositions[i].first == pos.first && this->simulatedPositions[i].second == pos.second)
        return true;
    return false;
  }

  bool simulateRotationRun()
  {
    if(this->hasPositionBeenSimulated(make_pair(this->guard.row,this->guard.col)))
       return false;
    Guard locGuard = Guard(this->guard);
    vector<string> locGrid = this->copyGrid();
    locGuard.changeDir();
    pair<int, int> next_pos = locGuard.getNextPos();
    if(this->isNextPosBlocked(next_pos))
      return false;
    while(!this->isPosOOB(next_pos))
    {
      while(this->isNextPosBlocked(next_pos))
      {
        if(this->isPosOOB(next_pos))
          return false;
        locGuard.changeDir();
        next_pos = locGuard.getNextPos();
      }
      
      if(locGrid[next_pos.first][next_pos.second] == locGuard.dir)
        return true;
      
      locGuard.move();
      locGrid[locGuard.row][locGuard.col] = locGuard.dir;
      /*for(int row = 0; row < rowSize; row++)*/
      /*{*/
      /*  cout << locGrid[row] << endl;*/
      /*}*/
      /*cout << endl << endl;*/
      next_pos = locGuard.getNextPos();
    }
    return false;
  }

  bool hasPosBeenFound(pair<int, int> pos)
  {
    for(int i = 0; i < this->found_positions.size(); i++)
      if(this->found_positions[i].first == pos.first &&
        this->found_positions[i].second == pos.second)
        return true;
    return false;
  }

  void printFound()
  {
    for(int i = 0; i < this->found_positions.size(); i++)
      cout << this->found_positions[i].first << " " << this->found_positions[i].second << endl;
  }

  void printGrid()
  {
    int count = 0;
    for(int row = 0; row < this->rowSize; row++)
    {
      for(int col = 0; col < this->colSize; col++)
        cout << this->grid[row][col];
      cout << endl;
    }
    cout << endl;
  }

  vector<string> copyGrid()
  {
    vector<string> locGrid;
    string temp;
    for(int i = 0; i < this->grid.size(); i++)
    {
      temp = this->grid[i];
      locGrid.push_back(temp);
    }
    return locGrid;
  }


};

int main()
{
  Game game;
  int iteration = 0;
  
  while(!game.isNextPosOOB()) 
  {
    if(game.willNextPosCauseLoop() && !game.hasPosBeenFound(game.guard.getStraightBlockPos()))
    {
      cout << "Straight Block" << endl;
      game.found_positions.push_back(game.guard.getStraightBlockPos());
      /*game.printGrid();*/
      //game.reset();
      continue;
    }

    if(game.willRotatedPosCauseLoop() && !game.hasPosBeenFound(game.guard.getNextPos()))
    {
      cout << "Rot Block" << endl;
      game.found_positions.push_back(game.guard.getNextPos());
      /*game.printGrid();*/
      //game.reset();
      continue;
    }

    if(game.simulateRotationRun() && !game.hasPosBeenFound(game.guard.getNextPos()))
    {
      cout << "Sim Block" << endl;
      game.found_positions.push_back(game.guard.getNextPos());
      /*game.printGrid();*/
      //game.reset();
      continue;
    }



    game.moveGuard();
    cout << iteration++ << endl;
  };
  //game.printFound();
  cout << game.found_positions.size() << endl;
}
