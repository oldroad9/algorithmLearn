#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // g(i) 代表每个孩子的胃口值 s(i) 代表饼干满足的大小
        // 输出最大满足大小 sort 默认为升序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int startIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = startIndex; j < g.size(); j++) {
                if (s[i] >= g[j]) {
                    startIndex++;
                    break;
                }
            }
        }
        return startIndex;
    }

    int findContentChildren2(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1; // 饼干数组的下标
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) { // 遍历胃口
            if (index >= 0 && s[index] >= g[i]) { // 遍历饼干
                result++;
                index--;
            }
        }
        return result;
    }
};