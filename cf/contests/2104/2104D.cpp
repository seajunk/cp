#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll pi(ll n) {
    if (n < 6)
        return 15; 
    return static_cast<int>(n * (log(n) + log(log(n))));
}
vector<ll> sieve(ll n) {
    ll limit = pi(n);
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= limit; ++p) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    vector<ll> primes;
    for (int i = 2; i <= limit && primes.size() < n; ++i) {
        if (is_prime[i])
            primes.push_back(i);
    }

    return primes;
}


void solve(){
    /*
       array is ideal if

       (1) if a[i] >= 2
       (2) if any pair of distinct guys are corpime



       can also redistribute sum of array ie 

       1 2 3 -> 0 0 6 -> 2 2 2 -> 1 4 1 ... etc


       array of len n is beautiful if its sum is greater or equal to sum of first n primes ?
    */


    ll n; cin >> n;
    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }


    vector<ll> primes = sieve(n);


    /*
    primes.push_back(2);

    // get first n primes

    // might tle lol
    for(int i = 3; primes.size() < n; i++){
        bool isprime = true;
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0){
                isprime = false;
                break;
            }
        }
        if(isprime) primes.push_back(i);
    }
    */





    ll pfsum[n + 1];
    pfsum[0] = 0;
    for(int i = 1; i <= n; i++) pfsum[i] = pfsum[i - 1] + primes[i - 1];

    sort(a, a + n);

    for(int i = 1; i <= n; i++){
        if(pfsum[n - i + 1] <= sum){
            cout << (i - 1) << '\n';
            return;
        }
        sum -= a[i - 1];
    }

    cout << "shit went wrong\n";




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
