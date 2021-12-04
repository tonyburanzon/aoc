#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

void remove_shit(vector<string> &vec, int ind, const char chr)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i][ind] == chr)
            vec.erase(vec.begin() + i--);
    }
};

int bin_to_int(string str)
{
    int acc = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '1')
        {
            //acc += 2**(str.length() - i - 1);
            acc += pow(2.0, str.length() - i - 1);
        }
    }
    return acc;
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
        
        int one = 0;
        int zero = 0;
        for(int j = 0; j < oxy.size(); j++)
        {
            if(oxy[j][i] == '1')
                one++;
            else
                zero++;
        }
        if(zero > one)
            remove_shit(oxy, i, '1');
        else
            remove_shit(oxy, i, '0');

    }

    //find carb code
    for(int i = 0; i < carb[0].length(); i++)
    {
        if(carb.size() == 1)
            break;
        
        int one = 0;
        int zero = 0;
        for(int j = 0; j < carb.size(); j++)
        {
            if(carb[j][i] == '1')
                one++;
            else
                zero++;
        }
        if(one >= zero)
            remove_shit(carb, i, '1');
        else
            remove_shit(carb, i, '0');

    }
    cout << bin_to_int(oxy[0]) * bin_to_int(carb[0]) << endl;

}
