#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;


    // works iff the initial found subsequence reversed makes the whole string sorted
    // works -> ans is length of initial subsequence


    ll sfmx[n + 1]; // sfmx[i] = index of largest char in [i, n) if tie index is left most 
    sfmx[n] = -1;
    for(ll i = n - 1; i >= 0; i--){
        if(sfmx[i + 1] == -1){
            sfmx[i] = i;
        }
        else{
            if(s[sfmx[i + 1]] > s[i]) sfmx[i] = sfmx[i + 1];
            else sfmx[i] = i;
        }
    }


    stack<char> characters; // char of subsequence
    queue<ll> indices; // index of subsequence
    ll curr = sfmx[0];
    char mxchar = s[curr];
    ll temp = 0; // this is pretty ass
    while(curr != -1){
        if(s[curr] == mxchar) temp++;
        characters.push(s[curr]);
        indices.push(curr);
        curr = sfmx[curr + 1];
    }

    ll len = indices.size();
    while(indices.size()){
        s[indices.front()] = characters.top();
        indices.pop();
        characters.pop();
    }


    bool sorted = true;

    for(int i = 1; i < n; i++){
        if(s[i - 1] > s[i]) sorted = false;
    }

    if(sorted) cout << len - temp << '\n';
    else cout << -1 << '\n';







}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

