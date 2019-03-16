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
	~stack();
	int pop();
	int& top();
	stack& push(int i);
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
	s.push(5).push(3).push(2);
	s.print();
	std::cout<<s.pop()<<std::endl;
	s.print();
	std::cout<<s.top()<<std::endl;
}
