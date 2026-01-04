class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int count=0;
            for(int fact=1;fact<=sqrt(nums[i]);fact++){
                if(nums[i]%fact==0){
                    int factSecond=nums[i]/fact;
                    if(factSecond==fact){
                        sum+=fact;
                        count++;
                    }else{
                        sum=sum+fact+factSecond;
                        count+=2;
                    }
                }
                if(count>4){
                    break;
                }
            }
            if(count==4){
                result+=sum;
            }
        }
        return result;
    }
};