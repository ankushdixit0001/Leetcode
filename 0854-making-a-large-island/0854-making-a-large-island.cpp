class Solution {
public:
    int helper(vector<vector<int>> &grid, int i, int j, vector<vector<int*>> &v, int* x) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || v[i][j] != nullptr || grid[i][j] == 0) {
            return 0;
        }

        v[i][j] = x;  // Assign the pointer to the current cell

        // Recursively calculate the size of the island
        int ans = 1;
        ans += helper(grid, i + 1, j, v, x);
        ans += helper(grid, i - 1, j, v, x);
        ans += helper(grid, i, j + 1, v, x);
        ans += helper(grid, i, j - 1, v, x);
        return ans;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int*>> v(n, vector<int*>(n, nullptr));  // Initialize a 2D vector of pointers
        
        // Store dynamically allocated sizes for cleanup later
        vector<int*> sizes;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && v[i][j] == nullptr) {
                    int* x = new int(0);  // Dynamically allocate memory for island size
                    sizes.push_back(x);   // Store pointer for cleanup
                    int weight = helper(grid, i, j, v, x);
                    *x = weight;          // Update the size of the island
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {  // Check if flipping this 0 can create a larger island
                    unordered_set<int*> st;
                    if (i - 1 >= 0 && v[i - 1][j] != nullptr) st.insert(v[i - 1][j]);
                    if (i + 1 < n && v[i + 1][j] != nullptr) st.insert(v[i + 1][j]);
                    if (j - 1 >= 0 && v[i][j - 1] != nullptr) st.insert(v[i][j - 1]);
                    if (j + 1 < n && v[i][j + 1] != nullptr) st.insert(v[i][j + 1]);

                    int x = 1;  // Flipping this cell contributes 1
                    for (auto it : st) {
                        x += *it;  // Add sizes of neighboring islands
                    }
                    ans = max(ans, x);
                }
            }
        }

        // Cleanup dynamically allocated memory
        for (int* size : sizes) {
            delete size;
        }

        if (ans == 0) return n * n;  // If the grid is already filled with 1s
        return ans;
    }
};