#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
int main(int argc, char **argv){
	pid_t cpid;
	int children = argc / 2;

	
	cout << "I have " << children << "children\n";
	for (int i = 0; i < children; i+= 2){
		cout << "itertation: " << i << "\n";
		cpid = fork();
		if ( cpid == 0){
			cout << "child # " <<  i << "\n";
		} 
	}
 
//	switch(cpid){
//		case -1:
//			cout << "There is an error\n";
//			break;
//		case 0:
//			cout << "We are in the child process\n";
//			break;
//		default:
//			cout << "We are in the parent process\n";
//			break;
//	}

}
