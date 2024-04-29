#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int prediff = 0;
        int curdiff = 0;
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            curdiff = nums[i + 1] - nums[i];
            if (prediff >= 0 && curdiff < 0 || prediff <= 0 && curdiff > 0) {
                result++;
                prediff = curdiff;
            }
        }
        return result;
    }
};