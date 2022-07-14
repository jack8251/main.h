#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
char* item;
struct node* next;
} Node;

Node* MakeNode(char* item) {
Node* newp;
newp = (Node*)malloc(sizeof(Node));
newp->item = (char*)malloc(strlen(item)+1);
strcpy(newp->item,item);
return newp;
}

Node* LinkEnd(Node* head,Node* p1) {
Node* p;
for(p = head; p->next != NULL; p = p->next);
p->next = p1;
return head;
}

Node* LinkNode(Node* head,Node* p1,int index) {
Node* p;
int i = 0;
for(p = head; p->next != NULL; p = p->next) {
if(i == index) {
p1->next = p->next;
p->next = p1;
break;
} else {++i;}
}
return head;
}

Node* RemoveNode(Node* head,int index) {
Node* p;
Node* prev;
int i = 0;
prev = NULL;
for (p = head; p != NULL; p = p->next) {
if(i == index) {
if(prev == NULL) {
head = p-> next;
} else
prev->next = p->next;
free(p->item);
free(p);
return head;
}
prev = p;
++i;
}
}

void PrintList(Node* head) {
Node* p = head;
while(p->next != NULL) {
printf("%s \n",p->item);
p = p->next;
}
printf("%s \n",p->item);
}
