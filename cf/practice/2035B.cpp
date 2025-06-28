#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    /*
       need decimal number of length n
       must be divisible by 33 and 66
       digits are either 3 or 6


       number needs to end with 6

       sum of odd index digits and even index digits need to have difference % 11 == 0

       this happens only when the odd digit sum and even digit sum are equal
    */


    ll n; cin >> n;

    if(n % 2 == 0){
        for(int i = 2; i < n; i++) cout << 3; 
        cout << "66";
        cout << '\n';
    } 
    else if(n % 2 != 0 && n >= 5){
        for(int i = 5; i < n; i++) cout << '3';
        cout << "36366";
        cout << '\n';
    }
    else{
        cout << -1 << '\n';
    }


    
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
