#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <cstdio>
using namespace std;
int main(int argc, char **argv){
	pid_t cpid;
	int children = (argc - 1) / 2;



	cout << "I have " << children << "children\n";

//	cpid = fork();

//	if (cpid == 0){
//		cout << "This is the child" << "\n";
//		execlp("/home/mekhi/School/2022_Fall/CECS_326/Labs/Lab_1/CECS-326-Assignment-1-/b.out","hello",NULL);
	//	execlp("/home/mekhi/School/2022_Fall/CECS_326/Labs/Lab_1/CECS-326-Assignment-1-/b.out",NULL);

	for (int i = 0; i < children; i++){
		cpid = fork();
		if ( cpid == 0){ // If this is the child process
			char childNum[100];
			int currentIteration = i;
			sprintf(childNum,"%d",currentIteration + 1);
			execlp("/home/mekhi/School/2022_Fall/CECS_326/Labs/Lab_1/CECS-326-Assignment-1-/b.out",childNum, argv[i+1],argv[i+2],NULL);
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
