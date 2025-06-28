#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll x[n];
    for(int i = 0; i < n; i++) cin >> x[i];

    ll score = 0; 
    ll l = 0, r = n - 1; 

    sort(x, x + n);

    while(l < r){
        if(x[l] + x[r] == k){
            score += 1;
            l++;
            r--;
        }
        else if(x[l] + x[r] > k){
            r--;
        }
        else{
            l++;
        }
    }
    cout << score << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

