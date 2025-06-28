#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;

    // 10 9 8 7 6
    // 1 2 3 4 5

    // 9 10 11 12 13 
    // -2 -1 0 +1 +2

    // 10 9 8 7 6
    // 2 1 5 4 3
    // +1 -1 +2 0 -2

    // 14 13 12 11 10 9 8
    // 1  2  3  4  5  6 7

    // 14 13 12 11 10 9 8
    // 1  2  3  4  5  6 7


    // the code for this makes my balls hurt


    // 1 2 3
    // 6 4 5


    // sum ranges from [1 + 2n - (n - 1)/2, 1 + 2n + (n - 1)/2] 
    // [1 + 2n - (n - 1)/2, 1 + 2n + (n - 1)/2] = [(2 + 4n - n + 1) / 2, (2 + 4n + n - 1) / 2]
    // [(2 + 4n - n + 1) / 2, (2 + 4n + n - 1) / 2] = [(3n + 3)/2, (5n + 1)/2]
    // [3(n + 1)/2, 3(n + 1)/2 + n - 1]





    // man fuck this





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
