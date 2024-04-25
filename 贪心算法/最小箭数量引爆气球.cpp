#include <vector>

using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 寻找最大交叉区间
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int result = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) {
                result++;
            }
            else {
                points[i][0] = min(points[i][0], points[i - 1][1]);
            }
        }
        return result;
    }

    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
};