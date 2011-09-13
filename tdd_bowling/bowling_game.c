//bowling_game.c

#include "bowling_game.h"

#define MAX_ROLLS 21

static int pin_counts[MAX_ROLLS];
static int roll_count;


void bowling_game_init() {

	roll_count = 0;
	for ( int x = 0; x < MAX_ROLLS; x++) {
		pin_counts[x] = 0;	
	}
}

void bowling_game_roll(int pins) {

	pin_counts[roll_count] = pins;
	roll_count++;
}

int  bowling_game_score() {

	int score = 0;
	for( int x = 0; x < MAX_ROLLS; x++) {
		score += pin_counts[x];
	}
	return score;
}
