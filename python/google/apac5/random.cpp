#include <iostream>
#include <iomanip>

using namespace std;

long N, X, k;
double a, b, c, out;

void create_tree(long n, long x, double prob)
{
	if (n == 0)
	{
		out += x*prob;
		return;
	}
	create_tree(n - 1, x & k, prob*a);
	create_tree(n - 1, x | k, prob*b);
	create_tree(n - 1, x ^ k, prob*c);
}

int main()
{
	cout.precision(10);
	cout.setf(ios::fixed, ios::floatfield);
	ios_base::sync_with_stdio(false);
	long T;
	cin >> T;
	for (long t = 1; t <= T; t++)
	{
		cin >> N >> X >> k >> a >> b >> c;
		a /= 100;	
		b /= 100;	
		c /= 100;	
		out = 0;
		create_tree (N, X, 1);
		cout << "Case #" << t << ": " << out << endl;
	}
}
