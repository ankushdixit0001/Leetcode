class Solution {

    unordered_map<int, int> solve(const vector<vector<int>>& G, const int bob) {
        const int N = G.size();
        vector<int> par(N, -1);
        vector<int> depth(N, 0);

        vector<int> stack;
        stack.emplace_back(bob);

        while (stack.size()) {
            const int node = stack.back();
            stack.pop_back();

            if (node == 0) {
                break; // early termination
            }

            for (const int n : G[node]) {
                if (n != par[node]) {
                    stack.emplace_back(n);
                    par[n] = node;
                    depth[n] = depth[node] + 1;
                }
            }
        }

        unordered_map<int, int> ret;
        for (int cur = 0, size; cur != -1; cur = par[cur]) {
            ret[cur] = depth[cur];
        }

        return ret;
        /*
        unordered_map<int, int> ret;
        const int SZ = path.size();

        for (int i = 0; i < SZ; ++i) {
            ret[path[i]] = SZ - i - 1;
        }
        */
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, const int bob, vector<int>& amount) {
        vector<vector<int>> graph;

        // create graph
        for (const auto& v : edges) {
            const int sz = max(v[0], v[1]);
            if (graph.size() <= sz) {
                graph.resize(sz + 1);
            }
            graph[v[0]].emplace_back(v[1]);
            graph[v[1]].emplace_back(v[0]);
        }

        // find bobs path to 0, with depth
        unordered_map<int, int> depths = solve(graph, bob);
        const int N = graph.size();
        int max_profit = INT32_MIN;

        vector<tuple<int, int, int, int>> stack;

        stack.emplace_back(0, -1, 0, 0);

        while (!stack.empty()) {
            const auto [node, par, val, depth] = stack.back();
            stack.pop_back();

            int new_val = val;
            if (depths.count(node)) {
                if (depths[node] == depth) {
                    new_val += amount[node] / 2; // reached at same time as bob
                }
                else if (depth < depths[node]) {
                    new_val += amount[node]; // got there before bob
                }
                // else do nothing, path already paid for
            }
            else {
                new_val += amount[node]; // not on bobs path so must pay
            }

            // leaf so see if this is an optimal path
            if (graph[node].size() == 1 && node != 0) {
                max_profit = max(max_profit, new_val);
                // cout << format("leaf: {} --- val: {}", node, new_val) << endl;
            }

            for (const auto n : graph[node]) {
                if (n != par) {
                    stack.emplace_back(n, node, new_val, depth + 1);
                }
            }
        }

        return max_profit;
    }
};