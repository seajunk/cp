#include<iostream>
#include<vector>
#include<string>
#define ll long long
using namespace std;

void generateLucky(vector<ll>&v, string lucky){
		if(lucky.size() == 4) return;
		string temp;
		temp = lucky + "4";
		v.push_back(stoll(temp));
		generateLucky(v, temp);
		temp = lucky + "7";
		v.push_back(stoll(temp));
		generateLucky(v, temp);
}

int main(){
    ll n;
		cin >> n;
		vector<ll> v;
		generateLucky(v, "");

		for(int i = 0; i < v.size(); i++){
				if(n % v[i] == 0){cout << "YES" << '\n'; return 0;}
		}
		cout << "NO" << '\n';
}
