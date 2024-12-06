#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int rowSize = 0;
int colSize = 0;
int searchUpLeft(int row, int col, vector<string>& ws)
{
  if(row < 3 || row < 3)
    return 0;
  if((ws[row-1][col-1]) == 'M' && ws[row-2][col-2] == 'A' && ws[row-3][col-3] == 'S')
  {
    cout << "Up Left" << endl;
  }
    return 1;
  return 0;
}
int searchUpRight(int row, int col, vector<string>& ws)
{
  if(row < 3 || col > colSize - 4)
    return 0;
  if(ws[row - 1][col+1] == 'M' && ws[row - 2][col+2] == 'A' && ws[row - 3][col+3] == 'S')
    return 1;
  return 0;
}
int searchDownLeft(int row, int col, vector<string>& ws)
{
  if(row < 3 || col > colSize - 4)
    return 0;
  if(ws[row - 1][col+1] == 'M' && ws[row - 2][col+2] == 'A' && ws[row - 3][col+3] == 'S')
    return 1;
  return 0;
}
int searchDownRight(int row, int col, vector<string>& ws)
{
  if(row > rowSize - 4 || col > colSize - 4)
    return 0;
  if(ws[row + 1][col+1] == 'M' && ws[row + 2][col+2] == 'A' && ws[row + 3][col+3] == 'S')
    return 1;
  return 0;
}
int searchLeft(int row, int col, vector<string>& ws)
{
  if(col < 3)
    return 0;
  if(ws[row][col-1] == 'M' && ws[row][col-2] == 'A' && ws[row][col-3] == 'S')
    return 1;
  return 0;
}
int searchRight(int row, int col, vector<string>& ws)
{
  if(col > colSize - 4)
    return 0;
  if(ws[row][col+1] == 'M' && ws[row][col+2] == 'A' && ws[row][col+3] == 'S')
    return 1;
  return 0;
}
int searchUp(int row, int col, vector<string>& ws)
{
  if(row < 3)
    return 0;
  if(ws[row-1][col] == 'M' && ws[row-2][col] == 'A' && ws[row-3][col] == 'S')
    return 1;
  return 0;
}
int searchDown(int row, int col, vector<string>& ws)
{
  if(row > rowSize - 4)
    return 0;
  if(ws[row+1][col] == 'M' && ws[row+2][col] == 'A' && ws[row+3][col] == 'S')
    return 1;
  return 0;
}

int find_xmas(int row, int col, vector<string>& ws)
{
  return
    searchUpLeft(row, col, ws) + 
    searchUpRight(row, col, ws) + 
    searchDownLeft(row, col, ws) +
    searchDownRight(row, col, ws) +
    searchLeft(row, col, ws) + 
    searchRight(row, col, ws) + 
    searchUp(row, col, ws) +
    searchDown(row, col, ws);
}



int main()
{
  string input;
  vector<string> ws;
  int index = 0;
  while(getline(cin, input))
  {
    ws.push_back(input);
  }
  colSize = ws[0].length();
  rowSize = ws.size();
  

  int count = 0;
  for(int row = 0; row < rowSize; row++)
  {
    for(int col = 0; col < colSize; col++)
    {
      cout << ws[row][col];
      if(ws[row][col] == 'X')
      {
        count += find_xmas(row, col, ws);
      }
      cout << endl;
    }
  }
  cout << "Count: " << count << endl;
}
