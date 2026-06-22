class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int j = 0;
        for(auto it = piles.begin(); it != piles.end(); ++it){
            if(j < *it) j = *it;
        }
        int i = 1;
        int mid = (i + (j - i)/2);
        int n;
        while(i < j){
            n = 0;
            for(auto it = piles.begin(); it != piles.end(); ++it){
                n += ((*it+(mid-1))/mid);
            }
            if(n <= h) j = mid;
            else i = mid + 1;
            mid = (i + (j - i )/2);
        }
        return mid;
    }
};