class Solution {
public:
    void subsetSol(vector<vector<int>>& allsubset,vector<int>& nums, int count , vector<int>& subsets ){
        allsubset.push_back(subsets);
        for(int i = count ; i < nums.size(); ++i){
            if(i > count && nums[i] == nums[i - 1]) continue;
            subsets.push_back(nums[i]);
            subsetSol(allsubset , nums , i + 1 , subsets);
            subsets.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allsubset;
        allsubset.reserve(1 << nums.size());
        vector<int> subsets = {};
        int count = 0;
        sort(nums.begin(), nums.end());
        subsetSol(allsubset , nums , count , subsets);
        return allsubset;
    }
};