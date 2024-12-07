#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

struct Calc
{
  int target;
  queue<int> operands;
};

int main()
{
  vector<Calc> calcs;
  char dump;
  string input;
  while(getline(cin, input))
  {
    Calc  calc;
    stringstream ss(input);
    ss >> calc.target;
    ss.ignore(); 
    while(ss >> input)
      calc.operands.push(stoi(input));
    calcs.push_back(calc);
  }
}
