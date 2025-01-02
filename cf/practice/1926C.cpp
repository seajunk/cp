#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll sum(ll n){
    
    if(n == 0) return 0;
    
    ll ans = 0;
    while(n){
        ans += (n % 10);
        n /= 10;
    }

    return ans;

    
}


int main(){
    ll table[200000 + 1];
    ll ans = 0;
    for(int i = 1; i <= 200000; i++){
        ans += sum(i);
        table[i] = ans;
    }

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << table[n] << '\n';
    }


}

