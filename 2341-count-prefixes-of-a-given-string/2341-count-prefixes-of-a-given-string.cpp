// class Solution {
// private:
//     bool isPrefix(string &s1, string &s2) {
//         int m = s1.size();
//         int n = s2.size();
//         if (m > n) return false;
//         for (int i = 0; i < m; i++) {
//             if (s1[i] != s2[i]) {
//                 return false;
//             }
//         }
//         return true;
//     }

// public:
//     int countPrefixes(vector<string>& words, string s) {
//         int count = 0;
//         for (int i = 0; i < words.size(); i++) {
//             if (isPrefix(words[i], s)) {
//                 count++;
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for (const auto& word : words) {
            if (s.find(word) == 0) {  // Check if pref is a prefix of word
                count++;
            }
        }
        return count;
    }
};
