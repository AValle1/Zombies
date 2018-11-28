/********************************************************
 * CS 103 Zombie-pocalypse PA
 * Name: Andrew Valle
 * USC email: Andrewjv@usc.edu
 * Comments (you want us to know):
 *
 *
 ********************************************************/

 // Add other #includes if you need
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

const int MAXPOP = 100000;

int main()
{
	// Array with enough entries for the maximum population size possible.
	bool pop[MAXPOP];

	// Your code here
	//N=Total Population k=Num Initial Zombies M=Num Similations S=Seed
	int N, k, M, S;
	
	//Other Variable I need to keep track of
	int num_Nights = 0;
	double avg_Nights = 0;
	double max_Nights = INT_MIN;
	double min_Nights = INT_MAX;
	

	cout << "Enter the following: N k M seed" << endl;
	cin >> N >> k >> M >> S;
	
	srand(S);
	
	int originalK = k; //To reinitialize k back to where it was after each simulation
	int random = 0; 


	if (k>N)
	{
		return 0;
	}

	else
	{	
		for (int i = 0; i < M; i++) //Goes throgh M simulations
		{
	
			//Initialize Zombies in Array
			for (int j = 0; j < originalK; j++)
			{
				pop[j] = true;
			}

			//Initialize Humans in Array
			for (int l = originalK; l < N; l++)
			{
				pop[l] = false;
			}

			int numBites = k;  //Tracks how many bites zomebies get each night

			while (k != N)  //While Whole Population is not zombies
			{

				for (int m = 0; m < numBites; m++) //Simulate Each Bite
				{
					random = (rand() % N);
				
				
					if (pop[random] == false)
					{
						pop[random] = true;
						k++;				
					}
				}
			
				num_Nights++; //Update num nights after zombies bite
			
				numBites = k; //Increase the number of bites next night depending on number of zombies
			}
		
			avg_Nights = (avg_Nights + num_Nights); 

			if (num_Nights > max_Nights)
			{
				max_Nights = num_Nights;
			}

			if (num_Nights < min_Nights)
			{
				min_Nights = num_Nights;
			}

			num_Nights = 0; //RESET num_Nights for next simulation
			k = originalK;
		}
	}

	avg_Nights = avg_Nights/(double)M;


	// Print out your average, max, and min number of nights here
	// Be sure to follow the format shown in the assignment writeup.
	cout << "Average Nights: " << avg_Nights << endl;
	cout << "Max Nights: " << max_Nights << endl;
	cout << "Min Nights: " << min_Nights << endl;


	return 0;
}