
// code to run the monty hall simulation in c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define NUM_ROOMS 3
#define MAX_ARRAY_SIZE 100000000


int** get_initial_array(int numTrials);
float calculateWithStayStrategy(int** montyHallArray, int size);
float calculateRateChangeChoice(int** montyHallArray, int size);


int main(){

	long int numTrials;

	// setting the seed of the rand function
	srand(time(NULL));

	printf("Please enter the number of experiments to run:\n");
	scanf("%ld", &numTrials);
	assert((numTrials > 0) && (numTrials <= MAX_ARRAY_SIZE));

	int** trials = get_initial_array(numTrials);

	float staySuccessRate = calculateWithStayStrategy(trials, numTrials);
	float changeChoiceSuccessRate = calculateRateChangeChoice(trials, numTrials);

	// deleting trials
	free(trials);

	printf("Number of trials: %ld\n", numTrials);
	printf("Success rate with STAY strategy: %f\n", staySuccessRate);
	printf("Success rate with CHANGE strategy: %f\n", changeChoiceSuccessRate);


}


int** get_initial_array(int numTrials){

	int** trials = (int**) malloc(numTrials * sizeof(int*));

	for(int i = 0; i < numTrials; i++){

		trials[i] = (int *) malloc(NUM_ROOMS * sizeof(int));

		for(int j = 0; j < NUM_ROOMS; j++){
			trials[i][j] = 0;
		}

		// set random 'room' to 1
		int randomIndex = rand() % NUM_ROOMS;
		assert((randomIndex >= 0) && (randomIndex <= 2));

		trials[i][randomIndex] = 1;
	}

	return trials;
}


float calculateWithStayStrategy(int** montyHallArray, int numTrials){

	int i;
	int numOfWins = 0;

	for(i = 0; i < numTrials; i++){

		int chosenRoom = rand() % NUM_ROOMS;
		assert((chosenRoom >= 0) && (chosenRoom <= 2));

		if( montyHallArray[i][chosenRoom] == 1){
			numOfWins++;
		}
	}

	float percentageOfWins = (float) numOfWins/(float)numTrials * 100;

	return percentageOfWins;
}

float calculateRateChangeChoice(int** montyHallArray, int numTrials){

	int i;
	int numOfWins = 0;

	for(i = 0; i < numTrials; i++){

		int chosenRoom = rand() % NUM_ROOMS;
		assert((chosenRoom >= 0) && (chosenRoom <= 2));

		for(int j = 0; j < NUM_ROOMS; j++){

			// skip the room that was initially chosen
			if (j == chosenRoom)
				continue;

			// if one of the other rooms is the car then it results in a win
			else if(montyHallArray[i][j] == 1){
				numOfWins++;
				break;
			}
		}
	}

	float percentageOfWins = (float) numOfWins/(float)numTrials * 100;

	return percentageOfWins;
}
