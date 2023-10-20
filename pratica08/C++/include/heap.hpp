#ifndef HEAP_HPP
#define HEAP_HPP

typedef struct s_edge{
    int u;
    int v;
    int custo;
} Aresta;


class Heap{

    public:
        Heap(int maxsize);
        ~Heap();

        void Inserir(Aresta x);
        Aresta Remover();

        //Retorna true caso o heap esteja vazio, false caso contrário.
        bool Vazio();

    private:
        int GetAncestral(int posicao);
        int GetSucessorEsq(int posicao);
        int GetSucessorDir(int posicao);

        int tamanho;
        Aresta* data;

        /* Funções necessárias para implementar o Heapify recursivo
         * Você pode apagar elas caso decida implementar o Heapify iterativo
         */
        // void HeapifyPorBaixo(int posicao);
        // void HeapifyPorCima(int posicao);
};


#endif