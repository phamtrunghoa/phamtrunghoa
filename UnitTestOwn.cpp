#include <stdio.h>
#include <iostream>
#include <string.h>
#include <gmock/gmock.h>
#include <vector>
#include <stdexcept>

using namespace std;

class Calculate
{
public:
    Calculate();
    double getNum1(double num1);
   // void NhapNum1();
    double getNum2(double num2);
    //void NhapNum2();
    double getTong();
    double getHieu();
    double getTich();
    double getThuong();

private:
    double Num1;
    double Num2;
    double tong;
    double hieu;
    double tich;
    double thuong;
};

Calculate::Calculate() : Num1{0}
{
}

// void Calculate::NhapNum1()
// {
//     std::cout << "Nhap so 1: ";
//     std::cin >> Num1;
// }

double Calculate::getNum1(double num1)
{
    // std::cout << "Nhap so 1: ";
    // std::cin >> Num1;
    return num1;
}

// void Calculate::NhapNum2()
// {
//     std::cout << "Nhap so 2: ";
//     std::cin >> Num2;
// }

double Calculate::getNum2(double num2)
{
    // std::cout << "Nhap so 2: ";
    // std::cin >> Num2;
    return num2;
}

double Calculate::getTong()
{
    tong = Calculate::getNum1(5) + Calculate::getNum2(5);
    return tong;
}

double Calculate::getHieu()
{
    hieu = Calculate::getNum1(4) - Calculate::getNum2(2);
    return hieu;
}

double Calculate::getTich()
{
    tich = Calculate::getNum1(8) * Calculate::getNum2(3);
    return tich;
}

double Calculate::getThuong()
{
    thuong = Calculate::getNum1(15) / Calculate::getNum2(10);
    return thuong;
}

class CalculateTest : public testing::Test
{
public:
    CalculateTest();
    virtual ~CalculateTest();

protected:
    Calculate calculate;
};

CalculateTest::CalculateTest()
{
    //std::cout << "Constructor called\n";
}

CalculateTest::~CalculateTest()
{
    //std::cout << "Destructor called\n";
}

TEST_F(CalculateTest, testTong)
{
    ASSERT_EQ(10, calculate.getTong());
}

TEST_F(CalculateTest, testHieu)
{
    ASSERT_EQ(2, calculate.getHieu());
}

TEST_F(CalculateTest, testTich)
{
    ASSERT_EQ(24, calculate.getTich());
}

TEST_F(CalculateTest, testThuong)
{
    ASSERT_EQ(1.5, calculate.getThuong());
}

int main(int argc, char **argv)
{
    // Calculate calculate;
    // calculate.NhapNum1();
    // calculate.NhapNum2();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
