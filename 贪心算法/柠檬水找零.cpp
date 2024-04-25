#include <vector>

using namespace std;


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> money(2, 0);
        // 0 代表 5 元 、 1 代表 10元  的数量
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                money[0]++;
            
            if (bills[i] == 10) {
                if (money[0] > 0) {
                    money[0]--;
                    money[1]++;
                }
                else {
                    return false;
                }
            }
            if (bills[i] == 20) {
                if (money[1] > 0 && money[0] > 0) {
                    money[1]--;
                    money[0]--;
                }
                else if (money[0] >= 3) {
                    money[0] -= 3;
                }
                else {
                    return false;
                }
            }
        }
    return true;
    }
};