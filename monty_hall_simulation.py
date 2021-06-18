from random import randrange
import sys


# creates the initialize array where each element is one instance of the monty hall problem
# input: num_trials (int)  is the number of experiments to conduct
# output: trials (array of array of ints) is an array where each element is an array with 3 ints
# 0 represents a goat, 1 represents the car
def get_trials_arr(num_trials):
	trials = []

	for i in range(num_trials):

		x = [0, 0, 0]
		index = randrange(3)

		# set one of elements to equal 1
		x[index] = 1

		trials.append(x)

	return trials


# returns the percentage of times you win the car if you stayed
# input: monty_hall_arr is an array representing n Monty Hall problems
# output: float representing the number of times you succeed by sticking to the initial choice
def percentage_success_stay_strategry(monty_hall_arr):
	num_successes = 0

	for i in range(len(monty_hall_arr)):

		chosen_index = randrange(3)

		if monty_hall_arr[i][chosen_index] == 1:
			num_successes += 1

	return (num_successes/len(monty_hall_arr) * 100.0)


# returns the percentage of time you win the car if you changed your choice
def percentage_success_change_strategy(monty_hall_arr):
	num_successes = 0

	for i in range(len(monty_hall_arr)):

		trial = monty_hall_arr[i]

		indices = [0, 1, 2]

		chosen_index = randrange(3)

		indices.remove(chosen_index)

		index = get_closed_room_index(trial, indices)

		if trial[index] == 1:
			num_successes += 1

	return (num_successes/len(monty_hall_arr)* 100.0)


# returns an index of the room that was not reveal
def get_closed_room_index(trial, other_rooms):

	index = other_rooms[0]

	if trial[index] == 1:
		return index
	else:
		return other_rooms[1]



args = sys.argv

if len(args) != 2:
	print("Usage: python monty_hall_simulation.py <num_trials>")
	sys.exit(0)

else:
	num_trials = int(args[1])

arr = get_trials_arr(num_trials)

print("Using stay strategy: " + str(percentage_success_stay_strategry(arr)))
print("Using change strategy: " + str(percentage_success_change_strategy(arr)))









