#include <vector>

#include "Math/ProbFuncMathCore.h"

#include "Integrator.h"
#include "TestUtilities.h"

using std::vector;

int main(){

    Integrator inte;
    TestUtilities test;

    // Simple test case:
    // Integration of the function y = x with non-equidistant values of x.
    vector<double> x{0., 0.05, 1.};
    double inte_trap = inte.trapezoidal_rule(x, x);
    test.test_closeness(inte_trap, 0.5, test.num_tol_rel);

    double inte_spli = inte.spline(x, x);
    test.test_closeness(inte_spli, 0.5, test.num_tol_rel);

    pair<double, double> inte_darb = inte.darboux(x, x);
    test.test_equality(inte_darb.first, 0.05*0.95);
    test.test_equality(inte_darb.second, 0.05*0.05+0.95*1.);
}