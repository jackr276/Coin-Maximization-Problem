/**
 * Author: Jack Robbins
 *
 * This simple C program implements the Dynamic Programming Problem regarding coin choosing strategies
 */

#include <stdlib.h>
#include <sys/types.h>

struct Player{
	u_int8_t total_money;
};


void strat_minimize_alice_gain(struct Player* Bob, struct Player* Alice){

}

void strat_take_largest(struct Player* Bob, struct Player* Alice){

}

void bob_turn(struct Player* Bob){

}

void alice_turn(struct Player* Alice){

}



/**
 * Program entry point, handles initial allocations and makes appropriate calls
 */
int main(void){
	// Our game has 2 player, Alice and Bob
	struct Player* Bob = (struct Player*)malloc(sizeof(struct Player));	
	struct Player* Alice = (struct Player*)malloc(sizeof(struct Player));	

	// We always start off with the same coin config, in this order
	u_int8_t coins[8] = {2, 6, 5, 2, 7, 3, 5, 4};


	// Not necessary but good practice -- clean up our garbage
	free(Bob);
	free(Alice);

	// Tell bash all went well
	return 0;
}
