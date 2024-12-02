#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class Counter 
{
public: 
  int left_count;
  int right_count;
  Counter() : left_count(0), right_count(0) {};
};

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

  map<int, Counter> myMap;

  //sort(left_list.begin(), left_list.end());
  //sort(right_list.begin(), right_list.end());

  for(int i = 0; i < left_list.size(); i++)
  {
    myMap[left_list.at(i)].left_count++;
  }
  
  // Count how many times it appear in the right list
  for(int i = 0; i < right_list.size(); i++)
  {
    if(myMap.find(right_list.at(i)) != myMap.end())
      myMap[right_list.at(i)].right_count++;
  }

  int count = 0;
  for(map<int, Counter>::iterator it = myMap.begin(); it != myMap.end(); it++)
  {
    //cout << it->first << " " << it->second.left_count << " " << it->second.right_count << endl;
    count += it->first * (it-> second.left_count * it->second.right_count);
  }

  cout << count << endl;


  return 0;
};
