class Solution {
//     private:
//     bool isPrefix(string &s1,string &s2){
//         int m=s1.size();
//         int n=s2.size();
//         if(m>n) return false;
//         for(int i=0;i<m;i++){
//             if(s1[i]!=s2[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
// public:
//     int prefixCount(vector<string>& words, string pref) {
//         int count=0;
//         for(int i=0;i<words.size();i++){
//             if(isPrefix(pref,words[i])){
//                 count++;
//             }
//         }
//         return count;
//     }

public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (const auto& word : words) {
            if (word.find(pref) == 0) {  
                count++;
            }
        }
        return count;
    }
};