#include <stdio.h>

const int CLOCKS = 16;
const int list_of_connection[10][5] = {
    {0, 1, 2, -1, -1},
    {3, 7, 9, 11, -1},
    {4, 10, 14, 15, -1},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15, -1},
    {3, 14, 15, -1, -1},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}
}
int time[(CLOCKS + 1)];
int pressed[(CLOCKS + 1)];

int check_clock(int result)
{
    int count = 0;
    
    for(int i = 0; i < CLOCKS; i++)
        count += pressed[i];
    
    if(count < result)
        result = count;
    
    return result;
}

int press_switch(bool p[])
{
    check_clock
}

int time_convert(int raw)
{
    if(raw == 3)
        return 1;
    else if(raw == 6)
        return 2;
    else if(raw == 9)
        return 3;
    else
        return 0;
}

int main()
{
    int test_case;
    
    scanf("%d", &test_case);
    for(int t = 0; t < test_case; t++)
    {
        for(int i = 0; i < CLOCKS; i++)
        {
            int time_raw;
            scanf("%d", &time_raw);
            time[i] = time_convert(time_raw);
        }
        
        
    }
}