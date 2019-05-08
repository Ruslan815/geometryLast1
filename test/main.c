#define CTEST_MAIN
#define CTEST_COLOR_OK
#include <ctest.h>
#include <foo.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(peres1__test, result_test)
{
    // Given
    const double x1 = 2;
    const double y1 = 2;
    const double r1 = 3;
    const double x2 = 5;
    const double y2 = 3;
    const double r2 = 2;

    // When
    const double result = peres(x1, y1, r1, x2, y2, r2);

    // Then
    const double expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(peres2__test, result_test)
{
    // Given
    const double x1 = -5;
    const double y1 = -4;
    const double r1 = 2;
    const double x2 = 11;
    const double y2 = 3;
    const double r2 = 2;

    // When
    const double result = peres(x1, y1, r1, x2, y2, r2);

    // Then
    const double expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(perimetrC__test, result_test)
{
    // Given
    const double r = 2;
    const double PI = 3.1415;

    // When
    const double result = PerimetrC(r, PI);

    // Then
    const double expected = 12.566;
    const double tol = 0.001;
    ASSERT_DBL_NEAR_TOL(expected, result, tol);
}

CTEST(perimetrT__test, result_test)
{
    // Given
    const double a = 4;
    const double b = 6;
    const double c = 3;

    // When
    const double result = PerimetrT(a, b, c);

    // Then
    const double expected = 13;
    ASSERT_EQUAL(expected, result);
}

CTEST(squareC__test, result_test)
{
    // Given
    const double r = 5;
    const double PI = 3.1415;

    // When
    const double result = SquareC(r, PI);

    // Then
    const double expected = 78.5375;
    const double tol = 0.0001;
    ASSERT_DBL_NEAR_TOL(expected, result, tol);
}

CTEST(squareT__test, result_test)
{
    // Given
    const double a = 4;
    const double b = 6;
    const double c = 3;

    // When
    const double result = SquareT(a, b, c);

    // Then
    const double expected = 5.332682;
    const double tol = 0.000001;
    ASSERT_DBL_NEAR_TOL(expected, result, tol);
}
