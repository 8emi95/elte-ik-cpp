2016.11.14.
9. C++ EA

// http://aszt.inf.elte.hu/~gsd/pny2/html/ea6_date/date.h.html

if (d < 2016) // d.operator<(2016) tagfv, nincs konverzió...
{			  // operator<(d, 2016)
	// ...
}

if (2016 > d)
{
	// operator>(2016, d) konverzió mindkt helyen (???)
}

inline fv-ek de morgane-nel, one def rule betartása

date d;
std::cout << ....	-> operator<<(std::cout, d)
					-> std::cout.operator<<(d)

date s("2016.11.7");
		^s   ^p1 ^p2
s.next(); // kövi nap legyen a létrehozott dátum
std::cin >> s;


tranzakcionális szemantika?
date d;
std::cin >> d;



dstack1
-------

tagonkénti másolás?
dstack.d2(d1)

d1:					d2:
[capacity:10]	->	[capacity:10]
[sp:1]			->	[sp:3]
[v]				->	[v]
		> [9.99][5.14][...] <


dstack d2 = d1; // dstack.d2(d1);

d1:				d2:
[capacity]	->	[capacity]
[sp]		->	[sp]
[]			->	[]
		> [] <


d1 = d2; // van mindkettőnek leallokált tárhelye vhol
d1: [                     ]
	 ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^
d2: [                     ][]


dstack &y = x;
x = y;
ˇ   ˇ
[   ]


dtack s(8);
s.push(1.4);
const dtack cs = s; // konsi-hívás
std::cout << cs.top();
s.top() = 6.2; // double referencia, ott lévő értéket változtathatom meg
++s.top();

a = b = c;