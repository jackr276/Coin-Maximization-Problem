/**
 * Author: Jack Robbins
 *
 * This simple C program implements the Dynamic Programming Problem regarding coin choosing strategies
 */

#include <stdlib.h>
#include <sys/types.h>

enum strategy{
	minize_gain = 0,
	take_largest = 1
};


typedef struct{
	u_int8_t total_money;
} Player;


void strat_minimize_alice_gain(Player* Bob, Player* Alice, u_int8_t coins[], int* length){
}

void strat_take_largest(Player* Bob, u_int8_t coins[], int* length){
	if(coins[0] > coins[*length - 1]){
		Bob->total_money += coins[0];
	
		for(int i = 0; i < *length - 1; i++){
			coins[i] = coins[i+1];	
		}

	} else {
		Bob->total_money += coins[*length -1];
	}

	(*length)--;
}


void bob_turn(Player* Bob, u_int8_t coins[], int length, enum strategy strat){
	
}


/**
 * Alice will always play the same strategy
 */
void alice_turn(Player* Alice, u_int8_t coins[], int length){

}


/**
 * Program entry point, handles initial allocations and makes appropriate calls
 */
int main(void){
	// Our game has 2 players, Alice and Bob
	Player* Bob = (Player*)malloc(sizeof(Player));	
	Player* Alice = (Player*)malloc(sizeof(Player));	
	Bob->total_money = 0;
	Alice->total_money = 0;

	// We always start off with the same coin config, in this order
	u_int8_t coins[8] = {2, 6, 5, 2, 7, 3, 5, 4};


	// Not necessary but good practice -- clean up our garbage
	free(Bob);
	free(Alice);

	// Tell bash all went well
	return 0;
}
