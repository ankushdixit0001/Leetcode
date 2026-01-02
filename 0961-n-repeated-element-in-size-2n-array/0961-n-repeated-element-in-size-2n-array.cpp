class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int s=nums.size();
        unordered_map<int,int> freq;

        for(int i=0;i<s;i++){
            freq[nums[i]]++;
        }

        int ans=-1;
        for(auto &num:freq ){
            if(num.second==s/2){
                return num.first;
            }
        }
        return -1;
    }
};