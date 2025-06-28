#include <bits/stdc++.h>
using namespace std;
typedef uint64_t ll;

void solve(){
    ll x, y; cin >> x >> y;

    // 10 -> 11, 1 -> 2

    // 9 -> 10, 9 -> 1

    // 99 -> 100, 18 -> 1

    // 999 -> 1000, 27 -> 1

    // 129 -> 130, 12 -> 4

    // S(n) -> S(n + 1)
    // lose 9c - 1 
    // gain 1


    if(y - x == 1){
        cout << "Yes\n";
        return;
    }

    ll diff = x - y;

    if(diff < 8){
        cout << "No\n";
        return;
    }

    diff += 1;

    if(diff % 9 != 0){
        cout << "No\n";
        return;
    }

    ll c = diff / 9;

    // diff = 9c - 1 

    if(9*c > x){
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    return;








    


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
