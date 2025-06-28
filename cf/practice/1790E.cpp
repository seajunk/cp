#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){

    /*
       x = a^b
       need a b such that a^b = (a+b)/2     (*not integer division)


       x = 10101

       sum should be 101010



       notice that 
       011 + 001 = 100 
       011 ^ 001 = 010



       x = 1001
       a = 0100
       b = 1100







    */


    ll x; cin >> x;
    bitset<64> xbs(x), abs(0), bbs(0);

    if(xbs[0] == 1){
        cout << -1 << '\n';
        return;
    }

    for(int i = 1; i < 64; i++){
        if(xbs[i] == 1){
            if(xbs[i - 1] == 0){
                abs[i] = 1;
                abs[i - 1] = 1;
                bbs[i - 1] = 1;
            } 
            else{
                cout << -1 << '\n';
                return;
            }
        }
    }

    ll all = abs.to_ullong();
    ll bll = bbs.to_ullong();

    // one way guess lol 
    cout << all << ' ' << bll << '\n';



    // sufficient by construction
    // nessecity proof?

    /*
       first suppose x[0] == 1. then exactly one of a or b is odd, in which case (a + b)/2 is not a natural number so clearly (a+b)/2 != a^b

       now suppose x contains 011 in its binary representation


       then in a+b at the position which 011 occurs in x, its also 011 (coudl pssible be 1011) 

       then if we divide by 2 we get 01011 and 011 


       tldr if 11 appears in x, (a+b)/2 can not equal a^b
    */
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
