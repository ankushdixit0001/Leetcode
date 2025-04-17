class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count=0;
        for(const int &num:nums){
            if(mp[num-k]) count+=mp[num-k];
            if(mp[num+k]) count+=mp[num+k];
            mp[num]++;
        }
        return count;
    }
};