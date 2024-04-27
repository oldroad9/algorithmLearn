#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n <= 9) {
            return n;
        }
        vector<int> digit;
        // 获得从个位数开始的数字
        int tmp = n;
        while (tmp) {
            tmp = tmp % 10;
            digit.push_back(tmp);
            tmp /= 10;
        }
        bool isIncreasing = true;
        for (int i = 1; i < digit.size(); i++) {
            if (digit[i] > digit[i - 1]) {
                isIncreasing = false;
            }
        }
        if (isIncreasing) {
            return n;
        }
        int result = 0;
        if (digit[digit.size() - 1] == 1) {
            for (int i = 1; i < digit.size() - 1; i++) {
                result += 9 * (i * 10);
            }
            return result;
        }
    }
    int monotoneIncreasingDigits(int N) {
        string strNum = to_string(N);
        // flag用来标记赋值9从哪里开始
        // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i] ) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};