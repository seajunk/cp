#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s; cin >> s;
    ll n = s.size();
    // cost of choose some c as the final character
    // = cost to remove every other character 
    ll ans = LLONG_MAX;

    for(int c = 'a'; c < 'a' + 26; c++){
        ll mx = LLONG_MIN;
        ll curr = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != c) curr++; 
            if(i == n - 1 || s[i + 1] == c){
                mx = max(mx, curr);
                curr = 0;
            }
        }

        if(mx == 0){
            cout << 0 << '\n';
            return;;
        }


        ll lg = 0;
        while(mx > 1){
            mx /= 2;
            lg++;
        }

        ans = min(ans, lg + 1);

        //ans = min(ans, (mx + 1) / 2);
    }

    cout << ans << '\n';

    // codeforces
    //  o e o c s

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
