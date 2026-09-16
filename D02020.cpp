#include <stdio.h>

#define MAX_N 1000005

// Khai báo mảng heap và biến kích thước toàn cục
long long heap[MAX_N];
int heap_size;

// Hàm hoán đổi giá trị
void swap(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

// Vun đống xuống dưới (sắp xếp lại phần tử từ trên xuống)
void heapify_down(int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // So sánh với nút con trái
    if (left <= heap_size && heap[left] < heap[smallest])
        smallest = left;
    // So sánh với nút con phải
    if (right <= heap_size && heap[right] < heap[smallest])
        smallest = right;

    // Nếu nút hiện tại không phải nhỏ nhất, đổi chỗ và đệ quy tiếp
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify_down(smallest);
    }
}

// Hàm đẩy một phần tử mới vào đống
void push(long long val) {
    heap[++heap_size] = val;
    int i = heap_size;
    // Vun đống lên trên
    while (i > 1 && heap[i / 2] > heap[i]) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

// Hàm lấy và xóa phần tử nhỏ nhất khỏi đống
long long pop() {
    long long min_val = heap[1];
    heap[1] = heap[heap_size--]; // Đưa phần tử cuối lên đầu
    heapify_down(1);             // Vun đống xuống
    return min_val;
}

// Hàm xây dựng đống (Min Heap) tối ưu từ mảng
void build_heap() {
    for (int i = heap_size / 2; i >= 1; i--) {
        heapify_down(i);
    }
}

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;

    heap_size = n;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &heap[i]);
    }

    // Xây dựng Min Heap trong thời gian O(N)
    build_heap();

    long long total_cost = 0;

    // Lặp cho đến khi chỉ còn 1 sợi dây
    while (heap_size > 1) {
        // Lấy 2 sợi ngắn nhất
        long long first = pop();
        long long second = pop();
        
        // Chi phí nối 2 sợi
        long long current_cost = first + second;
        total_cost += current_cost;
        
        // Bỏ sợi dây mới nối vào lại đống
        push(current_cost);
    }

    // In ra tổng chi phí
    printf("%lld\n", total_cost);
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}