class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd_count = 0, even_count = 1, xor_sum = 0, result = 0;

        for (int a : arr) {
            xor_sum ^= a;
            if (xor_sum % 2 == 0) {
                result = (result + odd_count) % MOD;
                even_count++;
            } else {
                result = (result + even_count) % MOD;
                odd_count++;
            }
        }
        return result;
    }
};