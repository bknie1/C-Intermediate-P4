#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "sstudent.h"
#include "functions.h"

#define MENU_MAX 6

/*
    module      :   StdRegSt.c, sstudent.h
    Description :   Student Registration Program
    Author      :   Brandon Knieriem
    Rev History :

    Date        Comment
    ----        -------
    11/8        Program creation.
    11/9        Basic functionality. Registration Function needs troubleshooting.
    11/10       Registration and Print Functions are somewhat reliable. Needs troubleshooting.
    11/11       Find Function implementation. All functions working properly. Print Function is a lot cleaner.
    11/15       Began implementing Stream functionality.
    11/18       You can stream input/output using the StudentDatabase.txt file. The new Print from File function
                isn't the prettiest but it works.
    12/3        Added a header file for the Student List struct.
    12/8        Added a header file for the functions.
    12/9        Added dynamic memory allocation.

    Notes:
    ------
    -   You can print directly from the text file. Kind of cool, but the formatting is garbage because of the
        size of the array. If you allow 40 chars for name and e-mail you can't print it back into the console
        without some misalignment. Still, I'm glad I figured out how to do it.

*/

int     fnRegister(int iSC, sStud fSL[], int iAS);
void    fnPrint(int iSC, sStud fSL[]);
void    fnPrintFromFile();
void    fnFind(int iSC, sStud fSL[]);

int main(void)
{
    /* Student List Array */
    int         iStudCount = 0;
    int         iArraySize = MAX_STUD;
    sStud       fStudentList[MAX_STUD];

    /* Quick Menu Array */
    const char  * cMenu[] = {"Register New Student",     "Print Student List", "Print from File",
                            "Find Student ID by Name",  "Quit"};
    int         i = 1, iUSel = 0;

    do
    {   /* Quick Menu */
        printf("\n\n\t\tRegistration System Main Menu\n\n");

        /* Print Loop */
        for (i = 1; i < MENU_MAX; ++i)
        {
            printf("%i. %s\n", i, cMenu[i-1]);
        }

        printf("\nSelection: ");
        scanf("%i", &iUSel);

        switch(iUSel)
        {
        /* Register */
        case 1 :
        {
            iStudCount = fnRegister(iStudCount, fStudentList, iArraySize);
            break;
        }
        /* Print */
        case 2 :
        {
            if(iStudCount != 0)
            {
                fnPrint(iStudCount, fStudentList);
                break;
            }
            else
            {
                printf("No students located. Populate the database first.");
                break;
            }
        }
        /* Print from File */
        case 3 :
        {
            fnPrintFromFile();
            break;
        }
        /* Find */
        case 4 :
        {
            if(iStudCount != 0)
            {
                fnFind(iStudCount, fStudentList);
                break;
            }
            else
            {
                printf("No students located. Populate the database first.");
                break;
            }
        }
        /* Quit */
        case 5 :
        {
            printf("\nShutting down ...\n\n");
            break;
        }
        /* Error */
        default :
        {
            printf("\nInvalid input.\n\n");
            break;
        }
        }
    }
    while (iUSel != 5);

    return 0;
}
