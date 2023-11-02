#include <vector.hpp>

class Vertex{
public:
    int index, color;
    Vector<int> adjacent;
    int size; 

    Vertex(int index, int size, int color){
        this->index = index;
        this->size = size;
        adjacent = Vector<int>(size);
        this->color = -1;
    }
    
};

class Graph{

public:
    Vector<Vertex> vertices;
};