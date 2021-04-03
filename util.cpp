#include "adjacency.h"
#include "util.h"

#include<iostream>
#include<fstream>

using std::cout;

AdjacencyGraph* createGraph(string fileName, bool d){
    string processing;
    bool isDirected = d;


    //open file
    ifstream infile;
    infile.open(fileName);
    if(infile.is_open()){

        //create the graph
        getline(infile, processing);
        AdjacencyGraph* graph = new AdjacencyGraph(processing[0] - '0');
        //TODO: DEBUG: make sure that actually worked lmao
        



        //read the contents into the graph 


        infile.close();
        //create the graph

    }
    else{
        //error: file can't be opened
    }

    
    
}