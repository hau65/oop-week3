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
class cNhanVienVP
{
private:
    string id, name;
    int yob, salary;

public:
    cNhanVienVP(){}
    int getSalary() const {return salary;}
    int getYear() const {return yob;}
    string getName() const {return name;}
    string info() const
    {
        ostringstream oss;
        oss << "Ma: " << id << endl;
        oss << "Ten: " << name << endl;
        oss << "Nam sinh: " << yob << endl;
        oss << "Luong: " << salary << endl;
        return oss.str();
    }

    void Input()
    {
        cout << endl;
        cout << "Nhap ma: "; cin >> id;
        cout << "Nhap ten: "; cin >> name;
        cout << "Nhap nam sinh: "; StrictInput(yob);
        cout << "Nhap luong: "; StrictInput(salary);
    }
};

class cNVList
{
private:
    vector<cNhanVienVP> lst;

public:
    cNVList(){}
    string info() const
    {
        ostringstream oss;
        for (int i = 0; i < lst.size(); i++){
            oss << lst[i].info() << endl;
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
            cNhanVienVP temp;
            temp.Input();
            lst.push_back(temp);
        }
    }

    string getHighPaidNV() const
    {
        cNhanVienVP temp = lst[0];
        for (const auto& i : lst){
            if (temp.getSalary() < i.getSalary()){
                temp = i;
            }
        }
        return temp.getName();
    }

    int getSumSalary() const
    {
        int sum = 0;
        for (const auto& i : lst){
            sum += i.getSalary();
        }
        return sum;
    }

    string getOldestNV() const
    {
        int minYear[2] = {0, lst[0].getYear()};
        for (int i = 1; i < lst.size(); i++)
        {
            if (minYear[1] > lst[i].getYear())
            {
                minYear[0] = i;
                minYear[1] = lst[i].getYear();
            }
        }
        return lst[minYear[0]].getName();
    }

    string SortAscendingSalary()
    {
        sort(lst.begin(), lst.end(), [](const cNhanVienVP& nv1, const cNhanVienVP& nv2){return nv1.getSalary() < nv2.getSalary(); });
        ostringstream oss;
        for (const auto& i : lst) oss << i.getName() << " ";
        return oss.str();
    }
};

int main()
{
    cNVList l;
    l.Input();
    cout << "_______________________________________________________________" << endl;
    cout << "Danh sach nhan vien: \n" << l.info() << endl;
    cout << "Nhan vien co luong cao nhat: " << l.getHighPaidNV() << endl;
    cout << "Tong luong: " << l.getSumSalary() << endl;
    cout << "Nhan vien gia nhat: " << l.getOldestNV() << endl;
    cout << "Sap xep theo nhan vien van phong tang dan theo luong: " << l.SortAscendingSalary() << endl;
}
/*
5
a
Hau
2006
1000000000
b
Tien
2025
200000
c
Thien
2001
6942000
d
Nghia
2000
123456789
e
Vu
1245
32
*/
