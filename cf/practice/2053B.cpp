#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    /*
       have l[n], r[n] st
       l[i] <= w[i] <= r[i]

       for each i, possible for some w to exist st w[i] != w[j] for any j != i ?


       w[i] unique as long as exists some x in [l[i], r[i]] st no other guy is forced to pick x,
       ie no j st l[j] = r[j] = x

       taken[x] = 1 if exists some j st x = l[j] = r[j] and 0 otherwise
       cnt[x] = cnt of j st l[j] = r[j] = x

       case, l[i] != r[i]
       then w[i] is unique if sum of taken over l[i] and r[i] = r[i] - l[i] + 1
       
       case l[i] = r[i]
       works if cnt[l[i]] == 1
    */

    ll n; cin >> n;
    ll l[n], r[n];
    for(int i = 0; i < n; i++){
        cin >> l[i];
        cin >> r[i];
    }

    vector<ll> cnt(2*n + 1, 0), taken(2*n + 1, 0);


    for(int i = 0; i < n; i++){
        if(l[i] == r[i]){
            cnt[l[i]] += 1;
            taken[l[i]] = 1;
        }
    }


    ll pfs[2*n + 2];
    pfs[0] = 0;
    for(int i = 1; i <= 2*n + 1; i++) pfs[i] = pfs[i - 1] + taken[i - 1];

    string s(n, '0');


    for(int i = 0; i < n; i++){
        if(l[i] == r[i]){
            if(cnt[l[i]] == 1) s[i] = '1';
            else s[i] = '0';
        }
        else{
            //cout << pfs[r[i] + 1] - pfs[l[i]] << '\n';
            if(pfs[r[i] + 1] - pfs[l[i]] < r[i] - l[i] + 1) s[i] = '1';
            else s[i] = '0';
        }
    }

    cout << s << '\n';




    /*
takeaway: dont just think about the space on n but also on the space of a[i]
here you didnt consider the space that a[i] lives in

by considering a[i] space, we can answer questions like "how many elements of a have values between l and r" where l and r live in a[i] space and not n space

    */


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
