class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return 0;

        unordered_map<int, int> productCount;
        int result = 0;

        // Generate all pairs and count their products
        for (int i = 0; i < n - 1; ++i) {
            int a = nums[i];
            for (int j = i + 1; j < n; ++j) {
                int b = nums[j];
                int product = a * b;
                ++productCount[product];
            }
        }

        // Calculate the number of tuples based on product frequencies
        for (const auto& [product, count] : productCount) {
            if (count > 1) {
                // Number of ways to choose 2 pairs from 'count' pairs
                int combinations = count * (count - 1) / 2;
                // Each combination can be arranged in 8 different ways
                result += combinations * 8;
            }
        }

        return result;
    }
};