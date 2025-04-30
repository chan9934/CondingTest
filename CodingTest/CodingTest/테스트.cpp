#include "CodingTest.h"

int N, cnt;
void solve(int N) {
	if (N == 0) return;
	cnt++;
	cout << "cnt : " << cnt << '\n';
	for (int i = 0; i < 3; i++) {
		solve(N - 1);
	}
	return;
}
int main() {
	cin >> N;
	solve(N);
	return 0;
}