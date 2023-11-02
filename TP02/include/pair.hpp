#ifndef PAIR_HPP
#define PAIR_HPP

template <typename T, typename U>
struct Pair {
    T first;
    U second;
};

template <typename T, typename U>
Pair<T, U> makePair(T first, U second){
    Pair<T, U> p;
    p.first = first;
    p.second = second;
    return p;
}

// Specifics for Pair<int, int> -> Greedy graphs
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


// Look here - I'm not sure if this is correct
bool operator<=(const Pair<int, int> &a, const Pair<int, int> &b){
    // Color, Index
    if(a.first == b.first) return a.second <= b.second;
    return a.first < b.first;
};

#endif