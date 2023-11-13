#ifndef MATRIX2_HPP
#define MATRIX2_HPP

#define ll long long
const int MOD = 1e8;

class Matrix2 {
    public:
        ll a11, a12, a21, a22;
        
        // Uma matriz identidade por padrão
        Matrix2() : a11(1), a12(0), a21(0), a22(1) {};  

        Matrix2(ll a, ll b, ll c, ll d) : a11(a), a12(b), a21(c), a22(d) {};

        Matrix2 operator*(const Matrix2& other){
            Matrix2 res;
            res.a11 = ((a11 % MOD) * (other.a11 % MOD)) + ((a12 % MOD) * (other.a21 % MOD)) % MOD;
            res.a12 = ((a11 % MOD) * (other.a12 % MOD)) + ((a12 % MOD) * (other.a22 % MOD)) % MOD;
            res.a21 = ((a21 % MOD) * (other.a11 % MOD)) + ((a22 % MOD) * (other.a21 % MOD)) % MOD;
            res.a22 = ((a21 % MOD) * (other.a12 % MOD)) + ((a22 % MOD) * (other.a22 % MOD)) % MOD;

            return res;
        }
      
        Matrix2 operator+(const Matrix2& other){
            Matrix2 res;
            res.a11 = a11 + other.a11;
            res.a12 = a12 + other.a12;
            res.a21 = a21 + other.a21;
            res.a22 = a22 + other.a22;

            return res;
        }

        bool operator==(const Matrix2& other){
            return (a11 == other.a11 && a12 == other.a12 && a21 == other.a21 && a22 == other.a22);
        }
        bool operator!=(const Matrix2& other){
            return !(*this == other);
        }
};

#endif