#include <bits/stdc++.h>
using namespace std;
#define cmax numeric_limits<streamsize>::max()
#define epsilon 0.001
const string tenLoai[8] = {"tam","tu","ngu","luc","that","bat","cuu","thap"};
void InputDouble(double& n)
{
    while (!(cin >> n))
    {
        cout << "Khong hop le. Thu lai: ";
        cin.clear();
        cin.ignore(cmax, '\n');
    }
}
void InputInt(int& n)
{
    while (!(cin >> n))
    {
        cout << "Khong hop le. Thu lai: ";
        cin.clear();
        cin.ignore(cmax, '\n');
    }
}

double Clamp01(const double& n){
    return max(-1.0, min(1.0, n));
}

bool isEqual(const double& a, const double& b){
    return (abs(a - b) < epsilon);
}

class cPoint
{
private:
    double x, y;

public:
    cPoint(){}
    cPoint(double _x, double _y): x(_x), y(_y){}

    string info() const
    {
        ostringstream oss;
        oss << "(" << x << "," << y << ")";
        return oss.str();
    }

    void Input()
    {
        cout << "Nhap x: "; InputDouble(x);
        cout << "Nhap y: "; InputDouble(y);
    }

    double DistanceTo(const cPoint& b) const{
        double dx = b.x - x;
        double dy = b.y - y;
        return sqrt(dx * dx + dy * dy);
    }
};

class cPolygon
{
private:
    vector<cPoint> p;

public:
    cPolygon(){}
    string info() const
    {
        ostringstream oss;
        for (int i = 0; i < p.size(); i++){
            oss << p[i].info() << "; ";
        }
        return oss.str();
    }
    int getSize() const {return p.size();}

    void Input()
    {
        int n;
        cout << "Nhap so diem: ";
        do {InputInt(n);}while (n < 3 || n > 10);
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap diem " << i + 1 << endl;
            cPoint temp;
            temp.Input();
            p.push_back(temp);
        }
    }
};

int main()
{
    cPolygon p;
    p.Input();
    cout << "Diem: " << p.info() << endl;
    cout << "Loai da giac: " << tenLoai[p.getSize()-3] << " giac." << endl;
    // Ko the tinh chu vi va dien tich khi mot hinh co 4 diem tro len va co it 1 diem nam trong 3 diem con lai thi co the ve ra nhieu hinh khac nhau.
    // Hoac la co cach nhung em qua ngu. mong thay thong cam.
}
