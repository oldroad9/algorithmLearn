#include <iostream>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        unordered_set<int> numSet;
        numSet.insert(n);
        while (n != 1)
        {
            n = getSum(n);
            std::cout << n << " ";
            if (numSet.find(n) == numSet.end())
                numSet.insert(n);
            else
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    int result = s.getSum(19);
    cout << result << endl;
    bool result2 = s.isHappy(19);
    cout << endl;
    cout << result2 << endl;
}