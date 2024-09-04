#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
	int no[20];
	char name[50];
	float price;
} BOOK;

typedef struct
{
	BOOK *elem;
	int length;
} SQLList;

// Status InitList(LinearList *l)
// {
// 	l->length=0;
// }
