class Solution {
    private:
    bool iseven(int num){
        int digicount=0;
        while(num>0){
            num=num/10;
            digicount++;
        }
        return digicount%2==0;
    }
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int num:nums){
            if(num!=0 && iseven(num)){
                count++;
            }
        }
        return count;
    }
};