#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

ll pow2(ll a, ll b){
    if(b == 0) return 1;
    ll res = pow2(a, b/2) % MOD;
    if(b%2 == 0) return (res * res) % MOD;
    else return (((res * res) % MOD) * a) % MOD;
}


void solve(){
    ll n; cin >> n;
    vector<vector<ll>> adj(n);

    for(int i = 0; i < n - 1; i++){
        ll u, v; cin >> u >> v;
        u--; 
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    /*

       tree is rooted at 1
       we want to assign to each vertex value of 1 or 2
       s[u] = sum of all value of nodes in the subtree rooted at u

       an assignment is beautiful if each S[u] is distinct 


       cant have more than 2 leaves



       tree will look like a Y

       if there is a node with more than 2 children, answer is 0
       if there is more than one node with 2 children, answer is 0
       if no node has two children, answer is 2^n
       if exactly one node has 2 children,

       let p be the parent of the two chidlren
       let l, r be the two children


       for the bottom min(size(l), size(r)) nodes in l and r, there is a constraint on them. Namely, one of the two will have to contain all even numbers and the other will have to contain all odd numbers.

       eg
       1 2 2 2 2
       2 2 2 2 2
       no other arangement works
       The proof looks something like this

       induction on n = min(size(l), size(r))
       case n = 1, clearly two leaves can not have the same node value so one must be 1 and the other must be 2
       case n > 1, suppose that claim holds for n - 1, ie, one of the children contain first n - 1 odds and the other contain first n - 1 evens. if we add 1 to the odd child, we will infact get sum of the even child so we must add 2 to the odd child.
       if we add 1 to the even child, we will get the sum of the odd child, so we must add 2 to the even child.
       since we added 2 to each children, their parity will not change.



       ok so the answer should be like

       ans = 2 * 2^(n - 2*min(size(l), size(r)))

       multiply by 2 for the choice of which child to assign odd/even
       then we have two choices for each of the remaining elements
    */


    vector<bool> seen(n, false);
    vector<ll> size(n, -1);

    stack<vector<ll>> dfs;


    dfs.push({0, -1}); // node, parent
    ll cnt = 0; // cnt of nodes with 2 children
    ll p = -1; // node with 2 children
    ll l = -1;
    ll r = -1;

    while(dfs.size()){
        vector<ll> top = dfs.top();
        if(adj[top[0]].size() - 1 > 2){
            cout << 0 << '\n';
            return;
        }
        if(top[0] == 0 && adj[0].size() > 2){
            cout << 0 << '\n';
            return;
        }


        bool finished = true;

        for(auto child : adj[top[0]]){
            if(child == top[1]) continue;
            if(seen[child]) continue;
            finished = false;
        }


        if(finished){
            dfs.pop();
            seen[top[0]] = true;

            size[top[0]] = 1;
            for(auto child : adj[top[0]]){
                if(child == top[1]) continue;
                size[top[0]] += size[child];
            }
            if(adj[top[0]].size() - 1 == 2){
                p = top[0];
                cnt++;

                vector<ll> stupid;
                for(auto child : adj[top[0]]){
                    if(child == top[1]) continue;
                    stupid.push_back(child);
                }

                l = stupid[0];
                r = stupid[1];
            }
            if(top[0] == 0 && adj[0].size() == 2){
                p = top[0];
                cnt++;

                vector<ll> stupid;
                for(auto child : adj[top[0]]){
                    if(child == top[1]) continue;
                    stupid.push_back(child);
                }

                l = stupid[0];
                r = stupid[1];
            }


            if(cnt > 1){
                cout << 0 << '\n';
                return;
            }
        }
        else{
            for(auto child : adj[top[0]]){
                if(child == top[1]) continue;
                dfs.push({child, top[0]});
            }
        }
    }


    if(p == -1){
        cout << pow2(2, n) << '\n';
        return;
    }


    if(size[l] == size[r]){
        cout << 2*pow2(2, n - 2*min(size[l], size[r])) << '\n';
        return;
    }


    ll ans = 0;
    ans += pow2(2, n - 2*min(size[l], size[r]));
    ans += pow2(2, n - 2*min(size[l], size[r]) - 1);
    cout << ans % MOD << '\n';














}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

