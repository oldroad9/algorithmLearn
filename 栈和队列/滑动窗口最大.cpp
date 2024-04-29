#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    class myQueue {
    public:
        deque<int> que;
        void pop(int value)
        {
            if (!que.empty() && que.front() == value) {
                que.pop_front();
            }
        }
        void push(int value)
        {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);
        }
        int front()
        {
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        myQueue que;
        vector<int> result;
        for (size_t i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        for (size_t i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};