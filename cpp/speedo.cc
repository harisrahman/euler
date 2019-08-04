/* 
 * Speedo - A C++ program performance measuring tool
 *
 * Measures processor time and wall clock time taken by a program to
 * run n number of times
 * 
 */


#include <iostream>
#include <ctime>
#include<time.h>
#include<bits/stdc++.h>

using namespace std;

void speedo(int runs)
{
	struct timespec start, finish;
	double cpu_elapsed, wall_elapsed, cpu_elapsed_avg, wall_elapsed_avg;
	double cpu_elapsed_sum = 0, wall_elapsed_sum = 0;
	clock_t time_req;

	cout << "Times executed : " << runs  << endl;

//Finding cpu elapsed time (low end functions always show 0)

	for (int i = 0; i < runs; i++)
	{
		time_req = clock();

//Execute code


		time_req = clock() - time_req;

		cpu_elapsed = (double)time_req/CLOCKS_PER_SEC;
		cpu_elapsed_sum += cpu_elapsed;
	}

	cpu_elapsed_avg = cpu_elapsed_sum / runs;

	cout << "Average cpu clock time taken  : ";
	cout << fixed << setprecision(7) << cpu_elapsed_avg << endl;

	
//Finding wall clock elapsed time

	for (int i = 0; i < runs; i++)
	{
		clock_gettime(CLOCK_MONOTONIC, &start);

		//Execute code	

		clock_gettime(CLOCK_MONOTONIC, &finish);

		wall_elapsed = (finish.tv_sec - start.tv_sec);
		wall_elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

		wall_elapsed_sum += wall_elapsed;
	}

	wall_elapsed_avg = wall_elapsed_sum / runs;


	cout << "Average wall clock time taken : ";
	cout << fixed << setprecision(7) << wall_elapsed_sum << endl;
	
}


int main()
{
	speedo(2);
	return 0;
}