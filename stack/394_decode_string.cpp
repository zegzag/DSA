#include<string>
#include<stack>
using namespace std;

/*两点：
  * 1. 栈并不一定要保存基本元素
  * 2. 在循环时一定要搞清当前的状态和出栈的状态。
  */
  
class Solution {
public:
    using strtime=pair<string, int>;
    string decodeString(string s) {
        string res = "";
        int time  =  0;
        stack<strtime> S;
        for (const auto& c : s){
            if (c >= '0' && c <='9') {
                time = time*10 + static_cast<int>(c-'0');
            } else if (c == '[') {
                S.emplace(strtime(res, time));
                res="";
                time = 0;
            } else if (c == ']') {
                auto st = S.top();
                S.pop();
                res = st.first + multi_string(res, st.second);
            } else {
                res+=c;
            }
        }
        return res;
    }

    string multi_string(string& s, int times) {
        string res = "";
        for (int i = 0; i < times; i++) {
            res += s;
        }
        return res;
    }
};