class DisjointSet{
    vector<int> rank, par, size;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        par.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) par[i]=i;
    }

    int ulp(int node) { 
        if(node==par[node]) return node;
        return par[node]=ulp(par[node]);
    }

    void u_rank(int u, int v) {
        int ulp_u=ulp(u);
        int ulp_v=ulp(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]) {
            par[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]) {
            par[ulp_v]=ulp_u;
        }
        else {
            par[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void u_size(int u, int v) {
        int ulp_u=ulp(u);
        int ulp_v=ulp(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]) {
            par[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            par[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

// Functions
/*

int ulp(int node, vector<int>& par) { 
    if(node==par[node]) return node;
    return par[node]=ulp(par[node], par);
}
void u_size(int u, int v, vector<int>& par, vector<int>& size) {
    int ulp_u=ulp(u, par);
    int ulp_v=ulp(v, par);
    if(ulp_u==ulp_v) return;
    if(size[ulp_u]<size[ulp_v]) {
        par[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else {
        par[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
}

*/