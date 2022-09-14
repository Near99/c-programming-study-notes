#include <stdio.h>

// Pointer values are strongly typed.

int pointer_basics();
int pointer_to_pointer();
int pointer_as_function_arguments();
int pointers_and_arrays();

void Increment(); // helper function for pointer_as_function_arguments.

int main()
{
    // pointer_basics();

    // pointer_to_pointer();

    // pointer_as_function_arguments();

    pointers_and_arrays();

    return 0;
}

int pointer_basics()
{
    int a = 1025;
    int *p = &a;

    // Address of pointer p.
    printf("%p\n", &p);

    // Address of where p is pointing to which is a's address.
    printf("%p\n", p);

    // Address of a which is equal to p's value.
    printf("%p\n", &a);

    // Value of a, the operation is called dereferencing.
    printf("%d\n", *p);

    char *pc;

    // typecasting
    pc = (char *)p;
    printf("address = %p, value = %d\n", pc, *pc);
    // *pc + 1 means dereference the value of pointer pc which is 1 then incrementing by 1
    // *(pc + 1) means to increment the address by 1 then dereferencing.
    printf("address = %p, value = %d\n", pc + 1, *(pc + 1));

    // Generic pointer.
    void *pv;

    return 0;
}

int pointer_to_pointer()
{
    int x = 5;
    int *p = &x;
    int **q = &p;
    int ***r = &q;

    // address of x.
    printf("%p\n", &x);
    // p's value is the address of x.
    printf("%p\n", p);
    // dereferencing a pointer to a pointer, value is the address of where p is pointing to which is x's address.
    printf("%p\n", *q);

    printf("Address of x is: %p, value of X is: %d\n", &x, x);
    printf("Address of P is: %p, value of P is: %p\n", &p, p);
    printf("Address of Q is: %p, value of Q is: %p\n", &q, q);
    printf("Address of R is: %p, value of R is: %p\n", &r, r);

    printf("%d\n", *p);
    **q = *p + 2;
    printf("%d\n", *(*q));
    ***r = **q + 2;
    printf("%d\n", *(*(*r)));

    return 0;
}

// call by reference
int pointer_as_function_arguments()
{
    int a = 10;
    Increment(&a);
    printf("a = %d\n", a); // 13

    return 0;
}

void Increment(int *p)
{
    // *p += 1;
    (*p)++;
    printf("%d\n", *p);   // 11
    printf("%d\n", ++*p); // 12

    // why doesn't the value increment?
    printf("%d\n", (*p)++); // 12
}

int pointers_and_arrays()
{
    int A[5] = {2, 4, 5, 8, 1};

    // An array's value is just the address of the first element.
    printf("%p\n", A);
    printf("%p\n", &A[0]);

    printf("%d\n", A[0]);
    printf("%d\n", *A);
    printf("%d\n", *(A + 1));

    for (int i = 0; i < 5; i++)
    {
        printf("%d", *(A + i));
    }
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", &A[i]);
    }
}
