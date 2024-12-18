#include <iostream>

enum status
{
    ERROR,
    OK
};
const int MAXSIZE = 20;

template <typename T, int MAXSIZE>
struct Sqlist
{
    T data[MAXSIZE];
    int length = 0;
    Sqlist &addelem(const T &singledata);
};

template <typename T, int MAXSIZE>
status GetElem(Sqlist<T, MAXSIZE> &L, int i, T *e) // 传递引用，不用复制Sqlist
{
    if (L.length == 0 || i < 0 || i > L.length - 1)
        return ERROR;
    *e = L.data[i];
    return OK;
}

template <typename T, int MAXSIZE>
status InsertElem(Sqlist<T, MAXSIZE> &L, int i, T *e)
{
    if (L.length == MAXSIZE || i > MAXSIZE - 1 || i < 0) //
        return ERROR;
    if (i < L.length)
    {
        for (int k = L.length - 1; k > i - 1; k--)
            L.data[k + 1] = L.data[k];
    }
    L.data[i] = *e;
    L.length++;
    return OK;
}
template <typename T, int MAXSIZE>
status DeleteElem(Sqlist<T, MAXSIZE> &L, int i)
{
    if (i > L.length - 1 || i < 0 || L.length == 0) 
        return ERROR;
    if (i < L.length)
    {
        for (int k = i; k < L.length - 1; k++) // 最后一位元素不动, 防止动用其他内存
            L.data[k] = L.data[k+1];
    }
    L.length--;
    return OK;
}

// int main()
// {
//     Sqlist<int, 20> example;
//     for (int i = 0; i < 20; i++)
//         example.addelem(i);
//     int *e = new int;
//     *e = 10;
//     status a = InsertElem(example, 1, e);
//     status b = DeleteElem(example, 5);
//     std::cout << (status)a << std::endl;
// }

template <typename T, int MAXSIZE>
Sqlist<T, MAXSIZE> &Sqlist<T, MAXSIZE>::addelem(const T &singledata)
{
    {
        if (length < MAXSIZE)
        {
            data[length] = singledata;
            length++;
            return *this;
        }
        std::cout << "out of MAXSIZE And " << "current length is : " << length << std::endl;
        return *this;
    }
}
