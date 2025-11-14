#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void read_file(string& str)
{
  ifstream file("test_input");
  getline(file, str);
}

int main() 
{
  string disk_map = "";
  read_file(disk_map);
   
  string raw_disk = "";
  int id = 0;

  for(int i = 0; i < disk_map.length(); i += 2)
  {
    int file_size = disk_map[i] = '0';
    int blank_space = i+1 < disk_map.length() ? disk_map[i+1] - '0' : 0;  

    for(int j = 0; j < file_size; j++)
      raw_disk += to_string(id);

    for(int j = 0; j < blank_space; j++)
      raw_disk += '.';

    id++;
  }

  cout << raw_disk << endl;

  return 0;
}
