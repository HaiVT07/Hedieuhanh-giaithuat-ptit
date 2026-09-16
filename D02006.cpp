#include <stdio.h>
#include <stdlib.h>

// Cấu trúc lưu thông tin một công việc
typedef struct {
    int start;
    int end;
} Job;

// Mảng tĩnh toàn cục tối đa 100,000 phần tử để tránh tràn bộ nhớ Stack
#define MAX_N 100005
Job jobs[MAX_N];

// Hàm so sánh dùng cho qsort: sắp xếp tăng dần theo thời gian kết thúc (end)
int compareJobs(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    if (jobA->end != jobB->end) {
        return jobA->end - jobB->end;
    }
    return jobA->start - jobB->start;
}

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jobs[i].start, &jobs[i].end);
    }
    
    // Sắp xếp danh sách công việc theo thời gian kết thúc tăng dần
    qsort(jobs, n, sizeof(Job), compareJobs);
    
    int count = 0;
    int last_end_time = -1;
    
    // Thuật toán tham lam chọn công việc
    for (int i = 0; i < n; i++) {
        // Nếu thời gian bắt đầu công việc hiện tại >= thời điểm kết thúc công việc trước đó đã chọn
        if (jobs[i].start >= last_end_time) {
            count++;
            last_end_time = jobs[i].end; // Cập nhật mốc kết thúc mới
        }
    }
    
    printf("%d\n", n > 0 ? count : 0);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}