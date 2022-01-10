#ifndef NODE_H
#define	NODE_H

using namespace std;

template<typename T> class List;

template <typename T>
class Node
{
private:
	T data;
	Node<T>* next;//Class type changes to fit what you want. 
public:
	Node(T);
	virtual ~Node(); // base class destructor must be virtual
	friend class List<T>;
};
template <typename T>
Node<T>::Node(T d) {
	data = d;
	next = NULL;
}
template <typename T>
Node<T>::~Node()
{

}
#endif	/* STRNODE_H */

