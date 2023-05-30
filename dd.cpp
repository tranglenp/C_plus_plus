/* Input: n, a[n]
   Output: s? lu?ng d?y con d?p c?a d?y 
=> C?c bu?c th?c hi?n:
1. S?p x?p d?y theo th? t? tang d?n
2. X?a c?c ph?n t? tr?ng nhau trong d?y 
3. T?m ra c?c x?u con c?a d?y */
#include <bits/stdc++.h>

using namespace std;

long long n, a[100001], d[100001], sum;
void intro() {
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			for (int j = i + 1; j < n; j++) a[j] = a[j + 1];
			n--;
		} 
	}
}
void solve() {
	intro();
	long long k = 0;
	for (int i = 0; i < n - 1; i++) {
		k = k * 10 + a[i];
		for (int j = i + 1; j < n; j++) {
			k = k * 10 + a[j];
			if (d[k] == 0) {
				sum++;
				d[k] = 1;
			} 
		}
	} cout << sum; 
}
int main() {
	cin >> n;
	sum = n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	} solve();
}
