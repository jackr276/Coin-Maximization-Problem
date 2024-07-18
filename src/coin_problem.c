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


void strat_minimize_alice_gain(Player* Bob, Player* Alice, u_int8_t* coins[], int* length){
}


/**
 * Bob's Greedy strategy -- always takes the largest coin at either end
 */
void strat_take_largest(Player* Bob, u_int8_t* coins[], int* length){
	//Always take the largest coin	
	if(*coins[0] > *coins[*length - 1]){
		Bob->total_money += *coins[0];
	
		//Advance pointer up by 1 to erase the first number
		(*coins)++;
	} else {
		//The number here will be gone implicitely 
		Bob->total_money += *coins[*length -1];
	}

	//Decrement length
	(*length)--;
}


/**
 * Bob takes his turn. Depending on our simulation, he will choose the greedy strategy or the
 * one that minize's Alice's gain
 */
void bob_turn(Player* Bob, Player* Alice, u_int8_t* coins[], int* length, enum strategy strat){
	if(strat == minize_gain){
		strat_minimize_alice_gain(Bob, Alice, coins, length);
	} else {
		strat_take_largest(Bob, coins, length);	
	}
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
	int size = 8;

	// Not necessary but good practice -- clean up our garbage
	free(Bob);
	free(Alice);

	// Tell bash all went well
	return 0;
}
