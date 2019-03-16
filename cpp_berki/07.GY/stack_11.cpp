#include <iostream>
#include <iterator>
#include <algorithm>

struct stack {
private:

	struct node {
		node(int data, node* next = 0) : data(data), next(next) {}
		int data;
		node* next;
	};
	
	node* head;
	
public:

	class iterator : public std::iterator<std::forward_iterator_tag, int> {

	private:
		node *n;
		iterator(node *n) : n(n) {}
	public:
		friend stack;
		friend class const_iterator;
	
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

	class const_iterator : public std::iterator<std::forward_iterator_tag, int> {

	private:
		const node *n;
		const_iterator(const node *n) : n(n) {}

	public:
		friend stack;
		
		const_iterator(stack::iterator it) : n(it.n) {}
		
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
	explicit stack(int i) { } 
	stack(const stack& other);
	stack& operator=(const stack& other);
	~stack();
	int pop();
	const int& top() const;
	int& top();
	stack& push(int i);
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
	head = new node(i, t);
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

stack::stack(const stack &other) {
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

std::ostream& operator<<(std::ostream& os, const stack& s)
{
	for(stack::const_iterator cit = s.begin(); cit != s.end(); ++cit)
		os<<*cit<<" ";
    return os;
}

std::istream& operator>>(std::istream& is, stack& s)
{
	int i;
	while(is>>i)
	{
		s.push(i);
	}
    return is;
}

int main() {
	stack s;
	s.push(5).push(3).push(2);
	std::cout<<s<<std::endl;
	stack t;
	std::cin>>t;
	std::cout<<t<<std::endl;
	stack::iterator it = std::find(s.begin(), s.end(), 3);
	if(it != s.end())
		std::cout<<*it<<std::endl;
}
