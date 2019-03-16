#include <iostream>

struct btree{
	int data;
	btree* left;
	btree* right;
};

btree* create(int data)
{
	btree* tree = new btree;
	tree->data = data;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}

void add(btree* tree, int data)
{
	if(tree)
	{
		if(tree->data > data)
		{
			if(tree->left)
			{
				add(tree->left, data);
			} 	else
				{
					tree->left = create(data);
				}
		}	else
			{
				if(tree->right)
				{
					add(tree->right, data);
				} 	else
					{
						tree->right = create(data);
					}
			}
	}
}

void print(btree* tree)
{
	if(tree)
	{
		std::cout<<tree->data<<" ";
		print(tree->left);
		print(tree->right);
	}
}

void destroy(btree* &tree)
{
	if(tree)
	{
		destroy(tree->left);
		destroy(tree ->right);
		delete tree;
		tree = NULL;
	}
}

int main()
{
	btree* tree = create(40);
	add(tree, 20);
	add(tree, 30);
	add(tree, 80);
	add(tree, 90);
	add(tree, 70);
	add(tree, 100);
	add(tree, 50);
	add(tree, 10);
	add(tree, 120);
	add(tree, 60);
	add(tree, 110);
	print(tree);
	destroy(tree);
	return 0;
}