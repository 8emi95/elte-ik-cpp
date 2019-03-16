#include <iostream>

void swap(int *a, int b) {
	int temp = *a;
	*a = b;
	b = temp;
}

int main() {
	int *i = new int(2);
	int j = 3;
	swap(&j, 5);
	swap(i, *i);
	swap(0, j);
	std::cout<<*i<<" "<<j<<std::endl;
}