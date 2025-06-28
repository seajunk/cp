#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    /*
       for array a of len n, 
       f(a) = len of longets palindromic subseq
       g(a) = number of palindromic subseq with len f(a)

       construct subseq a st 

       len = n
       1 <= a[i] <= n
       g(a) > n
    */

    int n; cin >> n;

    vector<ll> ans(n);

    ans[0] = 1;
    ans[n - 1] = 1;

    ll curr = 1;
    for(int i = 1; i < n - 1; i++){
        ans[i] = curr;
        curr += 1;
    }

    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
