// #include <stdio.h>
// #include <iostream>

// using namespace std;

// class PhanSo
// {
// private:
//     int TuSo;
//     int MauSo;

// public:
//     int GetTuSo()
//     {
//         return TuSo;
//     }
//     int GetMauSo()
//     {
//         return MauSo;
//     }
//     void SetTuSo(int tuso)
//     {
//         TuSo = tuso;
//     }
//     void SetMauSo(int mauso)
//     {
//         MauSo = mauso;
//     }
//     PhanSo Cong(const PhanSo &a)
//     {
//         PhanSo c;
//         c.TuSo = this->TuSo * a.MauSo + a.TuSo * this->MauSo;
//         c.MauSo = this->MauSo * a.MauSo;
//         return c;
//     }
// };

// int main()
// {
//     PhanSo a, b, c;
//     a.SetTuSo(1);
//     a.SetMauSo(2);
//     b.SetTuSo(1);
//     b.SetMauSo(2);
//     c = a.Cong(b);
//     cout << c.GetTuSo() << "/" << c.GetMauSo() << endl;
//     return 0;
// }

// //***************************************//

// #include <stdio.h>
// #include <iostream>

// using namespace std;

// class PhanSo
// {
// private:
//     int TuSo;
//     int MauSo;

// public:
//     PhanSo(int tuso = 0, int mauso = 1)
//     {
//         this->TuSo = tuso;
//         this->MauSo = mauso;
//     }
//     int GetTuSo()
//     {
//         return TuSo;
//     }
//     int GetMauSo()
//     {
//         return MauSo;
//     }
//     void SetTuSo(int tuso)
//     {
//         TuSo = tuso;
//     }
//     void SetMauSo(int mauso)
//     {
//         MauSo = mauso;
//     }
//     bool operator==(const PhanSo &a)
//     {
//         return (this->TuSo * a.MauSo == this->MauSo * a.TuSo);
//     }
//     bool operator!=(const PhanSo &a)
//     {
//         return !(*this == a);
//     }
//     friend ostream &operator<<(ostream &os, const PhanSo &a)
//     {
//         os << a.TuSo << "/" << a.MauSo << endl;
//         // os << a.str();
//         return os;
//     }
//     PhanSo operator+(const PhanSo &a)
//     {
//         PhanSo c;
//         c.TuSo = this->TuSo * a.MauSo + a.TuSo * this->MauSo;
//         c.MauSo = this->MauSo * a.MauSo;
//         return c;
//     }
// };

// int main()
// {
//     PhanSo a, b, c;
//     a.SetTuSo(1);
//     a.SetMauSo(2);
//     b.SetTuSo(1);
//     b.SetMauSo(2);
//     c = a + b;
//     cout << c;
//     cout << (a == b) << endl;
//     cout << (a != b) << endl;
//     return 0;
// }
//***************************************//

// #include <stdio.h>
// #include <iostream>

// using namespace std;

// class Number
// {
// private:
//     int num1;

// public:
//     int Getnum1()
//     {
//         return num1;
//     }
//     void Setnum1(int Num1)
//     {
//         num1 = Num1;
//     }
//     int Add(const Number &a)
//     {
//         return num1 + a.num1;
//     }
// };

// int main()
// {
//     int tong;
//     Number num, num2;
//     num.Setnum1(10);
//     num2.Setnum1(20);
//     tong = num.Add(num2);
//     cout << tong << "\n";
//     return 0;
// }

#include <stdio.h>
#include <iostream>

using namespace std;

class ConsecutiveArray
{
private:
    int *arr;
    int from;
    int to;
    int size;

public:
    ConsecutiveArray(int From, int To)
    {
        this->size = To - From + 1;
        this->from = From;
        this->to = To;
        this->arr = new int[this->size];
        for (int i = 0; i < this->size; i++)
        {
            *(arr + i) = i + From;
        }
    }
    void Xuat()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << *(arr + i) << " ";
        }
    }
    ConsecutiveArray operator+(const ConsecutiveArray &a)
    {
        // ConsecutiveArray c(this->from, a.to);
        // c.arr = new int[a.to - this->from];
        if (a.to > this->from)
        {
            ConsecutiveArray c(this->from, a.to);
            // c.arr = new int[this->from, a.to];
            return c;
        }
        else if (a.to < this->from)
        {
            ConsecutiveArray c(this->from, a.to);
            // c.arr = new int[this->from, a.to];
            c.arr = nullptr;
            return c;
        }
    }

    bool operator==(const ConsecutiveArray &a)
    {
        // ConsecutiveArray c(this->from, a.to);
        // c.arr = new int[a.to - this->from];
        if (this->from == a.from && this->to == a.to)
        {
            return true;
        }
        else if (this->from != a.from || this->to != a.to)
        {
            return false;
        }
    }
    ConsecutiveArray(const ConsecutiveArray &other)
    {
        this->from = other.from;
        this->to = other.to;
        this->size = other.size;
        this->arr = new int[this->size];
        for (int i = 0; i < this->size; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }
    ~ConsecutiveArray()
    {
        delete[] this->arr;
    }
};

int main()
{
    ConsecutiveArray A(2, 5);
    ConsecutiveArray B(6, 9);
    ConsecutiveArray C(2, 9);
    // ConsecutiveArray C(0, 0);
    (A + B).Xuat();
    cout << endl;
    cout << (C == (A + B)) << endl;
    // A.Xuat();
    // B.Xuat();
    //  C.Xuat();
    return 0;
}
