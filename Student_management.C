#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
};

void addStudent() {
    struct Student s;
    FILE *f = fopen("students.dat","ab");
    printf("Enter ID, Name, Age: ");
    scanf("%d %s %d",&s.id,s.name,&s.age);
    fwrite(&s,sizeof(s),1,f);
    fclose(f);
}

void displayStudents() {
    struct Student s;
    FILE *f = fopen("students.dat","rb");
    while(fread(&s,sizeof(s),1,f))
        printf("ID:%d Name:%s Age:%d\n",s.id,s.name,s.age);
    fclose(f);
}

int main() {
    int choice;
    while(1) {
        printf("\n1.Add\n2.Display\n3.Exit\nChoice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: exit(0);
            default: printf("Invalid!\n");
        }
    }
    return 0;
}
