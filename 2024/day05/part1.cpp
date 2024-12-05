#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  vector<string> rules;
  vector<string> pages;
  string buf;
  int index = 0;
  while(getline(cin, buf)) {
    if(buf == "")
      break;
    rules.push_back(buf);
  };

  while(getline(cin, buf))
    pages.push_back(buf);

  cout << rules.size() << endl;
  cout << pages.size() << endl;
}
