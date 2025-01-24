class Solution {
public:
    bool isCyclic(int node, vector<int>& visited, vector<int>& inPath, vector<int>& safe, vector<vector<int>>& graph) {
        visited[node] = 1;
        inPath[node] = 1;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (isCyclic(neighbor, visited, inPath, safe, graph)) {
                    return true;
                }
            } else if (inPath[neighbor] == 1) {
                return true;
            }
        }
        safe[node] = 1;
        inPath[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0), inPath(n, 0), safe(n, 0), result;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                isCyclic(i, visited, inPath, safe, graph);
            }
        }
        for (int i = 0; i < n; i++) {
            if (safe[i] == 1) {
                result.push_back(i);
            }
        }
        return result;
    }
};