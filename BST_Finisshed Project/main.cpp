#include <iostream>
#include <string>
#include "errorcode.h"
#include "BN.h"
#include "BT.h"
#include "BST.h"

using namespace std;



template <class T> void visit (T &d);
void menu();

int main(){
   string input = "";
   bool exit_now = false;
   BST<int> bst;
   while(!exit_now){
      cout << endl;
      cout << "======== Menu ========" << endl;
      cout << "i. Incremental Insert" << endl;
      cout << "r. Incremental Remove" << endl;
      cout << "c. Clear tree" << endl;
      cout << "t. Print tree" << endl;
      cout << "h. Print tree height" << endl;
      cout << "s. Print tree size" << endl;
      cout << "m. Pre-order traversal" << endl;
      cout << "n. In-order traversal" << endl;
      cout << "p. Post-order traversal" << endl;
      cout << "l. Leaf count" << endl;
      cout << "x. Exit" << endl;
      cout << "======== Menu ========" << endl;

      cout << "Select an option: ";
      getline(cin, input);

      if(input == "i"){
         cout << endl;
         cout << "Enter new integer keys to insert.  Enter \"q<Enter>\" to quit." << endl;
         cout << endl;
         getline(cin, input);

         while(input != "q"){
            bst.insert(stoi(input));
            bst.print();            
            getline(cin, input);
         }
      } 
      else if(input == "r"){
         cout << endl;
         cout << "Enter integer keys to delete.  Enter \"q<Enter>\" to quit." << endl;
         cout << endl;
         getline(cin, input);
         while(input != "q"){
            bst.remove(stoi(input));
            bst.print();            
            getline(cin, input);
         }
      } 
      else if (input == "c")
            bst.clear();
      else if (input == "t")
            bst.print();
      else if (input == "h")
            cout << endl << "The height of the binary tree is " << bst.height() << endl;
      else if (input == "s")
            cout << endl << "The size (node count) of the binary tree is " << bst.size() << endl;
      else if(input == "m")
            bst.preorder(visit);
      else if(input == "n")
            bst.inorder(visit);
      else if(input == "p")
            bst.postorder(visit);
      else if(input == "l")
            cout << endl << "The leaf count of the binary tree is " << bst.getLeafCount() << endl;
      else if(input == "x")
            exit_now = true;
   }
}

template <typename T>
void visit (T& d) {
        cout << d << endl;
}
