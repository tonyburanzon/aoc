#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    int hor_pos = 0;
    int depth = 0;
    int aim = 0;
    string dir;
    int mag;
    while(cin >> dir >> mag)
    {
        if(dir == "forward")
        {
            hor_pos += mag;
            depth += aim * mag;
        }
        else if(dir == "up")
            aim -= mag;
        else if(dir == "down")
            aim += mag;
    }
    cout << hor_pos * depth << "\n";
    return 0;
}
