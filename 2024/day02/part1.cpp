#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Report
{
public:
  vector<int> levels;
  bool isSafe()
  {
    bool increase = levels[0] < levels[1];
    for(int i = 0; i < levels.size() - 1; i++)
    {
      bool seq_ok = increase ? levels[i] < levels[i+1] : levels[i] > levels[i+1];
      bool delta_ok = abs(levels[i] - levels[i+1]) <= 3;
      if(!seq_ok || !delta_ok)
        return false;
    }
    return true;
  } 
};

int main()
{
  vector<Report> reports;
  string report_str;
  int index = 0;
  while(getline(cin, report_str))
  {
    Report rep;
    stringstream ss(report_str);
    int num;
    while(ss >> num)
    {
      rep.levels.push_back(num);
    }
    reports.push_back(rep);
  }

  int safe_count = 0;
  for(int i = 0; i < reports.size(); i++)
    if(reports[i].isSafe())
      safe_count++;

  cout << safe_count << endl;

  return 0;
}
