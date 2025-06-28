#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll q; cin >> q;

    /*
       rizz(a) = a[0] * 1 + a[1] * 2 + ... + a[n - 1] * n


       calculate rizz(a) after each operation

       let arr be a deque which corresponds to the state of a whenever flipped = false
       let rarr be a dqueue which corresponds tothe state of a whenever flipped = true

       ie flipped => a = arr, !flipped => a = rarr


       if we can gurantee after each operation that,
       (1) arr is correct
       (2) score corresponds to arr
       (2) rscore corresponds to rarr
       (3) rarr is the reverse of arr
       then we can just keep track of the current flipped state and output score or rscore accordingly after each query
    */


    ll score = 0;
    ll rscore = 0;
    ll sum = 0;
    deque<ll> arr, rarr;
    bool flipped = false; 



    for(int i = 0; i < q; i++){
        ll s; cin >> s;

        if(s == 1){
            // cyclic shift 
            if(arr.size() != 0){
                if(flipped){
                    rarr.push_front(rarr.back());
                    rarr.pop_back();
                    rscore = rscore + sum - rarr.front() * rarr.size();

                    arr.push_back(arr.front());
                    arr.pop_front();
                    score = score - sum + arr.back() * arr.size();
                }
                else{
                    arr.push_front(arr.back());
                    arr.pop_back();
                    score = score + sum - arr.front() * arr.size();

                    rarr.push_back(rarr.front());
                    rarr.pop_front();
                    rscore = rscore - sum + rarr.back() * rarr.size();
                }
            }
        }
        else if(s == 2){
            // reverse array
            flipped = !flipped;
        }
        else if(s == 3){
            // add k to array
            ll k; cin >> k;

            if(flipped){
                rarr.push_back(k);
                rscore = rscore + k * rarr.size();

                arr.push_front(k);
                score = score + sum + k;

                sum += k;
            }
            else{
                arr.push_back(k);
                score = score + k * arr.size();

                rarr.push_front(k);
                rscore = rscore + sum + k;

                sum += k;
            }
        }
        else assert(false);

        if(flipped) cout << rscore << '\n';
        else cout << score << '\n';
        //for(auto e : arr) cout << e << ' ';
        //cout << " : " << score << '\n';
        //for(auto e : rarr) cout << e << ' ';
        //cout << " : " << rscore << '\n';

    }




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


