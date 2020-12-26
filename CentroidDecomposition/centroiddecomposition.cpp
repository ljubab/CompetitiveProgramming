const int mxN = 2e5;

struct CentroidDecomposition {
    set<int> adj[mxN];
    int sz[mxN];

    void addEdge(int a, int b) {
        adj[a].insert(b);
        adj[b].insert(a);
    }

    int dfs(int s, int p = -1) {
        sz[s] = 1;
        for(auto e : adj[s]) {
            if(e == p)
                continue;
            dfs(e, s);
            sz[s] += sz[e];
        }
        return sz[s];
    }

    int centroid(int s, int p, int n) {
        for(auto e : adj[s]) {
            if(sz[e] > n/2)
                return centroid(e, s, n);
        }
        return s;
    }

    void build(int s) {
        int n = dfs(s);
        int c = centroid(s, -1, n);

        vi tmp(all(adj[c]));

        for(auto z : tmp) {
            adj[c].erase(z);
            adj[z].erase(c);
            build(z);
        }
    }
};
