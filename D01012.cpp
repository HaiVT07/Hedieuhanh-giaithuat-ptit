#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> a;
vector<bool> used;

// Quay lui sinh hoán vị N-1 vị trí đầu
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            used[j] = true;
            a[i] = j;

            if (i == n - 2) {
                // In ra hoán vị hoàn chỉnh với m ở vị trí cuối
                for (int p = 0; p < n; p++) {
                    cout << a[p] << (p == n - 1 ? "" : " ");
                }
                cout << "\n";
            } else {
                Try(i + 1);
            }

            used[j] = false; // Backtrack
        }
    }
}

int main() {
    // Tối ưu nhập xuất I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> n >> m) {
        a.resize(n);
        used.assign(n + 1, false);

        // Cố định m ở vị trí cuối cùng
        a[n - 1] = m;
        used[m] = true;

        if (n == 1) {
            // Trường hợp đặc biệt N = 1, M = 1
            cout << m << "\n";
        } else {
            Try(0);
        }
    }

    return 0;
}