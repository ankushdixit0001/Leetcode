class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &g) {
        int rows = g.size();
        int cols = g[0].size();
        int inf = rows + cols;

        // Initialize the grid: 0 for water, inf for land
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                g[r][c] = g[r][c] == 1 ? 0 : inf;
            }
        }

        // First pass: Top-Left to Bottom-Right
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (g[r][c] == 0)
                    continue; // Skip water cells
                int left = c > 0 ? g[r][c - 1] : inf;
                int top = r > 0 ? g[r - 1][c] : inf;
                g[r][c] = min(g[r][c], min(left, top) + 1);
            }
        }

        // Second pass: Bottom-Right to Top-Left
        for (int r = rows - 1; r >= 0; r--)
        {
            for (int c = cols - 1; c >= 0; c--)
            {
                if (g[r][c] == 0)
                    continue; // Skip water cells
                int right = c < cols - 1 ? g[r][c + 1] : inf;
                int bottom = r < rows - 1 ? g[r + 1][c] : inf;
                g[r][c] = min(g[r][c], min(right, bottom) + 1);
            }
        }

        return g;
    }
};