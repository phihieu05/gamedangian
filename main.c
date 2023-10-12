#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char ban[10];
    char may[10];
    char kq[10];
} Menu;

void printMenu(Menu menu) {
    printf("+----------------------+----------+----------------------+\n");
    printf("|    TRO CHOI DAN GIAN BY HIEU                           |\n");
    printf("+----------------------+----------+----------------------+\n");
    printf("| %-20s | %-8s | %-20s |\n", "BAN", "MAY","KQ");
    printf("+----------------------+----------+----------------------+\n");
    printf("| %-20s | %-8s | %-20s |\n", menu.ban, menu.may, menu.kq);
    printf("+----------------------+----------+----------------------+\n");
}

int main() {
    Menu gameMenu;

    printf("Xin moi ban chon (bua, keo, or bao): ");
    scanf("%s", gameMenu.ban);

    int x;
    srand(time(NULL));
    x = rand() % 3 + 1;

    if (x == 1) {
        snprintf(gameMenu.may, sizeof(gameMenu.may), "Bua");
    } else if (x == 2) {
        snprintf(gameMenu.may, sizeof(gameMenu.may), "Keo");
    } else {
        snprintf(gameMenu.may, sizeof(gameMenu.may), "Bao");
    }

    if (strcmp(gameMenu.ban, gameMenu.may) == 0) {
        snprintf(gameMenu.kq, sizeof(gameMenu.kq), "Hoa");
    } else if ((strcmp(gameMenu.ban, "bua") == 0 && strcmp(gameMenu.may, "keo") == 0) ||
               (strcmp(gameMenu.ban, "keo") == 0 && strcmp(gameMenu.may, "bao") == 0) ||
               (strcmp(gameMenu.ban, "bao") == 0 && strcmp(gameMenu.may, "bua") == 0)) {
        snprintf(gameMenu.kq, sizeof(gameMenu.kq), "Thang");
    } else {
        snprintf(gameMenu.kq, sizeof(gameMenu.kq), "Thua");
    }

    printMenu(gameMenu);

    return 0;
}