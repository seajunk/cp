#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    /*

       5 4 2 3

       -2 5 -2 5 -2 
       -5 8 -5 8 -5 
       3 0 3 0 3
       0 3 0 3 0


       -100 103 -100 103 -100


       


       p % n, left over 


       if (p / n) * q > m -> cant work ?





       3 2 2 1

       1 0 1



       0 1 0



       4 2 2 1

       1 0 1 0







    */

    ll n, m, p, q; cin >> n >> m >> p >> q;

    /*
       if p divies n, everyting is locked in

       if p doesnt divide n, we have degree of freedom and anything works ?

    */


    if(n % p == 0){
        if((n / p) * q != m) cout << "NO\n";
        else cout << "YES\n";
    }
    else{
        cout << "YES\n";
    }


    /*
       if (p/n) * q <= m, we can construct uhhh






    */




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
