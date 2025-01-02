#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;

    ll pfcnt[n + 1], sfcnt[n + 1]; // countn of happy guys if wall is built on idx i

    pfcnt[0] = 0;
    for(int i = 1; i <= n; i++){
        pfcnt[i] = pfcnt[i-1] + (s[i-1] == '0');
    }

    sfcnt[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        sfcnt[i] = sfcnt[i + 1] + (s[i] == '1');
    }

    ll ans = -1;
    ll mn = LLONG_MAX;

    for(int i = 0; i <= n; i++){
        // build wall at index i
        // happy left = pf[i];
        // happy right = sf[i];


        // [0, i) [i, n) 
        // a b c d|e f g
        //0 1 2 3 4 5 6 7
        //cout << i << ' ' << pfcnt[i] << ' ' << sfcnt[i] << '\n';


        if(pfcnt[i] >= (i + 1)/2 && sfcnt[i] >= (n - i + 1)/2){
            if(min(abs(n/2 - i), abs((n+1)/2 - i)) < mn){
                ans = i;
                mn = abs(n/2 - i);
            }
        }
    }

    cout << ans << '\n';





    



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
