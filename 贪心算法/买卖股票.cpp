#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int result = 0;
        for (int i = 0; i < prices.size() - 2; i++) {
            int profit = prices[i + 1] - prices[i];
            result += max(profit, 0);
        }
        return result;
    }
};