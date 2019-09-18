#include <iostream>
#include <chrono>
#include <thread> // used for timer functions
#include <cassert>// used for assert function 
using namespace std;

/*Sean Dever
 *
 *Pomodoro Timer - This console application is a study tool. The goal of this 
 *application is to create 4 25 minute study sessions seperated by 5 minute breaks
 *
 *Functions -
 *	void study_sesh -- Postcondition - output to console that the session has begun and then
 *				using the chrono library start a timer for 25 minutes.
 *
 *	void break_sesh -- Postcondition - output to console that the break has begun and then, 
 *				using the chrono libary, it starts a timer for 5 minutes.
 *
 *	int user_input -- Precondition - called only after either study_sesh or break_sesh have
 *				been completed.
 *				Postcondition - If the user enters 1 the program will continue,
 *				if not then program will exit using assert.	    
 */
int sesh_track = 1;// counter for sessions completed
int break_track = 1;// counter for breaks completed

void study_sesh(){
	cout << "Study session " << sesh_track << " has begun!" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	sesh_track ++;

}

void break_sesh(){
	cout << "Break " << break_track << " has begun!" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	break_track++;
}

void user_input(){
	int x;
	cout << "Please enter 1 to continue" << endl;
	cin >> x;

	switch (x){
		case 1:
			return;
		default:
			assert(x == 1);

	}

}


int main(){

	cout << "Welcome to the Pomodoro timer!" << endl;
	cout << " " << endl;
	
	study_sesh();
	cout << " " << endl;
	cout << "Study session 1 has ended" << endl;
	cout << " " << endl;
	
	user_input();
	break_sesh();
	cout << " " << endl;
	cout << "Break 1 has ended" << endl;
	cout << " " << endl;
	
	user_input();
	study_sesh();
	cout << " " << endl;
	cout << "Study Session 2 has ended" << endl;
	cout << " " << endl;

	user_input();
	break_sesh();
	cout << " " << endl;
	cout << "Break 2 has ended" << endl;
	cout << " " << endl;

	user_input();
	study_sesh();
	cout << " " << endl;
	cout << "Study Session 3 has ended" << endl;
	cout << " " << endl;

	user_input();
	break_sesh();
	cout << " " << endl;
	cout << "Break 3 was ended" << endl;
	cout << " " << endl;

	user_input();
	study_sesh();
	cout << " " << endl;
	cout << "Congradulations you have finished a Pomodoro cycle, a 25 minute break is advised before continuing" << endl;
	
	return 0;
}

