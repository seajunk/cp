#include <iostream>
#include <utility>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

ll pow2(ll x){
    ll ans = 1;
    while(x--){
        ans *= 2;
    }
    return ans;
}

// 10 12 13 14 15 -> 6 4 3 2 1 -> 2 4 5 6 7 -> 2 0 1 2 3 -> 0 2 1 0 1 -> 1 1 0 1 0 
void solve(){
    ll n, a[N], mx, ub, odd, even;
    cin >> n;
    odd = 0;
    even = 0;
    mx = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        if(a[i] % 2 == 0) even++;
        else odd++;
    }

    if(odd > 0 && even > 0){
        cout << -1 << '\n';
        return;
    }

    cout << 30 + (even > 0 ? 1 : 0) << '\n';

    for(int i = 29; i >= 0; i--){
        cout << pow2(i) << ' ';
    }
    if(even > 0) cout << 1 << ' ';
    cout << '\n';
    

}

int main(){
    ll t;
    cin >> t;
    while(t--) solve();
}
