#include <iostream>
#include <ctime>
// This program is a fast prototype of a the timing function require for benchmarking alorithms.
// References: https://www.programiz.com/cpp-programming/library-function/ctime/clock


int main() {
  std::cout << "Hello World!\n";
  
  clock_t time_req; // create clock_t object
  time_req = clock(); // set clock_t object to starting clock
  
  int value;
  for(int i=0; i < 1000000; i++){ // sample operation
    value++;
  }
  
  time_req = clock() - time_req; // difference between stop and end clocks
	std::cout << "The for loop took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << std::endl; // CLOCKS_PER_SEC the needed ratio of the clocks of this processor per second
}
