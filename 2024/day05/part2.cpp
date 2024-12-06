#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
  vector<string> rules_str;
  vector<string> pages_str;
  string buf;
  int index = 0;
  while(getline(cin, buf)) {
    if(buf == "")
      break;
    rules_str.push_back(buf);
  };

  while(getline(cin, buf))
    pages_str.push_back(buf);


  vector<vector<int>> rules;
  for(int i = 0; i < rules_str.size(); i++)
  {
    int num1, num2;
    char bar;
    vector<int> rule;
    stringstream ss(rules_str[i]);
    ss >> num1 >> bar >> num2;
    rule.push_back(num1);
    rule.push_back(num2);
    rules.push_back(rule);
  }

  vector<vector<int>> pages;
  for(int j = 0; j < pages_str.size(); j++)
  {
    for(int i = 0; i < pages_str[j].length(); i++)
    {
      if(pages_str[j][i] == ',')
        pages_str[j][i] = ' ';
    }
    stringstream ss(pages_str[j]);
    vector<int> page;
    int num;
    while(ss >> num)
      page.push_back(num);

    pages.push_back(page);
  }


  vector<vector<int>> broken_pages;
  for(int ruleIndex = 0; ruleIndex < rules.size(); ruleIndex++)
  {
    for(int pageIndex = 0; pageIndex < pages.size(); pageIndex++)
    {
      bool found = false;
      for(int i = pages[pageIndex].size() - 1; i >= 0; i--)
      {
        if(pages[pageIndex][i] == rules[ruleIndex][0])
        {
          found = true;
          continue;
        }
        if(found && pages[pageIndex][i] == rules[ruleIndex][1])
        {
          broken_pages.push_back(pages[pageIndex]);
          pages.erase(pages.begin()+pageIndex);
          pageIndex--;
          break;
        }
      }
    }
  }

  for(int ruleIndex = 0; ruleIndex < rules.size(); ruleIndex++)
  {
    for(int pageIndex = 0; pageIndex < broken_pages.size(); pageIndex++)
    {
      bool found;
      int foundIndex = -1;
      for(int i = broken_pages[pageIndex].size() - 1; i >= 0; i--)
      {
        if(broken_pages[pageIndex][i] == rules[ruleIndex][0])
        {
          found = true;
          foundIndex = i;
          cout << foundIndex << endl;
          continue;
        };
        if(found && broken_pages[pageIndex][i] == rules[ruleIndex][1])
        {
          int num = broken_pages[pageIndex][i];
          broken_pages[pageIndex].erase(broken_pages[pageIndex].begin()+i);
          broken_pages[pageIndex].insert(broken_pages[pageIndex].begin()+foundIndex+1, num);
          break;
        }
      }
    }
  }

  cout << "Broken: " << broken_pages.size() << endl;

  int count = 0;
  for(int i = 0; i < broken_pages.size(); i++)
  {
    cout << "Size: " << broken_pages[i].size() << broken_pages[i][broken_pages[i].size() / 2] << endl;
    for(int j = 0; j < broken_pages[i].size(); j++)
      cout << broken_pages[i][j] << " ";
    cout << endl;
    count += broken_pages[i][broken_pages[i].size() / 2];
  }

  cout << "Count: " << count << endl;
}
