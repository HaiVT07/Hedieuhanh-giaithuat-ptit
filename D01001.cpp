#include <iostream>
using namespace std;

int n;
int a[20];

// Sinh n-1 bit đầu tiên, bit thứ n tự động tính toán
void generate(int pos, int sum_ones) {
    if (pos == n - 1) {
        // In n-1 bit đầu
        for (int i = 0; i < n - 1; i++) {
            cout << a[i] << " ";
        }
        // Bit cuối cùng phụ thuộc vào tổng số bit 1 trước đó
        cout << (sum_ones % 2) << "\n";
        return;
    }

    // Ưu tiên chọn 0 trước 1 để đảm bảo thứ tự từ điển
    a[pos] = 0;
    generate(pos + 1, sum_ones);

    a[pos] = 1;
    generate(pos + 1, sum_ones + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> n) {
        generate(0, 0);
    }
    return 0;
}