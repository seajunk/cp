#include <iostream>
#include <string>
#define ll long long
using namespace std;

void solve(){
  string s;
  ll n;
  cin >> n >> s;

  string reversed = "";
  for(int i = s.size() - 1; i >= 0; i--){
    reversed += s[i];
  }

  if(s <= reversed){
    cout << s << '\n';
  }
  else{
    cout << reversed + s << '\n';
  }
}

int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}
