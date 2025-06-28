#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class DSU{
    private:
    vector<ll> size;
    vector<ll> parent;
    public:
    DSU(ll n){
        this->size.assign(n, -1);
        this->parent.assign(n, -1);
    }
    void make_set(ll x){
        parent[x] = x;
        size[x] = 1;
    }
    void union_set(ll a, ll b){
        if(size[a] < size[b]) swap(a, b);
        size[a] = size[b] + size[a];
        parent[b] = parent[a];
    }
    ll find_set(ll x){
        if(parent[x] == x) return x;
        parent[x] = find_set(parent[x]);
        return parent[x];
    }
    void print(){
        for(auto e : parent) cout << e << ' ';
        cout << '\n';
        for(auto e : size) cout << e << ' ';
        cout << '\n';
    }
};


void solve(){
    ll n, m1, m2; cin >> n >> m1 >> m2;

    vector<set<ll>> adjF(n), adjG(n);
    set<vector<ll>> edgeF;

    for(int i = 0; i < m1; i++){
        ll u, v; cin >> u >> v;
        u--; v--;
        adjF[u].insert(v);
        adjF[v].insert(u);
        edgeF.insert({u, v});
    }
    for(int i = 0; i < m2; i++){
        ll u, v; cin >> u >> v;
        u--; v--;
        adjG[u].insert(v);
        adjG[v].insert(u);
    }

    DSU dsuF = DSU(n);
    DSU dsuG = DSU(n);

    vector<set<ll>> ccF, ccG;
    vector<bool> seenF(n, false), seenG(n, false);

    for(int i = 0; i < n; i++){
        if(seenG[i]) continue;
        dsuG.make_set(i);

        set<ll> curr;
        stack<ll> dfs;
        seenG[i] = true;
        dfs.push(i);;
        curr.insert(i);

        while(dfs.size()){
            ll top = dfs.top();
            dfs.pop();

            for(ll neigh : adjG[top]){
                if(seenG[neigh]) continue;
                seenG[neigh] = true;
                curr.insert(neigh);
                dsuG.make_set(neigh);
                dsuG.union_set(dsuG.find_set(neigh), dsuG.find_set(i));
                dfs.push(neigh);
            }
        }
        ccG.push_back(curr);
    }

    ll ans = 0;

    // removing all edge in F that connect nodes which dont belong in the same cc in G
    for(auto edge : edgeF){
        ll u = edge[0], v = edge[1];
        if(dsuG.find_set(u) != dsuG.find_set(v)){
            ans += 1;
            adjF[u].erase(v);
            adjF[v].erase(u);
        }
    }

    for(int i = 0; i < n; i++){
        if(seenF[i]) continue;

        seenF[i] = true;
        dsuF.make_set(i);
        stack<ll> dfs;
        dfs.push(i);

        while(dfs.size()){
            ll top = dfs.top();
            dfs.pop();

            for(ll neigh : adjF[top]){
                if(seenF[neigh]) continue;
                seenF[neigh] = true;
                dfs.push(neigh);
                dsuF.make_set(neigh);
                dsuF.union_set(neigh, dsuF.find_set(i));
            }

        }
    }

    for(auto cc : ccG){
        ll leader = dsuG.find_set(*cc.begin());

        for(ll e : cc){
            if(dsuF.find_set(e) != dsuF.find_set(leader)){
                ans++;
                dsuF.union_set(dsuF.find_set(e), dsuF.find_set(leader));
            }
        }
    }



    cout << ans << '\n';


    // get connected components of G, 

    // iterate through each edge in F, if edge connects two guys in different component of G, remove the edge

    // get connectd components of F.

    // at this point, each cc of F is a subset of some cc in G since we cut all non matches 
    
    // iterate through each node in each cc in G. if the node in F isnt connected to same cc, add edge between leader and node in F

    // C: optimal(?) the removal is optimal probably. The stitching sounds optimal since after cutting, theres only one way to stitch(?) 

}



int main(){
    ll t; cin >> t;
    while(t--) solve();
}

