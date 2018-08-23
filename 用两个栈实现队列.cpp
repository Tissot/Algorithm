//  用两个栈实现队列
//
//  用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Queue {
private:
    stack<int> stack1, stack2;
public:
    void push(int value) {
        stack1.push(value);
    }
    
    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int result = stack2.top();
        stack2.pop();
        return result;
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

void test(bool result, string name) {
    if (result) {
        cout << name << ": 通过测试." << endl;
    } else {
        cout << name << ": 未通过测试." << endl;
    }
}

int main(int argc, char **argv) {
    Queue *q = new Queue();
    vector<int> v;

    //  队列序列
    for (int i = 0; i < 6; ++i) {
        q->push(i);
    }

    for (int i = 0; i < 3; ++i) {
        v.push_back(q->pop());
    }

    for (int i = 6; i < 10; ++i) {
        q->push(i);
    }

    while (!q->empty()) {
        v.push_back(q->pop());
    }

    bool passed = true;
    for (int i = 0; i < 10; ++i) {
        if (i != v[i]) {
            passed = false;
            break;
        }
    }

    test(passed, "队列序列");
}
