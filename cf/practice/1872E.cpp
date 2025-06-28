#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){

    /*
       binary string s
       array a[n]
       each query is either 

       (1) l r, flip s[l, r] 
       (2) g, get xor of all a[i] wherw s[i] = g

       xor of multiple values can be determined by parity of count of each set bit

       get bit count of every element in a
       then we can calculate xor in O(nlogn) time

       how to update bit count of range [l, r] ?

       so far idea is, if we have bit count parity of a[i] st s[i] = 0 and a[i] st s[i] = 1, we can process each query in O(nlogn) time

       how to update bit count array in nlogn time ?

       pre computation ? like prefix some or something 

       how to maintain prefix sum after swap ?

       maybe like have two prefex sums, one for set and one for the all of a

       then when we need to swap s[l, r], ... ?

       how to range update prefix sum array in o(n)/O(nlogn) time ?

       what matters is parity not the actual sum, does this help somehow ?

       oh shit, maybe difference array ? -> na, range update only works for adding,
       wait but for parity, adding and subtracting are the same thing (?). bro diff array query is O(n) still, adding being the same thing as subtracting with respect to pairty might be useful ?


       okay ditch prefix sum, isnt leading anywhere


       wait no i think prefix sum works


       have two arrays cnt1[64], cnt0[64] st
       cnt1[i] = number of times ith bit occurs in a[i] where s[i] = 1
       cnt0[i] = number of times ith bit occurs in a[i] where s[i] = 0

       also have pfs[n][64] st
       pfs[i][j] = cnt of jth bit in prefix a[i, n)

       then, 
       query g is answerd by iterating over cntg, and adding s^i if cntg[i] is odd
       query [l, r) is answer by adding pfs[r][i] - pfs[l][i] for each i 
    */

    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    string s; cin >> s;

    vector<vector<ll>> pfs(n + 1, vector<ll>(64, 0));


    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 64; j++){
            if((a[i - 1] >> j) % 2 == 1) pfs[i][j] = pfs[i - 1][j] + 1;
            else pfs[i][j] = pfs[i - 1][j];
        }
    }



    vector<ll> cnt0(64, 0), cnt1(64, 0);



    for(int i = 0; i < n; i++){
        for(int j = 0; j < 64; j++){
            if(s[i] == '0'){ if((a[i] >> j) % 2 == 1) cnt0[j]++; }
            else{ if((a[i] >> j) % 2 == 1) cnt1[j]++; }
        }
    }


    ll q; cin >> q;
    for(int i = 0; i < q; i++){

        ll tp; cin >> tp;

        if(tp == 1){
            ll l, r; cin >> l >> r;
            l--;


            for(int j = 0; j < 64; j++){
                cnt0[j] += pfs[r][j] - pfs[l][j];
                cnt1[j] += pfs[r][j] - pfs[l][j];
            }

        }
        else{
            ll g; cin >> g;
            if(g == 0){
                ll ans = 0;
                for(int j = 0; j < 64; j++){
                    if(cnt0[j] % 2 == 0) continue;
                    ans += 1ll << j;
                }
                cout << ans << '\n';
            }
            else{
                ll ans = 0;
                for(int j = 0; j < 64; j++){
                    if(cnt1[j] % 2 == 0) continue;
                    ans += 1ll << j;
                }
                cout << ans << '\n';
            }
        }
    }
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

