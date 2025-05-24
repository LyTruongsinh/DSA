#include <iostream>
#include <vector>

using namespace std;

// Cấu trúc điểm
struct Point
{
    float x, y;
    Point(float x = 0, float y = 0) : x(x), y(y) {}
};

// Hình chữ nhật dùng để kiểm tra vùng
struct Rect
{
    float x, y; // Tọa độ tâm
    float w, h; // Bán kính theo chiều ngang và dọc

    Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}

    bool contains(const Point &point) const
    {
        return (point.x >= x - w && point.x <= x + w && point.y >= y - h && point.y <= y + h);
    }

    bool intersects(const Rect &range) const
    {
        return !(range.x - range.w > x + w || range.x + range.w < x - w || range.y - range.h > y + h ||
                 range.y + range.h < y - h);
    }
};

// QuadTree node
class QuadTree
{
  private:
    static const int CAPACITY = 4;
    Rect boundary;
    vector<Point> points;
    bool divided = false;

    QuadTree *northeast = nullptr;
    QuadTree *northwest = nullptr;
    QuadTree *southeast = nullptr;
    QuadTree *southwest = nullptr;

  public:
    QuadTree(const Rect &boundary) : boundary(boundary) {}

    ~QuadTree()
    {
        delete northeast;
        delete northwest;
        delete southeast;
        delete southwest;
    }

    void subdivide()
    {
        float x = boundary.x;
        float y = boundary.y;
        float w = boundary.w / 2;
        float h = boundary.h / 2;

        northeast = new QuadTree(Rect(x + w, y - h, w, h));
        northwest = new QuadTree(Rect(x - w, y - h, w, h));
        southeast = new QuadTree(Rect(x + w, y + h, w, h));
        southwest = new QuadTree(Rect(x - w, y + h, w, h));
        divided = true;
    }

    bool insert(const Point &point)
    {
        if (!boundary.contains(point))
        {
            return false;
        }

        if (points.size() < CAPACITY)
        {
            points.push_back(point);
            return true;
        }
        else
        {
            if (!divided)
            {
                subdivide();
            }
            if (northeast->insert(point))
                return true;
            if (northwest->insert(point))
                return true;
            if (southeast->insert(point))
                return true;
            if (southwest->insert(point))
                return true;
        }

        return false;
    }

    void query(const Rect &range, vector<Point> &found) const
    {
        if (!boundary.intersects(range))
        {
            return;
        }
        else
        {
            for (const Point &p : points)
            {
                if (range.contains(p))
                {
                    found.push_back(p);
                }
            }
            if (divided)
            {
                northeast->query(range, found);
                northwest->query(range, found);
                southeast->query(range, found);
                southwest->query(range, found);
            }
        }
    }
};

// Demo
int main()
{
    Rect boundary(0, 0, 10, 10);
    QuadTree qt(boundary);

    qt.insert(Point(1, 1));
    qt.insert(Point(-2, -3));
    qt.insert(Point(4, 5));
    qt.insert(Point(-1, 2));
    qt.insert(Point(6, 6)); // sẽ chia vùng vì vượt CAPACITY

    Rect range(0, 0, 5, 5);
    vector<Point> found;
    qt.query(range, found);

    cout << "Các điểm nằm trong vùng tìm kiếm:\n";
    for (auto &p : found)
    {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
