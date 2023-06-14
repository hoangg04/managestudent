#include<stdio.h>
#include<string.h>


struct Point 
{
    float pointMath;
    float pointEnglish;
    float pointPhilology;// môn ngữ văn;
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
    struct Student stu;
    int order;
} listStu;



void initializeList(listStu *ptr);
void displayList(listStu *ptr);
void addStudent(listStu *ptr);
void editStudent(listStu *ptr);
void calculateAverageGrade(listStu *ptr);
void sortListStudent(listStu *ptr);
void removeStudent(listStu *ptr);
void saveToFile(listStu *ptr);
void readFile(listStu *ptr);
int main()
{
    listStu list[100];
    initializeList(list);
    readFile(list);
    displayList(list);
    int option;
    printf("\nApp Student Management design by Hoang:");
    printf("\n\t0. Exit");
    printf("\n\t1. Add students to the list.");
    printf("\n\t2. Edit List Student.");
    printf("\n\t3. Sort List Student.");
    printf("\n\t4. Remove Students to the list.");
    printf("\n\t5. Display List Student.");
    do{
        printf("\nEnter My Option: ");
        scanf("%d",&option);
        switch(option)
        {
        case 0:
            break;
        case 1:
            addStudent(list);
            break;
        case 2:
            editStudent(list);
            break;
        case 3:
            sortListStudent(list);
            break;
        case 4:
            removeStudent(list);
            break;
        case 5:
            displayList(list);
            break;
        case 6:
            readFile(list);
            break;
        case 7:
            saveToFile(list);
            break;
        default:
            break;
        }
    }while(option);
}

void initializeList(listStu *ptr)
{
    ptr->order = 0;
    // FILE *fOut = fopen("sv.txt", "a");
    // fprintf(fOut,"\nList Student:");
    // fprintf(fOut,"\n%-10s %-30s %-10s %-20s %-15s %-15s %-15s %-30s","STT","Name","Age","Student Code","Point Math","Point English","Point Philology","Point the average grade");
    // fclose(fOut);
}
void displayList(listStu *ptr)
{
    printf("\nList Student:");
    printf("\n %-10s %-30s %-10s %-20s %-15s %-15s %-15s %-30s","STT","Name","Age","Student Code","Point Math","Point English","Point Philology","Point the average grade");
    for (int i = 0; i < ptr->order; i++)
    {
        printf("\n %-10d %-30s %-10d %-20s %-15.2f %-15.2f %-15.2f %-30.2f",i + 1,(ptr + i)->stu.name,(ptr + i)->stu.age,(ptr + i)->stu.studentCode,(ptr + i)->stu.point.pointMath,(ptr + i)->stu.point.pointEnglish,(ptr + i)->stu.point.pointPhilology,(ptr + i)->stu.point.pointAverageGrade);
    }
}
void addStudent(listStu *ptr)
{
    if(ptr->order > 100) return;
    int n;
    printf("\nEnter the number of students to add:");
    scanf("%d",&n);
    for(int i = 0; i < n;i++)
    {
        ptr->order += 1;
        int stt = ptr->order - 1;
        printf("\nEnter the name of the student with the order number %d: ",stt + 1);
        getchar(); // Đọc ký tự newline còn lại trong bộ đệm
        fgets((ptr + stt)->stu.name, sizeof((ptr + stt)->stu.name), stdin);
        (ptr + stt)->stu.name[strcspn((ptr + stt)->stu.name, "\n")] = '\0'; 
        printf("\nEnter age of the student with the order number %d: ",stt + 1);
        scanf("%d",&(ptr + stt)->stu.age);
        printf("\nEnter the student code of the student with the order number %d: ",stt + 1);
        getchar();
        fgets((ptr + stt)->stu.studentCode, sizeof((ptr + stt)->stu.studentCode), stdin);
        (ptr + stt)->stu.studentCode[strcspn((ptr + stt)->stu.studentCode, "\n")] = '\0'; 
        printf("\nEnter the point Math of the student with the order number %d: ",stt + 1);
        scanf("%f", &(ptr + stt)->stu.point.pointMath);
        printf("\nEnter the point Philology of the student with the order number %d: ",stt + 1);
        scanf("%f",&(ptr + stt)->stu.point.pointEnglish);
        printf("\nEnter the point English of the student with the order number %d: ",stt + 1);
        scanf("%f",&(ptr + stt)->stu.point.pointPhilology);
        calculateAverageGrade(ptr + stt);
        printf("---------------------------------------------");
    }
}
void calculateAverageGrade(listStu *ptr)
{
    ptr->stu.point.pointAverageGrade = (ptr->stu.point.pointEnglish + ptr->stu.point.pointMath + ptr->stu.point.pointPhilology) / 3;
}
void editStudent(listStu *ptr)
{
    displayList(ptr);
    int num;
    printf("\nEnter the number of students: ");
    scanf("%d",&num);
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
    scanf("%d",&option);
    num--;
    switch (option)
    {
    case 1:
        printf("\nEnter new name: ");
        getchar(); // Đọc ký tự newline còn lại trong bộ đệm
        fgets((ptr + num)->stu.name, sizeof((ptr + num)->stu.name), stdin);
        (ptr + num)->stu.name[strcspn((ptr + num)->stu.name, "\n")] = '\0';
        break;
    case 2:
        printf("\nEnter new age: ");
        scanf("%d",&(ptr + num)->stu.age);
        break;
    case 3:
        printf("\nEnter new student code: ");
        getchar(); // Đọc ký tự newline còn lại trong bộ đệm
        fgets((ptr + num)->stu.studentCode, sizeof((ptr + num)->stu.studentCode), stdin);
        (ptr + num)->stu.studentCode[strcspn((ptr + num)->stu.studentCode, "\n")] = '\0';
        break;
    case 4:
        printf("\nEnter new point Math: ");
        scanf("%f",&(ptr + num)->stu.point.pointMath);
        calculateAverageGrade(ptr);
        break;
    case 5:
        printf("\nEnter new point English: ");
        scanf("%f",&(ptr + num)->stu.point.pointEnglish);
        calculateAverageGrade(ptr);
        break;
    case 6:
        printf("\nEnter new Point Philology: ");
        scanf("%f",&(ptr + num)->stu.point.pointPhilology);
        calculateAverageGrade(ptr);
        break;
    case 7:
        printf("\nEnter new name: ");
        getchar(); // Đọc ký tự newline còn lại trong bộ đệm
        fgets((ptr + num)->stu.name, sizeof((ptr + num)->stu.name), stdin);
        (ptr + num)->stu.name[strcspn((ptr + num)->stu.name, "\n")] = '\0';
        printf("\nEnter new age: ");
        scanf("%d",&(ptr + num)->stu.age);
        printf("\nEnter new student code: ");
        getchar(); // Đọc ký tự newline còn lại trong bộ đệm
        fgets((ptr + num)->stu.studentCode, sizeof((ptr + num)->stu.studentCode), stdin);
        (ptr + num)->stu.studentCode[strcspn((ptr + num)->stu.studentCode, "\n")] = '\0';
        printf("\nEnter new point Math: ");
        scanf("%f",&(ptr + num)->stu.point.pointMath);
        printf("\nEnter new point English: ");
        scanf("%f",&(ptr + num)->stu.point.pointEnglish);
        printf("\nEnter new point Philology: ");
        scanf("%f",&(ptr + num)->stu.point.pointPhilology);
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
    for(int i = 0;i < ptr->order;i++)
    {
        for(int j = 0; j < ptr->order - 1;j++)
        {
            if((ptr + i)->stu.point.pointAverageGrade > (ptr + j)->stu.point.pointAverageGrade )
            {
                temp.stu = (ptr + j)->stu;
                (ptr + j)->stu = (ptr + i)->stu;
                (ptr + i)->stu = temp.stu;
            }
        }
    }
}
void removeStudent(listStu *ptr)
{
    int index = -1;
    char studentId[4];
    printf("\nEnter studentId you want to remove:");
    scanf("%s",studentId);
    for (int i = 0; i < ptr->order; i++)
    {
        int isEqual = strcmp(studentId,(ptr + i)->stu.studentCode);
        if(isEqual)
        {
            index = i;
        }
    }
    if(index == -1)
    {
        printf("Not found student have that Id");
        return;
    }
    for(int i = index; i < ptr->order - 1 ; i++)
    {
        (ptr + index)->stu = (ptr + index + 1)->stu;
    }
    (ptr->order)--;
}
void saveToFile(listStu *ptr)
{
    FILE *fOut = fopen("sv.txt", "a");
    for (int i = 0; i < ptr->order; i++)
    {
        fprintf(fOut,"%-10d %-30s %-10d %-20s %-15.2f %-15.2f %-15.2f %-30.2f\n",i + 1,(ptr + i)->stu.name,(ptr + i)->stu.age,(ptr + i)->stu.studentCode,(ptr + i)->stu.point.pointMath,(ptr + i)->stu.point.pointEnglish,(ptr + i)->stu.point.pointPhilology,(ptr + i)->stu.point.pointAverageGrade);
    }
    fclose(fOut);
}

void readFile(listStu *ptr)
{
    FILE *fOut = fopen("sv.txt", "r");
    int i = 0;
    for (;;)
    {
        fscanf(fOut, "%10d %30s %10d %20s %15f %15f %15f %30f\n", &(ptr->order), (ptr + i)->stu.name, &(ptr + i)->stu.age, (ptr + i)->stu.studentCode, &(ptr + i)->stu.point.pointMath, &(ptr + i)->stu.point.pointEnglish, &(ptr + i)->stu.point.pointPhilology, &(ptr + i)->stu.point.pointAverageGrade);
        if(feof(fOut))
        {
            break;
        }
        i += 1;
    }
    fclose(fOut);
}