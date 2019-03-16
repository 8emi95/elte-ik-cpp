#ifndef __CHECKSUM_H__
#define __CHECKSUM_H__

template <class Cont, class Func, class T = typename Cont::value_type, class Binary = std::plus<int> >
class checksum {
	const Cont& c;
	int csum;
	int init;
public:
	checksum(const Cont& c, int i = 0) : c(c), csum(i), init(i) {
		for(typename Cont::const_iterator cit = c.begin(); cit != c.end(); ++cit)
			csum = Binary()(csum, Func()(*cit));
	}

	int get_checksum() const 
	{
		return csum;
	}
	
	bool validate_checksum() const {
		int vcsum = init;
		for(typename Cont::const_iterator cit = c.begin(); cit != c.end(); ++cit)
			vcsum = Binary()(vcsum, Func()(*cit));
		return vcsum == csum;
	}
	
	void update_checksum() {
		csum = init;
		for(typename Cont::const_iterator cit = c.begin(); cit != c.end(); ++cit)
			csum = Binary()(csum, Func()(*cit));
	}
};

#endif