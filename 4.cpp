#include <bits/stdc++.h>
using namespace std;

bool isPrime(const int& n)
{
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

void Input(int& n, const int& lowerbound = numeric_limits<int>::min())
{
    while (!(cin >> n) || n < lowerbound)
    {
        cout << "Thu lai: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

class cArray
{
private:
    vector <int> ar;

public:
    cArray(){}
    cArray(const vector<int>& v): ar(v){}

    string info() const
    {
        ostringstream oss;
        for (int i = 0; i < ar.size(); i++){
            oss << ar[i] << " ";
        }
        return oss.str();
    }

    void CreateRanArr()
    {
        srand(time(0));
        cout << "Nhap so luong so nguyen: ";
        int n; Input(n, 1);
        for (int i = 0; i < n; i++){
            ar.push_back(rand() % 101);
        }
    }

    int CountXinArr(const int& x) const{
        return count_if(ar.begin(), ar.end(), [&x](const int& i){ return (x == i); });
    }

    bool isAscend() const{
        return all_of(ar.begin(), ar.end(), [](const int& i){return i < *(&i+1); });
    }

    int getMinOdd() const {
        int minOdd = 101;
        for (int i = 0; i < ar.size(); i++){
            if (minOdd > ar[i] && ar[i]&1)
                minOdd = ar[i];
        }
        if (minOdd == 101)
            throw runtime_error("Khong co phan tu le trong mang.");
        return minOdd;
    }

    int getMaxPrime() const {
        int maxPrime = -1;
        for (int i = 0; i < ar.size(); i++){
            if (maxPrime < ar[i] && isPrime(ar[i]))
                maxPrime = ar[i];
        }
        if (maxPrime == -1)
            throw runtime_error("Khong co so nguyen to trong mang. ");
        return maxPrime;
    }

    void SortAscending(){
        sort(ar.begin(), ar.end());
    }
    void SortDescending(){
        sort(ar.begin(), ar.end(), [](const int& i, const int& j){ return i > j; });
    }
};

int main()
{
    cArray a;
    a.CreateRanArr();
    cout << "Nhap x: ";
    int x; Input(x);
    cout << "Mang: " << a.info() << endl;
    cout << "So lan " << x << " xuat hien trong mang: " << a.CountXinArr(x) << endl;
    cout << "Mang" << ((a.isAscend())? "": " khong") << " tang dan" << endl;
    cout << "Phan le nho nhat trong mang: ";
    try {cout << a.getMinOdd() << endl;} catch(const runtime_error& e) {cout << e.what() << endl;}
    cout << "So nguyen to lon nhat trong mang: ";
    try {cout << a.getMaxPrime() << endl;} catch(const runtime_error& e) {cout << e.what() << endl;}
    a.SortAscending();
    cout << "\nXep tang dan: " << a.info() << endl;
    a.SortDescending();
    cout << "\nXep giam dan: " << a.info() << endl;
}
