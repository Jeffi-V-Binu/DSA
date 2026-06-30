class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 3) return 0;
        int lmax = height[0];
        int rmax = height[n - 1];
        int result = 0;
        int l = 0 ;
        int r = n - 1;
        while(l < r){
            lmax = max(lmax , height[l]);
            rmax = max(rmax , height[r]);
            if(height[l] <= height[r]){
                int maxw = lmax - height[l];
                if(maxw > 0){
                    result += maxw;
                }
                ++l;
            }            
            else{
                int maxw = rmax - height[r];
                if(maxw > 0){
                    result += maxw;
                }
                --r;
            }
        }
        return result;
    }
};