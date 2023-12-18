/*
 * sorter.h
 *
 * Declares a template function:
 *    
 *   sorter() : k-way merge sort.
 * 
 * 
 * You may add other functions if you wish, but this template function
 * is the only one that need to be exposed for the testing code.
 * 
 * Authors: C. Painter-Wakefield & Tolga Can
 */

#ifndef _SORTER_H
#define _SORTER_H

#include <string>
#include <cstddef>
#include <vector>

using namespace std;


//Step 2 part b. function to recursively merge vuectors back together
template <class T>
vector<T> mergeBackTogether(vector<vector<T>> listVec) {
	vector<T> vecToPrint;

	// for (size_t i = listVec.size(); i > 0; i++){
	// 	if (listVec.at(i).empty()){
	// 		listVec.erase(listVec.begin() + i);
	// 	}
	// }
	

	while (listVec.size() != 0){ //while our k amount of vectors are not empty
		T maxElement = (listVec.at(0).back()); // variable to be assigned max element, temp with first max element to be compaired
		int maxElementIndex = 0; // index vector at which max element is located

		for (size_t i = 0; i < listVec.size(); i++){ //campare all max values and update max variables
			if (maxElement < (listVec.at(i)).back()){
				maxElement = (listVec.at(i)).back();
				maxElementIndex = i;
			}
		}

		vecToPrint.push_back(maxElement); // add max element to final vector
		listVec.at(maxElementIndex).pop_back(); // remove elment from vector		
		
		if ((listVec.at(maxElementIndex)).empty()) {
			listVec.erase(listVec.begin() + maxElementIndex);
		}
	}
	
	reverse(vecToPrint.begin(), vecToPrint.end()); // return final vector but flipped

	return vecToPrint;
}



template <class T>
void sorter(vector<T> &vec, int k) {  
	// write your solution for k-way merge sort below
	
	//Step 1: Split vectors

		// part a. Base case
	if (vec.size() == 1 || vec.size() == 0){
		return;
	}

		// part b. split vectors above size 1
	else{
		vector<vector<T>> vecArr; // create vector of vectors (size k)

		int numOfPartitions = k;

		if (vec.size() < k){
			numOfPartitions = vec.size();
		}
		

		for (size_t i = 0; i < numOfPartitions; i++){ // k amount of vectors
			vector<T> newVec; // create new vector
			vecArr.push_back(newVec); // add to vector of vectors

		}

		//part c. Assign new vector elements from original vectors

		for (size_t i = 0; i < vec.size(); i++){ //add elements from orginial vector to new vacArr
			vecArr.at(i % k).push_back(vec.at(i)); //assigning each element at correct vector basedon round robin approach

		}
	

	//Step 2: merge sort new vectors

		//part a. Recursivley call sorter

		for (size_t i = 0; i < vecArr.size(); i++){ //for each new vector (there are k of them)
			sorter(vecArr.at(i),k); //recursivly break all vectors into vectors of size 1
		}

	//part b. Make helper function above sorter

	vec = mergeBackTogether(vecArr);

	}

}
#endif
