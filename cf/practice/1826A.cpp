#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll l[n];
    for(int i = 0; i < n; i++) cin >> l[i];

    for(int i = 0; i <= n; i++){
        // assuming there are i liars 
        // need exactly n - i elements of l <= i
        // need exactly i elements of l > i

        ll liars = 0;

        for(int j = 0; j < n; j++){
            if(l[j] > i){
                liars += 1;
            }
        }

        if(liars == i){
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
