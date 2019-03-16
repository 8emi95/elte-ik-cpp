/* https://www.facebook.com/groups/1697853153792345/permalink/1876837855893873/
locu: Nem voltam ma, így nem tudom mi a feladat (rég megvan a tárgy.) . De a link ez a feladathoz:
http://patakino.web.elte.hu/pny2/csummain.cpp
Első ránézésre a kettesért kellett egy olyan class-t csinálni ami konstruktorba egy olyan paramétert kap ami az első template paraméterével megfelel. Gondolom ahhoz hasonlóba el is tárolja. Utána a get_checksum() pedig végigmegy a belső container elemein és a második paraméter által visszaadott értéket hozzáadja egy változóhoz. Szimpla megszámlálás. De mindjárt leprogramozom és kiderül :D

patrik: es a typename kulcsszo mukodeset nagyon kell tudni :D 5osre megirt programnal harmast kaptam ugy hogy vegul elmondtam csak sok idobe telt
*/

#ifndef CHECKSUM_H
#define CHECKSUM_H

struct mybinary: std::binary_function<int,int,int>
{
int operator()(int a , int b)const
{
return a+b;
}
};
template<typename S,typename UN,typename T=typename S::value_type,typename BIF = mybinary>
class checksum
{
private:
int sum;
S& container;
UN func;
BIF summer;
public:
checksum(S& cont,int start=0):sum(start),container(cont) {sum=get_sum();}
int get_sum()const
{
int s = sum;
for(typename S::const_iterator it = container.begin(); it!=container.end();++it)
{
s=summer(s,func(*it));
}
return s;
}
const int get_checksum() const {return sum;}
const bool validate_checksum()const {return get_sum()==sum;}
void update_checksum() {sum = get_sum();}
};

#endif