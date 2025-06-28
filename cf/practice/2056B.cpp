#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector<string> adj(n);
    for(int i = 0; i < n; i++) cin >> adj[i];

    // wlog i > j
    // if (i <-> j) then i appears after j



    // for some fixed i. 
    // if j > i,  j connected to i iff j comes after i 
    // if j < i,  j connected to i iff j comes before i 


    // can determine each i position with linear search across ith row

    ll p[n];
    for(int i = 0; i < n; i++){
        ll left = 0, right = 0;


        for(int j = 0; j < n; j++){
            if(i == j) continue;

            if(i < j){
                if(adj[i][j] == '1') right++;
                else left++;
            }
            else{
                if(adj[i][j] == '1') left++;
                else right++;
            }
        }

        p[left] = i + 1;
    }

    for(auto e : p) cout << e << ' ';
    cout << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
