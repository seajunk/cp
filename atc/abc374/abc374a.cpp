#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string s; cin >> s;
    ll n = s.size();
    if(s.substr(n - 3, 3) != "san") cout << "No\n"; 
    else cout << "Yes\n";
}
