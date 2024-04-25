#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 首先按照身高顺序进行排序，然后按照 k 依次插入
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> que;
        for(int i = 0; i < people.size(); i++) {
            int index = people[i][1];
            que.insert(que.begin() + index, people[i]);
        }
        return que;
    }

    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] < b[1]; // 身高相同则 k 小的站在前面
        }
        return a[0] > b[0];
    }
};