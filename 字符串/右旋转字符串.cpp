#include <algorithm>
#include <string>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    void turnStr(string &s, int start, int end)
    {
        for (; start < end; start++, end--)
        {
            swap(s[start], s[end]);
        }
    }

    void rightRotateStr(string &s, int k)
    {
        turnStr(s, 0, s.size() - 1);
        turnStr(s, 0, k - 1);
        turnStr(s, k, s.size() - 1);
    }
};

int main()
{
    string s = "asdasxzc";
    Solution s1;
    s1.rightRotateStr(s, 2);
    std::cout << s << std::endl;
}