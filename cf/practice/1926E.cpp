#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll guy(ll a, ll b){
    if(b == 0) return 1;
    ll temp = pow(a, b / 2);
    if(b % 2 == 0) return temp * temp;
    else return temp * temp * a;
}

void solve(){
    ll n, k; cin >> n >> k;

    /*
       have numbers 1 through n

       all odd guys get placed in increasing order,
       then all guys with 2^1 as factors get placed in increasing order
       then all guys with 2^2 as factors get placed in increasing order
       ...
       then all guys with 2^i as factors get placed in increasing order


       30 / 16 = 1 -> 1 guy with padic 4
       30 / 8 = 3 -> 2 guys with padic 3
       30 / 4 = 7 -> 4 guys with padic 2
       30 / 2 = 15 -> 8 guys with padic 1
       30 / 1 = 30 -> 15 guys with padic 0

       5 / 4 = 1 -> 1 guy with padic 2
       5 / 2 = 2 -> 1 guy with padic 1
       5 / 1 = 5 -> 3 guy withs padic 0


    */


    ll msb = 1;
    ll temp = n;
    ll pow2 = 1;
    while(temp > 1){
        msb++;
        temp /= 2;
        pow2 *= 2;
    }



    vector<ll> ans;
    ll curr = n / pow2;
    pow2 /= 2;

    ans.push_back(curr);



    while(pow2 > 1){
        ans.push_back(n / pow2 - curr);
        curr = n/pow2;
        pow2 /= 2;
    }

    ans.push_back((n + 1) / 2);
    reverse(ans.begin(), ans.end());

    vector<ll> pfs(ans.size() + 1);
    pfs[0] = 0;

    for(int i = 1; i <= ans.size(); i++) pfs[i] = pfs[i - 1] + ans[i - 1];



    /*
       want smallest i such that k <= pfsum[i]
       minimize on [0, ans.size()]
    */
    ll lo = 0, hi = ans.size() + 1;
    while(lo < hi){
        ll mid = (hi - lo)/2 + lo;
        if(k <= pfs[mid]) hi = mid ;
        else lo = mid + 1;
    }


    if(lo == ans.size() + 1){
        cout << "shit went wrong\n";
        return;
    }
    if(lo == 1) cout << 2 * k - 1 << '\n';
    else cout << guy(2, lo - 1) * (2*(k - pfs[lo - 1]) - 1) << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

