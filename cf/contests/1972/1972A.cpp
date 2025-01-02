#include<iostream>
#include<set>
#define ll long long
using namespace std;

void solve(){
		multiset<ll> A, B;
		ll n, in, out;
		out = 0;
		cin >> n;

		for(int i = 0; i < n; i++){
				cin >> in;
				A.insert(in);
		}
		for(int i = 0; i < n; i++){
				cin >> in;
				B.insert(in);
		}	

		multiset<ll>::iterator ita, itb;
		ita = A.begin();
		itb = B.begin();
		while(ita != A.end()){
				if(*ita > *itb){
						out++;
						A.insert(*itb);
						ita--;
						A.erase((--A.end()));

				}
				ita++;
				itb++;
		}
		cout << out << '\n';

}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}
