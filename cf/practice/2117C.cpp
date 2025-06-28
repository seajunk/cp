#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       let ll nxt[n + 1] st nxt[i] = index of next occurence of i


       a subarray a[l, r) can be a cool partition if max next[l, r) != INT_MAX
       if max nxt[l, r) == INT_MAX, then we must take the partition [l, n)

    */


    vector<ll> nxt(n, INT_MAX); // nxt[i] = index of next occurence of a[i]
    vector<ll> last_seen(n + 1, INT_MAX);

    for(int i = n - 1; i >= 0; i--){
        nxt[i] = last_seen[a[i]];
        last_seen[a[i]] = i;
    }

    ll ans = 1;
    ll l = 0;
    for(int r = 1; r <= n;){
        // trying to use partition [l, r)
        ll mx = -1;
        for(int i = l; i < r; i++) mx = max(mx, nxt[i]);

        if(mx != INT_MAX){
            ans++;
            l = r;
            r = mx + 1;
        }
        else{
            cout << ans << '\n';
            return;
        }
    }

    cout << ans << '\n'; // this shouldnt be needed(?)














}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
