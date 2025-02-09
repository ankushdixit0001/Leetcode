class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n= nums.size();
        long long cnt= 0;
        unordered_map<long long, long long> map;
        for(int i=0; i<n; i++) {
            nums[i]-=i;
            map[nums[i]]++;
        }
        for(auto it: map) {
            if(it.second<2) continue;
            cnt+= ((it.second)*(it.second-1))/2;
        }
        return ((n)*(n-1))/2 - cnt;
    }
};