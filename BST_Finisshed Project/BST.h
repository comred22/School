template <class T>
class BST: public BinaryTree<T> {
public:
   Error_code insert(const T&);
   Error_code remove(const T&);
   Error_code search(T&) const;
protected:

   // Auxiliary functions called by the public functions
   Error_code search_and_insert(BinaryNode<T>*&, const T&);
   Error_code search_and_delete(BinaryNode<T>*&, const T&);
   BinaryNode<T>* search_for_node(BinaryNode<T>*, const T&) const;
};


template <class T>
Error_code BST<T>::insert(const T& new_key)
{
   return search_and_insert(this->root, new_key);
}


template <class T>
Error_code BST<T>::search_and_insert(
           BinaryNode<T>*& sub_root, const T& new_key)
{
    //implement
}


template <class T>
Error_code BST<T>::remove(const T& target)
/*
Post: If a T with a key matching that of target belongs to the
      BST, a code of success is returned, and the corresponding node
      is removed from the tree.  Otherwise, a code of not_present is returned.
Uses: Function search_and_destroy
*/
{
   return search_and_delete(this->root, target);
}


template <class T>
Error_code BST<T>::search_and_delete(
           BinaryNode<T>* &sub_root, const T &target)
/*
Pre:  sub_root is either NULL or points to a subtree of the BST.
Post: If the key of target is not in the subtree, a code of not_present
      is returned.  Otherwise, a code of success is returned and the subtree
      node containing target has been removed in such a way that
      the properties of a binary search tree have been preserved.
Uses: Functions search_and_delete recursively
*/
{
    //implement each deletion case
}


template <class T>
Error_code BST<T>::search(T& target) const
/*
Post: If there is an entry in the tree whose key matches that in target,
      the parameter target is replaced by the corresponding T from
      the tree and a code of success is returned.  Otherwise
      a code of not_present is returned.
Uses: function search_for_node
*/
{
   Error_code result = success;
   BinaryNode<T> *found = search_for_node(this->root, target);
   if (found == NULL)
      result = not_present;
   else
      target = found->key;
   return result;
}


template <class T>
BinaryNode<T>* BST<T>::search_for_node(
            BinaryNode<T>* sub_root, const T &target) const
{
   if (sub_root == NULL || sub_root->key == target) 
        return sub_root;
   else if (sub_root->key < target)
        return search_for_node(sub_root->right, target);
   else 
        return search_for_node(sub_root->left, target);
}


