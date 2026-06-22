class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1 = cost[0];
        int prev2 = cost[1];
        int n = cost.size();
        for(int i = 2; i < n ; ++i){
            int current = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = current;
        }
        return min(prev1 , prev2);
    }
};