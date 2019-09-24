#include<vector>
using namespace std;


// I: buy stock only one time
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len<=1)
        return 0;
    
    int p_min=prices[0], profit = 0;
    for(int i = 1; i<len; i++){
        
        p_min = prices[i]>p_min?p_min:prices[i];
        
        int profit_new = profit;
        
        if(prices[i]>p_min){
            profit_new = prices[i]-p_min;
            profit = profit_new>profit?profit_new:profit; 
        }
    }
    return profit;
}

// II: buy stock as many time as possible
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len<=1)
        return 0;
    
    int p = 0;
    for(int i=1; i<len; i++)
        if(prices[i]>prices[i-1])
            p+=prices[i]-prices[i-1];
    return p;
}


//