#include<iostream>
#include<string>
#define ll long long
using namespace std;

int main(){
		string s;
		cin >> s;
		for(int i = 0; i < s.size(); i++){
				ll num = s[i] - '0';
				if(i == 0 && num == 9) continue;
				char c = (num < 5 ? num + '0' : (9 - num) + '0');
				s[i] = c;
		}

		cout << s << '\n';



}

