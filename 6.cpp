#include <bits/stdc++.h>
using namespace std;

void StrictInput(float& n)
{
    while (!(cin >> n))
    {
        cout << "Thu lai: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void StrictInput(int& n)
{
    while (!(cin >> n))
    {
        cout << "Thu lai: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

class cCandidate
{
private:
    string id, name, dob;
    float toan, van, anh;

public:
    cCandidate(){}
    string getName() const {return name;}
    string info() const
    {
        ostringstream oss;
        oss << "Ma: " << id << endl;
        oss << "Ten: " << name << endl;
        oss << "Ngay sinh: " << dob << endl;
        oss << "Diem toan: " << toan << "; Diem van: " << van << "; Diem anh: " << anh << endl;
        return oss.str();
    }

    void Input()
    {
        cout << "Nhap ma: "; cin >> id;
        cout << "Nham ten: "; cin >> name;
        cout << "Ngay sinh: "; cin >> dob;
        cout << "Diem toan: "; StrictInput(toan);
        cout << "Diem van: "; StrictInput(van);
        cout << "Diem anh: "; StrictInput(anh);
    }

    float GetSumPoint() const{
        return toan + van + anh;
    }
};

class cListCandidate
{
private:
    vector<cCandidate> lst;

public:
    cListCandidate(){}
    string info() const
    {
        ostringstream oss;
        for (int i = 0; i < lst.size(); i++) {
            oss << i + 1 << endl << lst[i].info() << endl;
        }
        return oss.str();
    }

    void Input()
    {
        int n;
        cout << "Nhap so thi sinh: "; StrictInput(n);
        for (int i = 0; i < n; i++)
        {
            cout << "Thi sinh thu " << i + 1 << endl;
            cCandidate temp;
            temp.Input();
            lst.push_back(temp);
            cout << endl;
        }
    }

    string GetOver15List() const
    {
        ostringstream oss;
        for (int i = 0; i < lst.size(); i++) {
            if (lst[i].GetSumPoint() > 15)
            oss << lst[i].info() << endl;
        }
        return oss.str();
    }

    string getBestCan() const
    {
        cCandidate best = lst[0];
        for (int i = 1; i < lst.size(); i++)
        {
            if (lst[i].GetSumPoint() > best.GetSumPoint())
                best = lst[i];
        }
        return best.getName();
    }

    void SortDescending(){
        sort(lst.begin(), lst.end(), [](const cCandidate& c1, const cCandidate& c2){return c1.GetSumPoint() > c2.GetSumPoint(); });
    }

    string GetAllName()
    {
        ostringstream oss;
        SortDescending();
        for (int i = 0; i < lst.size(); i++){
            oss << lst[i].getName() << " ";
        }
        return oss.str();
    }
};

int main()
{
    cListCandidate l;
    l.Input();

    cout << "Thi sinh voi tong diem hon 15: " << endl << l.GetOver15List() << endl;
    cout << "Thi sinh co tong diem cao nhat: " << l.getBestCan() << endl;
    cout << "Danh sach thi sinh giam dan theo tong diem: " << l.GetAllName() << endl;
}
/*
5
a
Hau
04/07/2006
3
1
10
b
Tien
13/7/2006
8.8
9
7
c
Thien
29/2/2001
10
10
0
d
Nghia
12/5/2006
5.6
3.4
1.2
e
Vu
3/7/1245
10
10
10
*/
