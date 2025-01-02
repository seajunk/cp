#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    // if n odd, last operation is &
    // if n even, last operation is |

    // n odd -> ans <= n
    // n even -> ans <= 2^k-1 where k is msb of n


    // when does n not achieve max value? 

    // case n odd:


    // n = ????...??1

    // ???? 3 & 1 | n - 1 & n 

    ll n; cin >> n;

    // just want to go next
    if(n == 6){
        cout << 7 << '\n';
        cout << "1 2 4 6 5 3\n";
        return;
    }

    if(n % 2 == 1){
        cout << n << '\n';
        for(int i = 2; i <= n - 2; i++){
            if(i == 3) continue;
            cout << i << ' ';
        }

        cout << 3 << ' ' << 1 << ' ' << n - 1 << ' ' << n << '\n';
        return;
    }


    //  0000011 & 000001 | 011110 & 011111 | 100000

    ll h = 1;
    ll temp = n;
    while(temp > 1){
        temp /= 2;
        h *= 2;
    }


    // 3 1 h-2 h-1 h


    cout << 2*h - 1 << '\n';

    for(int i = 1; i <= n; i++){
        if(i == 1 || i == 3 || i == (h-1) || i == (h-2) || i == h) continue;
        cout << i << ' ';
    }

    cout << 3 << ' ' << 1 << ' ' << h-2 << ' ' << h-1 << ' ' << h << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
