#include <stdio.h>

int main()
{
    int depth, next_depth;
    int count = 0;
    scanf("%d", &depth);
    while(scanf(" %d", &next_depth) > 0)
    {
        if(next_depth > depth)
            count++;
        depth = next_depth;
    }
    printf("%d \n", count);
    return 0;
}
