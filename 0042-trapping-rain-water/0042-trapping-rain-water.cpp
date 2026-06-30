class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> water(n , 0);
        int maxh = 0;
        int result = 0;
        for(int i = 0 ; i < n ; ++i){
            water[i] = maxh;
            maxh = max(height[i] , maxh);
        }
        maxh = 0;
        for(int i = n - 1 ; i >= 0 ; --i){
            int h = min(maxh , water[i]);
            if(h > height[i]){
                water[i] = h - height[i];
            }
            else{
                water[i] = 0;
            }
            maxh = max(maxh , height[i]);
        }
        for(int i = 0 ; i < n ; ++i){
            result += water[i];
        }
        return result;
    }
};