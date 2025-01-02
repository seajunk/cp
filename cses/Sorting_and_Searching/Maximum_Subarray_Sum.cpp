#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll curr = -1 * 10000000000, mx = curr;
    for(int i = 0; i < n; i++){
        curr = max(a[i], a[i] + curr);
        mx = max(mx, curr);
    }

    cout << mx << '\n';



}
