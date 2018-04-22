//
//  wildcard.cpp
//  book_Algorithmic-Problem-Solving-Strategies
//
//  Created by PARK on 2018. 4. 22..
//  Copyright © 2018년 Peter. All rights reserved.
//

#include <stdio.h>
#include <string.h>

const int MAX_LENGTH = 100;

char wildcard[MAX_LENGTH + 1];

// wildcard의 알파벳을 target에 1로 marking
// marking된 matching을 가지고 *의 범위를 설정
bool isfit(char* target)
{
    bool ret = false;
    bool matching[MAX_LENGTH + 1] = {0, };
    
    int length = strlen(target);
    
    for(int i = 0; i < length; i++)
    {
        if(target[i] == wildcard[i])
        {
            matching[i] = true;
        }
    }
    
    return ret;
}

int main()
{
    int test_case;
    int number_files;
    
    char target[MAX_LENGTH + 1];
    
    scanf("%d", &test_case);
    for(int t = 0; t < test_case; t++)
    {
        scanf("%s", wildcard);
        scanf("%d", &number_files);
        for(int f = 0; f < number_files; f++)
        {
            scanf("%s", target);
            if(isfit(target))
                printf("%s\n", target);
            
        }
    }
}