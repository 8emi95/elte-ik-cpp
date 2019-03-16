#include <iostream>


struct stack {
private:

	struct node {
		int data;
		node* next;
	};
	
	node* head;
	std::string name;
	
public:
	stack(const std::string& name = "") : head(0), name(name) { 
		std::cout<<name<<" ctor"<<std::endl;
	}
	stack(const stack& other, const std::string& myname = "");
	stack& operator=(const stack& other);
	~stack();
	int pop();
	int& top();
	const int& top() const;
	stack& push(int i);
	void print();
};

stack::~stack() {
	std::cout<<name<<" dtor"<<std::endl;
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

void stack::print() {
	node *n = head;
	while (n) {
		std::cout<<n->data<<" ";
		n = n->next;
	}
	std::cout<<std::endl;
}

stack::stack(const stack &other, const std::string& myname) {
	name = myname;
	std::cout<<name<<" copy ctor"<<std::endl;
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
	std::cout<<name<<" assignment op"<<std::endl;
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

void f(stack& s) {
	std::cout<<"f() last line"<<std::endl;
}
void g(stack s) {
	std::cout<<"g() last line"<<std::endl;
}
stack h() {
	return stack("v");
}
int main() {
	stack s("s");
	stack t(s, "t");
	stack u("u");
	u = t;
	std::cout<<"f()"<<std::endl;
	f(s);
	std::cout<<"g()"<<std::endl;
	g(s);
	std::cout<<"h()"<<std::endl;
	h();
	std::cout<<"Last line"<<std::endl;
}
