#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll n; cin >> n;

    ll mx = -1;
    ll ub = floor(sqrt(n));
    for(ll i = 2; i <= ub; i++){
        if(n % i == 0){
            mx = max(mx, i);
            while(n % i == 0){
                n /= i;
            }
        }
    }

    cout << mx << '\n';




}
