#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
    ll n; cin >> n;
    vector<vector<ll>> a(2 * n, vector<ll>(2));

    for(int i = 0; i < n; i++){
        cin >> a[2 * i][0];
        a[2 * i][1] = 1;
        cin >> a[2 * i + 1][0];
        a[2 * i + 1][1] = -1;
    }

    sort(a.begin(), a.end(), [](vector<ll> left, vector<ll> right){
            return left[0] < right[0];
            });

    ll ans = 0;
    ll count = 0;
    for(int i = 0; i < 2 * n; i++){
        count += a[i][1];
        ans = max(ans, count);
    }

    cout << ans << '\n';





}
