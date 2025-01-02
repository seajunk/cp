#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // 3 2 2 2 3

    // [3 2 x] : (3 2 3)
    // [2 2 x] : (2 2 2) (2 2 3)

    // [3 x 2] : (3 2 2) 
    // [2 x 2] : (2 2 2)
    // [2 x 3] : (2 2 3)

    // [x 2 2] : (3 2 2) (2 2 2)
    // [x 2 3] : (2 2 3)

    // 2 2 2 2 2
    // [x 2 2] : 0 1 2 
    // [2 x 2] : 0 1 2
    // [2 2 x] : 0 1 2

    map<vector<ll>, pair<unordered_map<ll, ll>, ll>> one;
    map<vector<ll>, pair<unordered_map<ll, ll>, ll>> two;
    map<vector<ll>, pair<unordered_map<ll, ll>, ll>> three;
    ll ans = 0;

    for(int i = 0; i < n - 2; i++){
        vector<ll> curr = {a[i + 1], a[i + 2]};

        if(one.find(curr) == one.end()){
            one[curr].second = 1;
            one[curr].first[a[i]] = 1;
        } 
        else{
            if(one[curr].first.find(a[i]) == one[curr].first.end()){
                one[curr].first[a[i]] = 1;
            }
            else{
                one[curr].first[a[i]]++;
            }
            one[curr].second += 1;
            ans += one[curr].second - one[curr].first[a[i]];
        }
    }
    for(int i = 0; i < n - 2; i++){
        vector<ll> curr = {a[i], a[i + 2]};

        if(two.find(curr) == two.end()){
            two[curr].second = 1;
            two[curr].first[a[i + 1]] = 1;
        } 
        else{
            if(two[curr].first.find(a[i + 1]) == two[curr].first.end()){
                two[curr].first[a[i + 1]] = 1;
            }
            else{
                two[curr].first[a[i + 1]]++;
            }
            two[curr].second += 1;
            ans += two[curr].second - two[curr].first[a[i + 1]];
        }
    }
    for(int i = 0; i < n - 2; i++){
        vector<ll> curr = {a[i], a[i + 1]};

        if(three.find(curr) == three.end()){
            three[curr].second = 1;
            three[curr].first[a[i + 2]] = 1;
        } 
        else{
            if(three[curr].first.find(a[i + 2]) == three[curr].first.end()){
                three[curr].first[a[i + 2]] = 1;
            }
            else{
                three[curr].first[a[i + 2]]++;
            }
            three[curr].second += 1;
            ans += three[curr].second - three[curr].first[a[i + 2]];
        }
    }
    cout << ans << '\n';





















    /*
    map<vector<ll>, unordered_multiset<ll>> first;
    map<vector<ll>, unordered_multiset<ll>> second;
    map<vector<ll>, unordered_multiset<ll>> third;
    // n times
    for(int i = 0; i < n - 2; i++){
        // O(1)
        vector<ll> curr = {a[i + 1], a[i + 2]};
        // logn
        if(first.find(curr) == first.end()) first[curr] = {a[i]};
        else{
            // logn + logn (?)
            first[curr].insert(a[i]);
            ans += first[curr].size() - first[curr].count(a[i]);
        } 
    }
    for(int i = 0; i < n - 2; i++){
        vector<ll> curr = {a[i], a[i + 2]};
        if(second.find(curr) == second.end()) second[curr] = {a[i + 1]};
        else {
            second[curr].insert(a[i + 1]);
            ans += second[curr].size() - second[curr].count(a[i + 1]);
        }
    }
    for(int i = 0; i < n - 2; i++){
        vector<ll> curr = {a[i], a[i + 1]};
        if(third.find(curr) == third.end()) third[curr] = {a[i + 2]};
        else{
            third[curr].insert(a[i + 2]);
            ans += third[curr].size() - third[curr].count(a[i + 2]);
        } 
    }
    cout << ans << '\n';
    */










}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
