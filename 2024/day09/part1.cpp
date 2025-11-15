#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void read_file(string& str)
{
  ifstream file("test_input2");
  getline(file, str);
}
void write_raw_disk(string& disk_map, vector<int>& raw_disk)
{
  int id = 0;

  for(int i = 0; i < disk_map.length(); i += 2)
  {
    int file_size = disk_map[i] - '0';
    int blank_space = i+1 < disk_map.length() ? disk_map[i+1] - '0' : 0;  

    for(int j = 0; j < file_size; j++)
      raw_disk.push_back(id);

    for(int j = 0; j < blank_space; j++)
      raw_disk.push_back(-1);

    id++;
  }
}

void defrag(vector<int> disk)
{
  int leftIndx = 0;
  int rightIndx = disk.size() - 1;

  while( leftIndx < rightIndx )
  {
    while( leftIndx < rightIndx && disk[leftIndx] != -1 )
      leftIndx++;
    
    while ( rightIndx > leftIndx && disk[rightIndx] == -1 )
      rightIndx--;

    disk[leftIndx] = disk[rightIndx];
    disk[rightIndx] = -1;
    //leftIndx++; rightIndx--;
  }
}

unsigned long long int find_checksum(vector<int> disk)
{
  unsigned long long int checksum = 0;
  for(unsigned long long int i = 0; i < disk.size(); i++)
  {
    if(disk[i] == -1)
      continue;

    checksum += disk[i] * i;
  }

  return checksum;
};

int main() 
{
  string disk_map = "";
  read_file(disk_map);
   
  vector<int> raw_disk;
  write_raw_disk(disk_map , raw_disk);

  defrag(raw_disk);

  //cout << raw_disk << endl << endl;

  cout << find_checksum(raw_disk) << endl;
  return 0;
}
