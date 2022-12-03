#include <stdio.h>

int sum_window(int* buf)
{
    int sum = 0;
    for(int i = 0; i < 3; i++)
        sum += buf[i];
    return sum;
}

int main()
{
    int cur_window[3];
    int win_index = 0;
    int count = 0;
    scanf("%d %d %d", cur_window, cur_window+1, cur_window+2);
    int cur_win_sum,prev_win_sum;
    prev_win_sum = sum_window(cur_window);
    while(scanf(" %d", cur_window+win_index) > 0)
    {
       cur_win_sum = sum_window(cur_window);
       if(cur_win_sum > prev_win_sum)
           count++;
       win_index = (win_index + 1) % 3;
       prev_win_sum = cur_win_sum;

    }
    printf("%d\n", count);
    return 0;
}
