#include "vector.hpp"

#ifndef ID_GRAPH
#define ID_GRAPH 0
#endif

/**
 * @brief Classe que representa um vertice do grafo (lista de adjacencia)
 * 
 */
class Vertex{
public:
    Vector<int> adjacent;

    /**
     * @brief Construtor padrao
     * 
     */
    Vertex() : adjacent(1, ID_GRAPH) {}

    /**
     * @brief Construtor que recebe o tamanho do vetor de adjacencia
     * 
     * @param size Tamanho do vetor de adjacencia - Quantidade de vertices adjacentes
     */
    Vertex(int size) : adjacent(size, ID_GRAPH) {}
    
};

using Graph = Vector<Vertex>;