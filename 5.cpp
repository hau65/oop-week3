#include <bits/stdc++.h>
using namespace std;

void Input(int& n, const int& lowerbound = numeric_limits<int>::min())
{
    while (!(cin >> n) || n < lowerbound)
    {
        cout << "Thu lai: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

class cDonThuc
{
private:
    int a, n;

public:
    cDonThuc(){}
    cDonThuc(const int& _a, const int& _n): a(_a), n(_n){}
    int getA() const {return a;}
    int getN() const {return n;}
    void setA(const int& _a) {a = _a;}

    string info() const
    {
        ostringstream oss;
        if (n == 0) oss << a;
        else if (n == 1) oss << a << "x";
        else oss << a << "x^" << n;
        return oss.str();
    }

    void InputDT(){
        cout << "Nhap he so: "; Input(a);
    }
    void SetN(const int& _n) {n = _n;}

    cDonThuc operator + (const cDonThuc& dt) const{
        return {a + dt.a, n};
    }
    cDonThuc operator - (const cDonThuc& dt) const{
        return {a - dt.a, n};
    }
    cDonThuc operator-() const{
        return {-a,n};
    }
};

class cDaThuc
{
private:
    vector<cDonThuc> dsDonThuc;

public:
    string info() const
    {
        ostringstream oss;
        for (int i = 0; i < dsDonThuc.size(); i++)
        {
            oss << dsDonThuc[i].info();
            if (i != dsDonThuc.size() - 1) oss << " + ";
        }
        return oss.str();
    }

    void InputDaT()
    {
        int n; Input(n);
        for (int i = 0; i <= n ; i++)
        {
            cDonThuc temp;
            temp.InputDT();
            temp.SetN(n - i);
            dsDonThuc.push_back(temp);
        }
    }

    cDaThuc operator + (const cDaThuc& dt) const
    {
        cDaThuc temp;
        const int mSize = dsDonThuc.size();
        const int ySize = dt.dsDonThuc.size();
        if (mSize >= ySize)
        {
            temp.dsDonThuc = dsDonThuc;
            for (int i = 0; i < ySize ; i++){
                temp.dsDonThuc[mSize-1-i] = temp.dsDonThuc[mSize-1-i] + dt.dsDonThuc[ySize-1-i];
            }
        }
        else
        {
            temp.dsDonThuc = dt.dsDonThuc;
            for (int i = 0; i < mSize; i++){
                temp.dsDonThuc[ySize-1-i] = temp.dsDonThuc[ySize-1-i] + dsDonThuc[mSize-1-i];
            }
        }

        return temp;
    }
    cDaThuc operator - (const cDaThuc& dt) const
    {
        cDaThuc temp;
        const int mSize = dsDonThuc.size();
        const int ySize = dt.dsDonThuc.size();
        if (mSize >= ySize)
        {
            temp.dsDonThuc = dsDonThuc;
            for (int i = 0; i < ySize ; i++){
                temp.dsDonThuc[mSize-1-i] = temp.dsDonThuc[mSize-1-i] - dt.dsDonThuc[ySize-1-i];
            }
        }
        else
        {
            temp.dsDonThuc = dt.dsDonThuc;
            for (int i = 0; i < ySize; i++){
                temp.dsDonThuc[i] = -temp.dsDonThuc[i];
            }
            for (int i = 0; i < mSize; i++){
                temp.dsDonThuc[ySize-1-i] = dsDonThuc[mSize-1-i] + temp.dsDonThuc[ySize-1-i];
            }
        }

        return temp;
    }

    int TinhDaThuc(const int& x) const
    {
        int sum = 0;
        for (int i = 0; i < dsDonThuc.size(); i++){
            sum += dsDonThuc[i].getA() * pow(x, dsDonThuc[i].getN());
        }
        return sum;
    }
};

int main()
{
    cDaThuc dt1, dt2;
    int x;
    cout << "Nhap x: "; Input(x);

    cout << "Nhap so bac da thuc 1: "; dt1.InputDaT();
    cout << "Nhap so bac da thuc 2: "; dt2.InputDaT();
    cout << dt1.info() << endl << dt2.info() << endl;
    cout << "DT1 + DT2: " << (dt1 + dt2).info() << endl;
    cout << "DT1 - DT2: " << (dt1 - dt2).info() << endl;
    cout << "DT1(" << x << "): "<< dt1.TinhDaThuc(x) << endl;
    cout << "DT2(" << x << "): " <<dt2.TinhDaThuc(x) << endl;
}
