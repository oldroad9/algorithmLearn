#include <iostream>
#include <vector>

class Solution
{
public:
    static std::vector<std::vector<int>> generateMatrix(int n)
    {
        // 生成二维数组
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2;           // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2;            // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int count = 1;              // 用来给矩阵中每一个空格赋值
        int offset = 1;             // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
        int i, j;
        while (loop--)
        { // 判断循环几次
            i = startx;
            j = starty;
            for (j = starty; j < n - offset; j++)
            {
                res[startx][j] = count++;
            }
            for (i = startx; i < n - offset; i++)
            {
                res[i][j] = count++;
            }
            for (; j > starty; j--)
            {
                res[i][j] = count++;
            }
            for (; i > startx; i--)
            {
                res[i][j] = count++;
            }
            startx++;
            starty++;

            offset++;
        }
        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2)
        {
            res[mid][mid] = count;
        }
        return res;
    }
};