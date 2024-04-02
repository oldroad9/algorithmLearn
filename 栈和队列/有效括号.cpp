#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool validParenthesis(string s)
    {
        stack<char> sta;
        for (auto elem : s) {
            if (elem == '(' || elem == '[' || elem == '{') {
                sta.push(elem);
                continue;
            }
            if (sta.empty() && elem != ' ')
                return false;
            if (elem == ')') {
                if (sta.top() == '(')
                    sta.pop();
                else {
                    return false;
                }
            }
            else if (elem == ']') {
                if (sta.top() == '[')
                    sta.pop();
                else {
                    return false;
                }
            }
            else if (elem == '}') {
                if (sta.top() == '{')
                    sta.pop();
                else {
                    return false;
                }
            }
        }
        if (sta.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    Solution s;
    string str = "{} [[]{}]{}{}";
    auto result = s.validParenthesis(str);
    cout << result << endl;
}