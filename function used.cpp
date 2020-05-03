int factorial(int n)
{
	int product=1;
	for(int i=2;i<=n;++i)
	{
		product*=i;
	}
	return product;
}

int permutation(int n, int r)
{
	return factorial(n)/factorial(n-r);
}

int combination(int n, int r)
{
	return factorial(n)/factorial(r)/factorial(n-r);
}

int subtract(int a, int b)
{
	if(a==b)
	{
		return 0;
	}
	else
	{
		if(a>b)
		{
			return (a-b);
		}
		else
		{
			return (b-a);
		}
	}
}

int bigger(int a, int b)
{
	if(a>=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int smaller(int a, int b)
{
	if(a<=b)
	{
		return a;
	}
	else 
	{
		return b;
	}
}
