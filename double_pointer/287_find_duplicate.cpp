#include <vector>
using namespace std;

//�����ô̫����
//����ָ��
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        for (int fast = 0; res != fast || fast == 0;){
            res = nums[res];
            fast = nums[nums[fast]];
        } //�ҵ����е�ĳ��λ��
        for (int i = 0; res != i; i = nums[i]){
            res = nums[res];
        } //�ҵ��������λ�ã�������ڴ�һ������0�����Դ�0��ʼ���еڶ��α�����
        //�ڶ��α������Ա�֤һ���ڻ�����ڴ�ͣ�£�������ô����ѧ��֤���أ�
        return res;
    }

    //���ֲ��ң�
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        for (int fast = 0; res != fast || fast == 0;){
            res = nums[res];
            fast = nums[nums[fast]];
        } //�ҵ����е�ĳ��λ��
        for (int i = 0; res != i; i = nums[i]){
            res = nums[res];
        } //�ҵ��������λ�ã�������ڴ�һ������0�����Դ�0��ʼ���еڶ��α�����
        //�ڶ��α������Ա�֤һ���ڻ�����ڴ�ͣ�£�������ô����ѧ��֤���أ�
        return res;
    }
};