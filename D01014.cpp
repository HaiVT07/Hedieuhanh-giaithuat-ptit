#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> a;

// Quay lui sinh tổ hợp lặp K phần tử từ N số
void Try(int i) {
    int start = (i == 0) ? 1 : a[i - 1]; // Phần tử sau >= phần tử trước
    for (int j = start; j <= n; j++) {
        a[i] = j;
        if (i == k - 1) {
            // In bộ K số thu được
            for (int p = 0; p < k; p++) {
                cout << a[p] << (p == k - 1 ? "" : " ");
            }
            cout << "\n";
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    // Tối ưu nhập xuất I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> n >> k) {
        a.resize(k);
        Try(0);
    }

    return 0;
}