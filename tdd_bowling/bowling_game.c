//bowling_game.c

#include "bowling_game.h"

#define MAX_ROLLS 21

static int pin_counts[MAX_ROLLS];
static int roll_count;

//void debug_scores() {
//	for (int i = 0; i < MAX_ROLLS; i++) {
//		printf("roll[%i] = %i\n",i,pin_counts[i]);
//	}
//}

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

int  bowling_game_score() {

	int score = 0;
	for( int x = 0; x < roll_count; ) {
		int increment = 2;
		if ((pin_counts[x] + pin_counts[x+1]) == 10) { //A spare
			score += 10;
			score += pin_counts[x+2];
			printf("In spare %i - %i\n",x,score);

		}
		else {
			score += pin_counts[x];
			score += pin_counts[x+1];
			printf("Not in spare %i - %i\n",x,score);

		}
		x += increment;
	}
//	debug_scores();
	
	return score;
}


