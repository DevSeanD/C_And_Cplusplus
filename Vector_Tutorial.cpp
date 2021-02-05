//Author: Sean Dever
//Date: 2-4-2021
//Description: The purpose of this C++ file is to give a breif introduction to vectors. They sound more complex than they are. A vector allows for a dynamic array.
//             This array can be manipulate in the following ways.

#include <iostream>
#include <vector>
 
int main()
{
	// Creating a vector set with int as it data type 
    	std::vector<int> v = {1,2,3,4,5};
	
	// Use the push_back(n) function to push a new element to the back of the vector
    	v.push_back(25); 
    		
	// You can check the value of the last element with the back() fucntion	 
	std::cout << "The last element of our vector array: " << v.back() << std::endl;

	// You can pop off the back value with function pop_back()
  	v.pop_back();

	// A effective way to output all element
	for (int n : v) {
       		std::cout << n << " ";
    	}
	std::cout << std::endl;

}
