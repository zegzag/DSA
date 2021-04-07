#include<cstdio>
using namespace std;
int climbStairs(int n){
    if(n == 0)
        return 0;
    int p = 1, q = 1;
    for(int i = 0; i< n; i++){
        q = p +1;
        p = q - p;
    }
    return q;
}