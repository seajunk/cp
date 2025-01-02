#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(2));

    for(int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1]; 

    sort(a.begin(), a.end(), [](vector<ll> left, vector<ll> right){ return left[1] < right[1];});

    ll ans = 0, latest = -1;

    for(int i = 0; i < n; i++){
        if(a[i][0] >= latest){
            ans++;
            latest = a[i][1];
        }
    }

    cout << ans << '\n';


}

