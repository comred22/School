#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BinaryNode.h"
#include "enum.h"

template <class T>
class BinarySearchTree: public BinaryTree<T> {
public:
   Error_code insert(const T&);
   Error_code remove(const T&);

protected:
   // Auxiliary functions
   Error_code search_and_insert(BinaryNode<T>*& sub_root, const T& new_data);
   Error_code search_and_delete(BinaryNode<T>*& sub_root, const T& target);
   
};

template <class T>
Error_code BinarySearchTree<T>::insert(const T& new_data)
{
   return search_and_insert(this->root, new_data);
}

template <class T>
Error_code BinarySearchTree<T>::search_and_insert(BinaryNode<T>*& sub_root, const T& new_data)
{
   Error_code result;
   if(sub_root == nullptr )
   {
      sub_root = new BinaryNode<T>(new_data);
      result = success;
      return result;
   }
   else if (sub_root->data > new_data)
   {
      // insert to the left subtree
      result = search_and_insert(sub_root->right, new_data);
   }
   else if (sub_root->data < new_data)
   {
      result = search_and_insert(sub_root-> left, new_data);
   }

   else{
      result = duplicate_error;
   }
   return result;
}


template <class T>
Error_code BinarySearchTree<T>::remove(const T& target)
/*
Post: If a T with a key matching that of target belongs to the
      BinarySearchTree, a code of success is returned, and the corresponding node
      is removed from the tree.  Otherwise, a code of not_present is returned.
Uses: Function search_and_destroy
*/
{
   return search_and_delete(this->root, target);
}


template <class T>
Error_code BinarySearchTree<T>::search_and_delete(BinaryNode<T>*& sub_root, const T& target)
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinarySearchTree.
Post: If the key of target is not in the subtree, a code of not_present
      is returned.  Otherwise, a code of success is returned and the subtree
      node containing target has been removed in such a way that
      the properties of a binary search tree have been preserved.
Uses: Functions search_and_delete recursively
*/
{
   Error_code result;
   BinaryNode<T> *temp = sub_root;

   if(target == sub_root->data)
   {
      if (sub_root->left == nullptr  && sub_root->right == nullptr)
      {
         delete  temp;
         sub_root = nullptr;
         return success;
      }
      else if(sub_root->left == nullptr){
         temp = sub_root;
         sub_root= sub_root->right;
         delete  temp;
         return success;
      }
      else if(sub_root->right == nullptr)
      {
         temp = sub_root;
         sub_root= sub_root->left;
         delete  temp;
         return success;
      }
      else // this will check if We have one child
      {
         if (sub_root->right != nullptr)
         {
            //sub_root->right= sub_root->data;
            sub_root->right= sub_root;
            while (temp->left != nullptr)
            {
               temp = temp->left;
            }
            sub_root->data= temp->data;
            return search_and_delete(sub_root->right,temp->data);
         }
      }
   }
   else if(target < sub_root->data)
   {
      return search_and_delete(sub_root->left, target);

   }
   else 
   {
      return search_and_delete(sub_root->right, target);
   }


}
#endif


