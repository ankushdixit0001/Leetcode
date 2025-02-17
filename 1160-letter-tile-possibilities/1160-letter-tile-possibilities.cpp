class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> cnt;
        for (char c : tiles) {
            cnt[c]++;
        }
        int ret = 0;
        stack<pair<char, int>> stk;
        stk.push({'A', -1});
        while (!stk.empty()) {
            auto [c, dx] = stk.top();
            stk.pop();
            if (c > 'Z') {
                continue;
            }
            if (dx == 1) {
                cnt[c]++;
            } else {
                stk.push({c + 1, -1});
                if (cnt[c] > 0) {
                    cnt[c]--;
                    ret++;
                    stk.push({c, 1});
                    stk.push({'A', -1});
                }
            }
        }
        return ret;
    }
};