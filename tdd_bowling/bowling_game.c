//bowling_game.c

#include "bowling_game.h"
#include <stdbool.h>

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

	if( roll_count < MAX_ROLLS - 1) {
		pin_counts[roll_count] = pins;
		roll_count++;
	}
}

static bool is_spare(int frame_index) {
	return pin_counts[frame_index] + pin_counts[frame_index + 1] == 10;
}

static bool is_strike(int frame_index) {
	return pin_counts[frame_index] == 10;
}
	
static int strike_score(int frame_index) {
	int score = 10;
	score += pin_counts[frame_index+1];
	score += pin_counts[frame_index+2];
	return score;
}

static int spare_score(int frame_index) {
	int score = 10;	
	score += pin_counts[frame_index+2];
	return score;
}

static int normal_score(int frame_index) {
	int score = 0;
	score += pin_counts[frame_index];
	score += pin_counts[frame_index + 1];
	return score;
}

int  bowling_game_score() {
	int score = 0;
	int frame_index = 0;
	for( int frame = 0; frame < 10; frame++) {
		if( is_strike(frame_index)) {
			score += strike_score(frame_index);
			frame_index += 1;
		}
		else if (is_spare(frame_index)) {
			score += spare_score(frame_index);
			frame_index += 2;
		}
		else {
			score += normal_score(frame_index);
			frame_index += 2;
		}
	}
	return score;
}


