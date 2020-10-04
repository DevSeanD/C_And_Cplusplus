/*! 
CSCI 343 Operating Systems, Fall 2020
Program #1: myshell.c
Author: Sean Dever
Date Due: 11 September 2020

The project myshell.c takes in a string of characters from the user and forwards it to the shell. In my case the Bash shell. It even allows for sudo operation that require the input of the root password.
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
  
  int i = 0;        // counter for later use
  char string[20]; // input from stdin
  char *args[20]; // command arguments
  int pid;       // process id
  
  while(1 == 1){
    pid = fork();
    if(pid == 0){ // childprocess running
      printf("\n");
      printf("Enter the string: ");
      fgets(string,20,stdin);         // input from stdin stream
      string[strlen(string) - 1] = '\0'; // adds null char to end of input
      if(!strcmp(string,"exit")){ // string compare(strcmp)  will return a value of 0 if there is no difference between arg0 and arg1. !0 = true
	kill(pid,2); // was getting this error: extern int kill (__pid_t __pid, int __sig) __THROW; but by making int __sig > 1 it exits just fine
      }
      printf("\nThe string is: %s",string);
      args[0] = strtok(string," "); // retreives the text until it its " "
      while(args[i] != NULL){
	args[++i] = strtok(NULL, " ");
      }
      execvp(args[0],args); // seems redundant but is correct syntax
    }
    else{
      wait(NULL); // getting errors without having the null perameter 
    }
  }
}
