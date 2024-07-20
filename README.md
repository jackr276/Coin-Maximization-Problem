# Coin Maximization Problem
Author: [Jack Robbins](https://www.github.com/jackr276)

This simple C program implements the optimal solution to the "coins in a line" dynamic programming problem, using memoization.

## The Problem
Given a line of coins as follows: `$2   $6   $5   $2   $7   $3   $5   $4` and two players, Alice and Bob, find the optimal solution for Alice, given that Bob will also play equally competently. That is, find the strategey that maximizes Alice's gain if Bob is at the same time trying to minimize her gain. This problem is solveable, and the recurrence equation: `Max(A[i] + min(a, b), A[j] + min(b, c))`,where A[i] and A[j] are the left and rightmost coins respectively, sometimes known as "min-max", always gives the optimal solution for Alice. It takes the maximum of the two options, **assuming** that Bob will always minimize Alice's gain. This is what gives us the `min` part of the equation. Here is the code below, with documentation:
```c
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
```
