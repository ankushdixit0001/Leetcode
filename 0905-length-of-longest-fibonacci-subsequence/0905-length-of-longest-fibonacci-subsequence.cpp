class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int len = 0;
        set<int> a(arr.begin(), arr.end()); //extra memory used
        for (int i = 0; i < arr.size() - 2; i++) {
            for (int j = i + 1; j < arr.size() - 1; j++) {
                int x = arr[i];
                int y = arr[j];
                int c = 2; 
                while (a.find(x + y) != a.end()) { // finding the current as well as the upcoming elements based on ith and jth element of the array.
                    int z = x + y;
                    x = y;
                    y = z;
                    c++;
                }
                len = max(len, c); // finding the max value
            }
        }
        if(len>2){   // the length will be directly 2 because 2 is the base condition for the fb series, we start finding directly from the 3rd element so either the answer is 0 or 3 and greater.
            return len;
        } 
        else return 0;
    }
};
