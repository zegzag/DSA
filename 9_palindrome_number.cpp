#include<math>

bool isPalindrome_my(int x) {
    if (x<0){
        return false;
    }
    if (x>=0 && x< 10)
        return true;
    
    int  hex  = 10, len = 1;
    while(x/hex>=10) {
        hex *= 10;
        len++;
    }
    len++;
    while(len > 0){
        int hex_l = pow(10, len - 1);
        int left =  x / hex_l;
        int right = x % 10;
        if (left !=  right) {
            return false;
        }
        x = (x - left*hex_l- right)/10;
        len = len -2;
    }
    return true;
}

bool isPalindrome_opt(int x) {
// ���������
// ������������ x < 0 ʱ��x ���ǻ�������
// ͬ���أ�������ֵ����һλ�� 0��Ϊ��ʹ������Ϊ���ģ�
// �����һλ����ҲӦ���� 0
// ֻ�� 0 ������һ����
if (x < 0 || (x % 10 == 0 && x != 0)) {
    return false;
}

int revertedNumber = 0;
while (x > revertedNumber) {
    revertedNumber = revertedNumber * 10 + x % 10;
    x /= 10;
}

// �����ֳ���Ϊ����ʱ�����ǿ���ͨ�� revertedNumber/10 ȥ��������λ�����֡�
// ���磬������Ϊ 12321 ʱ���� while ѭ����ĩβ���ǿ��Եõ� x = 12��revertedNumber = 123��
// ���ڴ�����λ�����ֲ�Ӱ����ģ����������Լ���ȣ����������ǿ��Լ򵥵ؽ���ȥ����
return x == revertedNumber || x == revertedNumber / 10;
}