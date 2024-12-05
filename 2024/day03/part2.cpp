
#include <cstdlib>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string input;
  string buf;
  while(getline(cin, buf))
    input += buf;

  int sum = 0;
  
  regex reg("do\\(\\)|don't\\(\\)|mul\\((\\d+),(\\d+)\\)");
  regex expr("mul\\(\\d+,\\d+\\)");
  sregex_iterator curMatch(input.begin(), input.end(), reg);
  sregex_iterator end;
  
  bool on = true;
  for(curMatch; curMatch != end; curMatch++) 
  {
    smatch match = *curMatch;
    if(match.str() == "do()")
    {
      on = true;
      continue;
    }
    if(match.str() == "don't()")
    {
      on = false;
      continue;
    }
    if(on && regex_match(match.str(), expr))
    {
      sum += stoi(match[1].str()) * stoi(match[2].str());
    }
  

  }


  cout << "Sum: " << sum << endl;

  return 0;


};
