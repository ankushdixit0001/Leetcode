class Solution {
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& qre) {
        vector<vector<int>> adj(num);
        vector<int> indegree(num);

        for(auto a : pre)
       { adj[a[0]].push_back(a[1]);
         indegree[a[1]]++;
       }
       queue<int> q;
       unordered_map<int,unordered_set<int>> nodepre;

       for(int i=0;i<num;i++)
       if(!indegree[i])
       q.push(i);

       while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto child : adj[node]){
            nodepre[child].insert(node);
            for(auto prereq : nodepre[node])
            {
                 nodepre[child].insert(prereq);
            }
            indegree[child]--;
            if(indegree[child]==0)
            q.push(child);
        }

       }
        
        vector<bool> ans;
        for (auto& query : qre) {
           int src = query[0], dest = query[1];
           ans.push_back(nodepre[dest].contains(src));    
        }

        return ans;
    }
};