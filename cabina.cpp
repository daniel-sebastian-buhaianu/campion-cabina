#include <fstream>
using namespace std;
struct Statie { int alt, np; };
int main()
{
	ifstream f("cabina.in");
	int n, i, np=0;
	f >> n;
	Statie s[n];
	for (i = 0; i < n; i++)
	{
		f >> s[i].alt >> s[i].np;
		np += s[i].np;
	}
	f.close();
	bool coboara=0, urca=0;
	int sp=0, c=0;
	for (i = 1; i < n; i++)
	{
		if (s[i].alt > s[i-1].alt)
		{
			c = c + 3*(s[i].alt - s[i-1].alt);
			if (coboara) sp++;
			coboara = 0, urca = 1;
		}
		else
		{
			c = c + (s[i-1].alt - s[i].alt);
			if (urca) sp++;
			urca = 0, coboara = 1;
		}
	}
	ofstream g("cabina.out");
	g << np << '\n' << c << '\n' << sp;
	g.close();
	return 0;
}

