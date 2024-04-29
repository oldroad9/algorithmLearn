#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    void eraseDuplicateItem(string &s)
    {
        while (true) {
            bool flag = 0;
            for (int i = 1; i < s.size(); i++) {
                if (s[i] == s[i - 1]) {
                    s.erase(s.begin() + i - 1, s.begin() + i + 1);
                    // erase 不包含右端，为左闭右开
                    flag = 1;
                }
            }
            if (!flag) {
                break;
            }
        }
    }
    string removeDuplicates(string S)
    {
        stack<char> st;
        for (char s : S) {
            if (st.empty() || s != st.top()) {
                st.push(s);
            }
            else {
                st.pop(); // s 与 st.top()相等的情况
            }
        } // 设计栈进行判断
        string result = "";
        while (!st.empty()) { // 将栈中元素放到result字符串汇总
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end()); // 此时字符串需要反转一下
        return result;
    }

    // 利用栈的方式，将string本身作为栈
    string removeDuplicates1(string S)
    {
        string result;
        for (char s : S) {
            if (result.empty() || result.back() != s) {
                result.push_back(s);
            }
            else {
                result.pop_back();
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    string str = "abbaca";
    s.eraseDuplicateItem(str);
    cout << str << endl;
}