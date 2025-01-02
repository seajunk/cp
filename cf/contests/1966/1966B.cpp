#include<iostream>
using namespace std;

void solve(){
  int n, m;
  char in;
  cin >> n >> m;
  char a[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> in;
      a[i][j] = in;
    }
  }

  if(a[0][0] == a[n - 1][m - 1] || a[0][m - 1] == a[n - 1][0]){
    cout << "YES" << '\n';
    return;
  }
  
  if(a[0][0] == a[0][m - 1]){
    for(int i = 0; i < m; i++){
      if(a[0][0] == a[n - 1][i]){
        cout << "YES" << '\n';
        return;
      }
    }
    for(int i = 0; i < m; i++){
      if(a[n-1][0] == a[0][i]){
        cout << "YES" << '\n';
        return;
      }
    }   
  }
  else{
    for(int i = 0; i < n; i++){
      if(a[0][0] == a[i][m - 1]){
        cout << "YES" << '\n';
        return;
      }
    }
    for(int i = 0; i < n; i++){
      if(a[0][m - 1] == a[i][0]){
        cout << "YES" << '\n';
        return;
      }
    }
  }
  cout << "NO" << '\n';
  return;
}


int main(){
  int t;
  cin >> t;
  while(t--) solve();
}
