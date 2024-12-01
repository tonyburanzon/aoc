#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
  string input_line;
  vector<int> left_list, right_list;
  while(getline(cin, input_line))
  {
    stringstream ss(input_line);
    int left_num, right_num;
    ss >> left_num >> right_num;
    left_list.push_back(left_num);
    right_list.push_back(right_num);
  }
  sort(left_list.begin(), left_list.end());
  sort(right_list.begin(), right_list.end());

  int count = 0;
  for(int i = 0; i < left_list.size(); i++)
  {
    //cout << left_list.at(i) << " " << right_list.at(i) << endl;
    count += abs(left_list.at(i) - right_list.at(i));
  }

  cout << "Count is: " << count << endl;

  return 0;
};
