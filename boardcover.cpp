#include <stdio.h>

char board[21][21];
bool taken[21][21];
int block_number;
int block_shape[4][4] = { {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}, {1, 0, 1, -1} };
int block_count;

int H;
int W;

bool is_in_boundary(int y1, int x1, int y2, int x2, int y3, int x3)
{
    bool ret = false;
    
    if(0 <= y1 && y1 <= (H - 1) && 0 <= x1 && x1 <= (W - 1) &&
       0 <= y2 && y2 <= (H - 1) && 0 <= x2 && x2 <= (W - 1) &&
       0 <= y3 && y3 <= (H - 1) && 0 <= x3 && x3 <= (W - 1))
    {
        if(taken[y2][x2] == false && taken[y3][x3] == false)
        {
            if(board[y2][x2] == '.' && board[y3][x3] == '.')
                ret = true;
        }
    }
    return ret;
}

int fill_board(int y, int x)
{
    int result = 0;
    if(block_count == block_number)
        return 1;

        if(board[y][x] == '.' && taken[y][x] == false)
        {
            for(int i = 0; i < 4; i++)
            {
                if(is_in_boundary(y, x, y + block_shape[i][0], x + block_shape[i][1], y + block_shape[i][2], x + block_shape[i][3]))
                {
                    taken[y][x] = true;
                    taken[y + block_shape[i][0]][x + block_shape[i][1]] = true;
                    taken[y + block_shape[i][2]][x + block_shape[i][3]] = true;
                    block_count = block_count + 1;
                    
                    result += fill_board(y + (x + 1) / W , (x + 1) % W);
                        
                    taken[y][x] = false;
                    taken[y + block_shape[i][0]][x + block_shape[i][1]] = false;
                    taken[y + block_shape[i][2]][x + block_shape[i][3]] = false;
                    block_count = block_count - 1;
                    }
                }
                
            }
        else
        {
            result = fill_board(y + (x + 1) / W , (x + 1) % W);
        }
    
    
    
    
    return result;
}



int main()
{
    int test_case;

    scanf("%d", &test_case);
    for(int t = 0; t < test_case; t++)
    {
        int black = 0;
        block_count = 0;
        
        scanf("%d %d", &H, &W);
        for(int i = 0; i < H; i++)
        {
            scanf("%s", board[i]);
            
            for(int j= 0; j < W; j++)
            {
                if(board[i][j] == '.')
                    black++;
                taken[i][j] = false;
            }
            
        }
        
        if(black % 3 != 0)
        {
            printf("0\n");
            continue;
        }
        
        block_number = black / 3;
        
        printf("%d\n", fill_board(0, 0));
    }
    
    return 0;
}