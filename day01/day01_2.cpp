#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
    int depth;
    vector<int> depths;
    int cur_sum, prev_sum;
    int count = 0;
    while(cin >> depth)
    {
        depths.push_back(depth);
    }
    int len = depths.size();
    prev_sum = depths[0] + depths[1] + depths[2];
    for(int i = 3; i < len; i++)
    {
       cur_sum = depths[i] + depths[i-1] + depths[i-2];
       if(cur_sum > prev_sum)
           count++;
       prev_sum = cur_sum;
    }
    cout << count;
    return 0;
}

