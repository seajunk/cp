#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    ll n; cin >> n;
    ll p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }

    // 2 1 4 5 3
    // 2 1 4 3 5

    // 2 3 4 5 1
    // 2 1 4 5 3
    // 2 1 4 3 5
    // 

    vector<bool> visited(n, false);
    ll ans = 0;

    for(int i = 0; i < n; i++){
        if(visited[p[i]]) continue;

        ll length = 1;

        stack<ll> dfs;
        visited[i] = true;
        dfs.push(i);

        while(dfs.size()){
            ll top = dfs.top();
            dfs.pop();
            if(!visited[p[top]]){
                length++;
                visited[p[top]] = true;
                dfs.push(p[top]);
            }
        }
        if(length > 2) ans += (length - 1) / 2;
    }

    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
