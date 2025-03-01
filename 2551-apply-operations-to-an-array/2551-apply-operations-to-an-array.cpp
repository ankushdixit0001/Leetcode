class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int nonZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i < nums.size() - 1 && nums[i] != 0 && nums[i] == nums[i + 1]) {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
            if (nums[i] != 0) {
                if (i != nonZero) {
                    swap(nums[i], nums[nonZero]);
                }
                nonZero++;
            }
        }
        return nums;
    }
};