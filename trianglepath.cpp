//
//  trianglepath.cpp
//  https://algospot.com/judge/problem/read/TRIANGLEPATH
//
//  Created by foronemonth on 2018. 5. 7..
//  Copyright © 2018년 Peter. All rights reserved.
//

#include <stdio.h>

inline int find_max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

const int MAX_SIZE_OF_TRIAGNLE = 100;

int triangle[MAX_SIZE_OF_TRIAGNLE + 1][MAX_SIZE_OF_TRIAGNLE + 1];
int dp[MAX_SIZE_OF_TRIAGNLE + 1][MAX_SIZE_OF_TRIAGNLE + 1];

int main()
{
    int test_case;
    scanf("%d", &test_case);
    
    for(int t = 0; t < test_case; t++)
    {
        int triangle_size;
        scanf("%d", &triangle_size);
        
        for(int row = 0; row < triangle_size; row++)
        {
            for(int column = 0 ; column < triangle_size; column++)
            {
                if(row < column)
                    continue;
                scanf("%d", &triangle[row][column]);
            }
        }
        
        dp[0][0] = triangle[0][0];
        
        for(int row = 1; row < triangle_size; row++)
        {
            for(int column = 0 ; column < triangle_size; column++)
            {
                if(row < column)
                    continue;
                
                if(column == 0)
                {
                    dp[row][column] = dp[row - 1][column] + triangle[row][column];
                }
                else if(row == column)
                {
                    dp[row][column] = dp[row - 1][column - 1] + triangle[row][column];
                }
                else
                {
                    dp[row][column] = find_max(dp[row - 1][column - 1], dp[row - 1][column]) + triangle[row][column];
                }
            }
        }
        
        int max = 0;
        for(int i = 0; i < triangle_size ; i++)
        {
            if(max < dp[triangle_size - 1][i])
                max = dp[triangle_size - 1][i];
        }
        
        printf("%d\n", max);
    }
}
