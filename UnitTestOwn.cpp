#include <stdio.h>
#include <iostream>
#include <string.h>
#include <gmock/gmock.h>
#include <vector>
#include <stdexcept>

using namespace std;

class Calculation
{
public:
    Calculation(double num1, double num2);
    ~Calculation();
    double getTotal();
    double getSubtract();
    double getMultiply();
    double getDivision();

private:
    double _firstNum;
    double _secondNum;
    double _total;
    double _subtract;
    double _multiply;
    double _division;
};

Calculation::Calculation(double num1, double num2)
{
    _firstNum = num1;
    _secondNum = num2;
}

Calculation::~Calculation()
{
}

double Calculation::getTotal()
{
    Calculation::_total = Calculation::_firstNum + Calculation::_secondNum;
    return Calculation::_total;
}

double Calculation::getSubtract()
{
    Calculation::_subtract = Calculation::_firstNum - Calculation::_secondNum;
    return Calculation::_subtract;
}

double Calculation::getMultiply()
{
    Calculation::_multiply = Calculation::_firstNum * Calculation::_secondNum;
    return Calculation::_multiply;
}

double Calculation::getDivision()
{
    Calculation::_division = Calculation::_firstNum / Calculation::_secondNum;
    return Calculation::_division;
}

class CalculateTest : public testing::Test
{
public:
    Calculation *_pCalculation;

protected:
    void SetUp()
    {
    }

    void TearDown()
    {
        if (_pCalculation)
        {
            delete _pCalculation;
            _pCalculation = NULL;
        }
    }
};

TEST_F(CalculateTest, testTotal)
{
    _pCalculation = new Calculation(15, 5);
    ASSERT_EQ(20, _pCalculation->getTotal());
}

TEST_F(CalculateTest, testSubtract)
{
    _pCalculation = new Calculation(15, 5);
    ASSERT_EQ(10, _pCalculation->getSubtract());
}

TEST_F(CalculateTest, testMultiply)
{
    _pCalculation = new Calculation(15, 5);
    ASSERT_EQ(75, _pCalculation->getMultiply());
}

TEST_F(CalculateTest, testDivision)
{
    _pCalculation = new Calculation(15, 5);
    ASSERT_EQ(3, _pCalculation->getDivision());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
