#include <bits/stdc++.h>
#define ll long
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];


    ll lo = 1, hi = n;
    ll k;
    // logn
    while(lo < hi){
        k = (hi - lo) / 2 + lo;

        bool works = true;
        unordered_map<ll, ll> bitcnt;
        for(int i = 0; i < k; i++){
            for(int b = 0; b < 20; b++){
                if(a[i] & (1ll << b)){
                    if(bitcnt.find(b) == bitcnt.end()) bitcnt[b] = 1;
                    else bitcnt[b]++;
                }
            }
        }

        
        //n - k
        for(int i = 1; i < n - k + 1; i++){
            for(int b = 0; b < 20; b++){
                if(a[i - 1] & (1ll << b)){
                    bitcnt[b]--;
                }
            }
            for(int b = 0; b < 20; b++){
                if(a[i + k - 1] & (1ll << b)){
                    if(bitcnt.find(b) == bitcnt.end()) works = false;
                    else bitcnt[b]++;
                }
            }
            for(int b = 0; b < 20; b++){
                if(bitcnt.find(b) != bitcnt.end() && bitcnt[b] == 0) works = false;
            }
        }

        if(works){
            hi = k;
        }
        else{
            lo = k + 1;
        }
    }

    cout << lo << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}




