#include <iostream>

struct node {
	int data;
	node* next;
};

struct stack {
	node* head;
	stack() : head(0) { }
	~stack();
	int pop();
	void push(int i);
	void print();
};

stack::~stack() {
	node* n = head;
	while (n) {
		node *m = n->next;
		delete n;
		n = m;
	}
}

void stack::push(int i) {
	node* t = head;
	head = new node;
	head->data = i;
	head->next = t;
}

int stack::pop() {
	node *n = head;
	head = head->next;
	int result = n->data;
	delete n;
	return result;
}

void stack::print() {
	node *n = head;
	while (n) {
		std::cout<<n->data<<" ";
		n = n->next;
	}
	std::cout<<std::endl;
}

int main() {
	stack s;
	s.push(5);
	s.print();
	s.push(3);
	s.print();
	std::cout<<s.pop()<<std::endl;
	s.print();
}
