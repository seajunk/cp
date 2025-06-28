#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pi[5001];

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll pcount(ll a){

    ll count = 0;
    ll temp = a;
    for(int factor = 2; factor * factor <= a; factor++){
        while(temp % factor == 0){
            temp /= factor;
            count++;
        }
    }

    if(temp != 1) count++;
    return count;
}

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       a[i] <= 5000
       n <= 5000

       in one operation, choose distinct i and j. then replace a[i] with gcd(a[i], a[j])
       need min operation to make all of a equal 


       claim. final value of a must be gcd of all values
       proof. suppose towards contradiction that final value isnt gcd(a).
       the final value cant be less than gcd(a) since gcd(a) is the minimum value obtainable through any number of operations on any number of elements
       so final value is greater than gcd(a). note this is a contradiction because this final value which is greater than gcd(a) is a factor of all elements in a[i] so this value is gcd(a)




       if we already have this final value, then cost is # of elements which arent final value

       if we dont have this final value, we first need to construct it, then cost is # of elements min cost to make final + # of elements not equal to final - 1



       what is min cost to make final ?


       choose some pivot element to turn into final

       then,

       O(n)
       for(pivot : a){
       cost = 0;

       O(log(max(a)))
       while(pivot != final){

       O(n)
       find a[i] such that # of pfactors of gcd(pivot, a[i]) is minimized
       set pivot to gcd(pivot, a[i])

       does this choice of a[i] minimize cost of transforming pivot to final ?
       proof. ... uhh
       idk but it sounds right
       cost++;
       }

       O(n)
       a[idx of pivot] = final
       ans = cost + # of guys != final in a 

       }

       O(n*(sqrt(max(a))*n + n)))
       max(a) <= 5000 so consider it constant 


       O(n^2)
       should work
    */


    ll ans = INT_MAX;

    ll final = a[0];
    for(int i = 1; i < n; i++) final = gcd(final, a[i]);


    for(int p = 0; p < n; p++){

        ll pivot = a[p];
        vector<bool> used(n, false);
        used[p] = true;
        ll cost = 0;

        while(pivot != final){
            ll mn = INT_MAX;
            ll mnidx = -1;
            for(int i = 0; i < n; i++){
                if(used[i]) continue;
                ll pcnt = pi[gcd(a[p], a[i])]; 

                if(pcnt < mn){
                    mn = pcnt;
                    mnidx = i;
                }
            }
            assert(mnidx != -1);
            used[mnidx] = true;
            pivot = gcd(pivot, a[mnidx]);
            cost++;
        }

        for(int i = 0; i < n; i++){
            if(i == p) continue;
            if(a[i] != final) cost++;
        }

        ans = min(ans, cost);
    }

    cout << ans << '\n';










}

int main(){
    for(int i = 1; i <= 5000; i++) pi[i] = pcount(i); // O(5000 * 70)

    ll t; cin >> t;
    while(t--) solve();
}

