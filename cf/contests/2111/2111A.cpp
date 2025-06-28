#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x; cin >> x;


    /*
       0 0 0

       1 0 0

       1 1 0

       1 1 1

       first, make 2 guys big and third guy bigger

       afterwards, make 1 guy big, third guy bigger


    */



    if(x == 1){
        cout << 3 << '\n';
        return;
    }





    ll cost = 5;
    ll curr = 3;



    while(curr < x){
        cost += 2;
        curr = curr * 2 + 1;
    }


    cout << cost << '\n';









}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
