#include<iostream>
#include<ostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

template<typename DataType>
class Point {
private:
    DataType x;
    DataType y;
    DataType z;
public:
    explicit Point(DataType x = 0, DataType y = 0, DataType z = 0): x(x), y(y), z(z) {}

    ~Point() = default;

    Point(const Point& obj) {
        x = obj.x;
        y = obj.y;
        z = obj.z;
    }

    bool operator==(const Point& obj) const{
        if (x == obj.x && y == obj.y && z == obj.z) {
            return true;
        } else {
            return false;
        }
    }

    Point& operator=(const Point& obj) {
        x = obj.x;
        y = obj.y;
        z = obj.z;
        return *this;
    }

    friend Point operator+(const Point& a, const Point& b) {
        return Point(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    friend Point operator-(const Point& a, const Point& b) {
        return Point(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    friend DataType dot(const Point& a, const Point& b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    friend Point cross(const Point& a, const Point& b) {
        return Point(a.y * b.z - a.z * b.y, a.z * b.x - a.x - b.z, a.x * b.y - a.y * b.x);
    }

    double norm() { // 不管是什么类型的点，范数都为 double 型
        return sqrt(x * x + y * y + z * z);
    }

    friend ostream& operator<<(ostream& os, const Point& obj) {
        os << "Point(" << obj.x << ", " << obj.y << ", " << obj.z << ")";
        return os;
    }

    // 是否四点共面
    friend bool FourPointInASurface(const Point& a, const Point& b, const Point& c, const Point& d) {
        if (dot(cross(a - b, a - c), a - d) == 0) {
            return true;
        } else {
            return false;
        }
    }
};

vector<Point<double> > v;

void test() // MyTestFunction
{
    cout << "My Test Begin..." << endl;
    v.emplace_back(1, 0, 0);
    v.emplace_back(2, 0, 0);
    v.emplace_back(3, 0, 0);
    v.emplace_back(-1, 3, 0);
    cout << dot(v[0], v[1]) << endl;

    cout << "Is Four Points In a Plane?:";
    cout << FourPointInASurface(v[0], v[1], v[2], v[3]) << endl;
    // 查找
    auto iter = find(v.begin(), v.end(), Point<double>(2, 0, 0));
    if (iter != v.end()) {
        cout << "Find it: " << *iter << endl;
    } else {
        cout << "Not Found" << endl;
    }
    cout << "My Test End." << endl;
}

int main()
{
    test();
    return 0;
}