#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
    ll n; cin >> n;
    ll p[n];
    for(int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);
    ll median = p[n / 2];
    ll ans = 0;
    for(int i = 0; i < n; i++) ans += abs(median - p[i]);
    cout << ans << '\n';

}
