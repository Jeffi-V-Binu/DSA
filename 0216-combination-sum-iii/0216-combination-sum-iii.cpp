class Solution {
public:
    void comb(vector<vector<int>>& result,vector<int>& subresult , int& k , int & n , int num , int count , int sum ){
        if(count > k) return;
        if(sum > n) return ;
        if(sum == n && count == k){
            result.push_back(subresult);
            return;
        }
        for(int i = num ; i <= 9 ; ++i ){
            subresult.push_back(i);
            comb(result , subresult , k , n , i + 1 ,count + 1 , sum + i);
            subresult.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> subresult;
        comb(result , subresult ,k , n , 1, 0 , 0);
        return result;
    }
};