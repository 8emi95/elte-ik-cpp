#include <iostream>

class btree{
	int data;
	btree* left;
	btree* right;
	void destroy(btree* &tree);
	void print(btree* tree);
public:
	btree(int data);
	~btree();
	btree* create(int data);
	void add(int data);
	void print();
};

btree::btree(int data) : data(data), left(0), right(0) {}

void btree::destroy(btree* &tree)
{
	if(tree)
	{
		destroy(tree->left);
		destroy(tree ->right);
		delete tree;
		tree = 0;
	}
}

btree::~btree()
{
	destroy(left);
	destroy(right);
}

void btree::add(int data)
{
	btree* p = this;
	btree* previous = this;
	while(p)
	{
		if (p->data > data)
		{
			if (p->left)
			{
				p = p->left;
			}	else
				{
					previous = p;
					p = p->left;
				}
		} else
			if (p->right)
			{
				p = p->right;
			}	else
				{
					previous = p;
					p = p->right;
				}
	}
	if (previous->data > data)
	{
		previous->left = new btree(data);
	} else
	{
		previous->right = new btree(data);
	}
}

void btree::print(btree* tree)
{
	if(tree)
	{
		std::cout<<tree->data<<" ";
		print(tree->left);
		print(tree->right);
	}
}

void btree::print()
{
	print(this);
}

int main()
{
	btree tree = btree(40);
	tree.add(20);
	tree.add(30);
	tree.add(80);
	tree.add(90);
	tree.add(70);
	tree.add(100);
	tree.add(50);
	tree.add(10);
	tree.add(120);
	tree.add(60);
	tree.add(110);
	tree.print();
	return 0;
}