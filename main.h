#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
char* item;
struct node* next;
} List;

typedef struct TreeNode {
char* item;
struct TreeNode* right;
struct TreeNode* left;
} Tree;

List* MakeNode(char* item) {
List* newp;
newp = (List*)malloc(sizeof(List));
newp->item = (char*)malloc(strlen(item)+1);
strcpy(newp->item,item);
return newp;
}

Tree* MakeTreeNode(char* item) {
Tree* newp;
newp = (Tree*)malloc(sizeof(Tree));
newp->item = (char*)malloc(strlen(item)+1);
strcpy(newp->item,item);
newp->right = NULL;
newp->left = NULL;
return newp;
}

List* LinkEnd(List* head,List* p1) {
List* p;
for(p = head; p->next != NULL; p = p->next);
p->next = p1;
return head;
}

List* LinkNode(List* head,List* p1,int index) {
List* p;
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

List* GetNode(List* head,int index) {
List* p = head;
for(int i = 0; p->next != NULL; p = p->next) {
if(i == index) {break;}
++i;
}
return p;
}

List* RemoveNode(List* head,int index) {
List* p;
List* prev;
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

void PrintList(List* head) {
List* p = head;
while(p->next != NULL) {
printf("%s \n",p->item);
p = p->next;
}
printf("%s \n",p->item);
}

void PrintTree(Tree* head) {
if(head) {
PrintTree(head->left);
printf("%s\n",head->item);
PrintTree(head->right);
}
}

long int GetFileSize(FILE* fp) {
fseek(fp,0,SEEK_END);
long int length = ftell(fp);
fclose(fp);
return length;
}

long int GetFileLineSize(FILE* fp) {
char* line = NULL;
size_t len = 0;
ssize_t size;
size = getline(&line, &len, fp);
if(line) {free(line);}
return size;
}

List* GetFileLines(FILE* fp) {
char * line = NULL;
size_t len = 0;
ssize_t read;
List* head = MakeNode("head");
while((read = getline(&line, &len, fp)) != -1) {
List* p = MakeNode(line);
LinkEnd(head,p);
}
if(line) {free(line);}
head = RemoveNode(head,0);
return head;
}

List* SplitText(List* start,char SplitChar) {
List* head = MakeNode("head");
char buffer[strlen(start->item)];
char* p = &(start->item[0]);
int i = 0;
while(i < strlen(start->item)) {
if(*p == SplitChar) {
buffer[i] = '\0';
LinkEnd(head,MakeNode(buffer));
i = -1;
} else {buffer[i] = *p;}
++p;
++i;
}
buffer[i] = '\0';
LinkEnd(head,MakeNode(buffer));
head = RemoveNode(head,0);
return head;
}
