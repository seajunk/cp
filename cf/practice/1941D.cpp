#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll mod(ll n, ll k){
    return (n % k + k) % k;
}


void solve(){
    /*
       n guys in a circle 

       x starts with ball

       m moves made

       for each m move we have
       r, d

       where r is the distance thrown and d is the direction. d could also be unknown

       want to know # of different places the ball could be after the m turns

       n*m <= 2*10^5



       brute force would be branch at each d = ?, worst case 2^1000 so impossible

       could be easier to iterate over players and check if they could have ended with the ball


       for some fixed player i, when could they end with the ball?

       get sum of distances of all right throws and left throws -> add and get net distance 

       then i could end with the ball if we can use the remamining unknown throws to get from (x + net) mod n to i

       ie get (x + net - i) mod n from the sum of unknown direction distances

       so tldr we have bunch of numbers and we want to know if there exists ways to add / subtract them st the result mod n is = wanted value = (x + net - i) mod n

    */



    /*
       literally keep track of the set of possible set of possible values after each throw  
    */


    set<ll> curr;


    ll n, m, x; cin >> n >> m >> x;
    x--;
    curr.insert(x);

    for(int q = 0; q < m; q++){
        ll r;
        char d;
        cin >> r >> d;

        set<ll> nxt;

        if(d == '0'){ // clockwise 
            for(ll e : curr){
                nxt.insert(mod(e + r, n));
            }
        }
        else if (d == '1'){ // counter clock wise
            for(ll e : curr){
                nxt.insert(mod(e - r, n));
            }
        }
        else { // unknown direction
            for(ll e : curr){
                nxt.insert(mod(e - r, n));
                nxt.insert(mod(e + r, n));
            }
        }
        curr = nxt;
    }




    
    cout << curr.size() << '\n';
    for(ll e : curr) cout << e + 1 << ' '; 
    cout << '\n'; 











}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
