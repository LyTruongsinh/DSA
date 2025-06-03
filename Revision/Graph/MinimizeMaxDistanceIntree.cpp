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
int dist[MAX];    // Mảng lưu khoảng cách từ đỉnh bắt đầu

void Input() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        A[i] = nullptr;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        Node* temp1 = new Node();
        temp1->x = v;
        temp1->next = A[u];
        A[u] = temp1;

        Node* temp2 = new Node();
        temp2->x = u;
        temp2->next = A[v];
        A[v] = temp2;
    }
}

int maxdist() {
    int maxdist = -1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > maxdist) {
            maxdist = dist[i];
        }
    }
    return maxdist;
}

void DFS(int s) {
    visited[s] = true;
    Node* temp = A[s];
    while (temp != nullptr) {
        int v = temp->x;
        if (!visited[v]) {
            dist[v] = dist[s] + 1;
            DFS(v);
        }
        temp = temp->next;
    }
}

void MinimizeMaxdistInTree() {
    int Mindumax = 1e9;
    vector<int> result;

    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        for (int j = 1; j <= n; j++) dist[j] = 0;

        DFS(i);
        int dmax = maxdist();

        if (dmax < Mindumax) {
            Mindumax = dmax;
            result.clear();
            result.push_back(i);
        } else if (dmax == Mindumax) {
            result.push_back(i);
        }
    }

    cout << "Cac dinh u thoa man dmax(u) nho nhat la: ";
    for (int u : result) {
        cout << u << " ";
    }
    cout << endl;
}

int main() {
    Input();
    MinimizeMaxdistInTree();
    return 0;
}
