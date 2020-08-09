#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <fcntl.h>

using namespace std;

int main(void) {
	int argNum = 32;  // A large number, does not need to be
	char buffer[1024];  // Input buffer
    
	printf("480shell> "); // print prompt
    
	while (fgets(buffer,1024,stdin) != NULL)  // reads the input 
    {
		buffer[strlen(buffer) -1] = '\0';  // Removes the last character as it is not helpfull
		char* argv[argNum];   // array to hold the different arguments 
		argv[0] = strtok(buffer, " ");  // There should allways be at least one argument 
        
		for(int i = 1; i < argNum; i ++) // Loop through the arguments to create an array of arguments 
        {  
            argv[i] = strtok(NULL, " ");
			if(argv[i] == NULL) 
            {
				argv[i] = NULL;  // Set the last index to null
				break;
			}
		}
        
		// Check check to see if we need to quit 
		if(strcmp(argv[0], "q") == 0 || strcmp(argv[0], "quit") == 0) 
        {
                return 0;
        }
            
        if(strcmp(argv[0], "about") == 0) // For the about command 
        {
            cerr << "The 480shell is the work of Matthew Lord, 2020\n";
        }
        
		// Check for "<+" and ">+"
		int indexOfReadChar = -1;
        int indexOfWriteChar = -1;
		for(int i = 1; i < argNum; i++) // Check if any of the substrings are "<+" or ">+"
        {
			if(argv[i] != NULL) 
            {
				if(strcmp(argv[i], "<+") == 0) 
                {
					indexOfReadChar = i;
					argv[i] = NULL;
				}
                else if(strcmp(argv[i], ">+") == 0)
                {
                    indexOfWriteChar = i;
                    argv[i] = NULL;
                }
			}
			else 
            {
                break;
            }
		}
        
        if( indexOfReadChar == -1 && indexOfWriteChar == -1) // If there is not a read or write character 
        {
            char* firstArgument = argv[0];
            
            int N = fork(); // Fork start 
            if (N < 0) // Error
            {
                cerr << "fork error";
            }
            else if (N == 0) // In child 
            {
                execvp(firstArgument, argv);
            }
            else // In Parent 
            {
                wait(0);
            }
        }
        
		if(indexOfReadChar > 0)  // If there is a read character
        {
            if (argv[indexOfReadChar + 2] != NULL)
            {
                cerr << "Error! An extra filename was found. \n";
            }
            else
            {
                char* firstArgument = argv[0];
                char* argv2[argNum];   // array to hold the different arguments 
                argv2[0] = strtok(buffer, " ");  // There should allways be at least one argument 
                
                for(int i = 1; i < indexOfReadChar; i++) // Get the remaining elements in argv to pass as the second argument to execvp()
                {
                    argv2[i] = argv[i];
                }
                
                char* fileName = argv[indexOfReadChar + 1];
                
                int N = fork(); // Fork start 
                if (N < 0) // Error 
                {
                    printf("fork error");
                }
                else if (N == 0) // In child 
                {
                    int in = open(fileName, O_RDONLY);
                    
                    dup2(in, 0);
                    close(in);
                    
                    execvp(firstArgument, argv2);
                }
                else // In Parent 
                {
                    wait(0);
                }
            }
		}
        
        if(indexOfWriteChar > 0)  // If there is a write character
        {
            if (argv[indexOfWriteChar + 2] != NULL)
            {
                cerr << "Error! An extra filename was found. \n";
            }
            else
            {
                char* firstArgument = argv[0];
                char* argv2[argNum];   // array to hold the different arguments 
                argv2[0] = strtok(buffer, " ");  // There should allways be at least one argument 
                
                for(int i = 1; i < indexOfWriteChar; i++) // Get the remaining elements in argv to pass as the second argument to execvp()
                {
                    argv2[i] = argv[i];
                }
                
                char* fileName = argv[indexOfWriteChar + 1];
                
                int N = fork(); // Fork start 
                if (N < 0) // Error 
                {
                    printf("fork error");
                }
                else if (N == 0) // In child 
                {
                    int out = open(fileName, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
                    
                    dup2(out, 1);
                    close(out);
                    
                    execvp(firstArgument, argv2);
                }
                else // In Parent 
                {
                    wait(0);
                }
            }
		}
        
		printf("\n480shell> ");
	}
	return 0;
}