#include <iostream>
#include <vector>

using namespace std;

int N;
char a[15];
int idx = 0;
char chars[] = {'A', 'B', 'C'};

// Quay lui sinh xâu tam phân độ dài N theo thứ tự từ điển
void Try(int i) {
    for (int j = 0; j < 3; j++) {
        a[i] = chars[j];
        if (i == N - 1) {
            idx++; // Tăng số thứ tự của xâu tam phân
            if (idx % 2 != 0) { // Lấy các xâu có thứ tự lẻ
                cout << idx << ": ";
                for (int m = 0; m < N; m++) {
                    cout << a[m];
                }
                cout << "\n";
            }
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    // Tối ưu tốc độ nhập/xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> N) {
        Try(0);
    }
    return 0;
}