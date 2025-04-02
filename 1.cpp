#include <bits/stdc++.h>
using namespace std;
#define cmax numeric_limits<streamsize>::max()
#define epsilon 0.001
void InputPoint(double& n)
{
    while (!(cin >> n))
    {
        cout << "Khong hop le. Thu lai: ";
        cin.clear();
        cin.ignore(cmax, '\n');

    }
}

double Clamp01(const double& n)
{
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
        cout << "Nhap x: "; InputPoint(x);
        cout << "Nhap y: "; InputPoint(y);
    }

    double DistanceTo(const cPoint& b) const{
        double dx = b.x - x;
        double dy = b.y - y;
        return sqrt(dx * dx + dy * dy);
    }
};

class cTriangle
{
private:
    cPoint a, b, c;

public:
    cTriangle(){}
    cTriangle(cPoint _a, cPoint _b, cPoint _c): a(_a), b(_b), c(_c){}

    bool isCollinear(const cTriangle& t) const{
        return isEqual(GetArea(),0);
    }

    string info() const
    {
        ostringstream oss;
        oss << "A: " << a.info() << "; B: " << b.info() << "; C: " << c.info();
        return oss.str();
    }

    void Input()
    {
        cout << "Nhap A" << endl; a.Input();
        cout << "Nhap B" << endl; b.Input();
        cout << "Nhap C" << endl; c.Input();

        if (isCollinear(*this))
        {
            cout << "Khong hop le. Nhap lai." << endl;
            Input();
        }
    }

    double CalculateAngle(const double& a, const double& b, const double& c) const
    {
        return acos(Clamp01((c*c + a*a - b*b)/(2*c*a)));
    }

    string GetType() const
    {
        ostringstream temp;
        temp <<  "Tam giac ";
        // Edges
        double ab = a.DistanceTo(b);
        double ac = a.DistanceTo(c);
        double bc = b.DistanceTo(c);

        // Angles
        double angleA = CalculateAngle(ab, bc, ac);
        double angleB = CalculateAngle(ab, ac, bc);
        double angleC = M_PI - angleA - angleB;

        // Debug
        cout << ab << " " << ac << " " << bc << endl;
        cout << angleA << " " << angleB << " " << angleC << endl;

        if (isEqual(angleA, M_PI / 2) || isEqual(angleB, M_PI / 2) || isEqual(angleC, M_PI / 2)) temp << "vuong ";
        if (isEqual(ab, ac) || isEqual(ab, bc) || isEqual(ac, bc))
            if (isEqual(angleA, M_PI / 3) || isEqual(angleB, M_PI / 3) || isEqual(angleC, M_PI / 3)) temp << "deu ";
            else temp << "can ";

        return (temp.str() != "Tam giac ")? temp.str() : "tam giac thuong";
    }

    double GetPerimeter() const{
        return a.DistanceTo(b) + a.DistanceTo(c) + b.DistanceTo(c);
    }

    double GetArea() const
    {
        //if() return 0;
        double ab = a.DistanceTo(b);
        double ac = a.DistanceTo(c);
        double bc = b.DistanceTo(c);

        double s = (ab + ac + bc) / 2;
        double areaSquared = s*(s-ab)*(s-ac)*(s-bc);
        return (areaSquared < 0)? 0 : sqrt(areaSquared);
    }

    string AllInfo() const
    {
        ostringstream oss;
        oss << "Diem: " << info() << endl << "Dang: " << GetType() << endl;
        oss << "Chu vi: " << GetPerimeter() << endl << "Dien tich: " << GetArea() << endl;
        return oss.str();
    }
};

int main()
{
    cTriangle t1;
    t1.Input();
    cout << t1.AllInfo();
}
