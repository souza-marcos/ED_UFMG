#ifndef MATRIX2_HPP
#define MATRIX2_HPP

#define ll long long
#include "utils.hpp"
class Matrix2 {
    public:
        ll a11, a12, a21, a22;
        
        // Uma matriz identidade por padrão
        Matrix2() : a11(1), a12(0), a21(0), a22(1) {};  

        Matrix2(ll a, ll b, ll c, ll d) : a11(a), a12(b), a21(c), a22(d) {};

        Matrix2 operator*(const Matrix2& other){
            Matrix2 res;

            res.a11 = sum(mult(a11, other.a11), mult(a12, other.a21));
            res.a12 = sum(mult(a11, other.a12), mult(a12, other.a22));
            res.a21 = sum(mult(a21, other.a11), mult(a22, other.a21));
            res.a22 = sum(mult(a21, other.a12), mult(a22, other.a22));

            return res;
        }
};

#endif