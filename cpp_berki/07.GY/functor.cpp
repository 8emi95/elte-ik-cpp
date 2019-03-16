#include <iostream>
#include <vector>

class multiply {
private:
	int factor;
	
public:
	multiply(int factor) : factor(factor) {}
	
	int operator()(int rhs) const {
		return rhs * factor;
	}
};

class max {
private:
	int val;
	
public:
    max(int val) : val(val) {}
	
	int operator()() {
		return val;
	}
	
	int operator()(int val) {
		this->val = (this->val<val)?val:this->val;
		return this->val;
	}
};

int main() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(5);
	v.push_back(8);
	v.push_back(3);
	
	multiply by2(2);
	multiply by3(3);
	max m(by2(*v.begin()));
	
	for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout<<by2(*it)<<" ";
		m(by2(*it));
	}
	std::cout<<std::endl;
	std::cout<<"max="<<m()<<std::endl;
	
	typedef std::vector<int>::iterator iter;
	
	for(iter it = v.begin(); it != v.end(); ++it)
	{
		std::cout<<by3(*it)<<" ";
	}
	std::cout<<std::endl;
	return 0;
}