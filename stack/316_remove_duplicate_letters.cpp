#include<string>
#include<stack>
#include<deque>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*���㣺
  * 1. �ֵ�����С˵���ˣ������ұ����������ǰԪ��С��ǰһ��Ԫ�أ���ô�Ϳ���ɾ��ǰһ��Ԫ�ء�
  *      ������ʹ��̰���㷨��
  *  2. ɾ��Ԫ�غ���֮�󻹿��ܳ�����Ӧ��Ԫ�أ���ʱ����Ҫһ��set����Ǹ�Ԫ���Ƿ���ֹ���
  *  3. ע��set��whileѭ���е�λ�ã�while����Ĳ����Լ�while���ж�������
  */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        for (auto& c: s) {
            if (count.count(c)) {
                ++count[c];
            } else {
                count[c]=1;
            }
        }
        deque<char> S;
        unordered_set<char> set;
        for (auto& c : s) {
            if (!set.count(c)) { 
                while(!S.empty() && c < S.back() && count[S.back()] > 0) {
                    set.erase(S.back());
                    S.pop_back();
                }
                set.emplace(c);
                S.push_back(c);
            } // if set ��֤�˽���ջ��Ԫ�رض�Ϊ1��
            --count[c]; // ��������Ѿ���set���ˣ��Ϳ���ֱ������������--
        }
        string ans = "";
        while(!S.empty()) {
            ans += S.front();
            S.pop_front();
        }
        return ans;
    }
};