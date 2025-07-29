#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, count = 0;
    cin >> n >> m;

    unordered_set<string> s;
    string str;

    for (int i = 0; i < n; ++i) {
        cin >> str;
        s.insert(str);
    }

    for (int i = 0; i < m; ++i) {
        cin >> str;
        if (s.find(str) != s.end()) {
            ++count;
        }
    }

    cout << count << '\n';
    return 0;
}
