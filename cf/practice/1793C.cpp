#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<bool> inside(n + 1, true);
    ll mn = 1;
    ll mx = n;

    ll l = 0, r = n - 1;

    while(r - l + 1 >= 4){
        if((a[l] != mx && a[l] != mn) && (a[r] != mx && a[r] != mn)){
            cout << l + 1 << ' ' << r + 1 << '\n';
            return;
        }

        if(a[l] == mx || a[l] == mn){
            inside[a[l]] = false;
            l++;
        }
        if(a[r] == mx || a[r] == mn){
            inside[a[r]] = false;
            r--;
        }
        

        // recalculate mx and mn
        while(!inside[mn]){
            mn++;
        }
        while(!inside[mx]){
            mx--;
        }
    }

    cout << -1 << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
