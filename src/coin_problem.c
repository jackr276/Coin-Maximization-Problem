/**
 * Author: Jack Robbins
 *
 * This simple C program implements the Dynamic Programming Problem regarding coin choosing strategies
 */

#include <stdio.h>


/**
 * In this case, it is easier for us to solve for Bob because we know what he will take
 */
int solve_bob_greedy(int coins[], int length){
	int bob_coins[length / 2];

	int i = 0;
	int j = length - 1;
	int turn = 1;
	int bob_index = 0;	

	while(i <= j){
		//Bob's turn
		if(turn % 2 != 0){
			if(coins[i] > coins[j]){
				bob_coins[bob_index] = coins[i];		
				i++;
			} else {
				bob_coins[bob_index] = coins[j];
				j--;
			}
			bob_index++;
		} else {
			if(coins[i] > coins[j]){
				i++;
			} else {
				j--;
			}
		}
		turn++;
	} 

	int sum = 0;
	for(int i = 0; i <= bob_index; i++){
		sum += bob_coins[i];
	}

	return sum;
}


/**
 * In this scenario, Bob and Alice are equally clever. They think about eachother's moves not in the immediate,
 * but two moves ahead. In this situation, Bob always chooses the coin that will minimize the amount that Alice
 * can get, so in this scenario, Alice always picks the coin that will give her more value 2 moves ahead
 */
int solve_bob_minimize(int coins[], int length){
	//A matrix for storing the result of each turn
	int MV[length][length];

	for(int idx = 0; idx < length; idx++){
		for(int i = 0, j = idx; j < length; i++, j++){
			//The results of each scenario, these all represent Alice's gain
			int opt_1;
			int opt_2;
			int opt_3;

			//Alice chooses i and then Bob chooses i + 1
			if(i + 2 <= j){
				opt_1 = MV[i+2][j];
			} else {
				opt_1 = 0;
			}

			//Alice chooses i and Bob chooses j, or vice versa(Opposite ends scenario)
			if(i + 1 <= j - 1){
				opt_2 = MV[i+1][j-1];	
			} else {
				opt_2 = 0;
			}

			//Alice chooses j, and Bob then chooses j - 1
			if(i <= j - 2){
				opt_3 = MV[i][j-2];
			} else {
				opt_3 = 0;
			}
		
			//Choosing logic: Max(A[i] + min(a, b), A[j] + min(b, c))
			//We use this logic because we always assume that Bob is going to play optimally
			//in trying to thwart Alice, so we always minimize the 2 options

			//We minimize ab and bc
			int min_factor_ab = opt_1 < opt_2 ? opt_1 : opt_2;
			int min_factor_bc = opt_2 < opt_3 ? opt_2 : opt_3;

			//Add the coin values in
			int option_ab = coins[i] + min_factor_ab;
			int option_bc = coins[j] + min_factor_bc;

			//We want the max of the 2
			MV[i][j] = option_ab > option_bc ? option_ab : option_bc;
		}
	}
	
	return MV[0][length - 1];
}


/**
 * Program entry point, handles initial allocations and makes appropriate calls
 */
int main(void){

	// We always start off with the same coin config, in this order
	int coins[8] = {2, 6, 5, 2, 7, 3, 5, 4};
	// The sum of all the coins
	int total_value = 34;

	//Evaluate Bob playing to minimize Alice first
	int alice_value = solve_bob_minimize(coins, 8);
	int bob_value = total_value - alice_value;
	printf("When Bob plays in a way that minimizes Alice's gain, the results are:\n\tAlice: %d\n\tBob:   %d\n", alice_value, bob_value);

	bob_value = solve_bob_greedy(coins, 8);
	alice_value = total_value - bob_value;
	printf("When Bob plays greedily, the results are \n\tAlice: %d\n\tBob:   %d\n", alice_value, bob_value);

	// Tell bash all went well
	return 0;
}
