#include <stdio.h>
#include <stdlib.h>

// Cấu trúc lưu thông tin đoạn thẳng trên trục Ox
typedef struct {
    int start;
    int end;
} Segment;

// Khai báo mảng tĩnh toàn cục tối đa 100,000 phần tử để tránh tràn Stack
#define MAX_N 100005
Segment segments[MAX_N];

// Hàm so sánh dùng cho qsort: sắp xếp tăng dần theo điểm kết thúc (end)
int compareSegments(const void *a, const void *b) {
    Segment *segA = (Segment *)a;
    Segment *segB = (Segment *)b;
    if (segA->end != segB->end) {
        return segA->end - segB->end;
    }
    return segA->start - segB->start;
}

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &segments[i].start, &segments[i].end);
    }
    
    // Sắp xếp các đoạn thẳng theo điểm kết thúc tăng dần
    qsort(segments, n, sizeof(Segment), compareSegments);
    
    int count = 0;
    int last_end_point = -1;
    
    // Thuật toán tham lam chọn đoạn thẳng
    for (int i = 0; i < n; i++) {
        // Nếu điểm bắt đầu của đoạn hiện tại >= điểm kết thúc của đoạn trước đó đã chọn
        if (segments[i].start >= last_end_point) {
            count++;
            last_end_point = segments[i].end; // Cập nhật mốc kết thúc mới
        }
    }
    
    printf("%d\n", count);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}