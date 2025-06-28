#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll N; cin >> N;
    map<ll, ll> cntX;
    set<ll> primes;


    ll A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
        primes.insert(A[i]);
    }
    for(int i = 0; i < N; i++) cin >> cntX[A[i]]; 

    ll M; cin >> M;
    map<ll, ll> cntY;
    ll C[M];
    for(int i = 0; i < M; i++){
        cin >> C[i];
        primes.insert(C[i]);
    }
    for(int i = 0; i < M; i++) cin >> cntY[C[i]]; 

    // lcm(p, q) = X means union of prime of p and q is X
    // for each prime which occurs in p or q, max cnt is equal to X's cnt of prime

    // gcd(p, q) = Y means intersection of prime of p and q is Y
    // for each prime which occurs in p or q, min cnt is equal to Y's cnt of prime

    ll ans = 1;
    for(ll prime : primes){
        if(cntX.find(prime) == cntX.end()){
            // if Y has a factor not in X, p and q need this factor for gcd(p, q) to be Y, but then lcm cant b X so impossible?
            cout << 0 << '\n';
            return;
        }
        else if(cntY.find(prime) == cntX.end()){
            // if X has a factor not in Y, as long as one of p or q doesnt contain this factor, gcd(p, q) = Y can still happen.
            // so either p has cntX[prime] and q has 0 or other way around
            ans *= 2;
            ans %= 998244353;
        }
        else{
            // if X and Y both have prime as a factor, we need max of prime cnt of p and q to be same as X and min of prime cnt of p and q to be same as Y. If X has less than Y, this is impossible. If the have the same count then only one way to distribuete, if x has more, two ways to distribute 
            if(cntX[prime] > cntY[prime]){
                ans *= 2;
                ans %= 998244353;
            }
            else if(cntX[prime] < cntY[prime]){
                cout << 0 << '\n';
                return;
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    solve();
}
