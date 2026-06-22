class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       vector <int> ans(2);
       int len = grid.size();
       int mlen = len*len;
       vector<int> nums(mlen, 0);
       for(int i = 0 ; i < len ; ++i){
            for(int j = 0; j < len ; ++j){
                nums[grid[i][j]-1]++;
            }
       }
       for(int g = 0 ; g < mlen ; ++g){
            if(nums[g] == 2){
                ans[0] = g+1;
            }
            else if(nums[g] == 0){
                ans[1] = g+1;
            }
       }
       return ans; 
    }
};