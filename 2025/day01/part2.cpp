#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>

#define MAX  100

using namespace std;



int main() {

  fstream input("input");
  string line;

  int pos = 50;
  int zero_count = 0;

  while(getline(input, line)) {
    char dir;
    int count;
    int prev_pos = pos;

    stringstream ss(line);
     
    ss >> dir >> count;

    zero_count += count / MAX;
    count %= MAX;

    if(dir == 'L')
      pos -= count;
    else 
      pos += count;


    if(pos == 0) {
      zero_count++;
      //cout << pos << endl;
    }
    else if(pos < 0) {
      pos += MAX;
      pos %= MAX;
      zero_count = prev_pos == 0 ? zero_count : zero_count + 1;
      //cout << pos << endl;
    }
    else if(pos >= MAX) {
      pos %= MAX;
      zero_count++;
      //cout << pos << endl;
    }

  }

  cout << zero_count << endl;

  return 0;
}
