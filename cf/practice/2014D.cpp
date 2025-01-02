#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, d, k; cin >> n >> d >> k;
    ll l[k], r[k];
    for(int i = 0; i < k; i++){ 
        cin >> l[i] >> r[i];
        l[i]--;

    }

    vector<vector<ll>> diff(n + 1, vector<ll>(2, 0));


    for(int i = 0; i < k; i++){
        diff[l[i]][0]++;
        diff[r[i]][1]++;
    }


    ll cnt = 0;
    for(int i = 0; i < d; i++){
        cnt += diff[i][0];
    }

    ll mn = cnt;
    ll mx = cnt;

    ll mother = 0;
    ll brother = 0;
    for(int i = 1; i < n - d + 1; i++){
        cnt -= diff[i][1];
        cnt += diff[i + d - 1][0];
        if(cnt > mx){
            brother = i;
            mx = cnt;
        }
        if(cnt < mn){
            mother = i;
            mn = cnt;
        }
    }
    brother++; mother++;

    /*
    for(int i = 0; i <= n; i++){
        cout << diff[i][0] << ' ' << diff[i][1] << '\n';
    }
    */
    
    cout << brother << ' ' << mother << '\n';







}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
