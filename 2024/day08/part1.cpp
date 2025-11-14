#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point 
{
  int x;
  int y;
};

void print_grid(vector<string>& grid) 
{
  for(int i = 0; i < grid.size(); i++)
  {
    cout << grid[i] << endl;
  }
  cout << endl;
}

void read_input(vector<string>& grid)
{
  ifstream file_input("input");

  string buf;
  while(getline(file_input, buf)) 
  {
    grid.push_back(buf);
  }
}

void assign_anti_node(vector<string>& grid, Point origin, Point diffPt)
{
  int maxHeight = grid.size();
  int maxWidth = grid[0].length();

  while(
    origin.x >= 0 && origin.x < maxWidth &&
    origin.y >= 0 && origin.y < maxHeight //&&
    //grid[origin.y][origin.x] != '#'
  )
  {
    grid[origin.y][origin.x] = '#';
    origin.x += diffPt.x;
    origin.y += diffPt.y;
  }
}

void assign_anti_nodes(vector<string>& grid)
{
  unordered_map<char, vector<Point> > antMap;
  int maxHeight = grid.size();
  int maxWidth = grid[0].length();

  for(int y = 0; y < maxHeight; y++)
  {
    for(int x = 0; x < maxWidth; x++)
    {
      char ant = grid[y][x];
      if(ant != '.')
      {
        Point point = {x, y};
        antMap[ant].push_back(point);
      }
    }
  }

  for(const auto& [antType, pntArr] : antMap)
  {
    for(int i = 0; i < pntArr.size(); i++) 
    {
      Point ant1 = pntArr[i];
      for(int j = i + 1; j < pntArr.size(); j++)
      {
        Point ant2 = pntArr[j];

        int firstDiffX = ant1.x - ant2.x;
        int firstDiffY = ant1.y - ant2.y;
        Point p1 = {firstDiffX, firstDiffY};
        assign_anti_node(grid, ant1, p1);

        int secondDiffX = ant2.x - ant1.x;
        int secondDiffY = ant2.y - ant1.y;
        Point p2 = {secondDiffX, secondDiffY};
        assign_anti_node(grid, ant2, p2);
      }
    }
  }
}

int count_anti_nodes(vector<string>& grid)
{
  int count = 0;
  for(const string& line : grid)
    for(const char& pnt : line)
      if(pnt == '#')
        count++;
  
  return count;
}

int main() 
{
  vector<string> grid;
  read_input(grid);
  print_grid(grid);
  assign_anti_nodes(grid);
  print_grid(grid);
  cout << count_anti_nodes(grid) << endl;
  
  return 0;
}
