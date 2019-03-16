#include <iostream>


struct stack {
private:

	struct node {
		int data;
		node* next;
	};
	
	node* head;
	
public:
	stack() : head(0) { }
	stack(const stack& other);
	stack& operator=(const stack& other);
	~stack();
	int pop();
	int& top();
	const int& top() const;
	stack& push(int i);
	void print() const;
};

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

int& stack::top() {
	return head->data;
}

const int& stack::top() const {
	return head->data;
}

void stack::print() const {
	node *n = head;
	while (n) {
		std::cout<<n->data<<" ";
		n = n->next;
	}
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
	const stack t = s;
	std::cout<<s.pop()<<std::endl;
	s.print();
	std::cout<<t.top()<<std::endl;
	t.print();
}
