#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
int a[20];
int idx = 0;
set<int> fib_set;

// Sinh trước các số Fibonacci để kiểm tra nhanh
void initFibonacci() {
    int f1 = 1, f2 = 1;
    fib_set.insert(1);
    while (f2 <= 32768) {
        int f3 = f1 + f2;
        fib_set.insert(f3);
        f1 = f2;
        f2 = f3;
    }
}

// Quay lui sinh xâu nhị phân độ dài N theo thứ tự từ điển
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == N - 1) {
            idx++; // Tăng số thứ tự của xâu nhị phân
            if (fib_set.count(idx)) {
                cout << idx << ": ";
                for (int m = 0; m < N; m++) {
                    cout << a[m] << (m == N - 1 ? "" : " ");
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

    initFibonacci();

    if (cin >> N) {
        Try(0);
    }
    return 0;
}