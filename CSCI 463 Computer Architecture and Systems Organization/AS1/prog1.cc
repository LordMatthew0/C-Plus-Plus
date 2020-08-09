/*
Matthew Lord
9/20/2019
CSCI 463
Prog1.cc
*/
#include<iostream>
#include<fstream>

using namespace std;

void output(string identifier, string parity, char SFlag, char UFlag, char ZFlag, char input[512]);
string getParity(char input[512]);
char sum(char a, char b, char& carry);
int getLength(char input[512]);
char getZFlag(char input[512]);

int main() {
   ifstream myReadFile;
   myReadFile.open("testdata");
   char v1Input[512];
   char v2Input[512];
   char sumChars;
   char sumCharsArr[512];
   char diffChars;
   char diffCharsArr[512];
   int length;
   char carry = '0';
   char zflag = ' ';
   char sflag = ' ';
   char uflag = ' ';
   string parity;
   char carryin = '0';
   char carryout = '0';
   
   if (myReadFile.is_open()) {
      while (myReadFile >> v1Input) {
          
         //myReadFile >> v1Input;
         parity = getParity(v1Input);
         output("v1   ",parity,' ',' ',' ',v1Input);
         
         myReadFile >> v2Input;
         parity = getParity(v2Input);
         output("v2   ",parity,' ',' ',' ',v2Input);
         
         length = getLength(v1Input);
        
         for(int i = 0; i <= length; i++)
         {
             carryin = carry;
             sumChars = sum(v1Input[length - i], v2Input[length - i], carry);
             carryout = carry;
             
            if(i == length)
             {
                 if(carryin != carryout)
                     sflag = 'S';
                 if(carryout == '1')
                     uflag = 'U';
                // cout << "Carry in:" << carryin << " Carry out: " << carryout << '\n';
             } 
             
             sumCharsArr[length - i] = sumChars;
         } 
         parity = getParity(sumCharsArr);
         zflag = getZFlag(sumCharsArr);
         output("sum  ", parity, sflag, uflag, zflag, sumCharsArr);
         
         sflag = ' ';
         uflag = ' ';
         
         for(int i = 0; i < 512; i++)
         {
            if(v2Input[i] == '0')
                v2Input[i] = '1';
            
            else if(v2Input[i] == '1')
                v2Input[i] = '0';
         }
         
         carry = '1';
         for(int i = 0; i <= length; i++)
         {
             carryin = carry;
             diffChars = sum(v1Input[length - i], v2Input[length - i], carry);
             carryout = carry;
             if(i == length)
             {
                 if(carryin != carryout)
                     sflag = 'S';
                 if(carryout == '0')
                     uflag = 'U';
             }
             diffCharsArr[length - i] = diffChars;
         }
         
         parity = getParity(diffCharsArr);
         zflag = getZFlag(diffCharsArr);
         output("diff ", parity, sflag, uflag, zflag, diffCharsArr);
         
         for(int erase = 0; erase < 512;erase++)
         {
             v1Input[erase] = '\0';
             v2Input[erase] = '\0';
             sumCharsArr[erase] = '\0';
             diffCharsArr[erase] = '\0';
         }
         cout << '\n';
         carry = '0';
         parity = " ";
         sflag = ' ';
         uflag = ' ';
       }
    }
    myReadFile.close();
    return 0;
}

void output(string identifier, string parity, char SFlag, char UFlag, char ZFlag, char input[512]){
    cout << identifier << parity << ' ' << SFlag << UFlag << ZFlag << ' ' << input << '\n';
}

string getParity(char input[512])
{
    string parity;
    for(int index = 0; index < 512; index++)
    {
        if(input[index] == '\0')
        {
            if(input[index - 1] == '0')
                parity = "even";
            if(input[index - 1] == '1')
                parity = "odd ";
        }
    }
    return parity;
}

int getLength(char input[512])
{
    int length;
    for(int index = 0; index < 512; index++)
    {
        if(input[index] == '\0')
            if(input[index - 1] == '0' || input[index - 1] == '1')
                length = index -1;
    }
    return length;
}

char sum(char a, char b, char& carry)
{
    char result = '0';
    
    if(a == '0' && b == '0' && carry == '0')
    {
        result = '0';
        carry = '0';
    }
    else if(a == '0' && b == '0' && carry == '1')
    {
        result = '1';
        carry = '0';
    }
    else if(a == '0' && b == '1' && carry == '0')
    {
        result = '1';
        carry = '0';
    }
    else if(a == '0' && b == '1' && carry == '1')
    {
        result = '0';
        carry = '1';
    }
    else if(a == '1' && b == '0' && carry == '0')
    {
        result = '1';
        carry = '0';
    }
    else if(a == '1' && b == '0' && carry == '1')
    {
        result = '0';
        carry = '1';
    }
    else if(a == '1' && b == '1' && carry == '0')
    {
        result = '0';
        carry = '1';
    }
    else if(a == '1' && b == '1' && carry == '1')
    {
        result = '1';
        carry = '1';
    }
    return result;
}

char getZFlag(char input[512])
{
    bool flag = false;
    for(int i = 0; i < 512; i++)
    {
        if(input[i] == '1')
           flag = true;
    }

    if(flag == true)
        return ' ';
    else
        return 'Z';
}
