#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    int hor_pos = 0;
    int depth = 0;
    string dir;
    int mag;
    while(cin >> dir >> mag)
    {
        if(dir == "forward")
            hor_pos += mag;
        else if(dir == "up")
            depth -= mag;
        else if(dir == "down")
            depth += mag;
    }
    cout << hor_pos * depth << "\n";
    return 0;
}
