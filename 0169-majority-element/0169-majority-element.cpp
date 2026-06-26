class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = INT_MIN;
        int count = 0;
        for(const int& i : nums){
            if(i == num) ++count;
            else if(!count){
                ++count;
                num = i;
            }
            else --count;
        }
        return num;
    }
};