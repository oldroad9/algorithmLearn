#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        // for (auto it = intervals.begin(); it != intervals.end(); it++) {
        //     for (auto ite = it->begin(); ite != it->end(); ite++) {
        //         cout << *ite << " ";
        //     }
        //     cout << endl;
        // }
        vector<vector<int>> result;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= intervals[i - 1][1]) {
                intervals[i][0] = intervals[i - 1][0];
                intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
            }
            else {
                result.push_back(intervals[i - 1]);
            }
        }
        result.push_back(intervals[intervals.size() - 1]);
        return result;
    }
    static bool cmp (vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 4}, {0, 4}};
    Solution s;
    auto result = s.merge(intervals);
    for (auto it = result.begin(); it != result.end(); it++) {
        for (auto ite = it->begin(); ite != it->end(); ite++) {
            cout << *ite << " ";
        }
        cout << endl;
    }
}