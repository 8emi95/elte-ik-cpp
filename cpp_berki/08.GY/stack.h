#ifndef __STACK_H__
#define __STACK_H__

#include <iterator>

template <class T>
struct stack {
private:

	struct node {
		node(T data, node* next = 0) : data(data), next(next) {}
		T data;
		node* next;
	};
	
	node* head;
	
public:

	class iterator : public std::iterator<std::forward_iterator_tag, T> {

	private:
		node *n;
		iterator(node *n) : n(n) {}
	public:
		friend stack;
		friend class const_iterator;
	
		T& operator*()
		{
			return n->data;
		}

		bool operator==(iterator it) {
			return it.n == n;
		}

		bool operator!=(iterator it) {
			return !(*this == it);
		}

		iterator operator++()	{
				n = n->next;
				return *this;
		}
		
	};

	class const_iterator : public std::iterator<std::forward_iterator_tag, T> {

	private:
		const node *n;
		const_iterator(const node *n) : n(n) {}

	public:
		friend stack;
		
		const_iterator(stack<T>::iterator it) : n(it.n) {}
		
		const T& operator*() {
			return n->data;
		}

		bool operator==(const_iterator it) {
			return it.n == n;
		}

		bool operator!=(const_iterator it) {
			return !(*this == it);
		}

		const_iterator operator++()	{
				n = n->next;
				return *this;
		}

	};
	
	stack() : head(0) { }
	stack(const stack& other) {
		if (!other.head) {
			head = 0;
			return;
		}
		head = new node(other.head->data);
		node *n = head;
		const_iterator cit = other.begin();
		++cit;
		for(; cit != other.end(); ++cit)
		{
			n->next = new node(*cit);
			n = n->next;
		}
	}

	stack<T>& operator=(const stack &other) {
		if (this == &other)
			return *this;
		node *n = head;
		while(n) {
			node *m = n->next;
			delete n;
			n = m;
		}
		if (!other.head) {
			head = 0;
			return *this;
		}
		head = new node(other.head->data);
		node *m = head;
		const_iterator cit = other.begin();
		++cit;
		for(; cit != other.end(); ++cit)
		{
			m->next = new node(*cit);
			m = m->next;
		}
		return *this;
	}
	
	~stack() {
	node* n = head;
	while (n) {
		node *m = n->next;
		delete n;
		n = m;
		}
	}
	
	T pop() {
		node *n = head;
		head = head->next;
		T result = n->data;
		delete n;
		return result;
	}
	
	const T& top() const {
		return head->data;
	}

	T& top() {
		return head->data;
	}
	
	stack<T>& push(const T& i) {
	node* t = head;
	head = new node(i, t);
	return *this;
	}

	iterator begin() { return iterator(head); }
	iterator end() { return iterator(0); }
	const_iterator begin() const { return const_iterator(head); }
	const_iterator end() const { return const_iterator(0); }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const stack<T>& s)
{
	for(typename stack<T>::const_iterator cit = s.begin(); cit != s.end(); ++cit)
		os<<*cit<<" ";
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, stack<T>& s)
{
	T i;
	while(is>>i)
	{
		s.push(i);
	}
    return is;
}
#endif