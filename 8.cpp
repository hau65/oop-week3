#include <bits/stdc++.h>
using namespace std;
void StrictInput(int& n)
{
    while (!(cin >> n))
    {
        cout << "Thu lai: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

class cNhanVienSX
{
private:
    string id, name;
    int yob, numSP, price;

public:
    cNhanVienSX(){}
    int getSalary() const {return numSP * price;}
    int getYear() const {return yob;}
    string getName() const {return name;}
    string info() const
    {
        ostringstream oss;
        oss << "Ma: " << id << endl;
        oss << "Ten: " << name << endl;
        oss << "Nam sinh: " << yob << endl;
        oss << "So SP: " << numSP << endl;
        oss << "Gia SP: " << price << endl;
        return oss.str();
    }

    void Input()
    {
        cout << "Nhap ma: "; cin >> id;
        cout << "Nhap ten: "; cin >> name;
        cout << "Nhap nam sinh: "; StrictInput(yob);
        cout << "Nhap so san pham da gia cong: "; StrictInput(numSP);
        cout << "Nhap gia san pham: "; StrictInput(price);
    }
};

class cListNV
{
private:
    vector<cNhanVienSX> l;

public:
    cListNV(){}
    string info() const
    {
        ostringstream oss;
        for (int i = 0; i < l.size(); i++){
            oss << l[i].info() << endl;
        }
        return oss.str();
    }
    void Input()
    {
        int n;
        cout << "Nhap so nhan vien: "; StrictInput(n);
        for (int i = 0; i < n; i++)
        {
            cout << "Nhan vien " << i + 1 << endl;
            cNhanVienSX temp;
            temp.Input();
            l.push_back(temp);
        }
    }
    string getLowPaidNV() const
    {
        cNhanVienSX temp = l[0];
        for (const auto& i : l){
            if (temp.getSalary() > i.getSalary()){
                temp = i;
            }
        }
        return temp.getName();
    }

    int getSumSalary() const
    {
        int sum = 0;
        for (const auto& i : l){
            sum += i.getSalary();
        }
        return sum;
    }

    string getOldestNV() const
    {
        int minYear[2] = {0, l[0].getYear()};
        for (int i = 1; i < l.size(); i++)
        {
            if (minYear[1] > l[i].getYear())
            {
                minYear[0] = i;
                minYear[1] = l[i].getYear();
            }
        }
        return l[minYear[0]].getName();
    }

    string SortAscendingSalary()
    {
        sort(l.begin(), l.end(), [](const cNhanVienSX& nv1, const cNhanVienSX& nv2){return nv1.getSalary() < nv2.getSalary(); });
        ostringstream oss;
        for (const auto& i : l) oss << i.getName() << " ";
        return oss.str();
    }
};

int main()
{
    cListNV l;
    l.Input();
    cout << "_______________________________________\n";
    cout << l.info();
    cout << "NV co luong thap nhat: " << l.getLowPaidNV() << endl;
    cout << "Tong luong: " << l.getSumSalary() << endl;
    cout << "NV gia nhat: " << l.getOldestNV() << endl;
    cout << "Sap xep tang dan theo luong: " << l.SortAscendingSalary() << endl;
}
/*
5
a
Hau
2006
1000
250
b
Tien
2025
200
100000
c
Thien
2001
69420
2130
d
Nghia
2000
1234
14155
e
Vu
1245
9999
2352
*/
