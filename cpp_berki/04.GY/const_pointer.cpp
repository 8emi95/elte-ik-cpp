int main()
{
	int i = 5;
	int j = 6;
	const int k = 7;
	int* p = &i;
	*p = 7;
	p = &j;
	p = &k; // forditasi hiba, a pointer nem biztositja, hogy a memoriateruletet nem modosithatjuk
	int* const q = &i;
	*q = 8;
	q = &j; // forditasi hiba const pointer, csak egyszer lehet valamire ramutatni, es ugy marad
	q = &k; // forditasi hiba, a pointer nem biztositja, hogy a memoriateruletet nem modosithatjuk
	const int* r = &i;
	*r = 9; // forditasi hiba const int tipus, a memoriatartalmat nem engedi modositani
	r = &j;
	r = &k;
	const int* const s = &i;
	*s = 9; // forditasi hiba const int
	s = &j; // forditasi hiba const pointer
	s = &k; // forditasi hiba const pointer miatt, ha s = &i helyett szerepelne, akkor fordulna
}