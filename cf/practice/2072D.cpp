#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // for each pair (l, r), keep track of how many guys in a(l, r] less than a[l], greater than a[l]
    // then # of new inversions after left cyclic shifting a[l, r] is (# of gys greater than - # of guys less than) 
    // [1 2 4 3] -> [3 1 2 4]  
    ll I, J;
    ll diff = 0;
    for(int i = 0; i < n; i++){
        ll lessthan = 0, greaterthan = 0;
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]) lessthan++;
            if(a[i] < a[j]) greaterthan++;
            if(diff > greaterthan - lessthan){
                diff = greaterthan - lessthan;
                I = i;
                J = j;
            }
        }
    }

    cout << I + 1 << ' ' << J + 1 << '\n';
    return;

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
