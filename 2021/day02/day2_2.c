#include <stdio.h>
#include <string.h>


int main()
{
    int hor_pos = 0;
    int depth = 0;
    int aim = 0;
    char  dir[8];
    int mag;
    while(scanf(" %s %d", dir, &mag) > 0)
    {
        if(strcmp(dir, "forward") == 0)
        {
            hor_pos += mag;
            depth += aim * mag;
        }
        else if(strcmp(dir, "up") == 0)
            aim -= mag;
        else if(strcmp(dir,"down") == 0)
            aim += mag;
    }
    printf("%d\n", hor_pos * depth);
    return 0;
}
