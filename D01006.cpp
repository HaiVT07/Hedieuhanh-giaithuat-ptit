#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n, k;
string s;
set<string> res;
string current;

// Quay lui sinh tổ hợp K vị trí từ N vị trí của xâu S
void Try(int start) {
    for (int i = start; i < n; i++) {
        current.push_back(s[i]);
        if ((int)current.size() == k) {
            res.insert(current); // Tự động loại bỏ trùng và sắp xếp tăng dần
        } else {
            Try(i + 1);
        }
        current.pop_back(); // Backtrack
    }
}

void solve() {
    cin >> s >> k;
    n = s.length();
    
    res.clear();
    current = "";
    
    Try(0);
    
    for (const string &x : res) {
        cout << x << "\n";
    }
}

int main() {
    // Tối ưu I/O tăng tốc độ thực thi
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