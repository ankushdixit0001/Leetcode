class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int result=sum;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                sum+=nums[i];
            }
            else{
                result=max(result,sum);
                sum=nums[i];
            } 
        }
        result=max(sum,result);
        return result;
    }
};