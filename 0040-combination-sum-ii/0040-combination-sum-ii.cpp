class Solution {
public:
    void comb(vector<vector<int>>& result ,vector<int>& subresult, int  sum , int & target , int count , vector<int> & candidates){
        if(sum > target) return ;
        if(sum == target){
            result.push_back(subresult);
            return;
        }
        for(int i = count  ; i < candidates.size() ; ++i){
            if(i > count  && candidates[i] == candidates[ i - 1]) continue;
            if(sum + candidates[i] > target) break;
            subresult.push_back(candidates[i]);
            comb(result , subresult, sum + candidates[i] , target , i + 1, candidates);
            subresult.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>> result;
       vector<int> subresult = {};
       int sum = 0 ; 
       int count = 0;
       sort(candidates.begin(), candidates.end());
       comb(result , subresult, sum , target , count , candidates);
       return result;
    }
};