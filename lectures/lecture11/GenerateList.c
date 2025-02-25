#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateList(node **head, const int num_nodes) {
  node *temp;
  srand(time(NULL));

  for (int i = 0; i < num_nodes; i++) {
    temp = (node *)malloc(sizeof(node));
    temp->value = rand() % 2 ? (rand() % (26)) + 'a' : (rand() % (26)) + 'A';
    temp->position = num_nodes - i - 1;
    printf("%d ", temp->value);

    if (*head == NULL) {
      *head = temp;
      (*head)->next = NULL;
    } else {
      temp->next = *head;
      *head = temp;
    }
  }
}
