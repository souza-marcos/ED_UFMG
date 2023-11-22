#ifndef UTILS_HPP
#define UTILS_HPP

const int MOD = 1e8;

#define ll long long
ll sum(ll a, ll b){
    return (a % MOD + b % MOD) % MOD;
}

ll mult(ll a, ll b){
    return (a % MOD * b % MOD) % MOD;
}

#endif