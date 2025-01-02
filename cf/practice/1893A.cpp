#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll b[n];
    for(int i = 0; i < n; i++) cin >> b[i];

    // 4 3 3 2 3
    // 3 2 3 4 3 
    // 3 4 3 3 2 
    // 3 2 3 4 3
    // 4 3 3 2 3

    // 5 5
    // 6 1 1 1 1 
    // 1 6 1 1 1
    // 1 1 6 1 1
    // 1 1 1 6 1
    // 1 1 1 1 6
    // 


    // conj: if b[n - 1] > n, impossible to reach this state from some other state 


    // conj: if b is the state of the array after some operation, b[n - 1] was the previous fixed point used in the operation

    // conj: if the operation can be performed >= n times, then cycle can be performed for any arbitrary k? 



    ll rotation = 0;

    ll cnt = 0;

    function<ll(ll, ll)> mod = [](ll a, ll k){return ((a%k + k)%k);};

    while(cnt < k && cnt < 2*n){
        if(b[mod(n - 1 - rotation, n)] > n){
            cout << "No\n";
            return;
        }

        rotation += b[mod(n - 1 - rotation, n)];
        rotation = mod(rotation, n);

        cnt++;
    }

    cout << "Yes\n";


  

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
