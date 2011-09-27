//bowling_game.c

#include "bowling_game.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_ROLLS 21
#define NUM_FRAMES 10

static int rolls[MAX_ROLLS];
static int roll_count;

void bowling_game_init( void) {
   roll_count = 0;
}

void bowling_game_roll(int pin_count) {
   rolls[roll_count] = pin_count;
   roll_count++;
}

bool is_strike(int roll_index) {
   return(rolls[roll_index] == 10);
}

bool is_spare(int roll_index) {
   return(rolls[roll_index] + rolls[roll_index + 1] == 10);
}

int score_strike(int roll_index) {
   return 10 + rolls[roll_index + 1] + rolls[roll_index + 2];
}

int score_spare(int roll_index) {
   return 10 + rolls[roll_index + 2];
}

int score_normal(int roll_index) {
   return rolls[roll_index] + rolls[roll_index + 1];   
}

int bowling_game_score(void) {
   int score = 0;
   int roll_index = 0;   
   for(int frame=0;frame<NUM_FRAMES;frame++) {
      if(is_strike(roll_index)) {
         score += score_strike(roll_index);         
         roll_index += 1;      
      }
      else if(is_spare(roll_index)) {
         score += score_spare(roll_index);
         roll_index += 2;
      }
      else {
         score += score_normal(roll_index);
         roll_index += 2;
      }
   }
   return score;
}
