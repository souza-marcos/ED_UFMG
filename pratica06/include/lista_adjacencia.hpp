#ifndef LIST_ADJ_HPP
#define LIST_ADJ_HPP

#include "linkedlist.hpp"
#include <iostream>

class ListaAdjacencia{
    public:
        ListaAdjacencia(){}

        ListaAdjacencia(int n){
            vertices = new LinkedList<LinkedList<int>>();
        }
        ~ListaAdjacencia(){ 
            // Node <LinkedList<int>> *linha = vertices->head;
            // while (linha != nullptr)
            // {
            //     Node<int> *aux = linha->data.head;
            //     while(aux != nullptr){
            //         Node<int> *next = aux->next;
            //         delete aux;
            //         aux = next;
            //     }
            //     Node<LinkedList<int>> *next = linha->next;
            //     linha = next;
            // }
            // delete vertices;
        }

        void InsereVertice(){
            vertices->Insert(LinkedList<int>());
        }

        int Size(){
            return vertices->size;
        }

        void InsereAresta(int v, int w){
            Node<LinkedList<int>> *linha = vertices->head;

            int i = 0;
            while(linha != nullptr){
                if(i == v){
                    linha->data.Insert(w);
                    break;
                }
                i++;
                linha = linha->next;
            }
        }

        int QuantidadeVertices(){
            return vertices->size;
        }
        int QuantidadeArestas(){
            int count = 0;
            Node<LinkedList<int>> *aux = vertices->head;
            while(aux != nullptr){
                count += aux->data.size;
                aux = aux->next;
            }
            return count/2;
        }

        int GrauMinimo(){
            Node<LinkedList<int>> *linha = vertices->head;
            int min = linha->data.size;
            linha = linha->next;
            while(linha != nullptr){
                if(linha->data.size < min){
                    min = linha->data.size;
                }
                linha = linha->next;
            }
            return min;
        }

        int GrauMaximo(){
            Node<LinkedList<int>> *linha = vertices->head;
            int max = linha->data.size;
            linha = linha->next;
            while(linha != nullptr){
                if(linha->data.size > max){
                    max = linha->data.size;
                }
                linha = linha->next;
            }
            return max;
        }

        void ImprimeVizinhos(int v){
            Node<LinkedList<int>> *linha = vertices[v].head;
            while(linha != nullptr){
                Node<int> *aux = linha->data.head;
                while(aux != nullptr){
                    std::cout << aux->data << " ";
                    aux = aux->next;
                }
                std::cout << std::endl;

                linha = linha->next;
            }
        }
        
    private:
        LinkedList<LinkedList<int>> *vertices;
};

#endif