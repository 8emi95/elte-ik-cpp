#include <iostream>

struct date
{
	int year;
	int month;
};

void print(date* d)
{
	std::cout<<d->year<<" "<<d->month<<std::endl;
}

int main()
{
	date d;
	d.year = 2017;
	d.month = 2;
}