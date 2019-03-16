#include <iostream>
#include <vector>
#include <algorithm>

class multiply {
private:
	int factor;
public:
	multiply(int factor) : factor(factor) {}
	int operator()(int& rhs) const {
		return rhs *= factor;
	}
};

class max {
private:
	int val;
public:
    max(int val) : val(val) {}
	int operator()() { return val; }
	int operator()(int val) {
		this->val = (this->val<val)?val:this->val;
		return this->val;
	}
};

struct print{
	void operator()(int i) { std::cout<<" " << i; }
};

void print2(int i) { std::cout<<" " << i; }

int main() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(5);
	v.push_back(8);
	v.push_back(3);

	std::for_each(v.begin(), v.end(), multiply(2));
	max m(*v.begin());
	std::for_each(v.begin(), v.end(), m);
	std::for_each(v.begin(), v.end(), print());
	std::cout<<std::endl;
	std::cout<<"max="<<m()<<std::endl;
	std::for_each(v.begin(), v.end(), print2);
	
	return 0;
}