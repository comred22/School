#ifndef BT_H
#define BT_H

template <class T>
class BinaryTree {
public:

   BinaryTree();
   BinaryTree(const BinaryTree<T>&);
   BinaryTree<T>& operator=(const BinaryTree<T>&);
   ~BinaryTree();

   void preorder(void (*visit)(T& ));
   void inorder(void (*visit)(T& ));
   void postorder(void (*visit)(T& ));
   void print()  const; // A method to print out the tree using preorder
   void clear();

   int  size()   const;
   int  height() const;
   bool empty()  const;
   int  getLeafCount() const;


protected:
   // Auxiliary functions
   void recursive_preorder(BinaryNode<T>*, void (*visit)(T&));
   void recursive_inorder(BinaryNode<T>*, void (*visit)(T&));
   void recursive_postorder(BinaryNode<T>*, void (*visit)(T&));
   void recursive_clear(BinaryNode<T>*);
   void recursive_preorder_print_node(BinaryNode<T>*) const;

   int recursive_size(BinaryNode<T>*) const;
   int recursive_height(BinaryNode<T>*) const;

   BinaryNode<T>* recursive_copy(BinaryNode<T>*);


   // Data member
   BinaryNode<T>* root;
};

template <class T>
BinaryTree<T>::BinaryTree()
/*
Post: An empty binary tree has been created.
*/
{
   root = NULL;
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &original) 
/*
Post: A new binary tree has been created with the same structure and content as those of original. 
Uses: The function recursive_copy 
*/
{
  root = recursive_copy(original.root);
}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& original) 
/*  
Post: The binary tree is assigned to copy a parameter 
*/
{
    //use the pointer swapping technique
}

template <class T>
BinaryTree<T>::~BinaryTree() 
{
   
}

template <class T>
bool BinaryTree<T>::empty() const
/*
Post: A result of true is returned if the binary tree is empty.
      Otherwise, false is returned.
*/
{
   return root == NULL;
}

template <class T>
void BinaryTree<T>::preorder(void (*visit)(T&))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_preorder(root, visit);
}

template <class T>
void BinaryTree<T>::inorder(void (*visit)(T&))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_inorder(root, visit);
}

template <class T>
void BinaryTree<T>::postorder(void (*visit)(T&))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_postorder(root, visit);
}

template <class T>
int BinaryTree<T>::size() const
/* 
Post: The number of entries in the binary tree is returned.
Uses: The function recursive_size
*/
{
   return recursive_size(root);
}


template <class T>
void BinaryTree<T>::clear()
/* 
Post: Dispose of all the nodes of the binary tree.
Uses: The function recursive_clear.
*/
{
   recursive_clear(root);
   root = NULL;
}

template <class T>
int BinaryTree<T>::height() const
/* 
Post: The height of the binary tree is returned.
Uses: The function recursive_height
*/
{
   return recursive_height(root);
}


template <class T>
void BinaryTree<T>::print() const{
/* 
Post: The tree has been traversed in preorder.  Each node and its two children is printed 
Uses: The function recursive_preorder_print_node
*/
   cout << endl;
   cout << "++++++++++++++++++++++" << endl;
   if(root == NULL)
      cout << "EMPTY TREE" << endl;
   else{
      if(root->left == NULL && root->right == NULL)
         cout << root->key << ":  -  -" << endl;

      recursive_preorder_print_node(root);
   }
   cout << "++++++++++++++++++++++" << endl;
   cout << endl;
}

// Functions

template <class T>
void BinaryTree<T>::recursive_preorder(BinaryNode<T> *sub_root,
                                            void (*visit)(T &))
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder recursively
*/
{
}

template <class T>
void BinaryTree<T>::recursive_inorder(BinaryNode<T> *sub_root,
                                           void (*visit)(T &))
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in inorder sequence.
Uses: The function recursive_inorder recursively
*/
{
}

template <class T>
void BinaryTree<T>::recursive_postorder(BinaryNode<T> *sub_root,
                                             void (*visit)(T &))
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in postorder sequence.
Uses: The function recursive_postorder recursively
*/
{
}

template <class T>
int BinaryTree<T>::recursive_size(BinaryNode<T>*sub_root) const
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The number of entries in the subtree is returned.
Uses: The function recursive_size recursively
*/
{
   if (sub_root == NULL)
      return 0;
   else{
      int ls = recursive_size(sub_root->left);
      int rs = recursive_size(sub_root->right);
      return 1 + ls + rs;
   }
      
}

template <class T>
void BinaryTree<T>::recursive_clear(BinaryNode<T>*sub_root)
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: All the nodes in the subtree are disposed of in postorder.
Uses: The function recursive_clear recursively
*/
{
}

template <class T>
int BinaryTree<T>::recursive_height(BinaryNode<T> *sub_root) const 
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: the height of the subtree is returned.
Uses: The function recursive_height recursively
*/
{
      if (sub_root == NULL)
      return 0;
   else{
      int ls = recursive_height(sub_root->left);
      int rs = recursive_height(sub_root->right);
      return 1 + ls + rs;
   }
      
}   

template <class T>
BinaryNode<T>* BinaryTree<T>::recursive_copy(BinaryNode<T>* sub_root) 
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: returns a pointer to the root of a new binary tree that has exactly the same structure and content as those of the subtree.
Uses: The function recursive_copy recursively
*/
{
   if (sub_root == NULL)
      return NULL;
   else {
      BinaryNode<T>* new_sub_root = new BinaryNode<T>(sub_root->key);
      new_sub_root->left = recursive_copy(sub_root->left);
      new_sub_root->right = recursive_copy(sub_root->right);
      return new_sub_root;
   }
}


template <class T>
void BinaryTree<T>::recursive_preorder_print_node(BinaryNode<T> *sub_root) const
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder_print_node recursively
*/
{
   if (sub_root != NULL) {
      if(sub_root->left != NULL || sub_root->right != NULL){
         cout << sub_root->key << ":  ";
         if(sub_root->left != NULL)
            cout << sub_root->left->key << "  ";
         else
            cout << "-  "; // "-" represents no child
         if(sub_root->right != NULL)
            cout << sub_root->right->key << " ";
         else
            cout << "-  "; // "-" represents no child
         //cout << "; ";
         cout << endl;
      }
      recursive_preorder_print_node(sub_root->left);
      recursive_preorder_print_node(sub_root->right);
   }
}
#endif
