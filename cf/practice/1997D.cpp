#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll>> children(n);
    for(int i = 1; i < n; i++){
        ll parent; cin >> parent; parent--;
        children[parent].push_back(i);
    }

    vector<ll> glb(n, LLONG_MAX);
    vector<bool> visited(n, false);
    stack<ll> dfs;
    dfs.push(0);

    while(dfs.size()){
        ll top = dfs.top();

        bool done = true;
        for(ll child : children[top]){
            if(!visited[child]){
                done = false;
                dfs.push(child);
            }
        }
        if(done){
            /*
               glb update issue(?). consider when (mn + a[top])/2 isnt the glb of tree rooted at top
               this happens(?) when 3 2 2 1 1 2
                   0  2 
                   1  2 
                   2  1

            */


            visited[top] = true;
            ll mn = LLONG_MAX;
            for(ll child : children[top]) mn = min(mn, glb[child]);
            if(mn == LLONG_MAX) glb[top] = a[top];
            else if(a[top] < mn) glb[top] = (mn + a[top])/2;
            else glb[top] = mn;
            dfs.pop();
        }
    }
    ll mn = LLONG_MAX;
    for(ll child : children[0]){
        mn = min(mn, glb[child]);
    }

    cout << (mn == LLONG_MAX ? a[0] : a[0] + mn) << '\n';

}


int main(){
    ll t; cin >> t;
    while(t--) solve();
}
