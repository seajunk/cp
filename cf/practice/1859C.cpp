#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;

    /*
       there are <= n*n potential max values. iterate over them then ...

       greedily choose rest of the pairings by matching the largest guys together ?

       1 2 3
       1*1 2*3 3*2

    */
    ll ans = 0;
    ll I, J;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){

            ll curr = 0;

            ll l = n, r = n;

            while(l && r){
                if(l == i){
                    l--;
                    continue;
                }
                if(r == j){
                    r--;
                    continue;
                }
                if(l*r > i*j) break;
                curr += l*r;
                l--;
                r--;
            }
            
            if(ans < curr){
                ans = curr;
                I = i;
                J = j;
            }

        }
    }
    printf("ans = %lld, i = %lld, j = %lld\n", ans, I, J);
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
