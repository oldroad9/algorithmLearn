#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }

private:
    vector<vector<string>> result;
    vector<string> path;
    void backtracking(string &str, int startIndex)
    {
        if (startIndex >= str.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < str.size(); i++) {
            if (isPalindrome(str, startIndex, i)) {
                string s = str.substr(startIndex, i - startIndex + 1);
                // 第二个参数为 指定的长度
                path.push_back(s);
            }
            else {
                continue;
            }
            backtracking(str, i + 1);
            path.pop_back();
        }
    }
    // 判断是否为回文
    bool isPalindrome(const string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};