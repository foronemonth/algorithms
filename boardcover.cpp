#include <stdio.h>

#define MAX_H 20
#define MAX_W 20

char board[(MAX_H + 1)][(MAX_W + 1)];
int block_shape[4][4] = {
    {0, 1, 1, 1},
    {1, 0, 1, -1},
    {1, 0, 1, 1},
    {1, 0, 0, 1}
};

int number_of_empty_space;
int total_nubmer_of_block;
int now_number_of_block;

int H;
int W;

bool is_possible_to_search(int y, int x, int y1, int x1, int y2, int x2)
{
    bool ret = false;
    //check boundary
    if( 0 <= y && y < H && 0 <= x && x < W &&
       0 <= y1 && y1 < H && 0 <= x1 && x1 < W &&
       0 <= y2 && y2 < H && 0 <= x2 && x2 < W
       )
    {
        if(board[y][x] == '.' && board[y1][x1] == '.' && board[y2][x2] == '.')
            ret = true;
    }
    return ret;
}

int fill_board(int y, int x)
{
    int result = 0;
    
    if(total_nubmer_of_block == now_number_of_block)
        return 1;
    
    if(board[y][x] == '#')
        result += fill_board(y + (x + 1) / W, (x + 1) % W);
    else
    {
        for(int i = 0; i < 4; i++)
        {
            int y1 = y + block_shape[i][0];
            int x1 = x + block_shape[i][1];
            int y2 = y + block_shape[i][2];
            int x2 = x + block_shape[i][3];
            
            if(is_possible_to_search(y, x, y1, x1, y2, x2))
            {
                board[y][x] = '#';
                board[y1][x1] = '#';
                board[y2][x2] = '#';
                ++now_number_of_block;
                
                result += fill_board(y + (x + 1) / W, (x + 1) % W);
                
                board[y][x] = '.';
                board[y1][x1] = '.';
                board[y2][x2] = '.';
                --now_number_of_block;
            }
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
        scanf("%d %d", &H, &W);
        for(int i = 0; i < H; i++)
            scanf("%s", board[i]);
        
        number_of_empty_space = 0;
        for(int i = 0; i< H; i++)
        {
            for(int j =0; j<W; j++)
                if(board[i][j] == '.')
                    number_of_empty_space += 1;
        }
        
        if(number_of_empty_space % 3 == 0)
        {
            total_nubmer_of_block = number_of_empty_space / 3;
            now_number_of_block = 0;
            printf("%d\n", fill_board(0, 0));
        }
        else
            printf("0\n");
        
    }

    return 0;
}