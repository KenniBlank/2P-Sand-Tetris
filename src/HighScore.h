#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "config.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_HIGH_SCORES HIGH_SCORE_COUNT

// Get top 10 high scores
// Returns array of scores in descending order (highest first)
// If less than 10 scores exist, remaining slots are 0
void getScores(int scores[MAX_HIGH_SCORES]);

// Post a new score to the high score table
// Only adds if score is higher than the lowest score in top 10
// Returns true if score was added, false otherwise
bool postScore(int newScore);

#endif
