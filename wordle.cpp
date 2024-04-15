#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here


void backtracking(std::string& in, const std::set<std::string>& dict, std::string floating, int x, std::set<std::string>& holder); 



// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here

	//one string in which is the string you want to add letters to, have floating letters and dictionary that has all the words
	//iterate through all charachters and your out of floating letters and you have a valid word 

	
	std::set<std::string> holder; 
	std::string floating2 = floating; 


  std::string in2 = in; 


	backtracking(in2, dict, floating2, 0, holder); 
	return holder; 


	

}

// Define any helper functions here

void backtracking(std::string& in, const std::set<std::string>& dict, std::string floating, int x, std::set<std::string>& holder){

	//in is the 
	//if something is already in IN then dont overwrite it, if its a - then can change
	//increment x whenever you change a dash 
	if(x == in.length()){
		if(dict.find(in) != dict.end() && floating.size() == 0){
			holder.insert(in); 
		}
		return;
	}

	//need to check if floating charachter 
	if(in[x] == '-'){

		int dashCount = 1;
		for (int curr = x+1; curr < in.length(); curr++) {
			if (in[curr] == '-') dashCount++;
		}
		
		if (dashCount > floating.length()) {		
			for(int i = 'a'; i <= 'z'; i++){
				in[x] = i; 
				backtracking(in, dict, floating, x + 1, holder); 
			}
		}

		string prev = floating; 
		for(int j = 0; j < prev.size(); j++){
			floating = prev.substr(0, j) + prev.substr(j + 1);
			in[x] = prev[j];
			backtracking(in, dict, floating, x + 1, holder);
		}

		in[x] = '-';
	}
	else{
		backtracking(in, dict, floating, x + 1, holder); 

	}

}



