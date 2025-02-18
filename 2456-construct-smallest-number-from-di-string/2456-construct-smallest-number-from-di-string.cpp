class Solution {

public:
    string smallestNumber(string pattern) {
        vector<int> visited(pattern.size() + 2);
        string res;
        dfs(pattern, 0, res, visited);

        return res;
    }

    bool dfs(string& pattern, int idx, string& res, vector<int>& visited) {
        if (idx == pattern.size() + 1)
            return true;

        for (int i = 1; i <= pattern.size() + 1; i++) {
            if (visited[i]) continue;

            if (res.empty() || 
                (pattern[idx - 1] == 'I' && i + '0' > res.back()) ||
                (pattern[idx - 1] == 'D' && i + '0' < res.back())) {

                visited[i] = 1;
                res.push_back(i + '0');

                if (dfs(pattern, idx + 1, res, visited)) return true;

                visited[i] = 0;
                res.pop_back();
            }
        }
        return false;
    }
};