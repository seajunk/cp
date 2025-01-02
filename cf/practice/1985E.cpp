#include <iostream>
#define ll long long
const ll N = 3e5 + 5;
using namespace std;

void solve(){
    ll x ,y, z, k, ans;
    ans = 0;
    cin >> x >> y >> z >> k;

    for(int a = 1; a <= x; a++){
        for(int b = 1; b <= y; b++){
            if(k % (a*b) == 0){
                ll c = k / (a * b);
                ans = max(ans, (x - a + 1) * (y - b + 1) * (z - c + 1));
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    ll t;
    cin >> t;
    while(t--) solve();
}
