#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    /*
       how to check if set of intervals contain non overlapping pair



       keep track of largest left end and smallest right end



       max(left) <= min(right)

       then every left end of an interval is <= max(left) and every right end of an intervals is >= min(right)


       ie every interval contains [max(left), min(right)]
    */


    map<vector<ll>, ll> intervals;

    map<ll, ll> left;
    map<ll, ll> right;


    ll q; cin >> q;

    for(int i = 0; i < q; i++){
        char type; cin >> type;


        ll l, r; cin >> l >> r;
        vector<ll> interval = {l, r};


        if(type == '+'){
            if(intervals.find(interval) == intervals.end()){
                intervals[interval] = 1;

                if(left.find(l) == left.end()) left[l] = 1;
                else left[l]++;

                if(right.find(r) == right.end()) right[r] = 1;
                else right[r]++;
            }
            else{
                intervals[interval]++;
                left[l]++;
                right[r]++;
            }
        }
        else{
            intervals[interval]--;
            left[l]--;
            right[r]--;

            if(intervals[interval] == 0) intervals.erase(interval);
            if(left[l] == 0) left.erase(l);
            if(right[r] == 0) right.erase(r);
        }


        if(intervals.size() == 0){
            cout << "NO\n";
            continue;
        }


        if((*prev(left.end())).first <= (*right.begin()).first){
            cout << "NO\n";
        }
        else cout << "YES\n";

    }
}

int main(){
    solve();
}
