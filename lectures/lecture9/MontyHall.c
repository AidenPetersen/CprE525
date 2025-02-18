#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    int door = rand() % 3;
    printf("Enter a door from 0-2:\n");
    int sel;
    scanf("%d", &sel);
    int op;
    while(1){
        op = rand() % 3;
        if(op != door && op != sel){
            break;
        }
    }
    printf("Opening door %d, which has a goat\n", op);
    int keep;
    printf("Keep %d as guess? (1 yes, 0 no)?\n", sel);
    scanf("%d", &keep);
    int win = (sel == door && keep) || (sel != door && !keep);
    printf("Door %d has the prize!\n", door);
    if(win) {
        printf("You won!");
    } else {
        printf("You got a goat!");
    }
}
