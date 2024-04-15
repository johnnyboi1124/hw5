#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please

#endif

#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here




bool helper(const AvailabilityMatrix& avail, int dailyNeed, DailySchedule& sched, int day, int worker, DailySchedule& temp, vector<int>& remainingDays, const int originalDailyNeed);


//Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below

		
		//create whats in the matrix??
	  vector<int> remainingDays(avail[0].size(), maxShifts); 
		DailySchedule temp(avail.size()); 
	
		const int originalDailyNeed = dailyNeed; 


		

		return helper(avail, dailyNeed, sched, 0, 0, temp, remainingDays, originalDailyNeed); 


	
}


bool helper(const AvailabilityMatrix& avail, int dailyNeed, DailySchedule& sched, int day, int worker, DailySchedule& temp, vector<int>& remainingDays, const int originalDailyNeed){



	if(day >= avail.size()){

		sched = temp; 


		return true; 

	}
	if (dailyNeed == 0) {
		return helper(avail, originalDailyNeed, sched, day + 1, 0, temp, remainingDays, originalDailyNeed); 
	}
	if(worker >= avail[0].size()){
		return false;
	}
	//once you go past the last worker, you will check if you have used up daily need workers 
  
	bool answer = false; 

	if(avail[day][worker] == true && remainingDays[worker] > 0){
		temp[day].push_back(worker); 
		remainingDays[worker]--; 
	
		answer = answer || helper(avail, dailyNeed - 1, sched, day, worker + 1, temp, remainingDays, originalDailyNeed); 
	  temp[day].pop_back(); 
		remainingDays[worker]++; 

	}

	answer = answer || helper(avail, dailyNeed, sched, day, worker + 1, temp, remainingDays, originalDailyNeed); 

	return answer; 


}




