#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 1001;

struct Node {
    int x;
    Node* next;
};

int n, m;             // Số đỉnh và số cạnh
Node* A[MAX];         // Danh sách kề bằng linked list
bool visited[MAX];    // Mảng đánh dấu dùng cho DFS
vector<int> path;
// Nhập dữ liệu đồ thị
void Input() {
    cin >> n >> m;

    // Khởi tạo tất cả các phần tử là nullptr
    for (int i = 1; i <= n; i++) {
        A[i] = nullptr;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Thêm v vào danh sách kề của u
        Node* temp1 = new Node();
        temp1->x = v;
        temp1->next = A[u];
        A[u] = temp1;

        // Thêm u vào danh sách kề của v (vì là đồ thị vô hướng)
        Node* temp2 = new Node();
        temp2->x = u;
        temp2->next = A[v];
        A[v] = temp2;
    }

    memset(visited, false, sizeof(visited)); // Reset mảng visited
}

// Duyệt DFS từ đỉnh s
void DFS(int s) {
    visited[s] = true;
    path.push_back(s);

    // In đường đi từ s đến u
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << (i < path.size() - 1 ? " -> " : "\n");
    }

    Node* temp = A[s];
    while (temp != nullptr) {
        int v = temp->x;
        if (!visited[v]) {
            DFS(v);
        }
        temp = temp->next;
    }
    path.pop_back();
}

// Duyệt BFS từ đỉnh s
void BFS(int s) {
    bool visited_bfs[MAX] = {false};
    queue<int> q;

    q.push(s);
    visited_bfs[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        Node* temp = A[u];
        while (temp != nullptr) {
            int v = temp->x;
            if (!visited_bfs[v]) {
                q.push(v);
                visited_bfs[v] = true;
            }
            temp = temp->next;
        }
    }
}

// Hàm in danh sách kề (để kiểm tra)
void Print() {
    for (int i = 1; i <= n; i++) {
        cout << "Đỉnh " << i << ": ";
        Node* p = A[i];
        while (p != nullptr) {
            cout << p->x << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main() {
    Input();
    Print();

    int start;
    cout << "Nhap dinh bat dau DFS/BFS: ";
    cin >> start;

    cout << "DFS: ";
    DFS(start);
    cout << endl;

    cout << "BFS: ";
    BFS(start);
    cout << endl;

    return 0;
}
