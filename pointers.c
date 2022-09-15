#include <stdio.h>
#include <string.h>

// Pointer values are strongly typed.

void pointer_basics();
void pointer_to_pointer();
void pointer_as_function_arguments();
void pointers_and_arrays();
void arrays_as_function_arguments();
void character_arrays_and_pointers();

// helper functions.
int sum_of_elements(int *a, int size); // helper function for arrays_as_function_arguments.
void increment();                      // helper function for pointer_as_function_arguments.
void print();                          // helper function for character_arrays_and_pointers.

int main()
{
    // pointer_basics();

    // pointer_to_pointer();

    // pointer_as_function_arguments();

    // pointers_and_arrays();

    // arrays_as_function_arguments();

    // character_arrays_and_pointers();

    return 0;
}

void pointer_basics()
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
}

void pointer_to_pointer()
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
}

// call by reference
void pointer_as_function_arguments()
{
    int a = 10;
    increment(&a);
    printf("a = %d\n", a); // 13
}

void increment(int *p)
{
    // *p += 1;
    (*p)++;
    printf("%d\n", *p);   // 11
    printf("%d\n", ++*p); // 12

    // why doesn't the value increment?
    printf("%d\n", (*p)++); // 12
}

// An array's value is just the address of the first element.
void pointers_and_arrays()
{
    int A[5] = {2, 4, 5, 8, 1};

    printf("%p\n", A);     // address of the first element.
    printf("%p\n", &A[0]); // same as above.

    printf("%d\n", A[0]);     // first element.
    printf("%d\n", *A);       // same as above.
    printf("%d\n", *(A + 1)); // second element

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

void arrays_as_function_arguments()
{
    // Compiler will allocate the minimum amount of space necessary if the size of an array is not explicit specified.
    int a[] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(*a);
    int r = sum_of_elements(&a[0], size);
    printf("%d\n", r);
}

// int a[] is as the as as int *a, another example of "pass by reference".
int sum_of_elements(int *a, int size)
{
    int r = 0;

    for (int i = 0; i < size; i++)
    {
        r += a[i];
    }

    return r;
}

/**
 * Size of array for storing strings must be greater and equal to the number of characters in string + 1.
 * one extra space is for telling that it's the end of the string array.
 * 
 * Arrays and pointers are different types that are used in similar manner.
 */
void character_arrays_and_pointers()
{
    char c[20] = "JOHN";
    int l = strlen(c);

    printf("%s\n", c);         // JOHN
    printf("%d\n", l);         // 4
    printf("%d\n", sizeof(c)); // 20

    print(c);

    for (int i = 0; i < 20; i++)
    {
        printf("%d", c[i]); // all unused are initialized to null (0 in ASCII);
    }

    printf("\n");
}

void print(char *c)
{
    while (*c != '\0')
    {
        printf("%c", *c);
        c++;
    }
    printf("\n");
}
