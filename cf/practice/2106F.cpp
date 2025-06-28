#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


typedef struct{
    ll id;
    ll start;
    ll end;
    ll cnt0;
} Node;


void solve(){
    ll n; cin >> n;
    string s; cin >> s;


    /*
       g = s stacked on each other n times with the diagonals flipped

       two types of columns in g

       if s[j] == 0 then, g[i][j] == 0 iff i != j

       if s[j] == 1 then, g[i][j] == 1 iff i != j





       that is to say,

       if s[j] == 0 then from top to bottom, column j consists of >= 0 number of 0's, followed by 1 at g[j][j], followed by >= 0 number of 0's

       AND

       if s[j] == 1 then from top to bottom, column j consists of >= 0 number of 1's, followed by 0 at g[j][j], followed by >= 0 number of 1's



       so we can consider each column as having 2 nodes if s[j] == 0 and 1 node if s[j] == 1, which represent the contiguous 0's
       a node will contain its # of zeros, its start index and its end index [start, end)

       then nodes in column i and i + 1 are connected iff 

       their [start, end) intervals overlap
    */



    vector<vector<Node>> columns(n);
    vector<Node> nodes; 
    ll id = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            Node node = {id, i, i + 1, 1};
            id++;
            columns[i].push_back(node);
            nodes.push_back(node);
        }
        else{
            Node node1 = {id, 0, i, i};
            id++;
            Node node2 = {id, i + 1, n, n - (i + 1)};
            id++;
            columns[i].push_back(node1);
            columns[i].push_back(node2);
            nodes.push_back(node1);
            nodes.push_back(node2);
        }
    }

    ll node_cnt = nodes.size();
    vector<ll> leader(node_cnt, -1);
    vector<ll> size(node_cnt, -1);
    vector<ll> cnt0(node_cnt, -1);

    function<void(ll)> make_set = [&](ll a){
        leader[a] = a; 
        size[a] = 1;
        cnt0[a] = nodes[a].cnt0;
    };

    function<ll(ll)> get_leader = [&](ll a){
        if(leader[a] == a) return a; 
        leader[a] = get_leader(leader[a]);
        return leader[a];
    };

    function<void(ll, ll)> union_set = [&](ll a, ll b){
        a = get_leader(a);
        b = get_leader(b);
        if(a == b) return;
        if(size[a] <= size[b]) swap(a, b);
        size[a] += size[b];
        cnt0[a] += cnt0[b];
        leader[b] = a;
    };


    // initialize nodes
    for(int i = 0; i < node_cnt; i++) make_set(i); 


    for(int i = 0; i < n - 1; i++){
        for(Node a : columns[i]){
            for(Node b : columns[i + 1]){

                // connect a and b if they are connected
                if(max(a.start, b.start) < min(a.end, b.end)) union_set(a.id, b.id); 

            }
        }
    }


    ll ans = 0;

    for(int i = 0; i < node_cnt; i++) ans = max(ans, cnt0[get_leader(i)]);

    cout << ans << '\n';












}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
