#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef int Telement;

typedef struct Node
{
    Telement info;
    Node *left;
    Node *right;
};

typedef Node *PNode;

class BinaryTree
{
protected:
    PNode T;

public:
    BinaryTree();
    ~BinaryTree();
    PNode PARENT(PNode n, PNode T);
    PNode PARENT1(PNode n, PNode T);
    PNode LEFT_CHILD(PNode n);
    PNode RIGHT_CHILD(PNode n);
    Telement GetLabel(PNode n);
    PNode BuildTree1(int m);
    void BuildTree(int m);
    PNode ROOT();
    void MAKENULL(PNode p);
    void PreOrder(PNode t);
    void InOrder(PNode t);
    void PostOrder(PNode t);
};

BinaryTree::BinaryTree()
{
    T = NULL;
}

void BinaryTree::MAKENULL(PNode p)
{
    if (p != NULL)
    {
        if (p->left != NULL)
            MAKENULL(p->left);

        if (p->right != NULL)
            MAKENULL(p->right);

        delete p;
        p = NULL;
    }
}

PNode BinaryTree::ROOT()
{
    return T;
}

PNode BinaryTree::PARENT(PNode n, PNode T)
{
    if (T == n)
        return NULL;

    return  PARENT1(n, T);
}

PNode BinaryTree::PARENT1(PNode n, PNode T)
{
    if ((T->left==n) || (T->right==n))
        return T;

    PNode tmp1=NULL;
    PNode tmp2=NULL;

    if (T->left!=NULL)
        tmp1=PARENT1(n,T->left);

    if (T->right!=NULL)
        tmp2=PARENT1(n,T->right);

    return (tmp1!=NULL)?tmp1 :tmp2;
}

PNode BinaryTree::LEFT_CHILD(PNode n)
{
    return n->left;
}

PNode BinaryTree::RIGHT_CHILD(PNode n)
{
    // PNode tmp = PARENT(n, T);

    // if ((tmp->left) == n)
    //     return tmp->right;

    // else
    //     return NULL;
    return n->right;
}

Telement BinaryTree::GetLabel(PNode n)
{
    if (n != NULL)
        return n->info;
}

PNode BinaryTree::BuildTree1(int n)
{
    if (n == 0)
        return NULL;

    int nl, np;
    Telement x;
    PNode tmp;

    nl = n / 2;
    np = n - nl - 1;

    cout << "Podaj wartość do wstawienia: ";
    cin >> x;

    tmp = new Node;
    tmp->info = x;
    tmp->left = BuildTree1(nl);
    tmp->right = BuildTree1(np);

    return tmp;
}

void BinaryTree::BuildTree(int n)
{
    T = BuildTree1(n);
}

void BinaryTree::PreOrder(PNode t)
{
    if (t != NULL)
    {
        cout << t->info;
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

void BinaryTree::InOrder(PNode t)
{
    if (t != NULL)
    {
        InOrder(t->left);
        cout << t->info;
        InOrder(t->right);
    }
}

void BinaryTree::PostOrder(PNode t)
{
    if (t != NULL)
    {
        PostOrder(t->left);
        PostOrder(t->right);
        cout << t->info;
    }
}

int main()
{
    BinaryTree *Tree = new BinaryTree;

    Tree->BuildTree(9);

    cout << endl;
    cout << "Korzeń: " << Tree->GetLabel(Tree->ROOT()) << endl;
    cout << "Lewe dziecko korzenia: " << Tree->GetLabel(Tree->LEFT_CHILD(Tree->ROOT())) << endl;
    cout << "Prawe dziecko korzenia: " << Tree->GetLabel(Tree->RIGHT_CHILD(Tree->ROOT())) << endl;
    cout << endl;

    cout << "Rodzic prawego dziecka korzenia: " << Tree->GetLabel(Tree->PARENT(Tree->RIGHT_CHILD(Tree->ROOT()), Tree->ROOT())) << endl;
    cout << endl;

    cout << "Rodzic prawego dziecka lewego dziecka korzenia: " << Tree->GetLabel(Tree->PARENT(Tree->RIGHT_CHILD(Tree->LEFT_CHILD(Tree->ROOT())), Tree->ROOT())) << endl;
    cout << endl;

    cout << "PreOrder: ";
    Tree->PreOrder(Tree->ROOT());
    cout << endl;

    cout << "InOrder: ";
    Tree->InOrder(Tree->ROOT());
    cout << endl;

    cout << "PostOrder: ";
    Tree->PostOrder(Tree->ROOT());
    cout << endl;

    return 0;
}