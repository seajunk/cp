#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

void solve(){
    ll x, n, m; cin >> x >> n >> m;

    /*
       maximizing
       wrong = odd use ceil, even use floor
       right = use every floor then use every ceil


       counter example
       wrong 110001 -> 11001 -> 1101 -> 110 -> 11 -> 1
       right 110001 -> 11000 -> 1100 -> 110 -> 11 -> 10

       doesnt work when theres an early odd which is too far to be carried all the up, whilst also being an odd further up ahead which can be carried up.

       ie, any 1 bit not in the last m bits cant be carried up since we dont have enough operations

       thus its optimal to use all floors at the start then use ceils


       minimizing

       simillar idea, 
       if theres atleast one 0 in the last n guys, we can minimize
       if theres no 0 in the last n guys but theres also no 1 in the last n + m guys, we can minimize
       if theres no 0 in the last n guys and theres at least one 1 in the last n + m guys, we can not minimize

       thus its optimal to use all ceils at the start then use floors
    */


    ll floor = n, ceil = m;
    ll mn = x, mx = x;


    while(floor + ceil > 0){
        if(ceil > 0){
            if(mn == 1 || mn == 0){
                ceil = 0;
            }
            else{
                mn = (mn + 1) / 2;
                ceil--;
            }
        }
        else{
            if(mn == 0){
                floor = 0;
            }
            else{
                mn /= 2;
                floor--;
            }
        }
    }
    cout << mn << ' ';

    floor = n, ceil = m;
    while(floor + ceil > 0){
        if(floor > 0){
            if(mx == 0){
                floor = 0;
            }
            else{
                mx /= 2;
                floor--;
            }
        }
        else{
            if(mx == 1 || mx == 0){
                ceil = 0;
            }
            else{
                mx = (mx + 1) / 2;
                ceil--;
            }
        }
    }
    cout << mx << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
