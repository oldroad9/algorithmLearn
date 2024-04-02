#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
class Solution {
    bool repeatSubstring(string s)
    {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1);
        // 排除查找到第一个或者最后一个s的可能性
        if (t.find(s) != std::string::npos) {
            return true;
        }
        else {
            return false;
        }
    }

    void getNext(int *next, const string &s)
    {
        next[0] = -1;
        int j = -1;
        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s)
    {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        // 利用kmp算法计算 是否存在重复的字串
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
            return true;
        }
        return false;
    }
};