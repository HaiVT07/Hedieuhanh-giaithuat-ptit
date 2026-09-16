#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> current;

// Quay lui sinh tổ hợp chập K của N theo thứ tự ngược
void Try(int i) {
    int min_val = (i == 0) ? 1 : current[i - 1] + 1;
    int max_val = n - k + i + 1;

    // Duyệt ngược từ max_val về min_val để thu được thứ tự giảm dần
    for (int j = max_val; j >= min_val; j--) {
        current[i] = j;
        if (i == k - 1) {
            // In ra tổ hợp hiện tại
            for (int p = 0; p < k; p++) {
                cout << current[p] << (p == k - 1 ? "" : " ");
            }
            cout << "\n";
        } else {
            Try(i + 1);
        }
    }
}

void solve() {
    cin >> n >> k;
    current.resize(k);
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