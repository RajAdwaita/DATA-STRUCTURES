

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Details
{
    char regNo[20];
    char nameStudent[50];

    char schoolName[50];

    float cg;
} Student;

int main()
{
    int n = 2;
    Student students[n];
    for (int i = 0; i < n; i++)
    {
        fgets(students[i].regNo, 20, stdin);
        fgets(students[i].nameStudent, 50, stdin);

        fgets(students[i].schoolName, 50, stdin);

        scanf("%f", &students[i].cg);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].cg < students[j + 1].cg)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n%s", students[i].regNo);

        printf("\n%s", students[i].nameStudent);
        printf("\n %s", students[i].schoolName);

        printf("\n %.2f", students[i].cg);
        printf("\n\n");
    }
end:
    return 0;
}
