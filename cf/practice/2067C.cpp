#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;

    /*
       in one operation, you can add number of form 10^x - 1 to n.

       what is the minimum number of operations needed to make n consist of only 7's in its decimal representation

       we need at most 9 operations since we can add 9 to n and each time the ones digit will cycle 


       iterate k = 0, ..., 9

       then can we choose k numbers of the form 10^x such that adding them to n - k creates a 7 ?
    */


    for(int k = 0; k < 7; k++){
        ll temp = n - k;

        string s = to_string(temp);

        for(char c : s){
            ll d = c - '0';

            if(d == 7){
                cout << k << '\n';
                return;
            }

            if((d + k) % 10 == 7){
                cout << k << '\n';
                return;
            }
        }
    }

    cout << 7 << '\n';
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


/*
   need at most 9 operations -> iterate over k = 0, ..., 9 -> if we do k operations, same thing as n - k plus k numbers of the form 10^x -> if any digit in n-k can be incremented to 7 in less than 7 operations, thats the answer, if it takes more than 7 operations, then we can just add big 10^x 7 times to make 7 in 7 operations.
*/
