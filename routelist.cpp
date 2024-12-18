#include <iostream> 
#include <random>
enum status
{
    ERROR,
    OK
};
template<typename T>
struct Node
{
    T data; // (数据域)
    Node* next; // 指向下一个Node的指针(指针域)
};
template<typename T>
status GetElem(Node<T>& L, int i, T* e) // i=1时， 取下一个Node的数据域
{
    Node<T>* p = L.next;
    int j = 0;
    while( p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p)
        return ERROR;
    *e = p->data;
    return OK;
}

template<typename T>
status InsertElem(Node<T>& L, int i, const T& e) // 左右值均可以传
{
    Node<T>* p;
    p = &L;
    int j = 0;
    while (p && j < i - 1) // 寻找对应位置, i=1时， 将元素插入到1
    {
        p = p->next;
        ++j;
    }           // 0 1 2 3 4 5 6 
    if (!p)
        return ERROR;
    Node<T>* temp = new Node<T>;
    temp->data = e;
    temp->next = p->next;
    p->next = temp;
    return OK; 
}

template<typename T>
status DeleteElem(Node<T>& L, int i) // 左右值均可以传
{
    Node<T>* p;
    p = &L;
    int j = 0;
    while (p && j < i - 1) // 寻找对应位置, i=1时， p为本指针node
    {
        p = p->next;
        ++j;
    }           // 0 1 2 3 4 5 6 
    if (!p)
        return ERROR;
    p->next = p->next->next; // p会自动释放(在函数执行完后)
    return OK; 
}
// 堆分配的内存要记得释放, 指针悬空
template<typename T>
void CreateListHead(Node<T>& L, int n) // 头插法,先进入的反而在后面
{
    Node<T>* p;

    L.next = nullptr;
    for (int i = 0; i < n; i++)
    {
        p = new Node<T>; // 每次循环指向不同的内存块, 地址在改变
        p->data = i;
        p->next = L.next; // 0(L) // 1(L)->0 // 2(L)->1->0 // n(L)->n-1->n-2....->0
        L.next = p;
    }

}
template<typename T>
void CreateListTail(Node<T>* L, int n) // 尾插法，新元素在后
{
    Node<T>* p;
    Node<T>* r;
    r = L;
    for (int i = 0; i < n; i++)
    {
        p = new Node<T>;
        p->data = i;
        L->next = p;
        L = p;
    }
        p->next = r;
}
template<typename T>
void DeleteList(Node<T>* L) 
{
    if (L == nullptr) return;
    Node<T>* head = L;
    Node<T>* temp;
    while ( L->next != head )
    {
    temp = L->next;
    delete L;
    L = temp; // 是删除了内存块(*L)，而非我的地址(L)
    }
    delete L;
}
// int main()
// {
//     Node<int>* L = new Node<int>;
//     CreateListTail(L, 5);
//     DeleteList(L);
//     std::cin.get();
// }