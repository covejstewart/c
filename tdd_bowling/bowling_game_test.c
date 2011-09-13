// bowling_game_test.c

#include "bowling_game.h"

#include <assert.h>
#include <stdbool.h>

static void roll_many(int rolls, int pin_count) {
	for(int i = 0; i < rolls; i++) {
		bowling_game_roll(pin_count);
	}
}

static void test_init() {
	bowling_game_init();
	bowling_game_roll(8);
	bowling_game_init();
	assert( bowling_game_score() == 0 && "test_init()" );
}

static void test_gutter_game() {
	bowling_game_init();
	roll_many(20,0);
	assert( bowling_game_score() == 0 && "test_gutter_game()" );
}

static void test_all_ones() {
	bowling_game_init();
	roll_many(20,1);
	assert( bowling_game_score() == 20 && "test_all_ones()" );
}

static void test_one_spare() {
	bowling_game_init();
	roll_many(10,0);
	bowling_game_roll(8);
	bowling_game_roll(2);
	roll_many(8,0);
	assert( bowling_game_score() == 20 && "test_one_spare()" );
}

int main() {
	test_init();
	test_gutter_game();
	test_all_ones();
	test_one_spare();
}
