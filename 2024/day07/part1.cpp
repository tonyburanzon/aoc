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

struct Sum
{
  int added_sum;
  int mult_sum;
};

bool multiply_next(int, int, queue<int>);
bool add_next(int, int, queue<int>);

bool multiply_next(int target, int total, queue<int>& operands)
{
  if(operands.size() == 0)
    return total == target;
  int next_num = operands.front();
  total += next_num;
  queue<int> add_operands(operands);
  queue<int> mult_operands(operands);
  return multiply_next(target, total, mult_operands) ||
    add_next(target, total, mult_operands);
}

bool add_next(int target, int total, queue<int>& operands)
{
  if(operands.size() == 0)
    return total == target;
  int next_num = operands.front();
  total += next_num;
  queue<int> add_operands(operands);
  queue<int> mult_operands(operands);
  return multiply_next(target, total, mult_operands) ||
    add_next(target, total, add_operands);
}

bool maths_out(int target, queue<int> operands)
{
  int total = operands.front();
  operands.pop();
  queue<int> add_operands(operands);
  queue<int> mult_operands(operands);

  return multiply_next(target, total, mult_operands) ||
    add_next(target, total, add_operands);
}

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

  int count = 0;
  for(int i = 0; i < calcs.size(); i++)
  {
    if(maths_out(calcs[i].target, calcs[i].operands))
       count++;
  }

  cout << "Count: " << count << endl;
}
