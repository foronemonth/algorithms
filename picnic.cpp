#include <stdio.h>

bool pairings_map[11][11];
bool taken[11];
int result;

int student_number;
int student_pair_number;

void init_var()
{
    result = 0;
    for(int i = 0; i<11; i++)
    {
        taken[i] = false;
        for(int j = 0; j<11; j++)
        {
            pairings_map[i][j] = false;
        }
    }
}

int counting_pairings(bool taken[])
{
    int friend1 = -1;
    for(int i = 0; i < student_number; i++)
    {
        if(taken[i] == false)
        {
            friend1 = i;
            break;
        }
    }
    if(friend1 == -1)
        return (result + 1);
    
    for(int j = 0; j < student_number; j++)
    {
        if(pairings_map[friend1][j] == true && taken[j] == false)
        {
            taken[friend1] = true;
            taken[j] = true;
            
            result = counting_pairings(taken);
            
            taken[friend1] = false;
            taken[j] = false;
        }
    }
    return result;
}

int main()
{
    int test_case;
    scanf("%d", &test_case);
    for(int t = 0; t < test_case; t++)
    {
        init_var();
        
        scanf("%d %d", &student_number, &student_pair_number);
        int friend1, friend2;
        for(int i = 0; i < student_pair_number; i++)
        {
            scanf("%d %d",&friend1, &friend2);
            pairings_map[friend1][friend2] = true;
            pairings_map[friend2][friend1] = true;
        }
        result = counting_pairings(taken);
        
        printf("%d\n", result);
    }
    
    return 0;
}