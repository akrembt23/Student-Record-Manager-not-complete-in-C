#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LENGHT 50
typedef struct Node
{
    int id;
    char name[LENGHT];
    float grade;
    struct Node *next;
    struct Node *prev;
} Node;
Node *createS()
{
    int id;
    char name[LENGHT];
    float grade;
    getchar();
    printf("Enter Name of Student=");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Enter ID of Student=");
    scanf("%d", &id);
    printf("Enter Grade of Student=");
    scanf("%f", &grade);
    Node *newnode = malloc(sizeof *newnode);
    newnode->id = id;
    newnode->grade = grade;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
Node *addB(Node *head)
{
    Node *newnode = createS();
    if (head == NULL)
    {
        puts("List is Empty");
        return newnode;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    return head;
}
Node *addE(Node *head)
{
    Node *newnode = createS();
    if (head == NULL)
    {
        return newnode;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}
Node *addP(Node *head, int pos)
{
    Node *newnode = createS();
    if (head == NULL)
    {
        puts("list is emplty");
        return newnode;
    }
    if (pos == 1)
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return head;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        puts("out of range");
        return head;
    }
    if (temp->next == NULL)
    {
        temp->next = newnode;
        newnode->prev = temp;
        return head;
    }
    Node *Nextnode = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = Nextnode;
    Nextnode->prev = newnode;
    return head;
}
Node *DelB(Node *head)
{
    if (head == NULL)
    {
        puts("list is emplty");
        return NULL;
    }
    Node *tempF = head;
    if (head->next == NULL)
    {
        free(tempF);
        return NULL;
    }
    head = head->next;
    head->prev = NULL;
    free(tempF);
    return head;
}
Node *DelP(Node *head, int pos)
{
    if (head == NULL)
    {
        puts("list is emplty");
        return NULL;
    }
    if (pos == 1)
    {
        return DelB(head);
    }
    Node *temp = head;
    int i = 1;
    while (i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        puts("Out Of Range");
        return head;
    }

    Node *toDelete = temp->next;
    Node *temp2 = toDelete->next;
    if (temp2 == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = temp2;
        temp2->prev = temp;
    }
    free(toDelete);
    return head;
}
Node *DelE(Node *head)
{
    if (head == NULL)
    {
        puts("list is emplty");
        return NULL;
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->prev->next = NULL;
    free(tail);
    return head;
}
Node *searchById(Node *head, int Id)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (Id == temp->id)
        {
            printf("ID:%d,NAME:%s,GRADE:%f->", temp->id, temp->name, temp->grade);
            
            return temp;
        }
        temp = temp->next;
    }
    printf("\n");
    printf("we didnt found a student with those charastcics");
    return NULL;
}
Node *searchByName(Node *head, char name[LENGHT])
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->name,name)==0)
        {
            printf("ID:%d,NAME:%s,GRADE:%f->", temp->id, temp->name, temp->grade);
            
            return temp;
        }
        temp = temp->next;
    }
    printf("\n");
    printf("we didnt found a student with those charastcics");
    return NULL;
}
Node *UpdateGrade(Node *head,int id){
    float change;
    Node *temp=head;
    while(temp!=NULL){
        if(temp->id==id){
            printf("Enter Grade:");
            scanf("%f",&change);
            temp->grade=change;
            return temp;
        }
        temp=temp->next;
    }
    printf("not Valid ID");
}
Node *sortGrade(Node *head) {
    if(head==NULL){
        return NULL;
    }
    int swapped;
    do{
        swapped=0;
        Node *temp=head;
        while(temp->next!=NULL){
         if(temp->grade<temp->next->grade){
            int id=temp->id;
            float grade=temp->grade;
            char name[LENGHT];
            strcpy(name,temp->name);
            temp->id=temp->next->id;
            temp->grade=temp->next->grade;
            strcpy(temp->name,temp->next->name);
            temp->next->id = id;
            strcpy(temp->next->name, name);
            temp->next->grade = grade;
            swapped=1;
         }
         temp=temp->next;
        }

    }while(swapped);
    return head;
}


void printL(Node *head)
{
    Node *temp1 = head;
    while (temp1 != NULL)
    {
        printf("ID:%d,NAME:%s,GRADE:%f->", temp1->id, temp1->name, temp1->grade);
        temp1 = temp1->next;
    }
    printf("\n");
    Node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    while (temp2 != NULL)
    {
        printf("ID:%d,NAME:%s,GRADE:%f<-", temp2->id, temp2->name, temp2->grade);
        temp2 = temp2->prev;
    }
    printf("\n");
}
int main()
{
    Node *head = NULL;
    int val, pos;
    int a;
    while (1)
    {
        puts("1. Add student");
        puts("2. Delete student");
        puts("3. Search student");
        puts("4. Update grade");
        puts("5. Sort by grade");
        puts("6. Display List");
        puts("7. Reverse list");
        puts("0. Exit");
        printf("Enter Ur Choice=");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            puts("Adding student...");
            puts("a-Add in begin:");
            puts("b-Add in the middle:");
            puts("c-Add in the end:");
            char c;

            printf("Enter ur choice:");
            scanf(" %c", &c);
            c = toupper(c);
            if (c == 'A')
            {
                head = addB(head);
            }
            if (c == 'B')
            {
                printf("enter position:");
                scanf("%d", &pos);
                head = addP(head, pos);
            }
            if (c == 'C')
            {
                head = addE(head);
            }

            printL(head);
            break;
        case 2:
            puts("Adding student...");
            puts("a-Delete in begin:");
            puts("b-Delete in the middle:");
            puts("c-Delete in the end:");
            char v;

            printf("Enter ur choice:");
            scanf(" %c", &v);
            v = toupper(v);
            if (v == 'A')
            {
                head = DelB(head);
            }
            if (v == 'B')
            {
                printf("enter position:");
                scanf("%d", &pos);
                head = DelP(head, pos);
            }
            if (v == 'C')
            {
                head = DelE(head);
            }

            printL(head);
            break;
        case 3:
        int id;
        char name[LENGHT];
        puts("Search by:");
        puts("a - ID");
        puts("b - Name");
        char s;
        scanf(" %c", &s);
        if (toupper(s) == 'A')
        {
            printf("Enter ID: ");
            scanf("%d", &id);
            searchById(head,id);
        }
        else if (toupper(s) == 'B')
        {
            printf("Enter Name: ");
            getchar();
            fgets(name,sizeof(name),stdin);
            searchByName(head, name);
        }
        
            break;
        case 4:
        puts("Update Grade");
        printf("Enter the Student ID you want to update");
        scanf("%d",&id);
        UpdateGrade(head,id);
            break;
        case 5:
           sortGrade(head);
           printL(head);
            break;
        case 6:
           printL(head);
            break;
        case 7:

            break;
        case 0:
            exit(0);
            break;

        default:
            puts("Invalid Choice Please Try Again");
            break;
        }
    }
}