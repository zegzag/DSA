int numTrees(int n) {
    if(n==0)
        return 0 ;
    int *num = new int[n+1];
    num[0] = 0;
    num[1] = 1;
    for(int i = 2; i<n+1; i++){
        num[i] = 0;
        for(int j = 0; j<i; j++){
            if(num[j] == 0)
                num[i] += num[i-j-1];
            else if(num[i-j-1]==0)
                num[i]+=num[j];
            else
                num[i] += num[j]*num[i-j-1];
        }
    }
    return num[n];
}