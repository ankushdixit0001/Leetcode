class Solution {
public:
    string getHappyString(int n, int k) {
        int i=0,v=3*pow(2,n-1);
        if(k>v) return "";
        
        string s="";
        v=v/3;
        if(k<=v) s+="a";
        else if(k<=2*v) s+="b"; 
        else s+="c";
        k=k%v;
        if(k==0) k=v;

        while(--n>0){
            v=v/2;
            char ch=s[i++];
            switch(ch){
                case 'a':
                    if(k<=v) s+='b';
                    else s+="c";
                    break;
                case 'b':
                    if(k<=v) s+='a';
                    else s+="c";
                    break;
                case 'c':
                    if(k<=v) s+='a';
                    else s+="b";
                    break;
            }
            k=k%v;
            if(k==0) k=v;
        }

        return s;
    }
};