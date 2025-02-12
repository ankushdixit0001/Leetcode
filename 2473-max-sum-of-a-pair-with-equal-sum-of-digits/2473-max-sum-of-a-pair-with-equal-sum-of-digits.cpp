class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        map<int,pair<int,int>> mp;  // sum of digits -> {max number, sum of 2 numbers}
        int ans = -1;
        for(int i=0; i<n; i++){
            string temp = to_string(nums[i]);
            int sum = 0;
            for(char c: temp){
                sum += c - '0';
            }

            mp[sum] = {max(nums[i], mp[sum].first), nums[i] + mp[sum].first};
            if(mp[sum].second != nums[i]){
                ans = max(ans, mp[sum].second);
            }
        }

        return ans;
    }
};