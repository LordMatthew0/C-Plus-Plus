/******************************************************
Assignment 5 - Spring 2020 CSCI 480 Section 1
Matthew Lord Z1848456
Due Date: 4/6/2020

This program uses POSIX threads, semaphores and a mutex to
illustrate the Producer-Consumer Problem. 
******************************************************/

#define BUFFER_SIZE 35 // Maximum size fo the buffer 

#include <iostream>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <mutex>
#include <utility>

using namespace std;

int P_NUMBER = 7; // Global variable for the number of producers 
int C_NUMBER = 5; // Global variable for the number of consumers 
int P_STEPS = 5; // Global variable for the number of iterations for each producer thread 
int C_STEPS = 7; // Global variable for the number of iterations for each consumer thread 
list<pair<long,int>> buffer; // This is a list acting like a queue
pthread_mutex_t buffMut;

void Insert(int threadID, int widgetID);
void Remove(int threadID);
void * Produce(void * threadID);
void * Consume(void *  threadID);
void PrintBuffer(); // This is to print the buffer 

int Counter = 0; // A counter to keep track of the number of widgets

sem_t notFull; // Not full semaphore 
sem_t notEmpty; // Not empty semaphore 

int main(int argc, char* argv[]) {
    
    //get command line arguments 
    P_NUMBER = atoi(argv[1]);
    C_NUMBER = atoi(argv[2]);  
    P_STEPS = atoi(argv[3]);
    C_STEPS = atoi(argv[4]);
    /*
    cout << "you have entered " << argc << " arguments: " << '\n';
    for(int i = 0; i < argc; ++i)
    {
        cout << "argument 0 is:" << argv[0] << "\n";
        cout << "argument 1 is:" << argv[1] << "\n";
        cout << "argument 2 is:" << argv[2] << "\n";
        cout << "argument 3 is:" << argv[3] << "\n";
        cout << "argument 4 is:" << argv[4] << "\n";
    }
	*/
    int rc; // Return code from the pthread creats
    int exitVal;
	exitVal = sem_init(&notFull, 0, BUFFER_SIZE); // Set up semphore for max
	if (exitVal != 0)
    {
        cerr << "sem_init failed with exit code: " << exitVal;
        exit(-1);
    }
    sem_init(&notEmpty, 0, 0); // Set up semphore for not empty

	pthread_t Consumer[C_NUMBER];	// Make array for consumer threads
	pthread_t Producer[P_NUMBER];	// Make array for producer threads

	pthread_mutex_init(&buffMut, nullptr);	// Set up mutex

	cout << "Simulation of Producer and Consumers" <<endl;
	cout << "The semaphores and mutex have been initialized." <<endl;

	for (long i = 0; i < C_NUMBER; i++){	// Loop and make all of the cousumer thread
		rc = pthread_create(&Consumer[i], NULL, Consume, (void *) i);	// Make the threads
		if(rc){	// If there is an error exit
			cerr << "Error in Consumer create" <<endl;
			exit(-1);
		}
	}
    
    for (long i = 0; i < P_NUMBER; i++){	// Make the producer threads
		rc = pthread_create(&Producer[i], NULL, Produce, (void *) i);
		if(rc){	// If there is an error exit
			cerr << "Error in producer create" <<endl;
			exit(-1);
		}
	}

	for (int i = 0; i < C_NUMBER; i++){	// Delete the consumer threads
		pthread_join(Consumer[i], NULL);
	}

	for(int i = 0; i < P_NUMBER; i++){	//D elete the producer threads
		pthread_join(Producer[i], NULL);
	}

	cout << "All the producer and consumer threads have been closed." <<endl;
	cout << "The semaphores and mutex have been deleted." << endl;

	pthread_mutex_destroy(&buffMut);
	pthread_exit(NULL);

	sem_destroy(&notFull);	// Delete the not full semphore
	sem_destroy(&notEmpty);	// Delete the not emtpy seamphore

	return 0;
}

// Function that inserts one widget into the counter. It locks adds 1 and then unlocks.
void Insert(int threadID, int widgetID){
	int code;

	code = pthread_mutex_lock(&buffMut);	// Try and lock the mutex

	if(code == 0){	// If there was not a problem
        pair<long,int> widget(threadID, widgetID);
        buffer.push_back(widget);
		Counter++;	// Add 1 to the counter
		cerr << "Producer " << threadID << " inserted one item.  Total is now " << Counter << ". ";
        PrintBuffer();
	}
	else{ // If there was a problem 
		cerr << "Producer " << threadID << " Error in lock" <<endl;
		exit(-1);
	}

	code = pthread_mutex_unlock(&buffMut);	// Unlock the mutex

	if (code != 0){	// If there is a problem
		cerr << "Producer " << threadID << " Error in Unlock" <<endl;
		exit(-1);
	}
}

// Function that takes one widget out of the counter. It locks and then removes the lock.
void Remove(int threadID) {
	int code;

	code = pthread_mutex_lock(&buffMut);	// Lock the mutex

	if (code == 0) {	// If there is not a problem
        // Remove a widget from the buffer 
        buffer.pop_front();
		Counter--;	// Remove one widget
		cerr << "Consumer " << threadID << " removed one item.   Total is now " << Counter << ". ";
        PrintBuffer();
	}
	else{ // If there is a problem 
		cerr << "Consumer " << threadID << ": Failure in Remove: lock" << endl;
		exit(-1);
	}

	code = pthread_mutex_unlock(&buffMut);	// Unlock the mutex

	if (code != 0) { // If there is a problem 
		cerr << "Consumer : " << threadID << ": Failure in Remove: Unlock" << endl;
		exit(-1);
	}
}

// Function that runs each thread to insert into the widgets buffer.
void * Produce(void * threadID) {
	long temp = (long) threadID;	// Convert the threadID to a long

	for (int i = 0; i < P_STEPS; i++) { // Loop for all the number of iterations for produce
		sem_wait(&notFull);	// Enter critical section
		Insert(temp, i); // Try insert 
		sem_post(&notEmpty); // Single out
		sleep(1); // Wait 1 sec
	}
	pthread_exit(NULL); // End thread 
}

// Function that runs the threads to delete the widgets from the buffer.
void * Consume(void * threadID) {
	long temp = (long) threadID;	// Conver to long 

	for (int i = 0; i < C_STEPS; i++) { // Loop through
		sem_wait(&notEmpty); // Single ready
		Remove(temp);	// Try remove 
		sem_post(&notFull); // Single out
		sleep(1); // Sleep
	}
	pthread_exit(NULL);	// End thread
}

// Prints the contents of buffer 
void PrintBuffer() {
    if (buffer.empty())
		cerr << "Buffer is now empty\n";
	else {
		cerr << "Buffer now conatins: ";
		for (list<pair<long, int>>::iterator it = buffer.begin(); it != buffer.end(); it++) {
			cerr << 'P' << it->first << 'W' << it->second << ' ';
		}
		cerr << endl;
		
	}
}

