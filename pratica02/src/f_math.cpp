#include <cmath>

#include "f_math.hpp"

// NOTE: This Fibonacci function start with 1, i.e. 1 1 2 3 5 ...
long long fibonacci_recursivo(int n){
    if(n <= 2) return 1;
    
    // double x;
    // for(int i=0; i<100; i++) x += std::sin(i); // Funcao de consumo de recursos computacionais
    
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2); 
}


// NOTE: This Fibonacci function start with 1, i.e. 1 1 2 3 5 ...
long long fibonacci_iterativo(int n){
    if(n <= 2) return 1;
    int a = 1, b = 1, aux;
    for(int i = 0; i < n - 2; i++){
        aux = a + b;
        a = b;
        b = aux;
    }
    return b;
}

long long fatorial_recursivo(int n){ // Talvez uma otimizacao do compilador trate essa recursao sem calda
    if(n <= 0) return 1;
    // double x;
    // for(int i=0; i<100; i++) x += std::sin(i); // Funcao de consumo de recursos computacionais
    
    return n * fatorial_recursivo(n - 1);
}

long long fatorial_iterativo(int n){
    long long res = 1;
    for(int i = 2; i <= n; i++) {
        res *= i;
    } 
    return res;
}