int fav(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n*fac(n-1);
	}
} // undefined reference lesz (a.cpp)