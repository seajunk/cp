#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;


    /*
       cycle shift each row ?

       1 2 3 4 5


       1 5 4 3 2
       2 3 4 5 1

       1 2 3 4 5
       1 5 4 3 2

       1 2 3 4 5
       1 2 5 4 3
       2 1 5 4 3

       1 2 3 5 4
       3 2 1 5 4



       1 3 2
       2 1 3
       3 2 1


       1 4 3 2
       2 1 4 3

    */

    cout << 2 * n - 1 << '\n';
    for(int i = 1; i < n; i++){
        cout << i << ' ' << 1 << ' ' << i << '\n';
        cout << i << ' ' << i + 1 << ' ' << n << '\n';
    }
    cout << n << ' ' << 1 << ' ' << n << '\n';







}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
