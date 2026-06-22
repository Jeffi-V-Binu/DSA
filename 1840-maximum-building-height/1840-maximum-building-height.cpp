class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1 , 0});
        int m = restrictions.size();
        restrictions.push_back({n , n - 1});    
        sort(restrictions.begin() , restrictions.end(),[](const vector<int>& a, const vector<int>& b) { return a[0] < b[0];});
    
        for(int i = 1 ; i <= m ; ++i){
            auto& a = restrictions[i];
            auto& b = restrictions[i - 1];
            a[1] = min(a[1] , b[1] + (a[0] - b[0]) );
        }
        for(int i = m - 1 ; i >= 0 ; --i){
            auto& a = restrictions[i];
            auto& b = restrictions[i + 1];
            a[1] = min(a[1] , b[1] + (b[0] - a[0]) );
        }
        int max_h = 0;
        for(int i = 0 ; i < m ; ++i){
            const auto& a = restrictions[i];
            const auto& b = restrictions[i + 1];
            int height = (a[1] + b[1] + (b[0] - a[0])) / 2 ;
            max_h = max(max_h , height);
        }
        return max_h;
    }
};