class Solution {
public:
    int trapRainWater(vector<vector<int>>& hm) {
        int m = hm.size();
        int n = hm[0].size();
        vector<vector<int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
        priority_queue<vector<int>,vector<vector<int>>,greater<>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0;i<m;i++) {
            for(int j : {0,n-1}) {
                q.push({hm[i][j],i,j});
                vis[i][j] = 1;
            }
        }
        for(int j = 0;j<n;j++) {
            for(int i : {0,m-1}) {
                if(!vis[i][j]) {
                    q.push({hm[i][j],i,j});
                    vis[i][j] = 1;
                }
            }
        }
        long long int tw = 0;
        while(!q.empty()) {
            auto it = q.top();
            int ch = it[0];
            int cr = it[1];
            int cc = it[2];
            q.pop();
            
            for(auto &d : dir) {
                int nr = cr + d[0];
                int nc = cc + d[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = 1;

                    if(hm[nr][nc] < ch) {
                        tw += ch-hm[nr][nc];
                    }

                    q.push({max(ch, hm[nr][nc]), nr, nc});
                }
            }

        }
        return tw;
    }
};