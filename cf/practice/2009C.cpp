#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x, y, k; cin >> x >> y >> k;

    ll dx = (x + k - 1) / k;
    ll dy = (y + k - 1) / k;

    if(dx > dy){
        cout << 2*dx - 1 << '\n';
    }
    else if(dx == dy){
        cout << dx + dy << '\n';
    }
    else{
        cout << 2*dy << '\n';
    }

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
