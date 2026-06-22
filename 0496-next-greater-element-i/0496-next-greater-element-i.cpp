class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int top = -1;
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int>  nge;
        for(int i = m - 1 ; i >= 0; --i){
            while((!st.empty()) && st.top() <= nums2[i] ){
                st.pop();
            }
            if(!st.empty()) nge[nums2[i]] = st.top();
            else nge[nums2[i]] = -1;
            st.push(nums2[i]);
        }
        vector<int> result;
        for(int i = 0 ; i < n ; ++i){
            result.push_back(nge[nums1[i]]);
        }
        return result;
    }
};