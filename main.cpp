#include <iostream>

using namespace std;

class Fraction {
public:
  int numerator;
  int denominator;

  Fraction(int n, int d) {
    numerator = n;
    denominator = d;
    simplify();
  }

  Fraction add(Fraction a)
  {
    int fdenom = a.denominator * denominator;
    int fnum = (a.numerator*denominator) + (a.denominator *numerator);
    Fraction result(fnum,fdenom);
    return result;
  }

  Fraction subtract(Fraction a)
  {
    int fdenom = a.denominator * denominator;
    int fnum = (a.numerator*denominator) - (a.denominator *numerator);
    Fraction result(fnum,fdenom);
    return result;
  }

  Fraction multiply(Fraction a)
  {
    int fdenom = a.denominator * denominator;
    int fnum = a.numerator * numerator;
    Fraction result(fnum,fdenom);
    return result;
  }

  Fraction divide(Fraction a)
  {
    int fdenom = denominator / a.numerator;
    int fnum = numerator * a.denominator;
    Fraction result(fnum,fdenom);
    return result;
  }

  void simplify()
  {
    int n = 2;
    while(n <= denominator)
    {
      if(numerator%n == 0 && denominator%n == 0)
      {
        numerator = numerator/n;
        denominator = denominator/n;
      }
      n++;
    }
  }

  void print()
  {
    cout << numerator << "/" << denominator << endl;
  }
};


int main() {
  Fraction x(1, 2);
  Fraction y(1, 2);
  x.print(); // 3/5
  y.print(); // 1/2
  Fraction z = x.add(y);
  z.print(); // 11/10
}