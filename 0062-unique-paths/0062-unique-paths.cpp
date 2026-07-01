class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>pathsdp(n , 1);
        for(int i = 1 ; i < m ; ++i){
            for(int j = 1 ; j < n ; ++j){
                pathsdp[j] = pathsdp[j] + pathsdp[j - 1];
            }
        }
        return pathsdp[n - 1];
    }
};