#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    // 18 21 25

    // fact: number of planks needed is <= 2n since 2 planks is enough to cover one layer of all three bridges

    // binary search ?

    // def works for 2n, def does not work for 0
    // lo = 0, hi = 2n

    // how to efficiently check if some x planks is enough?

    ll n; cin >> n;
    ll lo = 0, hi = 2*n;


    while(lo < hi){
        ll mid = (hi - lo)/2 + lo;

        // how to check if mid planks is enough?

        // mid works -> mid >= 18*n + 21*n + 25*n

        // is greedy optimal ? put smallest guy in largest bin
        // 3 -> (18 18 18) (21 21) (21 25) (25 25)

        // conj: always optimal to pair 25s together
        // conj: want as much 21 21 18 as possible.


        // (25 25) (25 21) (21 21 18) (18 18)



        vector<ll> bin(mid, 0);
        ll cnt18 = 0;
        ll cnt21 = 0;
        ll cnt25 = 0;


        int i = 0;

        while(i < mid){
            while((bin[i] + 25 <= 60) && (cnt25 < n)){
                bin[i] += 25;
                cnt25++;
            }
            if(cnt25 == n) break;
            else i++;
        }

        if(i < mid && bin[i] == 25){
            bin[i] += 21;
            cnt21++;
            i++;
        }

        // make as many 21 21 18 as possible
        while(i < mid){
            while(cnt21 < (n - 1) && (bin[i] + 21 + 21 + 18) <= 60){
                bin[i] += 21 + 21 + 18;
                cnt18++;
                cnt21 += 2;
            }
            if(cnt21 == n || cnt21 == (n-1)) break; 
            else i++;
        }

        if(i < mid && cnt21 == (n - 1)){
            bin[i] += 21;
            cnt21 += 1;
            i++;
        }



        // use remaining 18
        while(i < mid){
            while((bin[i] + 18 <= 60) && (cnt18 < n)){
                bin[i] += 18;
                cnt18++;
            }
            if(cnt18 == n) break;
            else i++;
        }


        bool works; // wip

        if(cnt18 == n && cnt21 == n && cnt25 == n) works = true;
        else works = false;

        if(works) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << '\n';

}

int main(){
    solve();
}
