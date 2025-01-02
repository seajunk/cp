#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, m, q; cin >> n >> m >> q;
    ll b[m], a[q];
    for(int i = 0; i < m; i++){ cin >> b[i]; b[i]--;}
    for(int i = 0; i < q; i++){ cin >> a[i]; a[i]--;}


    // t 0 d 0 0 t
    // 0         5

    if(a[0] > max(b[0], b[1])){
        cout << (n - 1) - max(b[0], b[1]) << '\n';
    }
    else if(a[0] < min(b[0], b[1])){
        cout << min(b[0], b[1]) << '\n';
    }
    else{
        ll dist = (max(b[0], b[1]) - min(b[0], b[1])) / 2;
        cout << dist << '\n';
    }

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
