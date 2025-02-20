class Solution {
public:
bool solve(int ind,int n,unordered_map<string,bool>&m,string &temp,string &result){
    if(ind ==n){
        if(m.find(temp)==m.end()){
            result = temp;
            return true;
        }
        return false;
    }
    for(char ch='0';ch<='1';ch++){
        temp.push_back(ch);
        if(solve(ind+1,n,m,temp,result)){
            return true;
        }
        temp.pop_back();
    }
    return false;
}
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,bool>m;
        int n = nums.size();
        for(auto s :nums){
            m[s] = true;
        }
        string temp="",result="";
        solve(0,n,m,temp,result);
        return result;
    }
};