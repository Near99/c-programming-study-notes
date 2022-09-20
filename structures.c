#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 31
#define MAXBOOK 10001
#define LEN 20

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    void (*convert)(const struct book *); // pretty cool.
    void (*print)(const struct book *);
};

struct names
{
    char first[LEN];
    char last[LEN];
};

struct guy
{
    struct names handle; // nested
    char favfood[LEN];
    char job[LEN];
    float income;
};

void usd_to_cny(const struct book *usd)
{
    printf("$%.2f will be %.2f CNY\n", usd->value, (usd->value) * 7.02);
}

void print(const struct book *library)
{

    printf("%s by %s: $%.2f\n", library->title, library->author, library->value);
}

void structure_basics()
{
    struct book library;
    strcpy(library.title, "Introduction to Computer Science");
    strcpy(library.author, "Charles Wong");
    library.value = 59.66;
    library.convert = usd_to_cny;
    library.print = print;
    library.convert(&library);
    library.print(&library);

    // compiler warnings here, why?
    // struct book booklist = {.author = 'Wang', .title = 'Data', .value = 89.69, .convert = usd_to_cny, .print = print};

    struct book booklist[MAXBOOK];

    for (int i = 0; i < MAXBOOK; i++)
    {
        strcpy(booklist[i].title, "Introduction to Computer Science");
        strcpy(booklist[i].author, "Charles Wong");
        booklist[i].value = 59.66 + i;
        booklist[i].convert = usd_to_cny;
        booklist[i].print = print;
    }

    for (int i = 0; i < MAXBOOK; i++)
    {
        booklist[i].convert(&booklist[i]);
        booklist[i].print(&booklist[i]);
    }
}

void pointers_to_structures_and_nested_structures()
{
    struct guy fellow[2] = {
        {{"Charles", "Wong"}, "grilled salmon", "personality coach", 68112.00},
        {{"Nick", "Yang"}, "tripe", "tabloid editor", 232400.00}};

    //  him->income == (*him).income === guy[0].income
    struct guy *him;                                                                        // a pointer to a structure.
    him = &fellow[0];                                                                       // pointing
    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);                              // structures' addresses.
    printf("pointer #1: %p #2: %p\n", him, him + 1);                                        // same as above.
    printf("him->income is $%.2f: (*him).income is $%.2f\n", him->income, (*him).income);   // -> operator.
    him++;                                                                                  // move to the next.
    printf("him->favfood is %s: him->handle.last is %s\n", him->favfood, him->handle.last); // -> and dot.
};

struct flex
{
    int count;
    double average;
    double scores[]; // flexible array can only be defined at the end of the structure along with at least one other memeber.
};

void flexible_array_memebers()
{
    struct flex *pf;                                                      // flexible array member structure must be used with pointers.
    pf = (struct flex *)malloc(sizeof(struct flex) + 5 * sizeof(double)); // ask for space for a structure and an array.
    pf->count = 66;                                                       // set count number.
    pf->scores[0] = 78.5;                                                 // access an element of the array number.
    pf->scores[1] = 78.5;                                                 // access an element of the array number.
    pf->scores[2] = 18.5;                                                 // access an element of the array number.

    for (int i = 0; i < 3; i++)
    {
        printf("%d %g\n", pf->count, pf->scores[i]);
    }

    free(pf);
};

int main()
{
    structure_basics();

    pointers_to_structures_and_nested_structures();

    flexible_array_memebers();

    return 0;
}
