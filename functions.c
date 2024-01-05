#include "functions.h"
void MainMenu()
{
    int user_choice, sort_choice, sort_dir, destroy_choice;
    list myList;
    student myStudent;
    int stuNum, searchID;
    node *foundStu;
    initList(&myList);
    do
    {
        system("cls");
        MainScheme();
        printf("\n");
        printf(BLU);
        printf("[01] Add New Student\n");
        printf("[02] Append New Student\n");
        printf("[03] View Students\n");
        printf("[04] Delete a Student\n");
        printf("[05] Delete All Students\n");
        printf("[06] Search For a Student\n");
        printf("[07] View Number of Students\n");
        printf("[08] View Student Rank\n");
        printf("[09] Edit a Student\n");
        printf("[10] Sort\n");
        printf("[00] Exit\n");

        printf("\n>> ");

        scanf("%d", &user_choice);
        fflush(stdin);
        printf(RESET);
        switch (user_choice)
        {
        case Insert:
            system("cls");
            InsertScheme();
            printf("Enter the number of the students you want to insert: ");
            scanf("%d", &stuNum);
            fflush(stdin);

            while (stuNum < 0)
            {
                printf(RED);
                printf("Please Enter a valid Number.\n");
                printf(RESET);
                printf("Enter the number of the students you want to insert: ");
                scanf("%d", &stuNum);
                fflush(stdin);
            }

            if (stuNum == 0)
            {
                break;
            }
            
            for (int i = 0; i < stuNum; i++)
                insert(&myList, scanStruct(&myList, myStudent));
            printf("\n");
            printf("%d student(s) appended successfully", stuNum);
            printf("\n");
            printf(GRN "Press any key to continue..." RESET "\n");
            while (!getch())
                ;
            break;

        case Append:
            system("cls");
            AppendScheme();
            printf("Enter the number of the students you want to append: ");
            scanf("%d", &stuNum);
            fflush(stdin);

            while (stuNum < 0)
            {
                printf(RED);
                printf("Please Enter a valid Number.\n");
                printf(RESET);
                printf("Enter the number of the students you want to append: ");
                scanf("%d", &stuNum);
                fflush(stdin);
            }
            
            if (stuNum == 0)
            {
                break;
            }
            
            for (int i = 0; i < stuNum; i++)
                append(&myList, scanStruct(&myList, myStudent));
            printf("%d student(s) appended successfully", stuNum);
            printf("\n");
            printf(GRN "Press any key to continue..." RESET "\n");
            while (!getch())
                ;
            break;

        case Print:
            system("cls");
            PrintStudentsScheme();
            printf("\n");
            if (isEmpty(&myList))
            {
                printf(RED);
                printf("List is Empty\n");
                printf(RESET);
                printf(GRN "Press any key to continue..." RESET "\n");
                while (!getch())
                    ;
                break;
            }
            printList(&myList);
            printf(GRN "Press any key to continue..." RESET "\n");
            while (!getch())
                ;
            break;

        case Delete:
            system("cls");
            DeleteScheme();
            printf("\n");
            if (isEmpty(&myList))
            {
                printf(RED);
                printf("List is Empty\n");
                printf(RESET);
                printf(GRN "Press any key to continue..." RESET "\n");
                while (!getch())
                    ;
                break;
            }
            printf("Enter the ID to delete: ");
            scanf("%d", &searchID);
            fflush(stdin);
            if (search(&myList, searchID) != NULL)
                delete (&myList, search(&myList, searchID));
            printf(RED);
            printf("Delete is Done!\n");
            printf(RESET);
            printf(GRN "Press any key to continue..." RESET "\n");
            while (!getch())
                ;
            break;

        case Destroy:
            system("cls");
            DeleteAllScheme();
            printf("\n");
            if (isEmpty(&myList))
            {
                printf(RED);
                printf("List is Empty\n");
                printf(RESET);
                printf(GRN "Press any key to continue..." RESET "\n");
                while (!getch())
                    ;
                break;
            }
            printf(REDB "Are you sure?" RESET "\n");
            printf("\t" GRN "1.Yes" RESET "\n");
            printf("\t" RED "2.No" RESET "\n");
            printf(BLU ">> ");
            scanf("%d", &destroy_choice);
            printf(RESET);
            if (destroy_choice == 2)
                break;
            else
            {
                system("cls");
                DeleteAllScheme();
            }
            destroy(&myList);
            printf(REDB);
            printf("DELETE DONE!\n");
            printf(RESET);
            printf(GRN "Press any key to continue..." RESET "\n");
            while (!getch())
                ;
            break;

        case Search:
            system("cls");
            SearchScheme();
            if (isEmpty(&myList))
            {
                printf(RED);
                printf("List is Empty\n");
                printf(RESET);
                printf(GRN "Press any key to continue..." RESET "\n");
                while (!getch())
                    ;
                break;
            }
            printf("\n");
            printf("Enter the ID: ");
            scanf("%d", &searchID);
            fflush(stdin);
            foundStu = search(&myList, searchID);
            LoadingScheme();
            if (foundStu == NULL)
            {
                printf(RED);
                printf("No data was found.\n");
                printf(RESET);
                printf(GRN "Press any key to continue..." RESET "\n");
                while (!getch())
                    ;
                break;
            }
            printStruct(foundStu->stu);

            printf(GRN "Press any key to continue..." RESET "\n");
            while (!getch())
                ;
            break;

        case Count:
            system("cls");
            ListSizeScheme();
            if (isEmpty(&myList))
            {
                printf(RED);
                printf("List is Empty\n");
                printf(RESET);
                printf(GRN "Press any key to continue..." RESET "\n");
                while (!getch())
                    ;
                break;
            }

            printf(GRN "There is/are %d student(s)\n" RESET, listlen(&myList));
            printf(GRN "Press any key to continue..." RESET "\n");
            while (!getch())
                ;
            break;

        case Rank:
            system("cls");
            ScoreScheme();
            sortbysocreD(&myList);
            if (isEmpty(&myList))
            {
                printf(RED);
                printf("List is Empty\n");
                printf(RESET);
                printf(GRN "Press any key to continue..." RESET "\n");
                while (!getch())
                    ;
                break;
            }
            printList(&myList);
            printf(GRN "Press any key to continue..." RESET "\n");
            while (!getch())
                ;
            break;

        case Edit:
            system("cls");
            EditScheme();
            printf("\n");
            if (isEmpty(&myList))
            {
                printf(RED);
                printf("List is Empty\n");
                printf(RESET);
                printf(GRN "Press any key to continue..." RESET "\n");
                while (!getch())
                    ;
                break;
            }
            printf("Enter the ID: ");
            scanf("%d", &searchID);
            fflush(stdin);
            foundStu = search(&myList, searchID);
            if (foundStu == NULL)
            {
                printf(RED);
                printf("Not Found.\n");
                printf(RESET);
                printf("Press any key to cotinue...\n");
                while (!getch())
                    ;
                break;
            }
            edit(&myList, foundStu);
            printf(GRN "Press any key to continue..." RESET "\n");
            while (!getch())
                ;
            break;

        case Sort:
            system("cls");
            SortScheme();
            printf("\n");
            if (isEmpty(&myList))
            {
                printf(RED);
                printf("List is Empty\n");
                {
                    printf(RESET);
                    printf(GRN "Press any key to continue..." RESET "\n");
                    while (!getch())
                        ;
                    break;
                }
            }

            printf("How do you want to sort?\n");
            printf("By:\n");
            printf("\t1.ID\n");
            printf("\t2.Name\n");
            printf("\t3.Arabic Degree\n");
            printf("\t4.English Degree\n");
            printf("\t5.Math Degree\n");
            printf("\t6.Computer Science Degree\n");
            printf(">> ");
            scanf("%d", &sort_choice);
            fflush(stdin);

            printf(GRN "Choose Sort Direction:" RESET "\n");
            printf(YEL "\t1.    Ascending" RESET "\n");
            printf(YEL "\telse. Descending" RESET "\n");
            printf(YEL ">> ");
            scanf("%d", &sort_dir);
            printf(RESET);

            switch (sort_choice)
            {
            case 1:
                system("cls");
                (sort_dir == 1) ? sortbyidA(&myList) : sortbyidD(&myList);
                printf(GRN);
                printf("Sort is done!\n");
                printf(RESET);

                break;
            case 2:
                system("cls");
                (sort_dir == 1) ? sortbynameA(&myList) : sortbynameD(&myList);
                printf(GRN);
                printf("Sort is done!\n");
                printf(RESET);

                break;

            case 3:
                system("cls");
                (sort_dir == 1) ? sortbyarA(&myList) : sortbyarD(&myList);
                printf(GRN);
                printf("Sort is done!\n");
                printf(RESET);

                break;

            case 4:
                system("cls");
                (sort_dir == 1) ? sortbyenA(&myList) : sortbyenD(&myList);
                printf(GRN);
                printf("Sort is done!\n");
                printf(RESET);

                break;

            case 5:
                system("cls");
                (sort_dir == 1) ? sortbymathA(&myList) : sortbymathD(&myList);
                printf(GRN);
                printf("Sort is done!\n");
                printf(RESET);

                break;

            case 6:
                system("cls");
                (sort_dir == 1) ? sortbycsA(&myList) : sortbycsD(&myList);
                printf(GRN);
                printf("Sort is done!\n");
                printf(RESET);

                break;

            default:

                printf(RED "Invalid Choice" RESET "\n");
                break;
            }

            printf(GRN "Press any key to continue..." RESET "\n");
            while (!getch())
                ;
            break;

        case Exit:
            system("cls");
            printf(RED);
            printf("Exiting program...\n");
            printf(RESET);
            break;

        default:
            system("cls");
            printf(RED);
            printf("Invalid choice.\n");
            printf(RESET);
            printf(GRN "Press any key to continue..." RESET "\n");
            while (!getch())
                ;
            break;
        }

        user_choice = (user_choice == 0) ? 0 : -1;
    } while (user_choice != 0);
}

void initList(list *myList)
{
    myList->head = NULL;
    myList->tail = NULL;
    myList->list_size = 0;
}
bool isEmpty(list *myList)
{
    // printf("List is Empty.\n");
    return (myList->head == NULL) ? true : false;
}
void append(list *myList, student stu)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf(RED "No available memory" RESET "\n");
        return;
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    if (isEmpty(myList))
    {
        myList->head = newNode;
        myList->tail = newNode;
    }
    else
    {
        myList->tail->next = newNode;
        newNode->prev = myList->tail;
        myList->tail = newNode;
    }
    newNode->stu = stu;
    myList->list_size += 1;
}

void insert(list *myList, student stu)
{
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("No Available Memory\n");
        return;
    }
    newNode->stu = stu;
    newNode->prev = NULL;
    newNode->next = NULL;
    myList->list_size++;
    if (myList->head == NULL)
    {
        myList->head = newNode;
        myList->tail = newNode;
    }
    else
    {
        node *current = myList->head;
        while (current != NULL && current->stu.id < stu.id)
        {
            current = current->next;
        }
        if (current == NULL)
        {
            myList->tail->next = newNode;
            newNode->prev = myList->tail;
            myList->tail = newNode;
        }
        else if (current == myList->head)
        {
            myList->head->prev = newNode;
            newNode->next = myList->head;
            myList->head = newNode;
        }
        else
        {
            current->prev->next = newNode;
            newNode->prev = current->prev;
            current->prev = newNode;
            newNode->next = current;
        }
    }
}

void LoadingScheme()
{
    for (int i = 0; i <= 100; i++)
    {
        printf("%d%%\n", i);
        for (int j = 0; j < i; j++)
        {
            printf("\xdb");
        }
        delay(30);
        system("cls");
    }
}

void printStruct(student stu)
{
    printf(CYN);
    printf("Student Personal Information:\n");
    printf("\nID: ");
    printf("%d", stu.id);

    printf("\nName: ");
    printf("%s", stu.name);

    printf("Grade: ");
    printf("%s", stu.grade);

    printf("Date of birth: ");
    printf("%d/%d/%d", (stu.date.day), (stu.date.month), (stu.date.year));

    printf("\nAddress:\n");
    printf("\tstreet name: ");
    printf("%s", stu.adrs.st);

    printf("\tBlock Name: ");
    printf("%s", stu.adrs.block_name);

    printf("\tblock number: ");
    printf("%d\n", stu.adrs.block_number);

    printf("\nSubjects Grade:\n");
    printf("\tArabic: ");
    printf("%d / 50\n", stu.degree.ar);

    printf("\tEnglish: ");
    printf("%d / 50\n", stu.degree.en);

    printf("\tMath: ");
    printf("%d / 50\n", stu.degree.math);

    printf("\tComputer Sceince: ");
    printf("%d / 50\n", stu.degree.cs);

    printf("\nTotal: %d/ 200\n", stu.degree.total);

    printf("Average: %.2f\n", stu.degree.avr);

    printf("In percentage:  %.2f%c \n", stu.degree.inprsntg, '%');
    printf(RESET "------------------------------\n");
}

void printList(list *myList)
{
    if (isEmpty(myList))
        return;
    node *temp = myList->head;
    while (temp != NULL)
    {
        printStruct(temp->stu);
        temp = temp->next;
    }
}

int listlen(list *myList)
{
    if (isEmpty(myList))
        return 0;
    return myList->list_size;
}

void delete(list *myList, node *myNode)
{
    if (isEmpty(myList))
        return;
    if (myNode == myList->head)
    {
        myList->head = myNode->next;
        myList->head->prev = NULL;
        myNode->next = NULL;
    }
    else if (myNode == myList->tail)
    {
        myList->tail = myNode->prev;
        myList->tail->next = NULL;
        myNode->prev = NULL;
    }
    else
    {
        myNode->next->prev = myNode->prev;
        myNode->prev->next = myNode->next;
        myNode->next = NULL;
        myNode->prev = NULL;
    }
    free(myNode);
    myList->list_size -= 1;
}

student scanStruct(list *myList, student stu)
{
    stu.degree.total = 0;
    int tempId, tempDeg, tempDay, tempMonth, tempYear;
    node *foundNode, *Temp;
    printf("Please Enter Student Data\n");
    printf("Id: ");
    scanf("%d", &tempId);
    fflush(stdin);

    Temp = search(myList, tempId);
    while (Temp != NULL && Temp->stu.id == tempId && tempId > 0)
    {
        printf(RED);
        printf("\nThis ID already exists.\nPlease enter another one. \n");
        printf(RESET);
        printf("Id: ");
        scanf("%d", &tempId);
        fflush(stdin);

        Temp = myList->head;

        while (Temp != NULL && Temp->stu.id != tempId && tempId > 0)
        {
            Temp = Temp->next;
        }
    }
    while (tempId <= 0)
    {
        printf(RED);
        printf("Please Enter a valid ID.\n");
        printf(RESET);
        printf("ID: ");
        scanf("%d", &tempId);
        fflush(stdin);
    }

    stu.id = tempId;

    printf("Name: ");
    fgets(stu.name, sizeof(stu.name), stdin);

    printf("Grade: ");
    fgets(stu.grade, sizeof(stu.grade), stdin);
    fflush(stdin);

    printf("day/month/year: ");
    scanf("%d/%d/%d", &(stu.date.day), &(stu.date.month), &(stu.date.year));
    fflush(stdin);

    printf("\nAddress:\n");
    printf("\tstreet name: ");
    fgets(stu.adrs.st, sizeof(stu.adrs.st), stdin);

    printf("\tblock name: ");
    fgets(stu.adrs.block_name, sizeof(stu.adrs.block_name), stdin);

    printf("\tblock number: ");
    scanf("%d", &(stu.adrs.block_number));
    fflush(stdin);

    printf("\nEnter student degrees: \n");
    printf("\tArabic: ");
    scanf("%d", &tempDeg);
    fflush(stdin);
    while (tempDeg > 50 || tempDeg < 0)
    {
        printf(RED);
        printf("\tPlease Enter a valid degree.\n");
        printf(RESET);
        printf("\tArabic: ");
        scanf("%d", &tempDeg);
        fflush(stdin);
    }
    stu.degree.ar = tempDeg;

    printf("\tEnglish: ");
    scanf("%d", &tempDeg);
    fflush(stdin);
    while (tempDeg > 50 || tempDeg < 0)
    {
        printf(RED);
        printf("\tPlease Enter a valid degree.\n");
        printf(RESET);
        printf("\tEnglish: ");
        scanf("%d", &tempDeg);
        fflush(stdin);
    }
    stu.degree.en = tempDeg;

    printf("\tMath: ");
    scanf("%d", &tempDeg);
    fflush(stdin);
    while (tempDeg > 50 || tempDeg < 0)
    {
        printf(RED);
        printf("\tPlease Enter a valid degree.\n");
        printf(RESET);
        printf("\tMath: ");
        scanf("%d", &tempDeg);
        fflush(stdin);
    }
    stu.degree.math = tempDeg;

    printf("\tComputer Sceince : ");
    scanf("%d", &tempDeg);
    fflush(stdin);
    while (tempDeg > 50 || tempDeg < 0)
    {
        printf(RED);
        printf("\tPlease Enter a valid degree.\n");
        printf(RESET);
        printf("\tComputer Sceince : ");
        scanf("%d", &tempDeg);
        fflush(stdin);
    }
    stu.degree.cs = tempDeg;
    stu.degree.total = stu.degree.ar + stu.degree.en + stu.degree.math + stu.degree.cs;
    stu.degree.avr = ((float)(stu.degree.ar + stu.degree.en + stu.degree.math + stu.degree.cs) / 4);
    stu.degree.inprsntg = ((float)(stu.degree.ar + stu.degree.en + stu.degree.math + stu.degree.cs) / 200) * 100;
    printf("------------------------------\n");
    return stu;
}

node *search(list *myList, int id)
{
    if (isEmpty(myList))
        return NULL;
    node *temp = myList->head;
    while (temp != NULL && temp->stu.id != id)
    {
        temp = temp->next;
    }
    return temp;
}

void destroy(list *myList)
{
    if (isEmpty(myList))
        return;
    node *temp = myList->head;
    while (temp != NULL)
    {
        temp = temp->next;
        free(myList->head);
        myList->head = temp;
    }
    myList->head = NULL;
    myList->list_size = 0;
}

void edit(list *myList, node *foundStu)
{
    int choice, tempint;
    char tempchar[15];
    if (foundStu == NULL)
    {
        printf(RED);
        printf("Student not found.");
        printf(RESET);
        return;
    }
    printf("Wht do you want to edit?\n");
    printf("\t1. ID\n");
    printf("\t2. Name\n");
    printf("\t3. Grade\n");
    printf("\t4. Date of Birth\n");
    printf("\t5. Address\n");
    printf("\t6. Arabic Degree\n");
    printf("\t7. English Degree\n");
    printf("\t8. Math Degree\n");
    printf("\t9. Cmoputer Sceince Degree\n");
    printf("\t10.Edit All\n");
    printf(">> ");
    scanf("%d", &choice);
    fflush(stdin);

    switch (choice)
    {
    case ID:
        printf("Enter the new ID:");
        scanf("%d", &tempint);
        fflush(stdin);

        node *Temp = search(myList, tempint);

        while (Temp != NULL && Temp->stu.id == tempint && tempint > 0)
        {
            printf(RED);
            printf("\nThis ID already exists.\nPlease enter a new one. \n");
            printf(RESET);
            printf("Enter the New ID: ");
            scanf("%d", &tempint);
            fflush(stdin);

            Temp = myList->head;

            Temp = search(myList, tempint);
            while (Temp != NULL && Temp->stu.id != tempint && tempint > 0)
            {
                Temp = Temp->next;
            }
        }
        while (tempint <= 0)
        {
            printf(RED);
            printf("Please Enter a valid ID.\n");
            printf(RESET);
            printf("ID: ");
            scanf("%d", &tempint);
            fflush(stdin);
        }

        foundStu->stu.id = tempint;
        break;

    case NAME:
        printf("Enter the new Name: ");
        fgets(foundStu->stu.name, sizeof(foundStu->stu.name), stdin);
        break;
    case GRADE:
        printf("Enter the new Name: ");
        fgets(foundStu->stu.grade, sizeof(foundStu->stu.grade), stdin);
        break;
    case DOB:
        printf("Enter the new Birth Date: ");
        scanf("%d/%d/%d", &(foundStu->stu.date.day), &(foundStu->stu.date.month), &(foundStu->stu.date.year));
        fflush(stdin);
        break;
    case ADDRESS:
        printf("Enter the new Address: ");
        printf("\tStreet Name: ");
        fgets(foundStu->stu.adrs.st, sizeof(foundStu->stu.adrs.st), stdin);
        printf("\tBlock Name: ");
        fgets(foundStu->stu.adrs.block_name, sizeof(foundStu->stu.adrs.block_name), stdin);
        printf("\tBlock Number: ");
        scanf("%d", &(foundStu->stu.adrs.block_number));
        fflush(stdin);
        break;
    case AR:
        printf("Enter student degrees: \n");
        printf("\tArabic: ");
        scanf("%d", &tempint);
        fflush(stdin);

        while (tempint > 50 || tempint < 0)
        {
            printf(RED);
            printf("\tPlease Enter a valid degree.\n");
            printf(RESET);
            printf("\tArabic: ");
            scanf("%d", &tempint);
            fflush(stdin);
        }
        foundStu->stu.degree.ar = tempint;
        break;
    case EN:
        printf("Enter student degrees: \n");
        printf("\tEnglish: ");
        scanf("%d", &tempint);
        fflush(stdin);

        while (tempint > 50 || tempint < 0)
        {
            printf(RED);
            printf("\tPlease Enter a valid degree.\n");
            printf(RESET);
            printf("\tEnglish: ");
            scanf("%d", &tempint);
            fflush(stdin);
        }
        foundStu->stu.degree.en = tempint;
        break;
    case MATH:
        printf("Enter student degrees: \n");
        printf("\tMath: ");
        scanf("%d", &tempint);
        fflush(stdin);

        while (tempint > 50 || tempint < 0)
        {
            printf(RED);
            printf("\tPlease Enter a valid degree.\n");
            printf(RESET);
            printf("\tMath: ");
            scanf("%d", &tempint);
            fflush(stdin);
        }
        foundStu->stu.degree.math = tempint;
        break;
    case CS:
        printf("Enter student degrees: \n");
        printf("\tCoumpter Sceince: ");
        scanf("%d", &tempint);
        fflush(stdin);

        while (tempint > 50 || tempint < 0)
        {
            printf(RED);
            printf("\tPlease Enter a valid degree.\n");
            printf(RESET);
            printf("\tCoumpter Sceince: ");
            scanf("%d", &tempint);
            fflush(stdin);
        }
        foundStu->stu.degree.cs = tempint;
        break;
    case ALL:
        printf("Enter the new ID:");
        scanf("%d", &tempint);
        fflush(stdin);

        Temp = search(myList, tempint);

        while (Temp != NULL && Temp->stu.id == tempint && tempint > 0)
        {
            printf(RED);
            printf("\nThis ID already exists.\nPlease enter another one. \n");
            printf(RESET);
            printf("Enter the new ID: ");
            scanf("%d", &tempint);
            fflush(stdin);

            Temp = myList->head;

            Temp = search(myList, tempint);
            while (Temp != NULL && Temp->stu.id != tempint && tempint > 0)
            {
                Temp = Temp->next;
            }
        }
        foundStu->stu.id = tempint;

        printf("Enter the New Name: ");
        fgets(foundStu->stu.name, sizeof(foundStu->stu.name), stdin);

        printf("Enter the New Grade: ");
        fgets(foundStu->stu.grade, sizeof(foundStu->stu.grade), stdin);

        printf("Enter the New Birth Date: ");
        scanf("%d/%d/%d", &(foundStu->stu.date.day), &(foundStu->stu.date.month), &(foundStu->stu.date.year));
        fflush(stdin);

        printf("Enter the New Address: \n");
        printf("\tStreet Name: ");
        fgets(foundStu->stu.adrs.st, sizeof(foundStu->stu.adrs.st), stdin);
        printf("\tBlock Name: ");
        fgets(foundStu->stu.adrs.block_name, sizeof(foundStu->stu.adrs.block_name), stdin);
        printf("\tBlock Number: ");
        scanf("%d", &(foundStu->stu.adrs.block_number));
        fflush(stdin);

        printf("Enter student degrees: \n");
        printf("\tArabic: ");
        scanf("%d", &tempint);
        fflush(stdin);

        while (tempint > 50 || tempint < 0)
        {
            printf(RED);
            printf("\tPlease Enter a valid degree.\n");
            printf(RESET);
            printf("\tArabic: ");
            scanf("%d", &tempint);
            fflush(stdin);
        }
        foundStu->stu.degree.ar = tempint;

        printf("\tEnglish: ");
        scanf("%d", &tempint);
        fflush(stdin);

        while (tempint > 50 || tempint < 0)
        {
            printf(RED);
            printf("\tPlease Enter a valid degree.\n");
            printf(RESET);
            printf("\tEnglish: ");
            scanf("%d", &tempint);
            fflush(stdin);
        }
        foundStu->stu.degree.en = tempint;

        printf("\tMath: ");
        scanf("%d", &tempint);
        fflush(stdin);

        while (tempint > 50 || tempint < 0)
        {
            printf(RED);
            printf("\tPlease Enter a valid degree.\n");
            printf(RESET);
            printf("\tMath: ");
            scanf("%d", &tempint);
            fflush(stdin);
        }
        foundStu->stu.degree.math = tempint;

        printf("\tCoumpter Sceince: ");
        scanf("%d", &tempint);
        fflush(stdin);

        while (tempint > 50 || tempint < 0)
        {
            printf(RED);
            printf("\tPlease Enter a valid degree.\n");
            printf(RESET);
            printf("\tCoumpter Sceince: ");
            scanf("%d", &tempint);
            fflush(stdin);
        }
        foundStu->stu.degree.cs = tempint;
        break;
    default:
        printf("Invalid Choice\n");
        break;
    }
}

void sortbyidD(list *myList)
{
    student swap;
    for (node *temp = myList->head; temp != NULL; temp = temp->next)
    {
        for (node *tempn = temp->next; tempn != NULL; tempn = tempn->next)
        {
            if (temp->stu.id < tempn->stu.id)
            {
                swap = temp->stu;
                temp->stu = tempn->stu;
                tempn->stu = swap;
            }
        }
    }
}
void sortbynameD(list *myList)
{
    student swap;
    for (node *temp = myList->head; temp != NULL; temp = temp->next)
    {
        for (node *tempn = temp->next; tempn != NULL; tempn = tempn->next)
        {
            if (strcmp(temp->stu.name, tempn->stu.name) == -1)
            {
                swap = temp->stu;
                temp->stu = tempn->stu;
                tempn->stu = swap;
            }
        }
    }
}
void sortbysocreD(list *myList)
{
    student swap;
    for (node *temp = myList->head; temp != NULL; temp = temp->next)
    {
        for (node *tempn = temp->next; tempn != NULL; tempn = tempn->next)
        {
            if (temp->stu.degree.total < tempn->stu.degree.total)
            {
                swap = temp->stu;
                temp->stu = tempn->stu;
                tempn->stu = swap;
            }
        }
    }
}
void sortbyarD(list *myList)
{
    student swap;
    for (node *temp = myList->head; temp != NULL; temp = temp->next)
    {
        for (node *tempn = temp->next; tempn != NULL; tempn = tempn->next)
        {
            if (temp->stu.degree.ar < tempn->stu.degree.ar)
            {
                swap = temp->stu;
                temp->stu = tempn->stu;
                tempn->stu = swap;
            }
        }
    }
}
void sortbyenD(list *myList)
{
    student swap;
    for (node *temp = myList->head; temp != NULL; temp = temp->next)
    {
        for (node *tempn = temp->next; tempn != NULL; tempn = tempn->next)
        {
            if (temp->stu.degree.en < tempn->stu.degree.en)
            {
                swap = temp->stu;
                temp->stu = tempn->stu;
                tempn->stu = swap;
            }
        }
    }
}
void sortbymathD(list *myList)
{
    student swap;
    for (node *temp = myList->head; temp != NULL; temp = temp->next)
    {
        for (node *tempn = temp->next; tempn != NULL; tempn = tempn->next)
        {
            if (temp->stu.degree.math < tempn->stu.degree.math)
            {
                swap = temp->stu;
                temp->stu = tempn->stu;
                tempn->stu = swap;
            }
        }
    }
}
void sortbycsD(list *myList)
{
    student swap;
    for (node *temp = myList->head; temp != NULL; temp = temp->next)
    {
        for (node *tempn = temp->next; tempn != NULL; tempn = tempn->next)
        {
            if (temp->stu.degree.cs < tempn->stu.degree.cs)
            {
                swap = temp->stu;
                temp->stu = tempn->stu;
                tempn->stu = swap;
            }
        }
    }
}

void sortbyidA(list *myList)
{
    student swap;
    for (node *temp = myList->head; temp != NULL; temp = temp->next)
    {
        for (node *tempn = temp->next; tempn != NULL; tempn = tempn->next)
        {
            if (temp->stu.id > tempn->stu.id)
            {
                swap = temp->stu;
                temp->stu = tempn->stu;
                tempn->stu = swap;
            }
        }
    }
}
void sortbynameA(list *myList)
{
    student swap;
    for (node *temp = myList->head; temp != NULL; temp = temp->next)
    {
        for (node *tempn = temp->next; tempn != NULL; tempn = tempn->next)
        {
            if (strcmp(temp->stu.name, tempn->stu.name) == 1)
            {
                swap = temp->stu;
                temp->stu = tempn->stu;
                tempn->stu = swap;
            }
        }
    }
}

void sortbyarA(list *myList)
{
    student swap;
    for (node *temp = myList->head; temp != NULL; temp = temp->next)
    {
        for (node *tempn = temp->next; tempn != NULL; tempn = tempn->next)
        {
            if (temp->stu.degree.ar > tempn->stu.degree.ar)
            {
                swap = temp->stu;
                temp->stu = tempn->stu;
                tempn->stu = swap;
            }
        }
    }
}
void sortbyenA(list *myList)
{
    student swap;
    for (node *temp = myList->head; temp != NULL; temp = temp->next)
    {
        for (node *tempn = temp->next; tempn != NULL; tempn = tempn->next)
        {
            if (temp->stu.degree.en > tempn->stu.degree.en)
            {
                swap = temp->stu;
                temp->stu = tempn->stu;
                tempn->stu = swap;
            }
        }
    }
}
void sortbymathA(list *myList)
{
    student swap;
    for (node *temp = myList->head; temp != NULL; temp = temp->next)
    {
        for (node *tempn = temp->next; tempn != NULL; tempn = tempn->next)
        {
            if (temp->stu.degree.math > tempn->stu.degree.math)
            {
                swap = temp->stu;
                temp->stu = tempn->stu;
                tempn->stu = swap;
            }
        }
    }
}
void sortbycsA(list *myList)
{
    student swap;
    for (node *temp = myList->head; temp != NULL; temp = temp->next)
    {
        for (node *tempn = temp->next; tempn != NULL; tempn = tempn->next)
        {
            if (temp->stu.degree.cs > tempn->stu.degree.cs)
            {
                swap = temp->stu;
                temp->stu = tempn->stu;
                tempn->stu = swap;
            }
        }
    }
}