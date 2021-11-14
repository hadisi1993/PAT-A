#include <iostream>
#include<string>
using namespace std;
typedef long long LL;
bool isPrime(LL num){
	for (int i = 2; i*i <= num; i++){
		if (num%i == 0) return false;
	}
	return true;
}
int k, l;
int main()
{
	cin >> l >> k;
	string num;
	cin >> num;
	for (int i = 0; i + k - 1<num.size(); i++){
		string tmp = num.substr(i, k);
		if (isPrime(stoi(tmp))){
			cout << tmp << endl;
			return 0;
		}
	}
	cout << "404" << endl;
	return 0;
}
