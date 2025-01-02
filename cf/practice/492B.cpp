#include<iostream>
#include<algorithm>
#include<iomanip>
#define ll long long
const ll N = 2e5;
using namespace std;

int main(){
		ll n, l;
		long double a[N], ans;
		ans = -1;
		cin >> n >> l;
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		for(int i = 1; i < n; i++) ans = max(ans, (a[i] - a[i - 1]) / 2);
		ans = max(ans, a[0]);
		ans = max(ans, l - a[n - 1]);
		cout << fixed << setprecision(100);
		cout << ans << '\n';

				


		


}
