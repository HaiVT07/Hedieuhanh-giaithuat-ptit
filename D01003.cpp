#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string s;
string current;

void Try(int start) {
    for (int i = start; i < n; i++) {
        current.push_back(s[i]);
        cout << current << " ";
        Try(i + 1);
        current.pop_back(); // Quay lui (backtrack)
    }
}

void solve() {
    cin >> n >> s;
    sort(s.begin(), s.end()); // Sắp xếp xâu S để sinh theo thứ tự từ điển
    current = "";
    Try(0);
    cout << "\n";
}

int main() {
    // Tối ưu I/O để chạy nhanh hơn trong giới hạn 1s
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}