#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

struct Calc
{
  long long target;
  queue<long long> operands;
};

struct Sum
{
  long long added_sum;
  long long mult_sum;
};

bool multiply_next(long long, long long, queue<long long>);
bool add_next(long long, long long, queue<long long>);

bool multiply_next(long long target, long long total, queue<long long> operands)
{
  if(operands.size() == 0)
    return total == target;
  long long next_num = operands.front();
  operands.pop();
  total *= next_num;
  queue<long long> add_operands(operands);
  queue<long long> mult_operands(operands);
  return multiply_next(target, total, mult_operands) ||
    add_next(target, total, mult_operands);
}

bool add_next(long long target, long long total, queue<long long> operands)
{
  if(operands.size() == 0)
    return total == target;
  long long next_num = operands.front();
  operands.pop();
  total += next_num;
  queue<long long> add_operands(operands);
  queue<long long> mult_operands(operands);
  return multiply_next(target, total, mult_operands) ||
    add_next(target, total, add_operands);
}

bool maths_out(long long target, queue<long long> operands)
{
  long long total = operands.front();
  operands.pop();
  queue<long long> add_operands(operands);
  queue<long long> mult_operands(operands);

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

  long long count = 0;
  for(int i = 0; i < calcs.size(); i++)
  {
    if(maths_out(calcs[i].target, calcs[i].operands))
       count += calcs[i].target;
  }

  cout << "Count: " << count << endl;
}
