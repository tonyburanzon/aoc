#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int find_digits(unsigned long long num)
{
  int digits = 0;
  while(num != 0)
  {
    num /= 10;
    digits++;
  }
  return digits;
}
struct Stone 
{
public: 
  unsigned long long num;
  int count;
  Stone(unsigned long long num): num(num), count(1) {};
  Stone(unsigned long long num, int count): num(num), count(count) {};
};

int main()
{
  std::vector<Stone> stones;
  unsigned long long num;
  while(cin >> num)
  {
    Stone s(num);
    stones.push_back(s);
  }

  for(int iter = 0; iter < 75; iter++)
  {
    for(int stoneInd = 0; stoneInd < stones.size(); stoneInd++)
    {
      if(stones[stoneInd].num == 0)
      {
        stones[stoneInd].num = 1;
      }
      else if(find_digits(stones[stoneInd].num) % 2 == 0)
      {
        unsigned long long curNum = stones[stoneInd].num;
        unsigned long long digits = find_digits(curNum);
        unsigned long long powerNum = pow(10, digits/2);
        unsigned long long firstNewNum = curNum / powerNum;
        unsigned long long secondNewNum = curNum % powerNum;
        stones[stoneInd].num = firstNewNum;
        stones.insert(stones.begin()+stoneInd+1, Stone(secondNewNum, stones[stoneInd].count));
        stoneInd++;
      }
      else 
    {
        stones[stoneInd].num *= (unsigned long long)2024;
      }
      // Consolidate Stones
    }
    for(int i = 0; i < stones.size(); i++) {
      for(int j = stones.size() - 1; j > i; j--) {
        if(stones[i].num == stones[j].num) {
          stones[i].count += stones[j].count;
          stones.erase(stones.begin() + j);
        }
      }
    }
  }
  unsigned long long count = 0;
  for(int i = 0; i < stones.size(); i++)
    count += stones[i].count;

  cout << count << endl;
}
