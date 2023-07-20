#include <stdio.h>
#include <string.h>

struct Point
{
    float pointMath;
    float pointEnglish;
    float pointPhilology; // môn ngữ văn;
    float pointAverageGrade;
};
struct Student
{
    char name[30];
    int age;
    char studentCode[4];
    struct Point point;
};
typedef struct listStudent
{
    struct Student stu[100];
    int order;
} listStu;

void initializeList(listStu *);
void displayList(listStu *);
void addStudent(listStu *, int *);
void editStudent(listStu *);
void calculateAverageGrade(listStu *, int);
void sortListStudent(listStu *);
void removeStudent(listStu *);
void saveToFile(listStu *, int *);
void readFile(listStu *);
void print_column_in_file(listStu *);
int main()
{
    listStu list;
    initializeList(&list);
    int index_old = list.order;
    int option;
    printf("\nApp Student Management design by Hoang:");
    printf("\n\t0. Exit");
    printf("\n\t1. Add students to the list.");
    printf("\n\t2. Edit List Student.");
    printf("\n\t3. Sort List Student.");
    printf("\n\t4. Remove Students to the list.");
    printf("\n\t5. Display List Student.");
    printf("\n\t6. Read List Student from file.");
    printf("\n\t7. Save list Student to file.");
    do
    {
        printf("\nEnter My Option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 0:
            break;
        case 1:
            addStudent(&list, &index_old);
            break;
        case 2:
            editStudent(&list);
            break;
        case 3:
            sortListStudent(&list);
            break;
        case 4:
            removeStudent(&list);
            break;
        case 5:
            displayList(&list);
            break;
        case 6:
            readFile(&list);
            break;
        case 7:
            saveToFile(&list, &index_old);
            break;
        default:
            break;
        }
    } while (option);
}

void initializeList(listStu *ptr)
{
    ptr->order = 0;
    FILE *file = fopen("sv.txt", "r");
    int ch = fgetc(file);
    if (ch == EOF)
    {
        print_column_in_file(ptr);
    }
}
void displayList(listStu *ptr)
{
    printf("\nList Student:");
    printf("\n%-10s %-30s %-10s %-20s %-15s %-15s %-15s %-30s", "STT", "Name", "Age", "Student Code", "Point Math", "Point English", "Point Philology", "Point the average grade");
    for (int i = 0; i < ptr->order; i++)
    {
        printf("\n%-10d %-30s %-10d %-20s %-15.2f %-15.2f %-15.2f %-30.2f", i + 1, ptr->stu[i].name, ptr->stu[i].age, ptr->stu[i].studentCode, ptr->stu[i].point.pointMath, ptr->stu[i].point.pointEnglish, ptr->stu[i].point.pointPhilology, ptr->stu[i].point.pointAverageGrade);
    }
}
void addStudent(listStu *ptr, int *index_old)
{
    *index_old = ptr->order;
    if (ptr->order > 100)
        return;
    int n;
    printf("\nEnter the number of students to add:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        ptr->order += 1;
        printf("\nEnter the name of the student with the order number %d: ", ptr->order);
        getchar(); // Đọc ký tự newline còn lại trong bộ đệm
        fgets(ptr->stu[ptr->order - 1].name, sizeof(ptr->stu[ptr->order - 1].name), stdin);
        ptr->stu[ptr->order - 1].name[strcspn(ptr->stu[ptr->order - 1].name, "\n")] = '\0';
        printf("\nEnter age of the student with the order number %d: ", ptr->order);
        scanf("%d", &ptr->stu[ptr->order - 1].age);
        printf("\nEnter the student code of the student with the order number %d: ", ptr->order);
        getchar();
        fgets(ptr->stu[ptr->order - 1].studentCode, sizeof(ptr->stu[ptr->order - 1].studentCode), stdin);
        ptr->stu[ptr->order - 1].studentCode[strcspn(ptr->stu[ptr->order - 1].studentCode, "\n")] = '\0';
        printf("\nEnter the point Math of the student with the order number %d: ", ptr->order);
        scanf("%f", &ptr->stu[ptr->order - 1].point.pointMath);
        printf("\nEnter the point Philology of the student with the order number %d: ", ptr->order);
        scanf("%f", &ptr->stu[ptr->order - 1].point.pointEnglish);
        printf("\nEnter the point English of the student with the order number %d: ", ptr->order);
        scanf("%f", &ptr->stu[ptr->order - 1].point.pointPhilology);
        calculateAverageGrade(ptr, ptr->order - 1);
        printf("---------------------------------------------");
    }
}
void calculateAverageGrade(listStu *ptr, int index)
{
    ptr->stu[index].point.pointAverageGrade = (ptr->stu[index].point.pointEnglish + ptr->stu[index].point.pointMath + ptr->stu[index].point.pointPhilology) / 3;
}
void editStudent(listStu *ptr)
{
    displayList(ptr);
    int num;
    printf("\nEnter the number of students: ");
    scanf("%d", &num);
    int option;
    printf("\nWhat do you want to edit:");
    printf("\n1.Edit name");
    printf("\n2.Edit age");
    printf("\n3.Edit student code");
    printf("\n4.Edit point Math");
    printf("\n5.Edit point English");
    printf("\n6.Edit point Philology");
    printf("\n7.Edit All");
    printf("\n8.Exit");
    printf("\nMy option:");
    scanf("%d", &option);
    num--;
    switch (option)
    {
    case 1:
        printf("\nEnter new name: ");
        getchar(); // Đọc ký tự newline còn lại trong bộ đệm
        fgets(ptr->stu[num].name, sizeof(ptr->stu[num].name), stdin);
        ptr->stu[num].name[strcspn(ptr->stu[num].name, "\n")] = '\0';
        break;
    case 2:
        printf("\nEnter new age: ");
        scanf("%d", &ptr->stu[num].age);
        break;
    case 3:
        printf("\nEnter new student code: ");
        getchar(); // Đọc ký tự newline còn lại trong bộ đệm
        fgets(ptr->stu[num].studentCode, sizeof(ptr->stu[num].studentCode), stdin);
        ptr->stu[num].studentCode[strcspn(ptr->stu[num].studentCode, "\n")] = '\0';
        break;
    case 4:
        printf("\nEnter new point Math: ");
        scanf("%f", &ptr->stu[num].point.pointMath);
        calculateAverageGrade(ptr, num);
        break;
    case 5:
        printf("\nEnter new point English: ");
        scanf("%f", &ptr->stu[num].point.pointEnglish);
        calculateAverageGrade(ptr, num);
        break;
    case 6:
        printf("\nEnter new Point Philology: ");
        scanf("%f", &ptr->stu[num].point.pointPhilology);
        calculateAverageGrade(ptr, num);
        break;
    case 7:
        printf("\nEnter new name: ");
        getchar(); // Đọc ký tự newline còn lại trong bộ đệm
        fgets(ptr->stu[num].name, sizeof(ptr->stu[num].name), stdin);
        ptr->stu[num].name[strcspn(ptr->stu[num].name, "\n")] = '\0';
        printf("\nEnter new age: ");
        scanf("%d", &ptr->stu[num].age);
        printf("\nEnter new student code: ");
        getchar(); // Đọc ký tự newline còn lại trong bộ đệm
        fgets(ptr->stu[num].studentCode, sizeof(ptr->stu[num].studentCode), stdin);
        ptr->stu[num].studentCode[strcspn(ptr->stu[num].studentCode, "\n")] = '\0';
        printf("\nEnter new point Math: ");
        scanf("%f", &ptr->stu[num].point.pointMath);
        printf("\nEnter new point English: ");
        scanf("%f", &ptr->stu[num].point.pointEnglish);
        printf("\nEnter new point Philology: ");
        scanf("%f", &ptr->stu[num].point.pointPhilology);
        break;
    case 8:
        return;
    default:
        return;
    }
    displayList(ptr);
}
void sortListStudent(listStu *ptr)
{
    listStu temp;
    for (int i = 0; i < ptr->order - 1; i++)
    {
        for (int j = i + 1; j < ptr->order; j++)
        {
            if (ptr->stu[i].point.pointAverageGrade < ptr->stu[j].point.pointAverageGrade)
            {
                temp.stu[0] = ptr->stu[i];
                ptr->stu[i] = ptr->stu[j];
                ptr->stu[j] = temp.stu[0];
            }
        }
    }
}
void removeStudent(listStu *ptr)
{
    int index = -1;
    int i = 0;
    char studentId[4];
    printf("\nEnter studentId you want to remove:");
    scanf("%s", studentId);
    for (i = 0; i < ptr->order; i++)
    {
        int isEqual = strcmp(studentId, ptr->stu[i].studentCode);
        if (isEqual == 0)
        {
            index = i;
        }
    }
    if (index == -1)
    {
        printf("Not found student have that Id");
        return;
    }
    else
    {
        for (i = index; i < ptr->order - 1; i++)
        {
            ptr->stu[i] = ptr->stu[i + 1];
        }
        (ptr->order)--;
    }
}
void saveToFile(listStu *ptr, int *index_old)
{
    FILE *fOut = fopen("sv.txt", "a");
    for (int i = *index_old; i < ptr->order; i++)
    {
        fprintf(fOut, "%-10d %-30s %-10d %-20s %-15.2f %-15.2f %-15.2f %-30.2f\n", i + 1, ptr->stu[i].name, ptr->stu[i].age, ptr->stu[i].studentCode, ptr->stu[i].point.pointMath, ptr->stu[i].point.pointEnglish, ptr->stu[i].point.pointPhilology, ptr->stu[i].point.pointAverageGrade);
    }
    *index_old = ptr->order;
    fclose(fOut);
}

void readFile(listStu *ptr)
{
    int lineNumber = 0;
    int linesToSkip = 2;
    FILE *fOut = fopen("sv.txt", "r");
    char ch;
    while ((ch = fgetc(fOut)) != EOF) // fgetc returns character if(character == '\n') => skip line ;
    {
        if (ch == '\n')
        {
            lineNumber++;
            if (lineNumber == linesToSkip)
            {
                break;
            }
        }
    }
    int i = 0;
    for (;;)
    {
        fscanf(fOut, "%10d %30s %10d %20s %15f %15f %15f %30f", &(ptr->order), ptr->stu[i].name, &ptr->stu[i].age, ptr->stu[i].studentCode, &ptr->stu[i].point.pointMath, &ptr->stu[i].point.pointEnglish, &ptr->stu[i].point.pointPhilology, &ptr->stu[i].point.pointAverageGrade);
        if (feof(fOut))
        {
            break;
        }
        i += 1;
    }
    fclose(fOut);
}
void print_column_in_file(listStu *ptr)
{
    FILE *fOut = fopen("sv.txt", "a");
    fprintf(fOut, "List Student:\n");
    fprintf(fOut, "%-10s %-30s %-10s %-20s %-15s %-15s %-15s %-30s\n", "STT", "Name", "Age", "Student Code", "Point Math", "Point English", "Point Philology", "Point the average grade");
    fclose(fOut);
}