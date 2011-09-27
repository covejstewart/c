// bowling_game_test.c

#include "bowling_game.h"

#include <stdlib.h>
#include <assert.h>

static void roll_once(int num_pins) {
   bowling_game_roll(num_pins);
}

static void roll_many(int rolls, int pins_per_roll) {
   for(int x = 0; x < rolls; x++) {
      roll_once(pins_per_roll);
   }
}   

static void test_perfect_game( void){
   bowling_game_init();
   roll_many(12,10);
   assert(bowling_game_score() == 300 && "Test Failed: perfect_game");
}

static void test_single_strike( void){
   bowling_game_init();
   roll_once(10);
   roll_once(5);
   roll_once(2);
   roll_many(16,0);
   assert(bowling_game_score() == 24 && "Test Failed: single_strike");
}

static void test_single_spare( void){
   bowling_game_init();
   roll_once(5);
   roll_once(5);
   roll_once(5);
   roll_many(17,0);
   assert(bowling_game_score() == 20 && "Test Failed: single_spare");
}

static void test_single_score( void){
   bowling_game_init();
   roll_once(5);
   roll_many(19, 0);
   assert(bowling_game_score() == 5 && "Test Failed: single_score");
}

static void test_gutter_game( void){
   bowling_game_init();
   roll_many(20, 0);
   assert(bowling_game_score() == 0 && "Test Failed: gutter_game");
}




int main() {
   test_gutter_game();
   test_single_score();
   test_single_spare();
   test_single_strike();
   test_perfect_game();
}
