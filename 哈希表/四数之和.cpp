#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        // 查找四数之和等于0 的计数
        int count = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                map[A[i] + B[j]]++;
            }
        }
        // 更简洁的写法
        for (int c : C)
        {
            for (int d : D)
            {
                if (map.find(-(c + d)) != map.end())
                {
                    count += map[-(c + d)];
                }
            }
        }
        return count;
    }
};