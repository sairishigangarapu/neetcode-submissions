class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int s1 = prices[0];
        for(int i = 0;i < prices.size() ; i++){
            profit = max(profit , prices[i]-s1);
            s1 = min(prices[i],s1);
        }
        return profit;
    }
};
