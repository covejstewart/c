// bowling_game_test.c

#include "bowling_game.h"

#include <stdlib.h>
#include <assert.h>


static void roll_many(int rolls, int pins) {
   for (int x = 0; x < rolls; x++) {
      bowling_game_roll(pins);      
   }   
}

static void test_score_gutter_game( void) {
   bowling_game_init();
   roll_many(20, 0);
   assert(bowling_game_score() == 0 && "Test Failed: score_gutter_game");
}

static void test_score_all_ones( void) {
   bowling_game_init();
   roll_many(20, 1);
   assert(bowling_game_score() == 20 && "Test Failed: score_all_ones");
}

static void test_score_single_spare( void) {
   bowling_game_init();
   bowling_game_roll(8);
   bowling_game_roll(2);
   bowling_game_roll(5);
   roll_many(17, 0);
   assert(bowling_game_score() == 20 && "Test Failed: score_single_spare");
}   

static void test_score_single_strike( void) {
   bowling_game_init();
   bowling_game_roll(10);
   bowling_game_roll(5);
   bowling_game_roll(2);
   roll_many(16, 0);
   assert(bowling_game_score() == 24 && "Test Failed: score_single_strike");
}   

static void test_score_perfect_game( void) {
   bowling_game_init();
   roll_many(12, 10);
   assert(bowling_game_score() == 300 && "Test Failed: score_perfect_game");
}

int main() {

   test_score_gutter_game();
   test_score_all_ones();
   test_score_single_spare();
   test_score_single_strike();
   test_score_perfect_game();
}
