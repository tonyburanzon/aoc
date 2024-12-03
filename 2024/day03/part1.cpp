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

  std::regex main_pattern("mul\\([1-9][0-9]{0,2},[1-9][0-9]{0,2}\\)");
  std::sregex_iterator it(input.begin(), input.end(), main_pattern);
  std::sregex_iterator end;


  regex sub_pattern("[1-9][0-9]{0,2}");
  string matched_str;
  int sum = 0;
  while (it != end) {
    std::smatch match = *it;

    string match_str = match.str();
    sregex_iterator sub_it(match_str.begin(), match_str.end(), sub_pattern);
    sregex_iterator sub_end;
    vector<int> multiplicants;
    while(sub_it != sub_end)
    {
      smatch sub_match = *sub_it;
      multiplicants.push_back(stoi(sub_match.str()));
      ++sub_it;
    }
    sum += (multiplicants[0] * multiplicants[1]);
    ++it;
  }

  cout << "Sum: " << sum << endl;

  return 0;

};
