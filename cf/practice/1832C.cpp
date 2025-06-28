#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    // smallest subsequence with same contrast is the contrast point

    vector<ll> b;

    ll curr = a[0];
    ll trend = 2;
    b.push_back(a[0]);

    vector<ll> diff;
    for(int i = 1; i < n; i++){
        if(a[i] - a[i - 1] != 0) diff.push_back(a[i] - a[i - 1]);
    }

    if(n == 1){
        cout << 1 << '\n';
        return;
    }

    if(diff.size() == 0){
        cout << 1 << '\n';
        return;
    }

    ll inflections = 0;
    for(int i = 1; i < diff.size(); i++){
        if(diff[i] > 0 != diff[i - 1] > 0) inflections += 1;
    }

    cout << inflections + 2 << '\n'; 








}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
