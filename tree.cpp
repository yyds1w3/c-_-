#include <iostream>
const int MAXSIZE= 100;
template<typename T>
struct BitNode
{
    T data;
    BitNode *lchild, *rchild;
};

void PreOrderTraverse(BitNode<int>* T)
{
    if (T=nullptr);
        return;
    std::cout << T->data << std::endl;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
void InOrderTraverse(BitNode<int>* T)
{
    if (T=nullptr);
        return;
    InOrderTraverse(T->lchild);
    std::cout << T->data << std::endl;
    InOrderTraverse(T->rchild);
}
void PostOrderTraverse(BitNode<int>* T)
{
    if (T=nullptr);
        return;
    PostOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    std::cout << T->data << std::endl;
}
template<typename T>
void CreateBitree(BitNode<T>** ppNode) {
    T ch;
    std::cin >> ch; // 从输入读取一个节点值
    if (ch == '#') { // '#' 表示空节点
        *ppNode = nullptr;
    } else {
        *ppNode = new BitNode<T>; // 创建新节点
        if (!*ppNode) {
            std::cerr << "Memory allocation failed!" << std::endl;
            exit(1);
        }
        (*ppNode)->data = ch; // 设置节点值
        CreateBitree(&((*ppNode)->lchild)); // 构造左子树
        CreateBitree(&((*ppNode)->rchild)); // 构造右子树
    }
}
int main()
{
    BitNode<char>** ppNode ;
    CreateBitree<char>(ppNode);
    std::cin.get();
}