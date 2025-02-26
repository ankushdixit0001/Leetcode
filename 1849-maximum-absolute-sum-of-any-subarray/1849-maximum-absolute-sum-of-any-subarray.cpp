class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = 0, min_sum = 0;
        int current_max = 0, current_min = 0;

        for (int num : nums) {
            current_max = max(0, current_max + num);
            current_min = min(0, current_min + num);

            max_sum = max(max_sum, current_max);
            min_sum = min(min_sum, current_min);
        }

        return max(max_sum, abs(min_sum));
    }
    };