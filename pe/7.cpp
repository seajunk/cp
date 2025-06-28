#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pfc(ll n){

    ll pfc = 0;
    ll temp = n;
    for(int i = 2; i <= floor(sqrt(n)); i++){
        while(temp % i == 0){
            pfc += 1;
            temp /= i;
        }
    }
    if(temp != 1) pfc += 1;



    return pfc;
}


int main(){
    ll n; cin >> n;


    vector<ll> primes;




    for(int i = 2; primes.size() < n ;i++){
        if(pfc(i) == 1) primes.push_back(i);
    }

    cout << primes[primes.size() - 1] << '\n';










}
