#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod(ll n, ll k){
    return (n%k + k) % k;
}

void solve(){
    ll n, x, y; cin >> n >> x >> y;

    /*
       set a[x] = 0, a[y] = 1

       then we have two paths between x and y not including the extra edge 

       if path length is odd, just alternate 0 1 0 1 0 1 ...
       if path length is even, alternate 0 1 0 1 0 1 then 2 then 1 0 1 0 1 0 ... 

    */



    vector<ll> ans(n, -1);
    x--;
    y--;

    ans[x] = 0;
    ans[y] = 1;

    ll d1 = mod(y - x, n); // clockwise distance
    ll d2 = mod(x - y, n); // counter clockwise distance

    if((d1 - 1) % 2 == 1) ans[mod(x + 1, n)] = 2; 

    bool toggle = true;
    for(int i = x + 1; mod(i, n) != y; i++){
        if(ans[mod(i, n)] == 2) continue;
        ans[mod(i, n)] = toggle;
        toggle = !toggle;
    }

    if((d2 - 1) % 2 == 1) ans[mod(x - 1, n)] = 2; 

    toggle = true;
    for(int i = x - 1; mod(i, n) != y; i--){
        if(ans[mod(i, n)] == 2) continue;
        ans[mod(i, n)] = toggle;
        toggle = !toggle;
    }

    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';








}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
/*
   no deep observation needed. basic constructive problem
   idea is set x to 0 and y to 1. then if even number of guys between x y in c.w, just alternate 0 1 or if odd then throw in a 2 in there 
   same for c.c.w

   I like the way mod stuff in for loop was handled. 
   nice and elegent.

*/
