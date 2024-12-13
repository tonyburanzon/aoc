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

int main()
{
  std::vector<unsigned long long> stones;
  unsigned long long num;
  while(cin >> num)
    stones.push_back(num);

  for(int iter = 0; iter < 25; iter++)
  {
    if(iter < 7)
    {
      cout << iter+1 << ": ";
      for(int i = 0; i < stones.size(); i++)
        cout << stones[i] << " ";
      cout << endl;
    }
    for(int stoneInd = 0; stoneInd < stones.size(); stoneInd++)
    {
      if(stones[stoneInd] == 0)
      {
        stones[stoneInd] = 1;
        continue;
      }

      if(find_digits(stones[stoneInd]) % 2 == 0)
      {
        unsigned long long curNum = stones[stoneInd];
        unsigned long long digits = find_digits(curNum);
        unsigned long long powerNum = pow(10, digits/2);
        unsigned long long firstNewNum = curNum / pow(10, digits/2);
        stones[stoneInd] = firstNewNum;
        stones.insert(stones.begin()+stoneInd+1, curNum % (firstNewNum * powerNum));
        stoneInd++;
        continue;
      }

      stones[stoneInd] *= (unsigned long long)2024;
    }

  }

  cout << stones.size() << endl;
}
