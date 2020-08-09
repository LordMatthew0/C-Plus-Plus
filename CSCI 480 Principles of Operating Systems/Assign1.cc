/******************************************************
Assignment 1- Spring 2020 CSCI 480 Section 1
Matthew Lord Z1848456
Due Date: 1/24/2020

This program demonstrates the use of fork to create
threads. This program also uses the system command ps
to show threads.
******************************************************/
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(){

    cerr << "I am the original process. My PID is " << getpid() << " and my parent's PID is " << getppid() << '\n';
    cerr << "Now we have the first fork. \n\n";

    int N = fork();
    if(N < 0) // Error
    {
        cerr << "The first fork failed. \n";
        return -1;
    }
    else if (N == 0) // In the child
    {
        cerr << "I am the child. My PID is " << getpid() << " and my parent's PID is " << getppid() << '\n';
        cerr << "Now we have the second fork \n";
        int F = fork();
        if(F < 0) //Error
        {
            cerr << "\nThe second fork failed. \n";
            return -1;
        }
        else if (F ==0) // In the child
        {
            cerr << "I am the grandchild. My PID is " << getpid() << " and my parent's PID is " << getppid() << '\n';
            sleep(3); // Have the grandchild sleep for three seconds
            cerr << "I am the grandchild. I should now be an orphan. My PID is " << getpid() << " and my parent's PID is " << getppid() << '\n';
            cerr << "I will now call ps. \n";
            system("ps");
            cerr << "\nI am the grandchild, about to exit. \n";
            return 0;
        }
        else
        {
            cerr << "I am the child. My PID is " << getpid() << " and my parent's PID is " << getppid() << '\n';
            cerr << "I am the child, about to exit. \n";
            return 0;
        }
    }
    else // In the parent and N = child's PID
    {
        cerr << "I am the parent. My PID is " << getpid() << " and my parent's PID is " << getppid() << '\n';
        sleep(2); // Have the parent sleep for two seconds
        cerr << "I am the parent, about to call ps. THe child should appeear as a zombie.\n";
        system("ps");
        cerr << '\n';
        sleep(3); // Have the parent sleep for three seconds
        wait(0); // wait for the child to terminate
        cerr << "I am the parent, having waiting on the child, about to call ps again. \n";
        system("ps");
        cerr << "I am the parent, about to exit.\n";
        return 0;
    }
    return 0;

}
