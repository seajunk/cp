#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<ll>> pfcnt(n + 1, vector<ll>(32, 0)); //pfcnt[i][j] = count of j th bit in [0, i)

    for(int i = 1; i <= n; i++){
        bitset<32> temp(a[i - 1]);
        for(int j = 0; j < 32; j++){
            pfcnt[i][j] = pfcnt[i - 1][j] + (temp[j] == 1);
        }
    }

    ll q; cin >> q;

    for(int i = 0; i < q; i++){
        ll l, k; cin >> l >> k;
        l--;

        // want largest l <= r < n st &[r, l] >= k


        ll lo = l - 1, hi = n - 1;

        while(lo < hi){
            ll mid = (hi - lo + 1)/2 + lo;


            bitset<32> temp(0);
            for(int j = 0; j < 32; j++){
                if(pfcnt[mid + 1][j] - pfcnt[l][j] == mid - l + 1) temp[j] = 1;
            }



            ll templl = temp.to_ullong();



            if(templl >= k) lo = mid;
            else hi = mid - 1;
        }

        if(lo == l - 1) cout << -1 << '\n';
        else cout << lo + 1 << '\n';
    }
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
