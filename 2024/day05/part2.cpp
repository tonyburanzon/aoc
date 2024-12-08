#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<int>> getRulesForNum(vector<vector<int>> rules, int num)
{
  vector<vector<int>> retRules;
  for(int i = 0; i < rules.size(); i++)
  {
    if(rules[i][1] == num)
      retRules.push_back(rules[i]);
  }
  return retRules;
};

bool numberBeenSorted(vector<int> sortedNums, int num)
{
  for(int i = 0; i < sortedNums.size(); i++)
    if(sortedNums[i] == num)
      return true;
  return false;
}

void sortPage(vector<int>& page, vector<vector<int>>& rules)
{
  vector<int> sortedNumbers;
  for(int pageIndex = 0; pageIndex < page.size(); pageIndex++)
  {
    if(numberBeenSorted(sortedNumbers, page[pageIndex]))
       continue;

    // Get Rules for current number where current number is the second number in the rule.
    vector<vector<int>> locRules = getRulesForNum(rules, page[pageIndex]);
    // find largest index of numbers where the rules first number is in the page
    int largestIndex = -1;
    for(int ruleIndex = 0; ruleIndex < locRules.size(); ruleIndex++)
    {
      for(int badPageIndex = 0; badPageIndex < page.size(); badPageIndex++)
      {
        if(page[badPageIndex] == locRules[ruleIndex][0] && badPageIndex > largestIndex)
          largestIndex = badPageIndex;
      }
    }
    // Remove and reinsert current number at the index of largest index.
    if(largestIndex > -1 && largestIndex > pageIndex)
    {
      int num = page[pageIndex];
      page.erase(page.begin()+pageIndex);
      page.insert(page.begin()+largestIndex, num);
      pageIndex--;
      sortedNumbers.push_back(num);
    }
  }
}

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

  for(int brokenPageIndex = 0; brokenPageIndex < broken_pages.size(); brokenPageIndex++)
  {
    sortPage(broken_pages[brokenPageIndex], rules);
  }

  int count = 0;
  for(int i = 0; i < broken_pages.size(); i++)
  {
    count += broken_pages[i][broken_pages[i].size() / 2];
  }

  cout << "Count: " << count << endl;
}
