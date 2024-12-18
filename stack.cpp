#include <iostream>

enum status
{
    ERROR,
    OK
};
const int MAXSIZE = 100;
template <typename T>
struct Sqstack
{
    T data[MAXSIZE];
    int top; // 指示栈顶在哪里
};
template <typename T>
status push(Sqstack<T> &S, T &e)
{
    if (S.top == MAXSIZE - 1)
        return ERROR;
    S.data[++S.top] = e;
    return OK;
}
template <typename T>
status pop(Sqstack<T> &S, T &e)
{
    if (S.top == -1)
        return ERROR;
    e = S.data[--S.top];
    return OK;
}
