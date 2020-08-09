/****************************************************************
PROGRAM:   Assign7
AUTHOR:    Matthew Lord
LOGON ID:  Z1848456
DUE DATE:  4/24/2020
FUNCTION:  Program that will maintain a file allocation table
 *****************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

const int HOWOFTEN = 6;
const int MAXBLOCK = 12;
const int MAXPRINT = 240;
const int MAXSIZE = 4096;
const int BLOCKSIZE = 512;


struct Entry{ //Entry Block for each file
	string name;
	int size;
	vector<int> blocks;
};

int FAT[MAXSIZE] = { };	//File allocation table array
vector<Entry> files;  //Vector to hold info about each file


//Function decleration
void Copy(string name, string name2);
void Delete(string name);
void New(string name, int size);
void Modify(string name, int size);
void Rename(string name, string name2);
int Search(string name);
void Print();

int main(int argc, char *argv[])
{
    cerr << "Beginning of the FAT Simulation \n\n";
    
	int counter = 0;

	ifstream file;  //Set to read the data file
	file.open("/home/turing/t90hch1/csci480/Assign7/data7.txt");	//Open it
	string line;


	New(".", 512);  //Make . and ..
	New("..",0);

	Print();  //Print the contents


	while(!file.eof())  //Read the file
	{
		char type;
		string name;
		string name2;
		int size;

		getline(file,line);	//  Read a line
		istringstream inLine(line);	//  Parse the line

		//  Find what transation it is
		if(line.at(0) == 'C')
        {
			inLine >> type >> name >> name2;
			Copy(name, name2);
		}
		else if(line.at(0) == 'D')
        {
			inLine >> type >> name;
			Delete(name);
		}
		else if(line.at(0) == 'N')
        {
			inLine >> type >> name >> size;
			New(name, size);
		}
		else if(line.at(0) == 'M')
        {
			inLine >> type >> name >> size;
			Modify(name, size);
		}
		else if(line.at(0) == 'R')
        {
			inLine >> type >> name >> name2;
			Rename(name, name2);
		}
		else
        {
			break;
		}

		counter++;  //When the coutner is equal to HOWOFTEN print the FAT
		if(counter == HOWOFTEN)
        {
			Print();
			counter = 0;
		}
	}

	file.close();  //close the file

	Print();  
	return 0;    
}

/****************************************************
* Function: Copy one file and make a new one just
* like it, but in a different location. It checks
* to see if the new name is already used and that
* it can find the old one.
*****************************************************/
void Copy(string name, string name2){
    cout << "Transaction: Copy a file\n";
	int index = Search(name);  //Call search to find the file
	int noDup = Search(name2);

	if(index < 0) //if the original file is not found
    {  
		cout << "Error! The old file name, " << name << ", was not found." <<endl;
		return;
	}
    
	if(noDup > 0)  //If new name is in use
    {	
		cout << "Error! The new file name, " << name2 << " already exists." <<endl;
		return;
	}

	New(name2, files.at(index).size);  //Call new funciton with the original info
	cout << "Successfully copied an existing file, " << name << ", to the file, " << name2 <<endl;
}

/*********************************************
* Function: Deletes a file from the FAT after
* it check to see if thre was one.
**********************************************/
void Delete(string name){
    cout << "Transaction: Delete a file\n";
	int location = Search(name);  //find location

	if(location == -1)  //If there is no file with the name
    {	
		cout << "Error! The file name, " << name << ", was not found." << endl;
		return;
	}
	else
    {	
		for (unsigned int i = 0; i < files.at(location).blocks.size(); i++)  //delete the blocks in the FAT by setting them to 0
        {	
			FAT[files.at(location).blocks.at(i)] = 0;
		}

		files.erase(files.begin() + location);	//delete it out of the file vector

		cout << "Successfully deleted a file, " << name << endl;
	}
}

/************************************************
* Function: Make new files by adding them into
* the FAT and into the file vector. It check to
* see if the file is already in use.
*************************************************/
void New(string name, int size){
	int blockCount;
	Entry tempFile;

    cout << "Transaction: Add a new file\n";

	if (Search(name) != -1)  //Check to see if the file alreday is in use
	{
		cout << "Error! The new file name, " << name << " already exists." <<endl;
		return;
	}

	tempFile.name = name;  //Set data into temp file
	tempFile.size = size;

	if(size % BLOCKSIZE > 0 )  //calc the Blocks needed, if there is a remainder add 1
    {	
		blockCount = size / BLOCKSIZE;
		blockCount = blockCount + 1;
	}
	else
    {
		blockCount = size / BLOCKSIZE;
	}

	int count = 1;
	while(count <= blockCount)  //loop through the blocks that are needed
    {	
		for(int i=0; i < MAXSIZE; i++)
        {     
			if(FAT[i] == 0 && count == blockCount)  //set the last block to -1
            {	
				FAT[i] = -1;
				tempFile.blocks.push_back(i);
				count++;
				break;
			}
			else if(FAT[i] == 0)  //set them to in use
            {	
				FAT[i] = 1;
				tempFile.blocks.push_back(i);
				count++;
				break;
			}
		}
	}
	
	files.push_back(tempFile);  //Make new file in the vector
	cout << "Successfully added a new file, " << name << " of size " << size << endl;
}


/*********************************************
*  Function: Modify a file that is already
*  in the FAT and in the file vector. It
*  Check to see if there is one already.
**********************************************/
void Modify(string name, int size){
    cout << "Transaction: Modify a file\n";
    
	int location = Search(name);  //get the file location

	if(location == -1)  //If there is no file with the name
    {	
		cout << "Error! The file name, " << name << ", was not found." <<endl;
		return;
	}	
	else  //Else add more blocks
    {	
		for(unsigned int i = 0; i < files.at(location).blocks.size(); i++)  //set blocks to 0
			FAT[files.at(location).blocks.at(i)] = 0;
		files.erase(files.begin() + location );  //delete the file from the vector
		New(name, size);  //Make a new file 
		cout << "Successfully modified a file, " << name << endl;
	}
}

/****************************************
*  Function: Renames a file to a new 
*  name. It check both names before
*  it does anything
*****************************************/
void Rename(string name, string name2){
    cout << "Transaction: Rename a file\n";
	int findName = Search(name);  //Check the OG name

	if(findName == -1)  //If the OG file is not found
    { 
		cout << "Error! The old file name, " << name << ", was not found." <<endl; 
		return;
	}
	else if(Search(name2) >= 0)  //If the new file is already in use
    {	
		cout << "Error!  The new file name, " << name << ", already exists." <<endl;
		return;
	}
	else{
		files.at(findName).name = name2;  //Change the name in the vector
		cout << "Successfully changed the file name " << name << " to " << name2 <<endl;
	}
}

/******************************************
*  Function: To find a name in the file
*  vector.
*******************************************/
int Search(string name){
	int count = 0;

	for(vector<Entry>::iterator iter = files.begin(); iter != files.end(); ++iter)  //Loop through the vector
    {	 
		if(iter->name == name)  //If found return the location
        {	
			return count;
		}
		count++;
	}
	return -1;	//else return -1 if not found
}

/*****************************************
*  Function: Print the contents of the 
*  File allocation table and what blocks
*  each file is using.
******************************************/
void Print(){
	int total = 0;

    cout << "\nDirectory Listing\n";

	for(vector<Entry>::iterator iter = files.begin(); iter != files.end(); ++iter)  //Print the blocks each file are in
    {	
		cout << "File Name: " << iter->name << "\t File Size: " << iter->size << "\n Cluster(s) in use: ";
		if(iter->blocks.size() == 0)  //If file does not take up any space, print none
			cout << "(none)";

		total = total + iter->size;
		
		for(unsigned int i = 0; i < iter->blocks.size(); i++)
        {	
			cout << iter->blocks.at(i) << " ";
		}
		cout <<endl;
	}
	cout << "Files: " << files.size() << "\t Total Size: " << total << " bytes" << endl << endl;

	cout << endl;
	cout << "Contents of the File Allocation Table " <<endl;

    int lineNum = 0;
    int lineCount = 0;
	while(lineCount < MAXPRINT)  //Print the contents of the File Allocation Table
    {	
        //print line Numbers
		if (lineCount % 12 == 0)
		{
            if (lineCount == 0)
				cout << "\n#" << setw(3) << setfill('0') << lineNum;
			else
				cout << " \n#" << setw(3) << setfill('0') << lineNum;
			
			lineNum += 12;
			cout << "-" << setw(3) << setfill('0') << lineNum-1 << " ";
		}
        cout << setw(6) << setfill(' ') << FAT[lineCount];
		lineCount++;
	}
	cout << endl << endl;


}