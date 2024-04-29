#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        int hash[27] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }
        vector<int> result;
        int maxIndex = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            maxIndex = max(maxIndex, hash[s[i] - 'a']);
            if (i == maxIndex) {
                result.push_back(maxIndex - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};