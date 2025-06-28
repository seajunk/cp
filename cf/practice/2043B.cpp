#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, d; cin >> n >> d;

    /*
       digit d written n! times

       which odd numbers divide this number

    */


    // always divisible by 1
    cout << 1 << ' ';

    // divisible by 3 if sum of digits is divisible by 3
    // since n! digits, sum will be multiple of 3 if n >= 3, so divisible if d == 3 or n >= 3
    if(n >= 3 || d % 3 == 0) cout << 3 << ' ';

    // divisible by 5 if d == 5
    if(d == 5) cout << 5 << ' ';

    // who the fuck just knows this fact btw 

    // divisible by 7 if ddd + ddd - ddd + ddd - ddd ... - ddd is divisible by 7
    // if n! is multiple of 6, works, 
    // if d == 7, works
    if(n >= 3 || d == 7) cout << 7 << ' ';

    // divisible by 9 if sum is divisible by 9
    // sum = n! * d need two 3's. 
    if(n >= 6 || (d % 3 == 0 && n >= 3) || d == 9) cout << 9 << ' ';

    cout << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


