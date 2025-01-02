#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string s, t; cin >> s >> t;
    ll ptrs = 0, ptrt = 0;

    while(ptrs < s.size() && ptrt < t.size()){
        if(s[ptrs] != t[ptrt]){
            cout << ptrs + 1 << '\n';
            return 0;
        }
        ptrs++; ptrt++;
    }

    if(ptrt != t.size() || ptrs != s.size()){
        cout << ptrs + 1 << '\n';
    }
    else{
        cout << 0 << '\n';
    }


}
