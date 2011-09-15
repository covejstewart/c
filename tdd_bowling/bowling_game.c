//bowling_game.c

#include "bowling_game.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_ROLLS 21
#define NUM_FRAMES 10

static int roll_index;
static int pin_counts[MAX_ROLLS];

void bowling_game_init( void) {
   roll_index = 0;
   for (int x = 0; x < MAX_ROLLS; x++) {
      pin_counts[x] = 0;   
   }
}

void bowling_game_roll(int pin_count) {
   pin_counts[roll_index] = pin_count;
   roll_index++;   
}

bool is_spare(int index) {
   return(pin_counts[index] + pin_counts[index+1] == 10);
}

bool is_strike(int index) {
   return(pin_counts[index] == 10);
}

int score_strike(int index) {
   return (10 + pin_counts[index+1] + pin_counts[index+2]);
}

int score_spare(int index) {
   return (10 + pin_counts[index+2]);
}

int score_normal(int index) {
   return (pin_counts[index] + pin_counts[index+1]);
}

int bowling_game_score(void) {
   int score = 0;
   int roll_index = 0;
   for(int frame_index = 0; frame_index < NUM_FRAMES; frame_index++) {
      if( is_strike(roll_index)) {
         score += score_strike(roll_index);
         roll_index += 1;
      }
      else if( is_spare(roll_index)) {     
         score += score_spare(roll_index); 
         roll_index += 2;
      }
      else {
         score += score_normal(roll_index);
         roll_index += 2;
      }        
   }
   return(score);
}
