#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long long> st;
        for (size_t i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                long long nums;
                if (tokens[i] == "+") {
                    nums = num1 + num2;
                }
                else if (tokens[i] == "-") {
                    nums = num1 - num2;
                }
                else if (tokens[i] == "*") {
                    nums = num1 * num2;
                }
                else if (tokens[i] == "/") {
                    nums = num2 / num1;
                } // 为 num2 / num1
                st.push(nums);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

int main()
{
    Solution s;
    vector<string> v1 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    // v1.push_back("2");
    // v1.push_back("1");
    // v1.push_back("+");
    // v1.push_back("3");
    // v1.push_back("*");
    auto result = s.evalRPN(v1);
    cout << result << endl;
}