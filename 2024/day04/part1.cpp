#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int find_xmas(int row, int col, vector<string>& ws)
{
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
  
  int count = 0;
  for(int row = 0; row < ws.size(); row++)
  {
    for(int col = 0; col < ws[row].length(); col++)
    {
      if(ws[row][col] == 'X')
      {
        count += find_xmas(row, col, ws);
      }
    }
  }
}
