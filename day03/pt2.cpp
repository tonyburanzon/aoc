#include <iostream>
#include <vector>

using namespace std;

void remove_shit(vector<string> &vec, int ind, char chr)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i][ind] != chr)
            vec.erase(vec.begin() + i);
    }
};
int main()
{
    vector<string> oxy;
    vector<string> carb;
    string temp;
    while(getline(cin,temp))
    {
        oxy.push_back(temp);
        carb.push_back(temp);

    }

    //find oxy code
    for(int i = 0; i < oxy[0].length(); i++)
    {
        if(oxy.size() == 1)
            break;
        
        int count = 0;
        for(int j = 0; j < oxy.size(); j++)
        {
            if(oxy[j][i] == "1")
                count++;
        }
        if(count < oxy.size() / 2)
            remove_shit(oxy, i, "0");
        else
            remove_shit(oxy, i, "1");

    }

}
