class Solution {
public:
    int countPairs(const vector<int>& nums, int k) {
        unordered_map<int, vector<int>> indexMap;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (indexMap.find(num) != indexMap.end()) {
                for (int j : indexMap[num]) {
                    if ((i * j) % k == 0) {
                        count++;
                    }
                }
            }
            indexMap[num].push_back(i);
        }
        
        return count;

    }
};