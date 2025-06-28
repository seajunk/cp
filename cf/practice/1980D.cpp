#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll b[n - 1];
    for(int i = 0; i < n - 1; i++){
        b[i] = gcd(a[i], a[i + 1]);
    }

    ll I = -1;
    for(int i = 1; i < n - 1; i++){
        if(b[i - 1] > b[i]){
            I = i;
            break;
        }
    }

    if(I == -1){
        cout << "YES\n";
        return;
    }

    vector<ll> temp, temp2;

    // b[I - 1] > b[I]
    // 0 1 2 3 4
    //  0 1 2 3
    // so one of a[I - 1], a[I], a[I + 1] are problematic ?

    // awful stuff down here
    bool works;

    temp.clear();
    temp2.clear();
    for(int i = 0; i < n; i++) if(i != I - 1) temp.push_back(a[i]); 
    for(int i = 1; i < temp.size(); i++) temp2.push_back(gcd(temp[i], temp[i - 1])); 
    works = true;
    for(int i = 1; i < temp2.size(); i++) if(temp2[i - 1] > temp2[i]) works = false;
    if(works){
        cout << "YES\n";
        return;
    }

    temp.clear();
    temp2.clear();
    for(int i = 0; i < n; i++) if(i != I) temp.push_back(a[i]); 
    for(int i = 1; i < temp.size(); i++) temp2.push_back(gcd(temp[i], temp[i - 1])); 
    works = true;
    for(int i = 1; i < temp2.size(); i++) if(temp2[i - 1] > temp2[i]) works = false;
    if(works){
        cout << "YES\n";
        return;
    }

    temp.clear();
    temp2.clear();
    for(int i = 0; i < n; i++) if(i != I + 1) temp.push_back(a[i]); 
    for(int i = 1; i < temp.size(); i++) temp2.push_back(gcd(temp[i], temp[i - 1])); 
    works = true;
    for(int i = 1; i < temp2.size(); i++) if(temp2[i - 1] > temp2[i]) works = false;
    if(works){
        cout << "YES\n";
        return;
    }


    cout << "NO\n";
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
