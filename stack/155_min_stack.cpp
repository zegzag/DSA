#include<stack>
#include<limits.h>
using namespace std;

/*�ؼ��㸨��ջ��֤��ջ�ڲ�����Сֵһֱ��top()λ��*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        s2.push(INT_MAX);
        return;
    }
    
    void push(int x) {
        s1.push(x);
        if (x < s2.top()) {
            s2.push(x);
        } else {
            s2.push(s2.top());
        }
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};