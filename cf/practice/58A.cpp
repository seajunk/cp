#include<iostream>
#include<string>
using namespace std;


int main(){
		string s;
		string hello = "hello";
		int c = 0;
		cin >> s;

		for(int i = 0; i < s.size(); i++){
				if(s[i] == hello[c]) c++;
		}
		

		if(c == 5) cout << "YES" << '\n';
		else cout << "NO" << '\n';

}
