class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count=0;
        int minimum=INT_MAX;
        long long result=0;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                result+=abs(matrix[i][j]);
                if(matrix[i][j]<0) count++;
                minimum=min(minimum,abs(matrix[i][j]));
            }
        }
        cout<<result<<"  "<<minimum<<endl;
        if(count%2!=0){
            result-=2*minimum;
        }
        return result;
    }
};