#ifndef NODE_H_
#define NODE_H_

typedef struct node node;
struct node {
  int position;
  char value;
  node *next;
};

int GetNumberOfNodes();
void GenerateList(node **head, const int length);
void Print(const int forward, const node *head);
void PrintList(const node *head);
void ReversePrintList(const node *head);
int GetKey();
void SearchList(const node *head, const int key);
void DeleteList(node **list);

#endif // NODE_H_
