#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> x(n, vector<ll>(2));

    for(int i = 0; i < n; i++){
        cin >> x[i][1];
        x[i][0] = i;
    }

    sort(x.begin(), x.end(), [](auto l, auto r){return l[1] < r[1];});

    ll leftsum[n], rightsum[n];


    leftsum[0] = 1;
    for(int i = 1; i < n; i++){
        leftsum[i] = leftsum[i - 1] + (x[i][1] - x[i - 1][1]) * i + 1;
    }

    rightsum[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--){
        rightsum[i] = rightsum[i + 1] + (x[i + 1][1] - x[i][1]) * (n - (i + 1)) + 1; 
    }

    ll ans[n];

    for(int i = 0; i < n; i++){
        ans[x[i][0]] = leftsum[i] + rightsum[i] - 1;
    }


    for(auto e : ans) cout << e << ' ';
    cout << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

