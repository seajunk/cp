#include <iostream>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll direction[n];
    direction[0] = 0;
    direction[n - 1] = 1;

    for(int i = 1; i < n-1; i++){
        if(abs(a[i] - a[i - 1]) > abs(a[i] - a[i + 1])) direction[i] = 0; 
        else direction[i] = 1;
    }

    ll dist = 0;
    ll pre[n];
    pre[0] = 0;
    for(int i = 1; i < n; i++){
        if(direction[i - 1] == 0) dist += 1;
        else dist += abs(a[i] - a[i - 1]);
        pre[i] = dist;
    }

    dist = 0;
    ll suff[n];
    suff[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--){
        if(direction[i + 1] == 1) dist += 1;
        else dist += abs(a[i] - a[i + 1]);
        suff[i] = dist;
    }

    ll m; cin >> m;
    for(int i = 0; i < m; i++){
        ll x, y; cin >> x >> y; x--; y--;

        if(x < y){
            cout << pre[y] - pre[x] << '\n';
        }
        else{
            cout << suff[y] - suff[x] << '\n';
        }
    }




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
