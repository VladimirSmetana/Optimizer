#include <QCoreApplication>
#include <iostream>
using namespace std;
double ciol(double x1, double x2)
{
    double const Velocity = 9259;
    double const w1 = 3300, w2 = 3700;
    double const s1 = 7, s2 = 10;
    double p1 = (s1 / (s1 - 1));
    double p2 = (s2 / (s2 - 1));

    double find = 1 + p1 * x1 + p2 * x2;

    return find;
}

double dVelocity (double x1, double x2)
{

    double const Velocity = 9259;
    double const w1 = 3300, w2 = 3700;
    double const s1 = 7, s2 = 10;
    double p1 = (s1 / (s1 - 1));
    double p2 = (s2 / (s2 - 1));

    double find1 = 1 + p1 * x1 + p2 * x2 ;
    double find2 = 1 + p2 * x2 ;
    double ogr;

    ogr = Velocity - w1 * log(find1 / (find1 - x1)) - w2 * log(find2 / (find2 - x2)) ;

    return ogr;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const double PI = 3.141592653589793;
    const double g = 9.81;

    double x1 = 14;
    double x2 = 4;
    double dx1 = 0, dx2 = 0, h, mu;
    double res1, res2;
    h = 1;
    mu = 1;
    for (int i = 1; i <= 15000; i++)
    {
        cout << x1 << ' ' << x2 << ' '  << endl;

        dx1 = mu * (ciol(x1 + h, x2) - ciol(x1 - h, x2)) / (2 * h);

        if (dVelocity(x1 - dx1, x2) > 0 || x1 <= 0) dx1 = -mu;

        dx2 = mu * (ciol(x1, x2 + h) - ciol(x1, x2 - h)) / (2 * h);
        if (dVelocity(x1, x2 - dx2) > 0 || x2 <= 0)  dx2 = -mu;

        mu = ciol(x1, x2) / 100;

        if (abs(mu) > 0.01) mu = 0.01;

        x1 = x1 - dx1;
        x2 = x2 - dx2;
    }

    return 0;
}
