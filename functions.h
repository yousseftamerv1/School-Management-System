#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include "scheme.h"
#include "scheme.c"

#define Insert 1
#define Append 2
#define Print 3
#define Delete 4
#define Destroy 5
#define Search 6
#define Count 7
#define Rank 8
#define Edit 9
#define Sort 10
#define Arabic 1
#define English 2
#define Math 3
#define Cs 4
#define Exit 0

#define ID 1
#define NAME 2
#define GRADE 3
#define DOB 4
#define ADDRESS 5
#define AR 6
#define EN 7
#define MATH 8
#define CS 9
#define ALL 10


typedef struct DEG
{
    int ar;
    int en;
    int math;
    int cs;
    int total;
    float avr;
    float inprsntg;
}deg;

typedef struct ADD
{
    char st[20];
    char block_name[15];
    int block_number;
}address;

typedef struct Dob
{
    int day;
    int month;
    int year;
}dob;

typedef struct STU
{
    char name[50];
    int id;
    char grade[20];
    dob date;
    address adrs;
    deg degree;

}student;

typedef struct Node
{
    student stu;
    struct Node * next;
    struct Node * prev;
}node;

typedef struct DLinked
{
    node * head;
    node * tail;
    int list_size;
}list;


void initList(list * myList);
void append(list * myList, student stu);
void insert(list * myList, student stu);
void printList(list * myList);
void printStruct(student stu);
void delete(list * myList, node * myNode);
void destroy(list * myList);
bool isEmpty(list * myList);
int listlen(list * myList);
node * search(list * myList, int id);
student scanStruct(list * myList, student stu);
void edit(list * myList, node * foundStu);
void sortbyid(list * myList);
void sortbyname(list * myList);
void sortbysocre(list * myList);
void sortbyar(list * myList);
void sortbyen(list * myList);
void sortbymath(list * myList);
void sortbycs(list * myList);

#endif // FUNCTIONS_H_INCLUDED
