class Solution {
public:
    vector<int> possibilities;
    vector<vector<int>> permutations;
    void permutation(vector<int>& nums, vector<int>& visit){
        int l = nums.size();
        if(possibilities.size() == l){
            permutations.push_back(possibilities);
            return;
        }
        for(int i = 0 ; i < l; ++i){
            if((visit[i])||(i > 0 && nums[i] == nums[i-1] && !visit[i-1])){continue;}
            visit[i] = 1;
            possibilities.push_back(nums[i]);
            permutation(nums,visit);
            possibilities.pop_back();
            visit[i] = 0;
            }
    return;
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> visit(nums.size(),0);
        permutation(nums,visit);
        return permutations;
    }
};