//DevSeanD
//1/21/2021
//Deck of Cards C++ implemenation - The purpose of this program is to provide a foundation for coding card games in C++.
//	The broader goal to better my understanding of classes in C++.

#include <iostream>
#include <string>

class Card {
	std::string suit;
	int value;
	
	public:
		void setValues(std::string x,int y){
			suit = x;
			value = y;
		}
		void showValues(){
			std::cout << suit << " " << value << std::endl;
		}
};

class Deck {
	//To DO

	}; 

int main(){
	std::cout << strarr[0] << std::endl; 
	Card testcard;
	testcard.setValues("Club",2);
	testcard.showValues();
	std::string test = "This is a test of the string library for C++";
	std::cout << test << std::endl;
	std::cout << "This is a test of iostream" << std::endl;

	return 0;
}
