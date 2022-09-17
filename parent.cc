#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <cstdio>
#include <sys/wait.h>
using namespace std;
int main(int argc, char **argv){
	pid_t cpid;
	int children = (argc - 1) / 2;



	cout << "I have " << children << " children.\n";


	for (int i = 0; i < children; i++){
		cpid = fork();
		int idxSpacer;

		if (i == 0){
			idxSpacer = 0;
		}
		else{
			idxSpacer = i;
		}

		if ( cpid == 0){ // If this is the child process
			char childNum[100]; // Buffer for the child number
			sprintf(childNum,"%d",i + 1); // Converts int to char[]
			execlp("/home/mekhi/School/2022_Fall/CECS_326/Labs/Lab_1/CECS-326-Assignment-1-/b.out",childNum, argv[i + idxSpacer + 1],argv[i+ idxSpacer +2],NULL);
		}
		else if(cpid < 0 ){ // Process failed
			cout << "\nProcess failed.\n";
		}
	}
	while (wait(NULL) > 0); // Blocks code after it until all children has terminated
	cout << "All child processes terminated. Parent exited\n";
}
