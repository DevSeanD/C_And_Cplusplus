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
 *	void user_input -- Precondition - called only after either study_sesh or break_sesh have
 *				been completed.
 *				Postcondition - If the user enters 1 the program will continue,
 *				if not then program will exit using assert.	    
 *
 *	void timer_out -- Precondition - called when wanting to tell the user that a session has
 *				has ended
 *			  Postcondition - this funtion will output if what session has ended and
 *
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
	cout << " " << endl;

	switch (x){
		case 1:
			return;
		default:
			assert(x == 1);
	}

}

void timer_out(){
	if (sesh_track == 1){
                cout << "Welcome to Pomodoro timer" << endl;
		cout << " " << endl;
		return;
	}
	if (sesh_track > break_track){
		cout << "Study session " << sesh_track - 1 << " has ended" << endl;
		cout << " " << endl;
	}
	if (sesh_track == break_track){
		cout << "Break " << break_track - 1 << " has ended" << endl;
		cout << " " << endl;
	}
	if (sesh_track == 5){
		cout << "Congradulations!, You have completed one Pomodoro cycle." << endl;
	}
	else
		return;
}


int main(){

	timer_out();
	study_sesh();
	timer_out();
	
	user_input();
	break_sesh();
	timer_out();
		
	user_input();
	study_sesh();
	timer_out();

	user_input();
	break_sesh();
	timer_out();

	user_input();
	study_sesh();
	timer_out();

	user_input();
	break_sesh();
	timer_out();

	user_input();
	study_sesh();
	timer_out();


	return 0;
}
