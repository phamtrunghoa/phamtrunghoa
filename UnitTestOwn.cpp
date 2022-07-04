#include <stdio.h>
#include <iostream>
#include <string.h>
#include <gmock/gmock.h>
#include <vector>
#include <stdexcept>

using namespace std;

class cCalculate
{
private:
    double iFirstNum;
    double iSecondNum;

public:
    cCalculate();
    int iGetFirstNum() const;
    int iGetSecondNum() const;
    void vAdd();
    void vSub();
    void vMul();
    void vDiv();
};

cCalculate::cCalculate() : iFirstNum{0}
{}

cCalculate::cCalculate() : iSecondNum{0}
{}

class cCalculateTest : public testing::Test
{
public:
    cCalculateTest();
    virtual ~cCalculateTest();

protected:
    cCalculate calculate;
};

int cCalculate::iGetFirstNum()
{
    std::cout << "Nhap so thu nhat: ";
    std::cin >> iFirstNum;
    return iFirstNum;
}

int cCalculate::iGetSecondNum()
{
    std::cout << "Nhap so thu hai: ";
    std::cin >> iSecondNum;
    return iSecondNum;
}

void cCalculate::vAdd()
{
    int tong;
    tong = cCalculate::iFirstNum + cCalculate::iSecondNum;
    std::cout << "Tong cua hai so la: " << tong << "\n";
}

void cCalculate::vSub()
{
    int hieu;
    hieu = cCalculate::iFirstNum - cCalculate::iSecondNum;
    std::cout << "Hieu cua hai so la: " << hieu << "\n";
}

void cCalculate::vMul()
{
    int tich;
    tich = cCalculate::iFirstNum * cCalculate::iSecondNum;
    std::cout << "Tich cua hai so la: " << tich << "\n";
}

void cCalculate::vDiv()
{
    double thuong;
    thuong = cCalculate::iFirstNum / cCalculate::iSecondNum;
    std::cout << "Thuong cua hai so la: " << thuong << "\n";
}

TEST(cCalculate::vAdd, Test_Tong)
{
    int so1;
    int so2;
    so1 = cCalculate::iGetFirstNum();
    so2 = cCalculate::iGetSecondNum();
    ASSERT_EQ(cCalculate::vAdd(so1, so2), 10);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
