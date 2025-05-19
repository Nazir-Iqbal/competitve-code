// A modular inverse based solution to
// compute nCr % p
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+1;
int p = 1e9+7;
unsigned long long fac[N];
void pre(){
	fac[0] = 1;
	for (int i = 1; i <N; i++)
		fac[i] = (fac[i - 1] * i) % p;
}

unsigned long long power(unsigned long long x, int y){
	unsigned long long res = 1; // Initialize result

	x = x % p;

	while (y > 0) {
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n){
	return power(n, p - 2);
}

unsigned long long nCrModPFermat(unsigned long long n,int r){
	// If n<r, then nCr should return 0
	if (n < r)
		return 0;
	// Base case
	if (r == 0)
		return 1;

	return (fac[n] * modInverse(fac[r]) % p*modInverse(fac[n - r]) % p)% p;
}

// Driver program
int main(){
    pre();
	int n = 10, r = 2, p = 13;
	cout << "Value of nCr % p is "
		<< nCrModPFermat(n, r);
	return 0;
}
