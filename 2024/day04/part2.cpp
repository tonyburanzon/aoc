#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int rowSize = 0;
int colSize = 0;



int find_xmas(int row, int col, vector<string>& ws)
{
  int cross = 0;
  // top left 
  if(ws[row-1][col-1] == 'M' && ws[row+1][col+1] == 'S')
    cross++;
  // top right
  if(ws[row-1][col+1] == 'M' && ws[row+1][col-1] == 'S')
    cross++;
  // bottom left
  if(ws[row+1][col-1] == 'M' && ws[row-1][col+1] == 'S')
    cross++;
  // bottom right
  if(ws[row+1][col+1] == 'M' && ws[row-1][col-1] == 'S')
    cross++;

  if(cross == 2)
    return 1;
  return 0;
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
  for(int row = 1; row < rowSize-1; row++)
  {
    for(int col = 1; col < colSize-1; col++)
    {
      if(ws[row][col] == 'A')
      {
        count += find_xmas(row, col, ws);
      }
    }
  }
  cout << "Count: " << count << endl;
}
