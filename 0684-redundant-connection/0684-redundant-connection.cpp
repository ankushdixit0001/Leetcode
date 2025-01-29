class Solution {
public:
    int findParent(int child, vector<int> &parent){
        if(child == parent[child]) return child;

        return parent[child] = findParent(parent[child], parent);
    } 

    bool join(int u, int v, vector<int> &parent, vector<int> &size){
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if(pu == pv) return true;

        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }

        return false;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0), size(n+1, 1);
        
        for(int i=0; i<=n; i++) parent[i] = i;

        vector<int> ret;

        for(auto e: edges)
            if(join(e[0], e[1], parent, size)) 
                ret = e;

        return ret;
    }
};