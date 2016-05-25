#ifndef FUNCTIONS
#define FUNCTIONS

#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX_STUD 2

/* Student Registration */
int fnRegister(int iStudCount, sStud fStudentList[], int iArraySize)
{
    FILE * fOut = fopen("StdDatabase.txt", "a+");
    sStud* fTemp;

    printf("\n\t\tREGISTER\n\n");

    /* Temp means of checking size... expires upon program termination. Need to use SEEK somehow.*/
    if(iStudCount < iArraySize)
    {
        printf("\nEnter a Student ID: ");
        scanf(" %lu", &fStudentList[iStudCount].ulID);
        fprintf(fOut, "%-10lu", fStudentList[iStudCount].ulID);

        printf("\nEnter a Student Name: ");
        scanf(" %39[^\n]", fStudentList[iStudCount].cName);
        fprintf(fOut," %-39s", fStudentList[iStudCount].cName);

        printf("\nEnter a Student E-mail: ");
        scanf(" %39[^\n]", fStudentList[iStudCount].cEMail);
        fprintf(fOut, " %-39s", fStudentList[iStudCount].cEMail);

        printf("\nEnter a Student GPA: ");
        scanf("%f", &fStudentList[iStudCount].fGPA);
        fprintf(fOut, "%1.2f\n", fStudentList[iStudCount].fGPA);
        printf("\n\n");

        iArraySize = sizeof(fStudentList[iStudCount]);

        ++iStudCount;
    }

    if(iStudCount >= iArraySize)
    {
        printf("Expanding memory ... Run this option again.\n\n");
        fTemp = (sStud*) realloc(fStudentList, 10);//(sStud*) malloc(10 * sizeof(sStud) ); // pointer = (type 'cast') malloc (size in bytes);

        if (fTemp == NULL)
        {
            printf("Error allocating memory.\n\n");
            free(fTemp);
        }
        fStudentList = fTemp;
    }

    fclose(fOut);

    return iStudCount;
}

/* Print List of Students */
void fnPrint(int iStudCount, sStud fStudentList[])
{
    int i = 0;

    printf("\n\t\tPRINT\n");
    printf("\t\tTotal # of Students: %i\n\n", iStudCount);
    for(i = 0; i < iStudCount; ++i)
    {
        printf("\n\t\tSTUDENT %i\n\n", i+1);
        printf("ID\t\t\tName\n");
        printf("--\t\t\t----\n");
        printf("%lu\t\t\t%s\n\n", fStudentList[i].ulID, fStudentList[i].cName);
        printf("E-Mail\t\t\tGPA\n");
        printf("------\t\t\t---\n");
        printf("%s\t\t%0.2f\n", fStudentList[i].cEMail, fStudentList[i].fGPA);
    }
}

/* Print from File */
void fnPrintFromFile()
{
    printf("\n\t\tPRINT FROM FILE\n\n");

    FILE * fIn = fopen("C:\\Dropbox\\School Work\\Computer Science - Graduate\\Intermediate Programming (C)\\Intermediate Projects - C\\StudentRegistrationSTREAM\\StdDatabase.txt", "r");
    int c;

    if (fIn)
    {
        while((c = getc(fIn)) != EOF)
        {
            putchar(c);
        }
        fclose(fIn);
    }
    else
    {
        printf("Error. File must exist.\n\n");
    }
}

/* Find a Student */
void fnFind(int iStudCount, sStud fStudentList[])
{
    char    cSearch[40] = {"Student Name"};
    int     iCompare = 0, i = 0;

    printf("\n\t\tFIND\n\n");
    printf("Enter a Name: ");
    scanf(" %39[^\n]", cSearch);

    for(i = 0; i < iStudCount; ++i)
    {
        iCompare = strcmp(cSearch, fStudentList[i].cName);
        if(iCompare == 0)
        {
            printf("Student located ...\n\n");
            printf("\n\t\tSTUDENT %i\n\n", i+1);
            printf("ID\t\t\tName\n");
            printf("--\t\t\t----\n");
            printf("%lu\t\t\t%s\n\n", fStudentList[i].ulID, fStudentList[i].cName);
            printf("E-Mail\t\t\tGPA\n");
            printf("------\t\t\t---\n");
            printf("%s\t\t%0.2f\n", fStudentList[i].cEMail, fStudentList[i].fGPA);

            return;
        }
    }
    printf("\n\t\tStudent could not be located.\n\n");
}

#endif // FUNCTIONS

