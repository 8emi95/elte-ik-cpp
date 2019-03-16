#include <iostream>


struct stack {
private:

	struct node {
		int data;
		node* next;
	};
	
	node* head;
	
public:

	class iterator {

	private:
		friend class const_iterator;
		node *n;
		iterator(node *n) : n(n) {}

	public:
		friend stack;
		int& operator*();

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

	class const_iterator {

	private:
		const node *n;
		const_iterator(node *n) : n(n) {}

	public:
		friend stack;
		
		const_iterator(iterator it) : n(it.n) {}
		
		const int& operator*() {
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
	stack(const stack& other);
	stack& operator=(const stack& other);
	~stack();
	int pop();
	const int& top() const;
	int& top();
	stack& push(int i);
	void print() const;
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(0); }
	const_iterator begin() const { return const_iterator(head); }
	const_iterator end() const { return const_iterator(0); }
};

int& stack::iterator::operator*()
{
	return n->data;
}

stack::~stack() {
	node* n = head;
	while (n) {
		node *m = n->next;
		delete n;
		n = m;
	}
}

stack& stack::push(int i) {
	node* t = head;
	head = new node;
	head->data = i;
	head->next = t;
	return *this;
}

int stack::pop() {
	node *n = head;
	head = head->next;
	int result = n->data;
	delete n;
	return result;
}

const int& stack::top() const {
	return head->data;
}

int& stack::top() {
	return head->data;
}

void stack::print() const {
	for(const_iterator cit = begin(); cit != end(); ++cit)
		std::cout<<*cit<<" ";
	std::cout<<std::endl;
}

stack::stack(const stack &other) {
	if (!other.head) {
		head = 0;
		return;
	}
	node *n = other.head;
	head = new node();
	node *m = head;
	m->data = n->data;
	n = n->next;
	while(n) {
		m->next = new node();
		m = m->next;
		m->data = n->data;
		m->next = 0;
		n = n->next;
	}
}

stack& stack::operator=(const stack &other) {
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
	n = other.head;
	head = new node();
	node *m = head;
	m->data = n->data;
	n = n->next;
	while(n) {
		m->next = new node();
		m = m->next;
		m->data = n->data;
		m->next = 0;
		n = n->next;
	}
	return *this;
}

int main() {
	stack s;
	s.push(5).push(3).push(2);
	s.print();
}
