#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    void reverse(string &s, int start, int end)
    {
        // 选择为左闭右开
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    void reverseStr(string &s, int k)
    {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if ((s.size() - i >= k) && (s.size() - i < 2 * k) ||
                s.size() - i > 2 * k) {
                reverse(s, i, i + k - 1); // 左闭右开，需要减 1
            }
            else if (s.size() - i < k) {
                reverse(s, i, s.size() - 1);
            }
            // 下面方法更加简洁
            // if (i + k <= s.size())
            // {
            //     reverse(s, i, i + k - 1);
            //     continue;
            // }
            // // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            // reverse(s, i, s.size() - 1);
        }
    }
};

int main()
{
    Solution s;
    string str = "abcdefg";
    s.reverseStr(str, 2);
    // for (auto it = str.begin(); it != str.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    cout << str << endl;
    return 0;
}