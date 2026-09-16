#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> a;
vector<int> current;

// Quay lui sinh tổ hợp chập K của N phần tử
void Try(int start) {
    for (int i = start; i < n; i++) {
        current.push_back(a[i]);
        if ((int)current.size() == k) {
            // In ra dãy con K phần tử
            for (int j = 0; j < k; j++) {
                cout << current[j] << (j == k - 1 ? "" : " ");
            }
            cout << "\n";
        } else {
            Try(i + 1);
        }
        current.pop_back(); // Backtrack
    }
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sắp xếp mảng A để đảm bảo thứ tự tăng dần và từ điển
    sort(a.begin(), a.end());
    
    current.clear();
    Try(0);
}

int main() {
    // Tối ưu nhập xuất I/O
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