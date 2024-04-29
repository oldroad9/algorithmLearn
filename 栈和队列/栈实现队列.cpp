#include <iostream>
#include <stack>

using namespace std;
class Myqueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    Myqueue() {}
    void push(int x) { stIn.push(x); }

    int pop()
    {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stIn.top();
        stIn.pop();
        return result;
    }

    int peek()
    {
        int res = this->pop();
        stOut.push(res);
        return res;
    }

    bool empty()
    {
        if (stOut.empty() && stIn.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() { return 0; }