#include "HighScore.h"
#include <stdio.h>

// Load high scores (text file, one per line)
void getScores(int scores[MAX_HIGH_SCORES]) {
        FILE *file = fopen(HIGH_SCORE_FILE, "r");

        for (int i = 0; i < MAX_HIGH_SCORES; i++) {
                scores[i] = 0;
                if (file) {
                        fscanf(file, "%d", &scores[i]);
                }
        }

        if (file) {
                fclose(file);
        } else {
                // File missing → create it
                file = fopen(HIGH_SCORE_FILE, "w");
                if (!file) return;

                for (int i = 0; i < MAX_HIGH_SCORES; i++) {
                        fprintf(file, "0\n");
                }
                fclose(file);
        }
}

// Insert score if it fits top 10
bool postScore(int newScore) {
        int scores[MAX_HIGH_SCORES];
        getScores(scores);

        if (newScore <= scores[MAX_HIGH_SCORES - 1]) {
                return false;
        }

        // Manual shift, boring but obvious
        for (int i = MAX_HIGH_SCORES - 1; i > 0; i--) {
                if (newScore > scores[i - 1]) {
                        scores[i] = scores[i - 1];
                } else {
                        scores[i] = newScore;
                        break;
                }

                if (i == 1) {
                        scores[0] = newScore;
                }
        }

        FILE *file = fopen(HIGH_SCORE_FILE, "w");
        if (!file) {
                perror("High score file");
                return false;
        }

        for (int i = 0; i < MAX_HIGH_SCORES; i++) {
                fprintf(file, "%d\n", scores[i]);
        }

        fclose(file);
        return true;
}