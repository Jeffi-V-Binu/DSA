class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int l = 0;
        int h = n;
        int mid = (m+n+1)/2;
        int l1;
        int l2;
        while(l <= h){
            l1 = l + (((h+1)-l)/2);
            if(l1 > mid) l1 = mid; // keeps mid as the upper bound of l1
            if((l1+m) < mid) l1 += (mid - (l1+m));// to avoid l2 from getting negative values
            l2 = mid - l1;
            int p1 = (l1 == 0) ? INT_MIN : nums1[l1 - 1];
            int q1 = (l1 == n) ? INT_MAX : nums1[l1];
            int p2 = (l2 == 0) ? INT_MIN : nums2[l2 - 1];
            int q2 = (l2 == m) ? INT_MAX : nums2[l2];
            if(p1 <= q2 && p2 <= q1){
                if((m+n)%2 == 0) return ( max(p1,p2)+( min(q1,q2) - max(p1,p2) )/2.0 );
                else return max(p1,p2)/1.0;
            }
            else if(p1 > q2) h = l1 - 1;
            else l = l1 + 1;
        }
        return 0.0;
    }
};