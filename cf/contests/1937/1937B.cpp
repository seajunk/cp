#include <iostream>
#include <string>
#include <set>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    char in;
    string r1(" ", n);
    string r2(" ", n);
    for(int i = 0; i < n; i++){
        cin >> in;
        r1[i] = in;
    }
    for(int i = 0; i < n; i++){
        cin >> in;
        r2[i] = in;
    }

    multiset<string> s;

    string temp;
    for(int i = 1; i <= n; i++){
        temp = "";
        temp.append(r1.substr(0, i));
        temp.append(r2.substr(i - 1, (n - 1) - (i - 1) + 1));
        s.insert(temp);
    }

    string out = *(s.begin());
    cout << out << '\n';
    cout << s.count(out) << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
