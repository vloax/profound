#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int score;
} Athlete;

void sortAthletes(Athlete *athletes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (athletes[j].score < athletes[j + 1].score) {
                Athlete temp = athletes[j];
                athletes[j] = athletes[j + 1];
                athletes[j + 1] = temp;
            } else if (athletes[j].score == athletes[j + 1].score) {
                if (strcmp(athletes[j].name, athletes[j + 1].name) > 0) {
                    Athlete temp = athletes[j];
                    athletes[j] = athletes[j + 1];
                    athletes[j + 1] = temp;
                }
            }
        }
    }
}

int main() {
    Athlete athletes[100];
    int n = 0;

    while (scanf("%s %d", athletes[n].name, &athletes[n].score) != EOF) {
        n++;
    }

    sortAthletes(athletes, n);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", athletes[i].name, athletes[i].score);
    }

    return 0;
}