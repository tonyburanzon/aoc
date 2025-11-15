#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

struct DataBlock 
{
  int id;
  int size;
  int free_space;
};

void read_file(string& str)
{
  ifstream file("input");
  getline(file, str);
}

void write_raw_disk(string& disk_map, vector<DataBlock>& raw_disk)
{
  int id = 0;

  for(int i = 0; i < disk_map.length(); i += 2)
  {
    int file_size = disk_map[i] - '0';
    int blank_space = i+1 < disk_map.length() ? disk_map[i+1] - '0' : 0;  

    DataBlock db = {id, file_size, blank_space};
    raw_disk.push_back(db);

    id++;
  }
}

void defrag(vector<DataBlock>& disk)
{
  for(int rearIndx = disk.size() -  1; rearIndx > 0; rearIndx--)
  {
    for(int frontIndx = 0; frontIndx < rearIndx; frontIndx++)
    {
      if(disk[frontIndx].free_space >= disk[rearIndx].size)
      {
        if(frontIndx == rearIndx - 1)
        {
          disk[rearIndx].free_space = disk[rearIndx].free_space + (disk[frontIndx].free_space - disk[rearIndx].size);
          disk[frontIndx].free_space = 0;
          break;
        }
        else
        {
          disk[rearIndx-1].free_space += disk[rearIndx].size + disk[rearIndx].free_space;
          disk[rearIndx].free_space = disk[frontIndx].free_space - disk[rearIndx].size;
          disk[frontIndx].free_space = 0;
          disk.insert(disk.begin() + frontIndx + 1, disk[rearIndx]);
          disk.erase(disk.begin() + rearIndx + 1);
          rearIndx++;
          break;
        }
      }
    }
  }

}

unsigned long long int find_checksum(vector<DataBlock>& disk)
{
  unsigned long long int checksum = 0;
  int multiplier = 0;
  for(unsigned long long int i = 0; i < disk.size(); i++)
  {
    for(int j = 0; j < disk[i].size; j++)
    {
      checksum += multiplier * disk[i].id;
      multiplier++;
    }
    multiplier += disk[i].free_space;
  }

  return checksum;
}

int main() 
{
  string disk_map = "";
  read_file(disk_map);
   
  vector<DataBlock> raw_disk;
  write_raw_disk(disk_map , raw_disk);

  defrag(raw_disk);

  //cout << raw_disk << endl << endl;

  cout << find_checksum(raw_disk) << endl;
  return 0;
}
