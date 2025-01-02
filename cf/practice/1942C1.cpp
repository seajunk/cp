#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod(ll n, ll k){
    return (n % k + k) % k;
}

void solve(){
    ll n, x, y; cin >> n >> x >> y;
    ll vert[x];
    for(int i = 0; i < x; i++){
        cin >> vert[i];
        vert[i]--;
    }
    sort(vert, vert + x);

    // conj: for a any polygon of n vertices, n - 3 diagonals is possible, n - 2 triangles are possible


    // x - 2 = # of triangles formed from smaller polygon 

    ll cnt = 0;

    for(int i = 0; i < x - 1; i++){
        if(vert[i + 1] - vert[i] == 2) cnt++;
    }
    if(mod(vert[0] - vert[x - 1], n) == 2) cnt++;



    cout << x - 2 + cnt << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
