#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>

#define MAX  100

using namespace std;



int main() {

  fstream input("test_input");
  string line;

  int pos = 50;
  int zero_count = 0;

  while(getline(input, line)) {
    char dir;
    int count;

    stringstream ss(line);
     
    ss >> dir >> count;

    if(dir == 'L')
      pos -= count;
    else 
      pos += count;

    if(pos < 0) {
      pos += MAX;
      pos %= MAX;
      zero_count++;
    }
    else if(pos >= MAX) {
      pos %= MAX;
      zero_count++;
    }
  }

  cout << zero_count << endl;

  return 0;
}
