#include <iostream>
#include <queue>

using namespace std;

// 用一个队列也可以实现
class myStack {
public:
    queue<int> que1;
    queue<int> que2;
    void push(int x)
    {
        que1.push(x);
    }

    int pop()
    {
        while (que1.size() != 1) {
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que1.pop();
        while (!que2.empty()) {
            que1.push(que2.front());
            que2.pop();
        }
        return result;
    }

    int top()
    {
        // while (que1.size() != 1) {
        //     que2.push(que1.front());
        //     que1.pop();
        // }
        // int result = que1.front();
        // return result;
        // 可以之间取 back
        return que1.back();
    }

    bool empty()
    {
        return que1.empty();
    }
};
