#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> fib(n);

    fib[0] = 1;
    fib[1] = 2;
    ll sum = 2;

    for(int i = 2; i < n; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
        if(fib[i] > 4000000) break;


        if(fib[i] % 2 == 0){
            sum += fib[i];
        }


    }

    cout << sum << '\n';





}

