#ifndef PAIR_HPP
#define PAIR_HPP

/**
 * @brief Struct que representa um par ordenado
 * 
 * @tparam T Tipo do primeiro elemento do par
 * @tparam U Tipo do segundo elemento do par
 */
template <typename T, typename U>
struct Pair {
    T first;
    U second;
};

/**
 * @brief Funcao que cria um par ordenado
 * 
 * @tparam T Tipo do primeiro elemento do par
 * @tparam U Tipo do segundo elemento do par
 * @param first Primeiro elemento do par
 * @param second Segundo elemento do par
 * @return Pair<T, U> Par ordenado
 */
template <typename T, typename U>
Pair<T, U> makePair(T first, U second){
    Pair<T, U> p;
    p.first = first;
    p.second = second;
    return p;
}

// Funções específicas para a solução deste problema
bool operator<(const Pair<int, int> &a, const Pair<int, int> &b){
    // Color, Index
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
};

bool operator>(const Pair<int, int> &a, const Pair<int, int> &b){
    // Color, Index
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
};

bool operator<=(const Pair<int, int> &a, const Pair<int, int> &b){
    // Color, Index
    if(a.first == b.first) return a.second <= b.second;
    return a.first < b.first;
};

#endif