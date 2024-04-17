#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
        result.clear();
        if (s.size() < 4 || s.size() > 12)
            return result; // 算是剪枝了
        backtracking(s, 0, 0);
        return result;
    }

private:
    vector<string> result;
    // 直接在 原字符串进行操作
    void backtracking(string &s, int startIndex, int pointNum)
    {
        if (pointNum == 3) {
            if (isvalidIP(s, startIndex, s.size())) {
                result.push_back(s);
            }
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            if (isvalidIP(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backtracking(s, i + 2, pointNum);
                s.erase(s.begin() + i + 1);
                pointNum--;
            }
            else {
                break;
            }
        }
    }

    bool isvalidIP(string &s, int start, int end)
    {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) {
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
            num += (s[i] - '0') * (start + 1) * 10;
            // num = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
};