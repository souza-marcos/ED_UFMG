// Vector class
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef> // size_t

/**
 * @brief Classe que representa um vetor dinâmico
 * 
 * @tparam T tipo do dado a ser armazenado no vetor
 */
template <typename T>
class Vector
{
private:
    T *arr;
    size_t size;
    size_t capacity;
    void resize(int capacity)
    {
        T *temp = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        this->capacity = capacity;
    }

public:
    /**
     * @brief Constrói um novo objeto Vector
     * 
     */
    Vector()
    {
        arr = new T[1];
        size = 0;
        capacity = 1;
    }

    /**
     * @brief Constrói um novo objeto Vector
     * 
     * @param size Tamanho inicial do vetor
     */
    Vector(int size)
    {
        arr = new T[2 * size];
        this->size = size;
        this->capacity = 2 * size;
    }

    /**
     * @brief Constrói um novo objeto Vector a partir de um Vector
     * 
     * @param v outro vetor
     */
    Vector(const Vector<T> &v)
    {
        arr = new T[v.capacity];
        size = v.size;
        capacity = v.capacity;
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = v.arr[i];
        }
    }

    /**
     * @brief Destrói o objeto Vector
     * 
     */
    ~Vector()
    {
        delete[] arr;
    }

    /**
     * @brief Empurra um elemento para o final do vetor
     * 
     * @param elem elemento a ser empurrado
     */
    void push_back(T elem)
    {
        if (size == capacity)
        {
            this->resize(2 * capacity);
        }
        arr[size] = elem;
        size++;
    }

    /**
     * @brief Remove o último elemento do vetor
     * 
     */
    void pop_back()
    {
        if (size > 0)
        {
            size--;
        }
    }

    /**
     * @brief Limpa o vetor
     * 
     */
    void clear()
    {
        size = 0;
    }

    /**
     * @brief Pega o tamanho do vetor
     * 
     * @return size_t Tamanho
     */
    size_t getSize(){
        return size;
    }

    /**
     * @brief Pega a capacidade atual do vetor
     * 
     * @return int capacidade
     */
    int getCapacity(){
        return capacity;
    }

    /**
     * @brief Acessa uma posição do vetor
     * 
     * @param index Índice do vetor a ser acessado
     * @return T& O elemento da posição index
     */
    T &operator[](int index){
        return arr[index];
    }

    /**
     * @brief Copia um vetor para outro
     * 
     * @param v Vetor a ser copiado
     * @return Vector<T>& 
     */
    Vector<T> &operator=(const Vector<T> &v){
        if (this != &v)
        {
            delete[] arr;
            arr = new T[v.capacity];
            size = v.size;
            capacity = v.capacity;
            for (size_t i = 0; i < size; i++)
            {
                arr[i] = v.arr[i];
            }
        }
        return *this;
    }
};

#endif