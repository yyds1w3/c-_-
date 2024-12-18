#include <iostream>

enum status
{
    ERROR,
    OK
};
const int MAXSIZE = 100;
template<typename T>
struct Sqdolstack
{
    T data[MAXSIZE];
    int top1;
    int top2;
};
template<typename T>
status push(Sqdolstack<T>& S, T& e, int stacknum)
{
    if (S.top1 + 1 == S.top2)  return ERROR;
    switch (stacknum)
    {
        case 1:
            S.data[++S.top1] = e;
            return OK;
        case 2:
            S.data[--S.top2] = e;
            return OK;
        default:
            return ERROR;
        
    }
}
template<typename T>
status pop(Sqdolstack<T>& S, T& e, int stacknum)
{
    switch (stacknum)
    {
        case 1:
            if (S.top1 == -1) return ERROR;
            e = S.data[S.top1--];
            return OK;
        case 2:
            if (S.top2 == MAXSIZE) return ERROR;
            e = S.data[S.top2++];
            return OK;

    }
}