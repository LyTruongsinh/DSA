// Cho n thành phố (đánh số từ 1 đến n) và m con đường nối các thành phố. Mức độ tắc nghẽn giao thông giữa hai thành phố
// u, v được cho bởi D[u, v]. Bạn có hai nhiệm vụ:

// a. Viết một chương trình để tìm một đường đi từ điểm xuất phát s đến điểm kết thúc e sao cho tổng mức độ tắc nghẽn
// trên đường đi là nhỏ nhất. b. Viết một chương trình để tìm đường đi có mức độ tắc nghẽn nhỏ nhất giữa tất cả các cặp
// thành phố.
#include <iostream>
#include <limits>
#include <vector>

using namespace std;
class Graph
{
  private:
    int SoluongThanhPho;
    int SoluongDuong;
    vector<vector<int>> D; // Ma trận trọng số
  public:
    void InputGraph();
    void FloydWarshall();
    void PrintShortestPath(int s, int e);
};
void Graph::InputGraph()
{
    cout << "Nhap so luong thanh pho: ";
    cin >> SoluongThanhPho;
    cout << "Nhap so luong duong: ";
    cin >> SoluongDuong;
    D.resize(SoluongThanhPho + 1, vector<int>(SoluongThanhPho + 1, numeric_limits<int>::max()));
    for (int i = 1; i <= SoluongThanhPho; ++i)
        D[i][i] = 0;
    cout << "Nhap cac duong di (u, v, do tac nghen):" << endl;
    for (int i = 0; i < SoluongDuong; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        D[u][v] = w;
    }
}
void Graph::FloydWarshall()
{
    for (int k = 1; k <= SoluongThanhPho; ++k)
    {
        for (int i = 1; i <= SoluongThanhPho; ++i)
        {
            for (int j = 1; j <= SoluongThanhPho; ++j)
            {
                if (D[i][k] != numeric_limits<int>::max() && D[k][j] != numeric_limits<int>::max())
                {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }
}
void Graph::PrintShortestPath(int s, int e)
{
    if (D[s][e] == numeric_limits<int>::max())
    {
        cout << "Khong co duong di tu thanh pho " << s << " den thanh pho " << e << endl;
    }
    else
    {
        cout << "Duong di ngan nhat tu thanh pho " << s << " den thanh pho " << e << " co do tac nghen la: " << D[s][e] << endl;
    }
}
int main()
{
    Graph g;
    g.InputGraph();
    g.FloydWarshall();
    
    int s, e;
    cout << "Nhap diem xuat phat (s) va diem ket thuc (e): ";
    cin >> s >> e;
    g.PrintShortestPath(s, e);
    
    cout << "Muc do tac nghen nho nhat giua tat ca cac cap thanh pho:" << endl;
    for (int i = 1; i <= g.SoluongThanhPho; ++i)
    {
        for (int j = 1; j <= g.SoluongThanhPho; ++j)
        {
            if (i != j)
            {
                g.PrintShortestPath(i, j);
            }
        }
    }
    
    return 0;
}