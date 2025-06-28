#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, q; cin >> n >> q;
    ll p[n];
    for(int i = 0; i < n; i++) cin >> p[i];

    map<ll, ll> idx; // idx[p[i]] = i;

    for(int i = 0; i < n; i++) idx[p[i]] = i;


    for(int i = 0; i < q; i++){
        ll l, r, k; cin >> l >> r >> k;
        l--;
        r--;


        /*
           need d, min number of elements that need to be arranged so that binary search on p[l, r] for k works
        */


        if(!(l <= idx[k] && idx[k] <= r)){
            cout << -1 << '\n';
            continue;
        }



        /*
           first get the directions that binary search will need to go to arrive at k


           eg for something like

           search for 5 in 1 2 3 4 5 6 7 8,
           1 2 3 4 5 6 7 8, right
           5 6 7 8 left
           5 6f found



           get the p[mid] value for each turn

           eg
           4
           6
           5


           if the value matches the direciton that we need to go, no issue

           if the value does not match the direction that we need to go, we will need to swap this value

           we would first try to swap with amongsts the p[mid] values



           then we would try to swap with the non p[mid] values.
        */


        ll needgreater = 0; // < k value which needs > k value
        ll needlesser = 0; // > k value which needs < k value 


        ll greater = n - k;
        ll lesser = k - 1;


        while(l <= r){
            ll mid = (l + r) / 2;
            //cout << p[mid] << '\n';
            if(p[mid] == k) break;


            if(idx[k] < mid){
                // need to go left

                if(p[mid] < k){
                    // will go right
                    needgreater += 1;
                    lesser -= 1;
                }
                else{
                    greater -= 1;
                }

                r = mid - 1;

            }
            else{
                // need to go right
                if(p[mid] > k){
                    // will go left
                    needlesser += 1;
                    greater -= 1;
                }
                else{
                    lesser -= 1;
                }
                l = mid + 1;
            }
        }

        ll d = needlesser + needgreater;


        if(needlesser == needgreater){
            cout << d << ' ';
        }
        else if(needlesser < needgreater){
            d += needgreater - needlesser;

            if(needgreater - needlesser > greater) cout << -1 << ' '; 
            else cout << d << ' '; 
        }
        else{
            d += needlesser - needgreater;

            if(needlesser - needgreater > lesser) cout << -1 << ' ';
            else cout << d << ' ';
        }
    }
    cout << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
