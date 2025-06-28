#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*

       for a[i] >= 1, can kill 1 monster in one move, x += 1
       for a[i] >= x, can kill x monsters in one move 

       what is minimum # of moves to kill monsters


       two pointers ? 


       1 2 2 3 4 5
       0 0 0 3 4 5, 5 moves
       0 0 0 3 4 0, 1 move
       0 0 0 0 4 0, 3 moves
       0 0 0 0 1 0, 1 move
       0 0 0 0 0 0, 1 move
    */

    sort(a, a+n);


    ll ans = 0;
    ll curr = 0;
    for(int l = 0, r = n - 1; l <= r;){
        if(l == r){
            if(a[r] == 0) break;
            if(a[r] == 1){
                ans += 1;
                break;
            }

            ans += (a[r] + curr) / 2 - curr;

            ans += 1 + (a[r] + curr) % 2;

            break;

        }


        if(curr + a[l] >= a[r]){
            assert(curr <= a[r]); // makes sense i think
            a[l] -= (a[r] - curr);
            ans += (a[r] - curr) + 1;
            curr = 0;
            r--;
        }
        else{
            curr += a[l];
            ans += a[l];
            l++;
        }


    }

    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
