#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

void solve(){
    ll n, x, y; cin >> n >> x >> y;

    /*
       need to count the number of values that are divisible by x but not y 
       need to count the number of values that are divisible by y but not x 

       xnoty = n/lcm(x, y) - n/y // # of guys divisible by x and y - # of guys divisible by y
       ynotx = n/lcm(x, y) - n/x // # of guys divisible by x and y - # of guys divisible by x
    */


    ll lcm = (x*y) / gcd(x, y);


    ll xnoty = n/x - n/lcm;
    ll ynotx = n/y - n/lcm;


    ll ans = 0;

    ans += (n*(n + 1))/2 - ((n - xnoty) * (n - xnoty + 1))/2;
    ans -= (ynotx * (ynotx + 1))/2;

    cout << ans << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
