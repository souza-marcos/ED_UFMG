#ifndef UTILS_HPP
#define UTILS_HPP

const int MOD = 1e8;

#define ll long long

/**
 * @brief Soma de dois numeros considerando apenas os 8 ultimos digitos
 * 
 * @param a Primeiro numero
 * @param b Segundo numero
 * @return ll Soma
 */
ll sum(ll a, ll b){
    return (a % MOD + b % MOD) % MOD;
}

/**
 * @brief Multiplicacao de dois numeros considerando apenas os 8 ultimos digitos
 * 
 * @param a Primeiro numero
 * @param b Segundo numero
 * @return ll Produto
 */
ll mult(ll a, ll b){
    return (a % MOD * b % MOD) % MOD;
}

#endif