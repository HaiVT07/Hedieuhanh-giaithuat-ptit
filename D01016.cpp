#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Tối ưu tốc độ đọc/ghi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    string fixed_name;
    cin >> fixed_name;

    // Loại bỏ tên đứng cuối ra khỏi danh sách chính để tiến hành sinh hoán vị phần còn lại
    vector<string> remaining;
    for (const string& s : names) {
        if (s != fixed_name) {
            remaining.push_back(s);
        }
    }

    // Sắp xếp theo thứ tự từ điển ban đầu để next_permutation hoạt động chính xác từ cấu hình nhỏ nhất
    sort(remaining.begin(), remaining.end());

    // Sinh và in các hoán vị theo thứ tự từ điển
    do {
        for (int i = 0; i < remaining.size(); i++) {
            cout << remaining[i] << (i == remaining.size() - 1 ? "" : " ");
        }
        cout << " " << fixed_name << "\n";
    } while (next_permutation(remaining.begin(), remaining.end()));

    return 0;
}