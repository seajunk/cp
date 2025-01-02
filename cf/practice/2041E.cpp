#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a, b; cin >> a >> b;

    // mean a, median b
    // 1 <= n <= 1000



    // if b, a >= 0
    // -2b b b+3a

    // if b >= 0 a < 0
    // -2b+3a b b 

    // if a >= 0 b < 0
    // b b 3a-2b 

    // if a < 0 b < 0
    // 3a+b b -2b 

    ll ans[3];

    if(a >= 0 && b >= 0){
        ans[0] = -2*b;
        ans[1] = b;
        ans[2] = b+3*a;
    }
    else if(a >= 0){
        ans[0] = b;
        ans[1] = b;
        ans[2] = 3*a-2*b;
    }
    else if(b >= 0){
        ans[0] = b;
        ans[1] = b;
        ans[2] = 3*a-2*b;
    }
    else{
        ans[0] = 3*a+b;
        ans[1] = b;
        ans[2] = -2*b;
    }

    cout << 3 << '\n';
    for(ll e : ans) cout << e << ' ';
    cout << '\n';






    // as long a stheres two b's in array, b is always median





}

int main(){
    solve();
}
