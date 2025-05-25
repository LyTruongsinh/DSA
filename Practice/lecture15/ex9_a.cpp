// Cho n thành phố (đánh số từ 1 đến n) và m con đường nối các thành phố. Mức độ tắc nghẽn giao thông giữa hai thành phố u, v được cho bởi D[u, v]. Bạn có hai nhiệm vụ:

// a. Viết một chương trình để tìm một đường đi từ điểm xuất phát s đến điểm kết thúc e sao cho tổng mức độ tắc nghẽn trên đường đi là nhỏ nhất.
// b. Viết một chương trình để tìm đường đi có mức độ tắc nghẽn nhỏ nhất giữa tất cả các cặp thành phố.
#include <iostream>
#include <vector>
using namespace std;
class Graph {
private:
    int Sothanhpho;
    int Soduong;
    int Start;
    int End;
    vector<pair<int, int>> adj[1001];
    vector<long long> dist;
    bool marked[1001];
    vector<int> previous;
public:
    Graph();
    void InputGraph();
    void Dijkstra();
    void FloydWarshall();
};
Graph::Graph() {
    Sothanhpho = 0;
    Soduong = 0;
}
void Graph::InputGraph() {
    cout << "Nhap so thanh pho: ";
    cin >> Sothanhpho;
    cout << "Nhap so duong: ";
    cin >> Soduong;
    cout << "Nhap diem bat dau: ";
    cin >> Start;
    cout << "Nhap diem ket thuc: ";
    cin >> End;

    dist.assign(Sothanhpho + 1, 1e18);
    previous.assign(Sothanhpho + 1, -1);
    memset(marked, false, sizeof(marked));

    cout << "Nhap cac duong di (u v w):\n";
    for (int i = 0; i < Soduong; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u); // Nếu đường đi là hai chiều
        // Cần thêm trọng số vào đây nếu cần
    }
}
void Graph::Dijkstra() {
    marked[Start] = true;
    if (dist[Start] == 1e18) dist[Start] = 0;
    

    if (Start == End) 
    {
        cout << "Da den diem dich: " << End << endl;
        cout << "Khoang cach tu diem bat dau den " << End << " la: " << dist[End] << endl;

        vector<int> path;
        for (int v = End; v != -1; v = previous[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        cout << "Duong di: ";
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
        return;
    }
    // Cập nhật khoảng cách từ Start đến các đỉnh kề
    for(auto v : adj[Start])
    {
        int v = x.first;
        int w = x.second;
        if(dist[Start] + w < dist[v]) {
            dist[v] = dist[Start] + w;
            previous[v] = Start; // Lưu đường đi
        }
    }
    // Tìm đỉnh tiếp theo có khoảng cách nhỏ nhất
    long long minDist = 1e18;
    int next = -1;
    for(int i = 1; i <= Sothanhpho;i++)
    {
        if(!marked[i] && dist[i] < minDist) {
            minDist = dist[i];
            next = i;
        }
    }
    if(next != -1) 
    {
        Start = next;
        Dijkstra();
    }
}
int main() {
    Graph g;
    g.InputGraph();
    g.Dijkstra();
    return 0;
}