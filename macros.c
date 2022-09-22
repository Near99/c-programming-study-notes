#include <stdio.h>
#include <math.h>

/**
 * The preprocessor doesn't make calculations! It just substitutes character sequences.
 * 
 * In what circumstances does macro have better performence than functions?
 */

/**
 * #define  -> preprocessor directive
 * MANIFEST -> macro // represent values also called object-like macros
 * 2        -> body
 * 
 * the process of going from a macro to a final replacement in the program is called macro expansion.
 */
#define MANIFEST 2 // Manifest constant declaration.
#define OW "What makes \
you beautiful"
#define FOUR (MANIFEST * MANIFEST)
#define PX printf("X is %d\n", x)

/**
 * #define           ->  preprocessor directive
 * MEAN(X, Y)        ->  macro // function-like macros, it can take arguments
 * (((X) + (Y)) / 2) ->  replacement body
 */
#define MEAN(X, Y) (((X) + (Y)) / 2)
#define SQUARE(X) ((X) * (X))
// #define SQUARE(X) X *X // pitfalls
#define PR(X) printf("The result is %d.\n", X)
#define PSQR(X) printf("The square of " #X " is %d.\n", ((X) * (X))) // stringizing.
#define XNAME(n) x##n
#define PRINT_XN(n) printf("x" #n " = %d\n", x##n);
#define PP(X, ...) printf("Message " #X " : " __VA_ARGS__) // ellipses.

/**
 * macro versus function?
 * 
 * use macros for simple functions seem good.
 */
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define ABS(X) ((X) < 0 ? -(X) : (X))
#define ISSIGN(X) ((X) == '+' || (X) == '-' ? 1 : 0)

/**
 * directive playground.
 */
#define STABLES 5
#define SIZE 10
#undef SIZE

#ifdef MAVIS
    #include "ActiveDS.h"
    #define STABLES 5
#else
    #include "BiDiSpl.h"
    #define STABLES 15
#endif

#ifndef SIZE
    #define SIZE 100
#endif

#if SYS == 1
    #include "amp_math.h"
#elif SYS == 2
    #include "vadefs.h"
#else
    #include "gameux.h"
#endif

#if defined (VAX) // newer form of #ifdef
    #include "sac.h"
#elif defined (IBMPC)
    #include "vadefs.h"
#else 
    #include "ual.h"
#endif 


void simple_macros()
{
    int max = MAX(7, 9); // 9
    int min = MIN(7, 9); // 7
    int abs = ABS(-23);  // 23

    printf("max: %d\n", max);
    printf("min: %d\n", min);
    printf("abs: %d\n", abs);
}

void variadic()
{
    double x = 48;
    double y;

    y = sqrt(x);
    PP(1, "X = %g\n", x);
    PP(2, "X = %.2f, y = %.4f\n", x, y);
}

void gluing()
{
    int XNAME(1) = 14; // becomes int x1 = 14;
    int XNAME(2) = 20; // becomes int x2 = 20;
    int x3 = 30;
    // printf("x" #n " = %d\n", x##n);
    PRINT_XN(1); // it prints x1 variable // x1 = 14
    PRINT_XN(2); // it prints x2 variable
    PRINT_XN(3); // it prints x3 vairbale
}

void macros_with_arguments()
{
    int x = 5;
    int z;

    printf("x = %d\n", x); // 5
    z = SQUARE(x);
    printf("Evaluating SQUARE(x): ");
    PR(z); // 25

    z = SQUARE(2);         // 4
    printf("z = %d\n", z); // 4
    printf("Evaluating SQUARE(2): ");
    PR(z); // 4

    printf("Evaluating SQUARE(x+2): ");
    PR(SQUARE(x + 2)); // 49; 17 wrong because it expands (x + 2 * x + 2) = (5 + 10 + 2) = 17 if the declaration is SQUARE(X) (X*X)

    printf("Evaluating 100/SQUARE(2): ");
    PR(100 / SQUARE(2)); // 25

    printf("x is %d.\n", x); // 5
    printf("Evaluating SQUARE(++x): ");
    PR(SQUARE(++x));                             // 49 // it increments twice before the actual calculation so it gives us 7 * 7.
    printf("After incrementing, x is %x.\n", x); // 7, avoid using ++ as a macro argument.

    int y = 5;
    PSQR(y);
    PSQR(2 + 4);
}

void manifest_basics()
{
    int x = MANIFEST;
    PX;
    x = FOUR;

    printf("%s\n", OW);
    printf("%d\n", x);

    printf("%d\n", MEAN(10, 15));
    int s = SQUARE(100);
    printf("%d\n", s);
}

int main()
{
    manifest_basics();

    macros_with_arguments();

    gluing();

    variadic();

    simple_macros();

    return 0;
}
