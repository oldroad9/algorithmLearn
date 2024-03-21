#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    //  暴力求解法
    static vector<int> sortedSquares(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }

    static vector<int> sortedSquares2(vector<int> nums)
    {
        int left_pointer = 0;
        int right_pointer = nums.size() - 1;
        vector<int> numsNew(nums.size(), 0);
        int count = nums.size() - 1;
        while (left_pointer < right_pointer)
        {
            int leftSquare = nums[left_pointer] * nums[left_pointer];
            int rightSquare = nums[right_pointer] * nums[right_pointer];
            if (leftSquare >= rightSquare)
            {
                numsNew[count] = leftSquare;
                left_pointer++;
                // std::cout << numsNew[count] << "right"<< " ";
            }
            else
            {
                numsNew[count] = rightSquare;
                right_pointer--;
                // std::cout << "left" << numsNew[count] << " ";
            }
            count--;
        }
        return numsNew;
    }

    vector<int> sortedSquares3(vector<int> &A)
    {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;)
        { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j])
            {
                result[k--] = A[j] * A[j];
                j--;
            }
            else
            {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};
