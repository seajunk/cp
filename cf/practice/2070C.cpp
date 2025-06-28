#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       answer /in [0, 10^9], binary search?

       find smallest x such that penalty <= x is possible

       for a fixed x, if we want penalty to be <= x then,
       any a[i] > x must be correct and any a[i] <= x dont need to be correct

       then we can determine which cells must be red, must be blue, can be either

       r b r b e e b r

    */

    ll lo = 0, hi = 1000000001;
    while(lo < hi){
        ll x = (hi - lo)/2 + lo;
        vector<char> b(n);
        for(int i = 0; i < n; i++){
            if(a[i] > x) b[i] = s[i];
            else b[i] = 'e';
        }

        

        // need number of times r and b interleave?
        bool painting = false;
        ll cnt = 0;
        if(b[0] == 'B'){
            painting = true; 
            cnt++;
        }
        for(int i = 1; i < n; i++){
            if(painting){
                if(b[i] == 'R') painting = false;
            }
            else{
                if(b[i] == 'B'){
                    painting = true;
                    cnt++;
                }
            }
        }
        if(cnt <= k) hi = x;
        else lo = x + 1;

        /*
        cout << "penalty = " << ' ' << x << '\n';
        cout << "cnt = " << ' ' << cnt << '\n';
        for(auto e : b) cout << e << ' ';
        cout << '\n';
        */

    }
    if(hi == 1000000001){
        cout << "shit went wrong\n";
        return;
    }

    cout << lo << '\n';
    return;



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
