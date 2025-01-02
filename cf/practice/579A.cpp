#include<iostream>
#include<cmath>
using namespace std;

int main(){
		int x, ans;
		cin >> x;
		ans = 0;

		while(x){
				x -= pow(2, floor(log2(x)));
				ans++;
		}

		cout << ans << '\n';
		


}
