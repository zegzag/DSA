#include<queue>
using namespace std;

/*�����ܽ��ڶ������ݽṹ�£���ջ�����в������ڳ���ʱ���ڡ�
  *�������һ��O(n)�Ĳ������򵹹���*/
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        return;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int len = q.size();
        while(--len) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto result = q.front();
        q.pop();
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};