#include <vector>
using namespace std;
void nachalo(vector<double> &a)
{
    double Y, V, X;
    double P_0, P_1, P_3;
    double U_0, U_3;
    double ro_0, ro_3;
    int ro_0, ro_3;
    double b_0, b_3;
    double a_0, a_1, a_2, a_3, a_4, a_5, a_6;
    double h_0, h_3;
    double e;
    double alpha_0, alpha_3;
    double delta_0, delta_3;

    V = U_0 - U_3;
    Y = P_1 / (ro_0 * ro_3 * V ^ 2);
    X = P_3 / (ro_0 * ro_3 * V ^ 2);
    b_0 = alpha_0 / (ro_0 * ro_3 * V ^ 2);
    b_3 = alpha_3 / (ro_0 * ro_3 * V ^ 2);
    delta_0 = (h_0 - 1) * ro_3;
    delta_3 = (h_3 - 1) * ro_0;
    e = P_0 / (ro_0 * ro_3 * V ^ 2);
    ////////////////
    ////////////////
    a_0 = (delta_0 * h_3 - delta_3 * h_0) * (delta_0 * h_3 - delta_3 * h_0);
    a_1 = 2 * (h_3 * delta_0 * delta_0 * (b_3 - h_3 * e) +
               h_0 * delta_3 * delta_3 * (b_0 - h_0 * X) -
               h_0 * h_3 * (h_3 * delta_0 + h_0 * delta_3) -
               delta_0 * delta_3 * (h_0 * b_3 + h_3 * b_0) +
               delta_0 * delta_3 * h_0 * h_3 * (X + e));

    a_2 = h_0 * h_0 * h_3 * h_3 + delta_0 * delta_0 * (h_3 * h_3 * e * e + b_3 * b_3 + 4 * b_3 * h_3 * e) +
          delta_3 * delta_3 * (b_0 * b_0 + h_0 * h_0 * X * X - 4 * b_0 * X * h_0) -
          2 * delta_0 * h_3 * (2 * b_3 * h_0 + h_3 * b_0 - e * h_0 * h_3) -
          2 * delta_3 * h_0 * (2 * b_0 * h_3 + h_0 * b_3 - h_0 * h_3 * X) -
          2 * delta_0 * delta_3 * (X * e * h_0 * h_3 + b_0 * b_3) +
          2 * delta_0 * delta_3 * (X + e) * (b_3 * h_0 + h_3 * b_0);

    a_3 = h_0 * h_3 * (b_0 * h_3 + b_3 * h_0) +
          delta_0 * delta_0 * e * b_3 * (h_3 * e - b_3) +
          (X * h_0 - b_0) * delta_3 * delta_3 * b_0 * X -
          delta_0 * (h_0 * b_3 * b_3 - e * b_0 * h_3 * h_3) -
          2 * delta_0 * h_3 * b_3 * (b_0 - e * h_0) -
          delta_3 * (h_3 * b_0 * b_0 - X * b_3 * h_0 * h_0) -
          2 * delta_3 * b_0 * h_0 * (b_3 - X * h_3) -
          e * delta_0 * delta_3 * X * (h_0 * b_3 + h_3 * b_0) +
          delta_0 * delta_3 * b_0 * b_3 * (X + e);
    a_3 *= 2;

    a_4 = b_0 * b_0 * h_3 * h_3 +
          b_3 * b_3 * h_0 * h_0 +
          4 * b_0 * b_3 * h_0 * h_3 +
          delta_0 * delta_0 * b_3 * b_3 * e * e +
          delta_3 * delta_3 * b_0 * b_0 * X * X -
          2 * delta_0 * (b_0 * b_3 * b_3 - e * b_3 * b_3 * h_0 - 2 * e * h_3 * b_0 * b_3) -
          2 * delta_3 * b_0 * (b_0 * (b_3 - X * h_3) - 2 * b_3 * X * h_0) -
          2 * e * delta_0 * delta_3 * b_0 * b_3 * X;

    a_5=2*(b_0*b_3*(b_0*h_3+b_3*h_0)+b_0*b_3*(delta_0*e*b_3+delta_3*X*b_0));
    a_6=b_0*b_0*b_3*b_3;
}

int main()
{
}