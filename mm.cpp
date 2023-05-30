/* Input: s
   Output: s? lu?ng s? nguy?n xu?t hi?n trong x?u
=> C?c bu?c th?c hi?n:
1. D?ng for ch?y cho t?i khi g?p s? (tru?ng h?p g?p '0' th? b? qua)
2. Ki?m tra xem s? d? xu?t hi?n trong x?u chua
3. In ra s? lu?ng s? nguy?n xu?t hi?n trong x?u */
#include <bits/stdc++.h>

using namespace std;

string s; int a[10001], countt = 0;
int toInterger(string s) {
	int k = 0;
	for (int i = 0; i < s.length(); i++) {
		k = k * 10 + (int(s[i]) - '0');
	} return k;
}
void solve() {
	string x = "";
	s = s + " ";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0' and x == "") continue;
		else if (s[i] >= '0' and s[i] <= '9') x += s[i];
		else {
			int k = toInterger(x);
			if (a[k] == 0 and k != 0) {
				countt++; 
				a[k] = 1;
			} x = "";
		}
	} cout << countt;
}
int main() {
	cin >> s;
	solve();
} 
