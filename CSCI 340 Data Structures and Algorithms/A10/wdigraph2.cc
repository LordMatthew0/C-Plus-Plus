/*
Matthew Lord
Assignment 10
12/6/2018
CSCI 340 Section 1
*/
#include "/home/cs340/progs/18f/p10/wdigraph.h"

void wdigraph :: depth_first ( int u ) const{
    static int firstVertex = -1;
      static bool* visited = NULL;
   
      if (firstVertex == -1)
      {
         firstVertex = u;
         //allocate visited array of size elements
		 visited =  new bool(size);
         //set all elements of visited to false
		 for(int i = 0; i < size; i++)
		 {
            visited[i] = false;
		 }
      }

      cout << label[u];
      visited[u] = true;

      for(int w = 0; w != size; w++)
      {
         if (adj_matrix[u][w] != 0 && visited[w] != true)
         {
            //print an arrow
			cout << "->";

            //call depth_first() with w as the argument
            depth_first(w);
         }
      }
	  
      if (u == firstVertex)
      {
	     cout << endl << endl;
         firstVertex = -1;
         delete[] visited;
         visited = NULL;
      }
}

void wdigraph :: print_graph ( ) const{
    //Prints out the number of nodes
   cout << "No of Nodes = " << size << endl << endl;
   
   cout << "Adjacency Matrix:" << endl << endl;
   
   cout << "  |";
   for(int i = 0; i < (int) label.size(); i++)
      cout << "  " << label[i];   
   
   cout << endl <<"--|";
   for(int i = 0; i < (int) label.size(); i++)
      cout << "---";
   cout << endl;
   
   for(int i = 0; i < (int) label.size(); i++)
   {
      cout << label[i] << " |";
	  
	  for(int j = 0; j < (int) label.size(); j++)
	  {
	     if(adj_matrix[i][j] != 0)
		    cout << setw(3) << adj_matrix[i][j];
		 else
		    cout << setw(3) << "-";
	  }
	  if(i < (int) label.size() -1)
	     cout << endl << "  |" << endl; 
   }
}