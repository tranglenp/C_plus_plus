/* Input: n, a[n], k
   Output: ph?m vi ng?n nh?t c?a k
=> C?c bu?c th?c hi?n: 
1. S?p x?p d?y tang d?n theo ph?m vi ph?t s?ng
2. Vi?t h?m ki?m tra kho?ng c?ch x c? d? ph?t s?ng tr?n ph?m vi k kh?ng:
- ??t v? tr? tr?m ph?t s?ng d?u ti?n l?: a[1] + x;
- Ki?m tra xem a[i] > t + x hay kh?ng: N?u kh?ng, th?m m?t tr?m ph?t s?ng: a[i] + x
- Ki?m tra xem s? tr?m ph?t s?ng t c? <= k kh?ng
3. Duy?t d?y theo t?m ki?m nh? ph?n, t?m x nh? nh?t th?a m?n h?m tr?n */
#include <bits/stdc++.h>

using namespace std;

long long n, a[100001], k;
bool check(long long x) {
	long long t = a[0] + x, d = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] > t + x) {
			d++;
			t = a[i] + x;
		}
	} t = a[1] + x;
	long long e = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] > t + x) {
			e++;
			t = a[i] + x;
		}
	} return min(d, e) <= k;
}
void solve(long long l, long long r) {
	long long res = 0;
	while (l <= r) {
		long long mid = (l + r)/2;
		if (check(mid) == true) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	} cout << res;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	} cin >> k;
	sort(a, a + n);
	a[n] = 1000000 + a[0];
	solve(0, 1000000);
}
