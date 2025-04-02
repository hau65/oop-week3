#include <bits/stdc++.h>
using namespace std;
#define epsilon 0.001

void InputNum(double& n)
{
    while (!(cin >> n))
    {
        cout << "Khong hop le. Thu lai: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}
void InputNum(int& n, const int& minN)
{
    while (!(cin >> n) || n < minN)
    {
        cout << "Khong hop le. Thu lai: ";
        cin.clear();
        cin.ignore(1000, '\n');
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

    double getX() const {return x;}
    double getY() const {return y;}

    string info() const
    {
        ostringstream oss;
        oss << "(" << x << "," << y << ")";
        return oss.str();
    }

    void Input()
    {
        cout << "Nhap x: "; InputNum(x);
        cout << "Nhap y: "; InputNum(y);
    }

    double DistanceTo(const cPoint& b) const{
        double dx = b.x - x;
        double dy = b.y - y;
        return sqrt(dx*dx + dy*dy);
    }
};


class cDaGiac
{
private:
    vector<cPoint> points;

public:
    cDaGiac(){}
    cDaGiac(const vector<cPoint>& vP): points(vP){}

    string info() const
    {
        ostringstream oss;
        for (int i = 0; i < points.size(); i++){
            oss << "(" << points[i].getX() << "," << points[i].getY() << "); ";
        }
        return oss.str();
    }

    void Input()
    {
        int n;
        cout << "Nhap so diem: "; InputNum(n, 3);
        for (int i = 0; i < n; i++)
        {
            cPoint temp;
            temp.Input();
            points.push_back(temp);
        }
    }

    double GetPerimeter() const
    {
        vector<double> edges;
        for (int i = 0; i < points.size(); i++)
        {

        }
    }
};

int main()
{
    cDaGiac dg;
    dg.Input();
    cout << "Diem: " << dg.info();
}
