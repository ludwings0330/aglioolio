#include<iostream>
using namespace std;

int M;

int main() {
	cin >> M;


	long long 
	mul = 0;
	for (long long i = 0; i <= 100000000; i = i+5) {
		
		
		if (i % 5 == 0 && i!=0) {
			mul++;
		}
		if (mul % 5 == 0 && mul!=0) {
			mul++;
		}

		if (mul == M) {
			cout << i;
			break;
		}
		if (mul> M) {
			cout << "-1";
			break;
		}
	}



}


