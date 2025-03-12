class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg,pos;
        for(auto i : nums){
            if(i<0) neg++;
            else if(i>0) pos++;
        }
        return max(neg,pos);
    }
};