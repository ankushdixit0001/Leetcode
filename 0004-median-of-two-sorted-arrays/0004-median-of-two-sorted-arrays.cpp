class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>vec;
        vec=nums1;
        double ans;
        for(int i=0;i<nums2.size();i++){
            vec.push_back(nums2[i]);
            }
        sort(vec.begin(),vec.end());
        int n=vec.size();
        if(n%2==0){
            ans=(vec[n/2]+vec[n/2-1])/2.0;
            }
        else ans=vec[n/2];
        return ans;
    }
};