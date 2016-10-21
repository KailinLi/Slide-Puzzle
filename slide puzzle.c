//SILDE PUZZLE V1.3
//Copyright © 2016 LiKaiLin in HUST. All rights reserved.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define m 3
#define n 4
int save_i ,save_j;
void show(int (*)[n]);
void freshen(int (*)[n]);
int judgement(int (*)[n]);
int down(int (*)[n]);
int up(int (*)[n]);
int left(int (*)[n]);
int right(int (*)[n]);
int main(void)
{
    int work_space[m][n];
    int i = 1,j;
    int * p;
    for (p = *work_space; p < *(work_space + m); ) {
        *(p++) = i;
        i ++;
    }
    for (i = 0;i < m; i++) {
        for (j = 0; j < n; j++) {
            if (*(*(work_space+i)+j) == m * n) {
                save_i = i;
                save_j = j;
                break;
            }
        }
    }
    freshen(work_space);
    printf("INPUT w s a d TO MOVE,INPUT # TO QUIT\n");
    char option;
    while (1) {
        system("stty -icanon");
        option = getchar();
        switch (option) {
            case 'w':case 'W':
                if(up(work_space)){
                    show(work_space);
                    break;
                };
                show(work_space);
                printf("CAN NOT MOVE\n");
                break;
            case 's':case 'S':
                if(down(work_space)){
                    show(work_space);
                    break;
                };
                show(work_space);
                printf("CAN NOT MOVE\n");
                break;
            case 'a':case 'A':
                if(left(work_space)){
                    show(work_space);
                    break;
                };
                show(work_space);
                printf("CAN NOT MOVE\n");
                break;
            case 'd':case 'D':
                if(right(work_space)){
                    show(work_space);
                    break;
                };
                show(work_space);
                printf("CAN NOT MOVE\n");
                break;
            case 'r':case 'R':
                freshen(work_space);
                break;
            case '#':
                return 0;
            default:
                show(work_space);
                printf("INVALID INPUT\n");
                break;
        }
    }
}
int down(int (*sheet)[n])
{
    if (save_i == 0) {
        return 0;
    }
    else{
        *(*(sheet + save_i) + save_j) = *(*(sheet + save_i - 1) + save_j);
        *(*(sheet + save_i - 1) + save_j) = n*m;
        save_i -= 1;
        return 1;
    }
}
int up(int (*sheet)[n])
{
    if (save_i == m - 1) {
        return 0;
    }
    else{
        *(*(sheet + save_i) + save_j) = *(*(sheet + save_i + 1) + save_j);
        *(*(sheet + save_i + 1) + save_j) = n*m;
        save_i += 1;
        return 1;
    }
}
int left(int (*sheet)[n])
{
    if (save_j == n - 1) {
        return 0;
    }
    else{
        *(*(sheet + save_i) + save_j) = *(*(sheet + save_i) + save_j + 1);
        *(*(sheet + save_i) + save_j + 1) = n*m;
        save_j += 1;
        return 1;
    }
}
int right(int (*sheet)[n])
{
    if (save_j == 0) {
        return 0;
    }
    else{
        *(*(sheet + save_i) + save_j) = *(*(sheet + save_i) + save_j - 1);
        *(*(sheet + save_i) + save_j - 1) = n*m;
        save_j -= 1;
        return 1;
    }
}
void show(int (*sheet)[n])
{
    system("clear");
    int i;
    for (i = 0; i < 2*(n - 3); i++) {
        putchar(' ');
    }
    printf("SLIDEPUZZLE\n");
    int count = 1;
    int *p;
    for (p = *sheet; p < *(sheet + m); p++) {
        if (*p == n*m) {
            printf("    ");
        }
        else {
            printf("%2d",*p);
            if (count % n != 0) {
                printf("  ");
            }
        }
        if (count % n == 0 && count != n*m) {
            puts("\n");
        }
        else if(count == n*m){
            putchar('\n');
        }
        count++;
    }
    if (judgement(sheet)) {
        printf("EXCELLENT!! \n");
        printf("INPUT r TO REPLAY\n");
    }
}
void freshen(int (*sheet)[n])
{
    srand((unsigned)time(NULL));
    int i;
    for (i = 0; i < 100*n*m; i ++) {
        int answer = 1 + rand()%(4);
        switch (answer) {
            case 1:
                up(sheet);
                break;
            case 2:
                down(sheet);
                break;
            case 3:
                left(sheet);
                break;
            case 4:
                right(sheet);
                break;
            default:
                break;
        }
    }
    show(sheet);
}
int judgement(int (*a)[n])
{
    int judge = 1 , i = 1;
    int * p;
    for (p = *a; p < *(a + m); p++) {
        if (*p == i++) {
            judge *= 1;
        }
        else
            judge *= 0;
    }
    if (judge) {
        return 1;
    }
    else
        return 0;
}