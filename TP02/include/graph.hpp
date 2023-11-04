#include "vector.hpp"

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
    Vertex()
    {
        adjacent = Vector<int>(1);
    }

    /**
     * @brief Construtor que recebe o tamanho do vetor de adjacencia
     * 
     * @param size Tamanho do vetor de adjacencia - Quantidade de vertices adjacentes
     */
    Vertex(int size){
        adjacent = Vector<int>(size);
    }
    
};

using Graph = Vector<Vertex>;