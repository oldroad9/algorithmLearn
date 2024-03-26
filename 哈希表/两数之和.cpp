#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end())
            {
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

int main()
{
    Solution s;
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(4);
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(6);
    auto result = s.twoSum(v1, 9);
    for (auto ite = result.begin(); ite != result.end(); ite++)
    {
        std::cout << *ite << " ";
    }
    std::cout << std::endl;
}