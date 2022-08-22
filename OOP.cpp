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

//***************************************//

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
//     PhanSo operator +(const PhanSo &a)
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
//     cout << c.GetTuSo() << "/" << c.GetMauSo() << endl;
//     return 0;
// }
//***************************************//

#include <stdio.h>
#include <iostream>

using namespace std;

class Number
{
private:
    int num1;

public:
    int Getnum1()
    {
        return num1;
    }
    void Setnum1(int Num1)
    {
        num1 = Num1;
    }
    int Add(const Number &a)
    {
        return num1 + a.num1;
    }
};

int main()
{
    int tong;
    Number num, num2;
    num.Setnum1(10);
    num2.Setnum1(20);
    tong = num.Add(num2);
    cout << tong << "\n";
    return 0;
}


//***************************************//

#include <stdio.h>
#include <iostream>

using namespace std;

class Number
{
private:
    int num1;
    int num2;

public:
    int Getnum1()
    {
        return num1;
    }
    void Setnum1(int Num1)
    {
        num1 = Num1;
    }
    int Getnum2()
    {
        return num2;
    }
    void Setnum2(int Num2)
    {
        num2 = Num2;
    }
    // Number operator+(const Number &a)
    // {
    //     Number result;
    //     result.num1 = num1 + a.num2;
    //     return result;
    // }
    Number Add(const Number &a)
    {
        Number result;
        result.num1 = num1 + a.num2;
        return result;
    }
};

int main()
{
    // int tong;
    // Number num, num2;
    // num.Setnum1(10);
    // num2.Setnum1(20);
    // tong = num.Add(num2);
    // cout << tong << "\n";
    // return 0;
    Number tong;
    Number num, num2;
    num.Setnum1(10);
    num2.Setnum2(40);
    tong = num + num2;
    cout << tong.Getnum1() << "\n";
    return 0;
}
