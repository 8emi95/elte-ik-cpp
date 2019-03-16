int i = -3;
unsigned int j = 1; // nem lesz negatív soha
if (i < j)
{
	std::cout << "ok";
}
else
{
	std::cout << "wtf"; // wtf-et fog írni, 2 int v 2 unsigned int között tud
}					   // int -> unsigned int konvertál, előjelet "bebillenti" (?), nagy szám lesz