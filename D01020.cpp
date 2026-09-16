#include <iostream>
#include <vector>

using namespace std;

int N, K;
int a[25];
long long idx = 0; // Đếm số thứ tự tổ hợp (0-based)

// Hàm quay lui sinh tổ hợp chập K của N theo thứ tự từ điển
void Try(int i) {
    for (int j = a[i - 1] + 1; j <= N - K + i; j++) {
        a[i] = j;
        if (i == K) {
            // Kiểm tra nếu chỉ số thứ tự chia hết cho K
            if (idx % K == 0) {
                for (int m = 1; m <= K; m++) {
                    cout << a[m] << (m == K ? "" : " ");
                }
                cout << "\n";
            }
            idx++;
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    // Tối ưu tốc độ đọc/ghi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> N >> K) {
        a[0] = 0;
        Try(1);
    }
    return 0;
}