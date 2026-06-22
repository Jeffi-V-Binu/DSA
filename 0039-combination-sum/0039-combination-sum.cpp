class Solution {
public:
    void subsetSol(vector<vector<int>>& allsubset,vector<int>& candidates, int count , vector<int>& subsets , int & target , int sum){
        if(sum > target) return;
        if(sum == target){
        allsubset.push_back(subsets);
        return ;}
        for(int i = count ; i < candidates.size(); ++i){
            sum += candidates[i];
            subsets.push_back(candidates[i]);
            subsetSol(allsubset , candidates , i  , subsets , target , sum);
            subsets.pop_back();
            sum -= candidates[i];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> allsubset;
        vector<int> subsets = {};
        int count = 0;
        int sum = 0;
        subsetSol(allsubset , candidates , count , subsets , target, sum);
        return allsubset;
    }
};