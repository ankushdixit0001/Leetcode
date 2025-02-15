class Solution {
private:
    bool solve(string s, int val, int index = 0, int sum = 0) {
        if (index == s.length()) {
            return sum == val;
        }

        int num = 0;
        for (int i = index; i < s.length(); i++) {
            num = num * 10 + (s[i] - '0');

            if (num > val)
                break;

            if (solve(s, val, i + 1, sum + num)) {
                return true;
            }
        }

        return false;
    }

public:
    int punishmentNumber(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int temp = i * i;
            if (solve(to_string(temp), i))
                ans += temp;
        }
        return ans;
    }
};