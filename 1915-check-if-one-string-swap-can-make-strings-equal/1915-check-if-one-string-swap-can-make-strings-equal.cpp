class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;

        vector<int> index;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                index.push_back(i);
            }
        }
        if (index.size() == 2) {
            swap(s1[index[0]], s1[index[1]]);
            return s1 == s2;
        }

        return false;
    }
};