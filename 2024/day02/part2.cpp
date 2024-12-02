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
    for(int i = 0; i < levels.size() - 1; i++)
    {
      //bool seq_ok = increase ? levels[i] < levels[i+1] : levels[i] > levels[i+1];
      bool seq_ok = (i == 0 || 
        (levels[i-1] < levels[i] && levels[i] > levels[i+1]) || 
        (levels[i-1] > levels[i] && levels[i] < levels[i+1]));

      bool delta_ok = abs(levels[i] - levels[i+1]) <= 3 && abs(levels[i] - levels[i+1]) != 0;
      if(!seq_ok || !delta_ok)
        return false;
    }
    return true;
  };

  bool isSafeMod(vector<int> locLevels)
  {
    //    bool previous_bad = false;
    //    for(int i = 0; i < levels.size(); i++)
    //    {
    //      if(
    //        (i < (levels.size() - 1) && levels[i] == levels[i+1]) ||
    //        (i > 0 && levels[i-i] < levels[i] && levels[i] > levels[i+1]) || 
    //        (i < (levels.size() - 1) && levels[i-1] > levels[i] && levels[i] < levels[i+1]) ||
    //        (abs(levels[i] - levels[i+1]) > 3)
    //      )
    //      {
    //        // We found a bad index, try removing and move index back one.
    //        if(previous_bad)
    //          return false;
    //        if(i == levels.size() - 2)
    //          return true;
    //
    //        // Set flag, remove bad index, and try again
    //        previous_bad = true;
    //        levels.erase(levels.begin()+i);
    //        i = -1;
    //        continue;
    //      }
    //
    //    } 
    //    return true;
    //  }
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
  {
    if(
      reports[i].isSafe()
    )
    {
      safe_count++;
    }
    else
    cout << i+1 << ": Not Safe" << endl;
  }

  cout << safe_count << endl;

  return 0;
};
