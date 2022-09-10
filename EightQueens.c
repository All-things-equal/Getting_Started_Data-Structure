/* 递归 - 八皇后问题 */

#include <stdio.h>
#include <string.h>

void EightQueen(int row, int col, int (*chess)[8]); // row 表 起始行, col 表棋盘列数
int notDanger(int row, int j, int (*chess)[8]);

int count = 0;

int main(int argc, char const *argv[])
{
    int chess[8][8] = {0}; // 8x8棋盘, 0表空, 1表皇后
    EightQueen(0, 8, chess);
    printf("总计%d种方案!\n", count);

    return 0;
}

void EightQueen(int row, int col, int (*chess)[8])
{
    int chessTemp[8][8];
    int i = 0, j = 0;

    memmove(chessTemp, chess, 8 * 8 * sizeof(int));

    if (8 == row)
    {
        printf("NO.%d:\n", ++count);
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                printf("%d ", *(*(chessTemp + i) + j));
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        // 判断这个位置是否有危险
        // 如果没有危险, 继续往下判断
        for (j = 0; j < col; j++)
        {
            if (notDanger(row, j, chess)) // 判断是否危险
            {
                for (i = 0; i < 8; i++)
                {
                    *(*(chessTemp + row) + i) = 0;
                }
                *(*(chessTemp + row) + j) = 1;

                EightQueen(row + 1, col, chessTemp);
            }
        }
    }
}

int notDanger(int row, int col, int (*chess)[8])
{
    int ret = 1;

    int flag_col = 0;
    int flag_upperLeft = 0;
    int flag_bottomRight = 0;
    int flag_topLeft = 0;
    int flag_lowerLeft = 0;

    int i = 0, j = 0;

    // 判断列方向
    for (i = 0; i < 8; i++)
    {
        if (*(*(chess + i) + col) != 0)
        {
            flag_col = 1;
            break;
        }
    }

    // 判断左上方
    i = row;
    j = col;
    while (i >= 0 && j >= 0)
    {
        if (*(*(chess + i) + j) != 0)
        {
            flag_upperLeft = 1;
            break;
        }

        i--;
        j--;
    }

    // 判断右下方
    i = row;
    j = col;
    while (i < 8 && j < 8)
    {
        if (*(*(chess + i) + j) != 0)
        {
            flag_bottomRight = 1;
            break;
        }

        i++;
        j++;
    }

    // 判断右上方
    i = row;
    j = col;
    while (i >= 0 && j < 8)
    {
        if (*(*(chess + i) + j) != 0)
        {
            flag_topLeft = 1;
            break;
        }

        i--;
        j++;
    }

    // 判断左下方
    i = row;
    j = col;
    while (i < 8 && j >= 0)
    {
        if (*(*(chess + i) + j) != 0)
        {
            flag_lowerLeft = 1;
            break;
        }

        i++;
        j--;
    }

    if (flag_col || flag_upperLeft || flag_topLeft || flag_bottomRight || flag_lowerLeft)
    {
        ret = 0;
    }

    return ret;
}
