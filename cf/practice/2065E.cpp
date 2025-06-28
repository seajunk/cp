#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    /*
       need binary string t of lenght n + m such that

       (1) has n 0's and m 1's
       (2) every substring of t has balance of k

       balance of binary string is abs(# of 1's - # of 0's)


       000111000111001
       2 4 3
       111001

       2/3 = 0
       4/3 = 1

       2%3 = 2
       4%3 = 1



       abs(n/k - m/k) <= 1

       if(n/k > m/k){
       001100 ...
       n%k < m%k or doesnt work
       }
       else if(n/k < m/k){
       n%k > m%k or doesnt work
       }
       else{
       if(n%k > m%k){}
       else{}
       }

    */


    // proving nessecity is for losers

    if(max(n, m) < k){
        cout << -1 << '\n';
        return;
    }

    if(abs(n/k - m/k) > 1){
        cout << -1 << '\n';
        return;
    } 


    if(n/k > m/k){

        if(n%k > m%k){
            cout << -1 << '\n';
            return;
        }

        for(int i = 0; i < m/k + n/k; i++){
            for(int j = 0; j < k; j++){
                if(i%2 == 0) cout << 0;
                else cout << 1;
            }
        }

        for(int i = 0; i < m%k; i++) cout << 1;
        for(int i = 0; i < n%k; i++) cout << 0;

        cout << '\n';
        return;
    }

    if(n/k < m/k){

        if(n%k < m%k){
            cout << -1 << '\n';
            return;
        }

        for(int i = 0; i < m/k + n/k; i++){
            for(int j = 0; j < k; j++){
                if(i%2 == 0) cout << 1;
                else cout << 0;
            }
        }

        for(int i = 0; i < n%k; i++) cout << 0;
        for(int i = 0; i < m%k; i++) cout << 1;

        cout << '\n';
        return;
    }

    // n/k == m/k

    if(n%k <= m%k){
        for(int i = 0; i < m/k + n/k; i++){
            for(int j = 0; j < k; j++){
                if(i%2 == 0) cout << 1;
                else cout << 0;
            }
        }

        for(int i = 0; i < m%k; i++) cout << 1;
        for(int i = 0; i < n%k; i++) cout << 0;


        cout << '\n';
        return;
    }



    for(int i = 0; i < m/k + n/k; i++){
        for(int j = 0; j < k; j++){
            if(i%2 == 0) cout << 0;
            else cout << 1;
        }
    }

    for(int i = 0; i < n%k; i++) cout << 0;
    for(int i = 0; i < m%k; i++) cout << 1;

    cout << '\n';
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
