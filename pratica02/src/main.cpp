#include <iostream>
#include <sys/resource.h>

#include "f_math.hpp"

using namespace std;

void timeval_subtract (timeval &result, timeval &start, timeval &end)
{
    result.tv_sec = end.tv_sec - start.tv_sec;
    result.tv_usec = end.tv_usec - start.tv_usec;
    
    // Adjust
    if(end.tv_usec < start.tv_usec) result.tv_usec += 1e6;
}

int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "Numero de argumentos invalido!!\n";
        return -1;
    } 

    int forma = std::atoi(argv[1]), n = std::atoi(argv[2]);
    
    if(forma < 1 or forma > 4){
        cout << "Numero de funcao invalida!\n";
        return -1;
    }

    if(n < 0){
        cout << "Argumento 'n' fora do intervalo permitido!\n";
        return -1;
    }

    long long (* functions[4])(int n) = {
        fibonacci_recursivo,
        fibonacci_iterativo,
        fatorial_recursivo,
        fatorial_iterativo
    };

    timespec t1, t2, res;
    rusage usage_start, usage_end;

    getrusage(RUSAGE_SELF, &usage_start);
    
    clock_gettime(CLOCK_MONOTONIC, &t1);
    // Function call
    long long f_res = functions[forma - 1](n);
    clock_gettime(CLOCK_MONOTONIC, &t2);

    getrusage(RUSAGE_SELF, &usage_end);


    res.tv_sec = t2.tv_sec - t1.tv_sec;
    res.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    
    // Adjust
    if(t2.tv_nsec < t1.tv_nsec) res.tv_nsec += 1e9;
    cout << "-----------" << endl;
    cout << f_res << endl;
    cout << "Clock Time: " << res.tv_sec << " sec, " << res.tv_nsec << " nsec" << endl;

    timeval res_usage;
    timeval_subtract(res_usage, usage_start.ru_utime, usage_end.ru_utime);
    cout << "CPU time User: " << res_usage.tv_sec << " sec, " << res_usage.tv_usec  * 100 << " nsec.\n";

    timeval_subtract(res_usage, usage_start.ru_stime, usage_end.ru_stime);
    cout << "CPU time System: " << res_usage.tv_sec << " sec, " << res_usage.tv_usec * 100 << " nsec.\n";
    cout << "-----------";
    return 0;
       
}

// NOTE: FOR THE FIRST FUNCTION(recursive fibonacci) looks good choose values near 40.