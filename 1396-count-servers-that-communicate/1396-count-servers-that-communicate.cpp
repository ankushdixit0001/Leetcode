class Solution {
public:
    int m, n;    
    int countServers(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        // Row and column counters for servers
        vector<int> rowCount(m, 0), colCount(n, 0);
        
        // Calculate row and column server counts
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        int count = 0;
        
        // Now check each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // A server counts if it's in a row or column with more than one server
                if (grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1)) {
                    count++;
                }
            }
        }

        return count;
    }
};