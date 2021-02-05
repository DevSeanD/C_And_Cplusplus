//Sean Dever
//permutations.py
//Description: This program proves the permuations of the specified array. It then uses vectors to store the master list of permutations.

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

std::vector<int> permutations(int a[], int n) //needs to be a vector<int> type in order to return list of permutations
{
	std::vector<int> perms;
    	// Sort the given array
    	sort(a, a + n);

    	// Find all possible permutations
    	cout << "Possible permutations are:\n";
    	do {
        	for (int i = 0; i < n; i++) {
                	perms.push_back(a[i]);
        	}
    	} while (next_permutation(a, a + n));

	return perms;
}

int main()
{
	int arr[] = {1,2,3,4,5};  	
	int n = sizeof(arr) / sizeof(arr[0]);

	std::vector<int> permuVector = permutations(arr,n);
	int counter = 0; 
	for(int x: permuVector){
		if(counter == 5){
			std::cout << " " << std::endl;	
			counter = 0;
		}
		std::cout << x << " ";
		counter ++;
	}
	std::cout << " " << std::endl;


}
