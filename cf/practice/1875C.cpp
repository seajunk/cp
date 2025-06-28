#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void solve(){
    ll n, m; cin >> n >> m;
    n = n % m;

    // is there a way to distribute pieces such that some guys get different number of pieces ?
    // each guy needs n/m apples 
    // 6 4, 1 1 1 1 0.5 0.5 0.5 0.5 


    // VVV sufficient but idk if nessecary

    // works if exists some k such that 
    // (n * 2^k = 0) mod m 
    // this happens when n * 2^k is multiple of m
    // this happens when n contains m ie m divides n 
    // or if the factors needed for n to contain m is 2^k
    // ie m / gcd(n, m) = 2^k

    ll temp = m / gcd(n, m);
    if(temp == 1){
        cout << 0 << '\n';
        return;
    }
    while(temp % 2 == 0){
        temp /= 2;
    }

    if(temp != 1){
        cout << -1 << '\n';
        return;
    }


    bitset<64> hate(n/gcd(n, m));
    ll ans = 0;
    for(int i = 0; i < 64; i++) if(hate[i] == 1) ans++;
    
    cout << ans * m - n << '\n'; // each guy gets ans pieces. there are m guys. we started out with n pieces 





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


/*
   each guy will need total of n/m kg of apples.
   the minimal number of cuts will result in every guy having the same set of pieces. since if we supposed otherwise, then there exists a guy with a piece like 1/2 and another guy with a piece like 1/4, 1/4. then we can just add the two smaller pieces to get 1/2. this logic works for any guy recursively since n/m is a sum of inverse powers of two 
   look at binary representation of n/gcd(n, m). then this is the number of pieces we need eg if we have n/gcd(n, m) = 3 and m = 4, then we need a 1/2 piece and a 1/4 piece. the number of set bits in the guy is the number of pieces each guy will get 
   note also for each cut we make, we get one more piece. ie if we need more pieces, we will need to make 10 more cuts. since each of the m guys will need S pieces, we will need m * S - n pieces. the - n is since we started with n pieces 



   note,
   for fraction n / m, n/gcd(n, m) is the reduced numerator and m / gcd(n, m) is the reduced demoninator 




*/
