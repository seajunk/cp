#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector<ll> even, odd;

    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        if(i % 2 == 0) even.push_back(in);
        else odd.push_back(in);
    }

    /*
       10 9 8 7 6 5 4 3 2 1
       10 9 8 7 6 5 2 1 4 3
       10 9 8 7 2 1 6 5 4 3
       10 9 2 1 8 7 6 5 4 3
       2 1 10 9 8 7 6 5 4 3
       2 1 10 9 8 5 4 7 6 3
       2 1 10 9 4 7 8 5 6 3
       2 1 4 7 10 9 8 5 6 3
       2 1 4 7 10 9 6 3 8 5
       2 1 4 7 10 3 8 9 6 5
       2 1 4 3 8 7 10 9 6 5
       2 1 4 3 8 9 6 7 10 5
       2 1 4 3 6 9 8 7 10 5
       2 1 4 3 6 5 8 9 10 7





    */

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
