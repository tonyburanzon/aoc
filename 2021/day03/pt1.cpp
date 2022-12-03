#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> bin;
    string temp;
    while(getline(cin, temp))
    {
        bin.push_back(temp);
    }
    int counts[bin[0].length()];
    for(int i = 0; i < bin[0].length(); i++)
        counts[i] = 0;
    for(int i = 0; i < bin.size(); i++)
    {
        for(int j = 0; j < bin[i].length(); j++)
        {
            counts[j] += (int)bin[i][j] - '0';
        }
    }
    int gamma_rate = 0;
    int epsilon_rate = 0;
    for(int i = 0; i < bin[0].length(); i++)
    {
        if(counts[i] > bin.size() / 2)
        {
            gamma_rate |= 1 << (bin[0].length()-1-i);
        }
        else
        {
            epsilon_rate |= 1 << (bin[0].length()-1-i);
        }
    }
//    epsilon_rate = ~gamma_rate | 0x1ff;
    cout << gamma_rate * epsilon_rate << endl; 



    return 0;
}
