#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 31
#define MAXBOOK 10001

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    void (*convert)(const struct book *); // pretty cool.
    void (*print)(const struct book *);
};

void usd_to_cny(const struct book *usd)
{
    printf("$%.2f will be %.2f CNY\n", usd->value, (usd->value) * 7.02);
}

void print(const struct book *library)
{

    printf("%s by %s: $%.2f\n", library->title, library->author, library->value);
}

int main()
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

    return 0;
}