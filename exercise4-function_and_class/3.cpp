#include <iostream>

class Fraction{
private:
    int molecular;
    int denominator;
public:
    Fraction(int umolecular = 0, int udenominator = 1);
    int gcd(int a, int b);
    void simplify();
    Fraction add(Fraction ufraction);
    Fraction sub(Fraction ufraction);
    Fraction mul(Fraction ufraction);
    Fraction div(Fraction ufraction);
    void show();
};

Fraction::Fraction(int umolecular, int udenominator)
{
    if (udenominator < 0) {
        umolecular = -umolecular;
        udenominator = -udenominator;
    }
    molecular = umolecular;
    if (molecular == 0) {
        denominator = 1;
    } else {
        denominator = udenominator;
        simplify();
    }
}

int Fraction::gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

void Fraction::simplify()
{
    int FractionGcd;
    if (molecular > 0)
        FractionGcd = gcd(molecular, denominator);
    else {
        FractionGcd = gcd(-molecular, denominator);
    }
    molecular /= FractionGcd;
    denominator /= FractionGcd;
}

Fraction Fraction::add(Fraction ufraction)
{
    molecular + ufraction.molecular;
    denominator + ufraction.denominator;
    return Fraction(molecular * ufraction.denominator + denominator * ufraction.molecular, ufraction.denominator * denominator);
}

Fraction Fraction::sub(Fraction ufraction)
{
    return Fraction(molecular * ufraction.denominator - denominator * ufraction.molecular, ufraction.denominator * denominator);
}

Fraction Fraction::mul(Fraction ufraction)
{
    return Fraction(molecular * ufraction.molecular, ufraction.denominator * denominator);
}

Fraction Fraction::div(Fraction ufraction)
{
    return Fraction(molecular * ufraction.denominator, ufraction.molecular * denominator);
}

void Fraction::show()
{
    std::cout << molecular << '/' << denominator << std::endl;
}

int main()
{
    int molecular1, denominator1, molecular2, denominator2;
    std::cin >> molecular1 >> denominator1 >> molecular2 >> denominator2;
    Fraction fraction1(molecular1, denominator1);
    Fraction fraction2(molecular2, denominator2);
    Fraction fraction3 = fraction1.add(fraction2);
    Fraction fraction4 = fraction1.sub(fraction2);
    Fraction fraction5 = fraction1.mul(fraction2);
    Fraction fraction6 = fraction1.div(fraction2);
    fraction1.show();
    fraction2.show();
    fraction3.show();
    fraction4.show();
    fraction5.show();
    fraction6.show();
    return 0;
}