#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       if a[i] has 1 prime factor, not strongly composite
       if a[i] has 2 prime factors, if same prime factors,
       if duplicate then strongly composite, else not strongly composite
       if a[i] has >= 3 prime factors, strongly composite 

       then to get most strongly composite numbers, 
       create as many numbers of the form p^2, then use the remaining numbers to form three-prime numbers
    */

    map<ll, ll> pcnt;

    for(int i = 0; i < n; i++){
        ll temp = a[i];

        for(int j = 2; j*j <= a[i]; j++){
            while(temp % j == 0){
                if(pcnt.find(j) == pcnt.end()) pcnt[j] = 1;
                else pcnt[j]++;
                temp /= j;
            }
        }
        if(temp > 1){
            if(pcnt.find(temp) == pcnt.end()) pcnt[temp] = 1;
            else pcnt[temp]++;
        }
    }

    ll k = 0;
    for(auto &p : pcnt){
        k += p.second / 2;
        p.second = p.second - 2*(p.second / 2);
    }
    ll sum = 0;
    for(auto &p : pcnt){
        //cout << p.first << ' ' << p.second << '\n';
        sum += p.second;
    }
    k += sum / 3;


    cout << k << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
