#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int depth, next_depth;
    int count = 0;
    cin >> depth;
    while(cin >> next_depth)
    {
        if(next_depth > depth)
            count++;
        depth = next_depth;
    }
    cout << count << "\n";
    return 0;
}
