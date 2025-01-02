#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    if(n % 2 == 0){
        unordered_map<char, ll> cnteven, cntodd;
        ll mxeven = 0, mxodd = 0;

        for(int i = 0; i < n/2; i++){
            if(cnteven.find(s[2*i]) == cnteven.end()) cnteven[s[2*i]] = 1;
            else cnteven[s[2*i]]++;
            mxeven = max(mxeven, cnteven[s[2*i]]);
        }
        for(int i = 0; i < n/2; i++){
            if(cntodd.find(s[2*i + 1]) == cntodd.end()) cntodd[s[2*i + 1]] = 1;
            else cntodd[s[2*i + 1]]++;
            mxodd = max(mxodd, cntodd[s[2*i + 1]]);
        }
        
        ll ans = n/2 - mxodd + n/2 - mxeven;
        cout << ans << '\n';
    }
    else{
        vector<vector<vector<ll>>> pfcnt(n + 1, vector<vector<ll>>(2, vector<ll>(26, 0)));
        // pfcnt[i][parity][j] = "count of letter j in the pairty indicies of s[0, i)"
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 26; j++){
                pfcnt[i][0][j] = pfcnt[i - 1][0][j];
                pfcnt[i][1][j] = pfcnt[i - 1][1][j];
            }
            if((i - 1) % 2 == 0){
                pfcnt[i][0][s[i - 1] - 'a']++;
            }
            else{
                pfcnt[i][1][s[i - 1] - 'a']++;
            }
        }

        ll ans = LLONG_MAX;
        for(int i = 0; i < n; i++){
            ll mxeven = 0, mxodd = 0;
            for(int j = 0; j < 26; j++){
                mxeven = max(mxeven, pfcnt[i][0][j] + pfcnt[n][1][j] - pfcnt[i + 1][1][j]);
                mxodd = max(mxodd, pfcnt[i][1][j] + pfcnt[n][0][j] - pfcnt[i + 1][0][j]);
            }
            ans = min(ans, 1 + n/2 - mxeven + n/2 - mxodd);
        }

        cout << ans << '\n';



    }


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
