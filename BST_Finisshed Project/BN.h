#ifndef BINARY_NODE_H
#define BINARY_NODE_H
template <typename T>
struct BinaryNode{
//    key members:
   T key;
   BinaryNode<T> *left;
   BinaryNode<T> *right;
//    constructors:
   BinaryNode();
   BinaryNode(const T& x);

};

template <class T>
BinaryNode<T>::BinaryNode(){
   left = NULL;
   right = NULL;
}

template <class T>
BinaryNode<T>::BinaryNode(const T& x){
   key = x;
   left = NULL;
   right = NULL;
}
#endif
