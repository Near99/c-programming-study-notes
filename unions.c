#include <stdio.h>
#include <string.h>

#define MAX 41

// A union is a type to store different data types in the same memory space (but not simultaneously).
// ONLY one value is stored at a time.

// define a union.
union hold
{
    int digit;
    double bigfl;
    char letter;
};

void union_basics()
{
    union hold fit;      // union variable of hold type.
    union hold save[10]; // array of 10 union variables.
    union hold *pu;      // pointer to a variable of hold type.

    union hold valA;
    valA.letter = 'W';
    union hold valB = valA;             // initialize one union to another.
    union hold valC = {88};             // initialize digit member of union.
    union hold valD = {.bigfl = 118.2}; // designated initializer.

    fit.digit = 23;              // assign to digit.
    printf("%d\n", fit.digit);   // 23
    fit.bigfl = 2.0;             // reassign value to bigfl.
    printf("%d\n", fit.digit);   // 0 cause only one value is stored at a time, fit.digit is overwritten.
    printf("%.1f\n", fit.bigfl); // 2.0
    fit.letter = 'w';            // reassign a char value.
    printf("%c\n", fit.letter);  // w

    pu = &fit;                  // point to fit now.
    printf("%c\n", pu->letter); // w, can use -> operator with pointers.
    printf("%d\n", pu->digit);  // 119 ascii for letter 'w', an example of using different member for viewing the contents.
}

void use_unions_in_structures()
{
    struct owner
    {
        char socsecurity[MAX];
    };

    struct leasecompany
    {
        char name[40];
        char headquarters[40];
    };

    union data
    {
        struct owner owncar;
        struct leasecompany leasecar;
    };

    struct car_data
    {
        char make[15];
        int status; // 0 = owned, 1 = leased
        union data ownerinfo;
    };

    struct owner a;
    strcpy(a.socsecurity, "Charles Wang");

    struct leasecompany b;
    strcpy(b.name, "Google");
    strcpy(b.headquarters, "Silicon Valley ");

    struct car_data filter;
    filter.status = 0;

    if (filter.status == 0)
    {
        filter.ownerinfo.owncar = a;
        printf("Car is currently owned by: %s\n", filter.ownerinfo.owncar);
    }

    filter.status = 1;

    if (filter.status == 1)
    {
        filter.ownerinfo.leasecar = b;
        printf("Company name: %s based in %s\n", filter.ownerinfo.leasecar.name, filter.ownerinfo.leasecar.headquarters);
    }
}

int main()
{
    union_basics();

    use_unions_in_structures();

    return 0;
};