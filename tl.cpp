/* Input (tl.inp): n, a[n], b[n]
   Output (tl.out): H = S - (a[max] - a[min]) l?n nh?t
=> C?c bu?c th?c hi?n:
1. S?p x?p d?y theo th? t? k?ch thu?c tang d?n
2. Ki?m tra xem H c? l?n nh?t kh?ng */
#include <bits/stdc++.h>

using namespace std;

long long n, a[100001], b[100001], h = 0;
void quickSort(long long a[], long long b[], long long l, long long r) {
	long long p = a[(l + r)/2];
	long long i = l, j = r;
	while (i < j) {
		while (a[i] < p) i++;
		while (a[j] > p) j--;
		if (i <= j) {
			long long temp = a[i];
			long long tempp = b[i];
			a[i] = a[j];
			b[i] = b[j];
			a[j] = temp;
			b[j] = tempp;
			i++;
			j--;
		}
	} if (i < r) quickSort(a, b, i, r);
	if (l < j) quickSort(a, b, l, j);
}
void solve() {
	quickSort(a, b, 0, n - 1);
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			long long k = (b[i] + b[j]) - abs(a[i] - a[j]);
			if (k > h) h = k;
		}
	} cout << h;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	} solve();
}
