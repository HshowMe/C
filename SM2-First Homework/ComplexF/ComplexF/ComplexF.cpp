#include<iostream>

typedef long long LLInteger;
typedef unsigned long long UInteger;

UInteger gcd(UInteger a, UInteger b)
{
    if (a * b == 0)
    {
        return a + b;
    }
    if (a < b)
    {
        return gcd(b, a);
    }
    return gcd(b, a % b);
}

UInteger lcm(UInteger a, UInteger b)
{
    return a / gcd(a, b) * b;
}
struct Fraction {
    LLInteger wholePart;    // Whole part of the number
    LLInteger numerator;    // Numerator
    UInteger denominator;   // Denominator

    Fraction() : wholePart(0), numerator(0), denominator(1) {}

    Fraction(LLInteger whole, LLInteger num, UInteger denom) : wholePart(whole), numerator(num), denominator(denom) {
        if (denominator == 0) {
            std::cerr << "Error: Denominator cannot be zero." << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    ~Fraction() {}

    void print() {
        std::cout << "(" << wholePart << " " << numerator << "/" << denominator << ")";
    }
};

Fraction reduceFraction(Fraction f) {
    if (f.numerator == 0) {
        f.denominator = 1;
        return f;
    }
    UInteger common = gcd(std::abs(f.numerator), f.denominator);
    f.numerator /= common;
    f.denominator /= common;
    return f;
}

Fraction toImproperFraction(Fraction f) {
    f.numerator += f.wholePart * f.denominator;
    f.wholePart = 0;
    return f;
}


Fraction sum(Fraction f1, Fraction f2) {
    f1 = toImproperFraction(f1);
    f2 = toImproperFraction(f2);

    UInteger commonDenominator = lcm(f1.denominator, f2.denominator);

    LLInteger newNumerator = f1.numerator * (commonDenominator / f1.denominator) +
        f2.numerator * (commonDenominator / f2.denominator);
    Fraction result(0, newNumerator, commonDenominator);
    return reduceFraction(result);
}

Fraction difference(Fraction f1, Fraction f2) {
    f1 = toImproperFraction(f1);
    f2 = toImproperFraction(f2);

    UInteger commonDenominator = lcm(f1.denominator, f2.denominator);

    LLInteger newNumerator = f1.numerator * (commonDenominator / f1.denominator) -
        f2.numerator * (commonDenominator / f2.denominator);

    Fraction result(0, newNumerator, commonDenominator);
    return reduceFraction(result);
}
Fraction conjugate(Fraction f) {
    f.numerator *= -1;
    return f;
}
Fraction multiply(Fraction f1, Fraction f2) {
    f1 = toImproperFraction(f1);
    f2 = toImproperFraction(f2);

    LLInteger newNumerator = f1.numerator * f2.numerator;
    UInteger newDenominator = f1.denominator * f2.denominator;

    Fraction result(0, newNumerator, newDenominator);
    return reduceFraction(result);

}

Fraction divide(Fraction f1, Fraction f2) {
    f1 = toImproperFraction(f1);
    f2 = toImproperFraction(f2);

    if (f2.numerator == 0) {
        std::cerr << "Error: Division by zero." << std::endl;
        exit(EXIT_FAILURE);
    }

    LLInteger newNumerator = f1.numerator * f2.denominator;
    UInteger newDenominator = f1.denominator * f2.denominator;


    return Fraction(0, newNumerator, newDenominator);
}

int main(int argc, char* argv[]){
    Fraction re1(0, 3, 2);  // 0 + 3/2
    Fraction im1(0, 5, 8);  // 0 + 5/8 i

    Fraction re2(0, -1, 4); // 0 + -1/4
    Fraction im2(0, 1, 4);  // 0 + 1/4 i


    Fraction sumRe = sum(re1, re2);
    Fraction sumIm = sum(im1, im2);

    std::cout << "Sum: ";
    sumRe.print();
    std::cout << " + ";
    sumIm.print();
    std::cout << "i" << std::endl;

    Fraction diffRe = difference(re1, re2);
    Fraction diffIm = difference(im1, im2);

    std::cout << "difference: ";
    diffRe.print();
    std::cout << " + ";
    diffIm.print();
    std::cout << "i" << std::endl;



    Fraction multRe1 = multiply(re1, re2);
    Fraction multRe2 = multiply(im1, im2);
    Fraction multIm1 = multiply(re1, im2);
    Fraction multIm2 = multiply(im1, re2);

    Fraction finalRe = difference(multRe1, multRe2);
    Fraction finalIm = sum(multIm1, multIm2);

    std::cout << "product: ";
    finalRe.print();
    std::cout << " + ";
    finalIm.print();
    std::cout << "i" << std::endl;

    Fraction f2Conjugate = conjugate(im2);
    Fraction divRe1 = multiply(re1, re2);
    Fraction divRe2 = multiply(im1, f2Conjugate);
    Fraction divIm1 = multiply(re1, f2Conjugate);
    Fraction divIm2 = multiply(im1, re2);

    Fraction den = multiply(re2, re2);
    Fraction den2 = multiply(im2, im2);
    Fraction numerator1 = difference(multRe1, multRe2);
    Fraction numerator2 = sum(multIm1, multIm2);
    Fraction denominator = sum(den, den2);


    Fraction finalRea = divide(numerator2, denominator);
    Fraction finalIma = divide(numerator1, denominator);
    std::cout << "Quotient: ";
    finalRea.print();
    std::cout << " + ";
    finalIma.print();
    std::cout << "i" << std::endl;

    return EXIT_SUCCESS;
}