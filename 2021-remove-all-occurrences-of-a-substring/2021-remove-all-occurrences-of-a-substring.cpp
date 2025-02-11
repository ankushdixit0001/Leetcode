class Solution {
public:
bool check(stack<char> st,string &part,int m){
    stack<char> newst=st;

    for(int i=m-1;i>=0;i--){
        if(newst.top()!=part[i]){
            return false;
        }
        newst.pop();
    }
    return true;
}
    string removeOccurrences(string s, string part) {

        int n=s.length();
        int m=part.length();

        stack<char> st;
        for(int i=0;i<n;i++){
            st.push(s[i]);

            if(st.size()>=m && check(st,part,m)==true){
                for(int j=0;j<m;j++){
                    st.pop();
                }
            }
                            
        }
    string result="";
        while(!st.empty()){

            result+=st.top();
            st.pop();
            
        }

        reverse(result.begin(),result.end());
        return result;
    }
};