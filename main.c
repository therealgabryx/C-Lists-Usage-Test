#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list * l;

struct list {
    int ID;
    char check;
    l next; // ptr to next struct: list-node
};

l head = NULL;

void add() {
    l temp = malloc(sizeof(l));

    int id = 0;
    do {
      id = rand() % 2103 + 7000;  // ID
    } while ((id % 7) != 0);
    temp->ID = id;

    int character = 0;
    do {
      character = rand() % 26 + 97;
    } while ((character % 2) != 0);
    temp->check = character; // Check [97-122 : a-z]

    temp->next = head;
    head = temp;
}

void printList() {
    if (head == NULL) {
        printf(" [i] Lista vuota");
    }
    else {
        int count = 0;
        l temp = head;
        printf(" [i] Lista:\n\n HEAD");
        while (temp != NULL) {
            printf("\n [%d]: %d %c", ++count, temp->ID, temp->check);
            temp = temp->next;
        }
        printf("\n NULL");
    }
}

void printListPari() {
    if (head == NULL) {
        printf("\n\n [i] Lista vuota");
    }
    else {
        int count = 0;
        l temp = head;
        printf("\n\n [i] Lista:\n\n HEAD");
        while (temp != NULL) {
            if ((++count % 2) == 0) {
              printf("\n [%d]: %d %c", count, temp->ID, temp->check);
            } 
            temp = temp->next;
        }
        printf("\n NULL");
    }
}

void printListDispari() {
    if (head == NULL) {
        printf("\n\n [i] Lista vuota");
    }
    else {
        int count = 0;
        l temp = head;
        printf("\n\n [i] Lista:\n\n HEAD");
        while (temp != NULL) {
            if ((++count % 2) != 0) {
              printf("\n [%d]: %d %c", count, temp->ID, temp->check);
            } 
            temp = temp->next;
        }
        printf("\n NULL");
    }
}

void printListM() {
    int m = 0;
    printf("\n\n [?] Quanti elementi della lista vuoi vedere?\n [>] ");
    scanf("%d", &m);

    if (head == NULL) {
        printf("\n\n [i] Lista vuota");
    }
    else {
        int count = 0;
        l temp = head;
        printf("\n\n [i] Lista:\n\n HEAD");
        while (temp != NULL) {
            if ((++count) <= m) {
              printf("\n [%d]: %d %c", count, temp->ID, temp->check);
            } 
            temp = temp->next;
        }
        printf("\n NULL");
    }
}

void menu() {
    printf("\n\n [i] Menu:\n 1. Elementi in posizione pari\n 2. Elementi in posizione dispari\n 3. Primi M elementi della lista\n 0. Termina programma\n");
}

int main()
{
    srand(time(NULL));
    printf("\n [i] Quanti elementi vuoi inserire?\n [>] ");
    int n, choice;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        add();
    }

    do {
        system("clear");
        printList();
        menu();
        printf("\n\n [i] Inserisci la scelta:\n [>] ");
        scanf("%d", &choice);
        system("clear");

        switch(choice) {
        case 1:
            printList();
            // Elem pos pari
            printListPari();
            getchar();
            getchar();
            break;

        case 2:
            system("clear");
            printList();
            // Elem pos dispari
            printListDispari();
            getchar();
            getchar();
            break;

        case 3:
            system("clear");
            printList();
            // primi M elem
            printListM();
            getchar();
            getchar();
            break;

        case 0:
            choice = 0;
            // Close
            printf("\n [!] Programma terminato. Premi invio per chiudere..");
            getchar();
            getchar();
            system("clear");
            break;

        default:
            system("clear");
            printList();
            menu();
            printf("\n\n [i] Inserisci la scelta:\n [>] ");
            scanf("%d", &choice);
            break;
        }
    } while(choice != 0);
    printf("\n\n");

    return 0;
}