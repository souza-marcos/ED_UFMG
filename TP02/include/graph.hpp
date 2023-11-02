#include "vector.hpp"

class Vertex{
public:
    int index;
    Vector<int> adjacent;

    // Pode ocasionar um erro aqui
    Vertex()
    {
        index = 0;
        adjacent = Vector<int>(1);
    }

    Vertex(int index, int size){
        this->index = index;
        adjacent = Vector<int>(size);
    }
    
};

class Graph{

public:
    Vector<Vertex> vertices;

    Graph(int size){
        vertices = Vector<Vertex>(size);
    }

};