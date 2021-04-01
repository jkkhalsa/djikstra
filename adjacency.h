

//An adjacency node is a single vertex showing an edge between the index and the vertex it represents
//Each node has a weight, a vertex, and a pointer to the next node in the list
class AdjacencyNode
{
    private:
    int vertex;
    float weight;
    AdjacencyNode* next;


    public:
    AdjacencyNode();

    AdjacencyNode(int v);

    AdjacencyNode(int v, float w);

    void setNext(AdjacencyNode* n);
    AdjacencyNode* returnNext();

    void setVertex(int v);
    int getVertex();

    void setWeight(float w);
    float getWeight();
};


//An adjacency list is a linked list made up of adjacency nodes
//The adjacency lists in the graph list show what vertices their node is linked to - determined by their index +1 in the overall graph list
class AdjacencyList
{
    private:

    AdjacencyNode* head;

    public:
    AdjacencyList();

    void insertEdge(AdjacencyNode* h);

};


//Array object to hold the adjacency lists (and honestly mostly to keep all the file i/o methods in ONE PLACE)
class AdjacencyGraph
{
    private:
    AdjacencyList* graph[];
};