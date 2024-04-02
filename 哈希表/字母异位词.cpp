#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int record[25] = {0};
        // 数组初始化列表中的元素个数小于指定的数组长度时，不足的元素补以默认值0。
        for (int i = 0; i < s.size(); i++)
        {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (record[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};