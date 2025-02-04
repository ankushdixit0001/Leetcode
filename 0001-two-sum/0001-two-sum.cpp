class Solution {
public:
    static bool compare(pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int, int>> helper(n, make_pair(0, 0));
        for (int i = 0; i < n; i++) {
            helper[i] = make_pair(i, nums[i]);
        }
        sort(helper.begin(), helper.end(), compare);

        int start = 0, end = n - 1;
        while (start < end) {
            int sum = helper[start].second + helper[end].second;
            if (sum == target)
                return {helper[start].first, helper[end].first};
            else if (sum > target)
                end--;
            else
                start++;
        }
        return {};
    }
};