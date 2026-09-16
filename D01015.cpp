#include <iostream>
#include <vector>

using namespace std;

const int MAX_VAL = 100000;
bool is_prime[MAX_VAL + 1];

int N, K;
int a[25];
int idx = 0;

// Sàng Eratosthenes chuẩn bị trước các số nguyên tố
void sieve() {
    fill(is_prime, is_prime + MAX_VAL + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= MAX_VAL; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX_VAL; i += p)
                is_prime[i] = false;
        }
    }
}

// Quay lui sinh tổ hợp
void Try(int i) {
    for (int j = a[i - 1] + 1; j <= N - K + i; j++) {
        a[i] = j;
        if (i == K) {
            idx++; // Thứ tự hiện tại của tổ hợp
            if (is_prime[idx]) {
                cout << idx << ": ";
                for (int m = 1; m <= K; m++) {
                    cout << a[m] << (m == K ? "" : " ");
                }
                cout << "\n"; // Dùng \n thay cho endl để tối ưu tốc độ in
            }
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    // Tối ưu nhập/xuất dữ liệu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    if (cin >> N >> K) {
        a[0] = 0;
        Try(1);
    }
    return 0;
}