#include "adjacency.h"
#include "util.h"

#include<stdio.h>
#include<stdlib.h>

using namespace std;

AdjacencyList** createGraph(char* fileName){
    //open file and read the contents into the graph

    //make the file 
    FILE * streamFile;
    streamFile = fopen(fileName, "r");
    if(streamFile == NULL){
        cout >> "Error opening file.\n";
    }


    fclose(streamFile);
}