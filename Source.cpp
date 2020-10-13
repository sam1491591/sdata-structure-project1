#include <iostream>
using namespace std;

void drop(string obj, int m, int n, int rp, int move);

int matrix[15][40];

int main()
{
	int m, n;
	cin >> m >> n;
	cout << m << " "<<n << endl;
	string obj;
	cin >> obj;
	int rp, move;
	while (obj!="End")
	{
		//cout << obj << endl;
		cin >> rp >> move;
		//cout << rp <<" "<< move << endl;
		drop(obj, m, n, rp, move);

		cin >> obj;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void drop(string obj, int m, int n, int rp, int move)
{
	int x,y,y2;
	if (obj == "T1")
	{
		for (y = 1; y < m; y++)
		{
			if (matrix[y - 1][rp - 1] || matrix[y][rp] || matrix[y - 1][rp + 1] == 1)
				break;
		}
		if (y != 1)
			y -= 1;
		for (y2 = 0; y2 < m-y; y2++)
		{
			if (matrix[y - 1+y2][rp - 1+move] || matrix[y+y2][rp+move] || matrix[y - 1+y2][rp + 1+move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp + move] = 1;
		matrix[y + y2][rp + move] = 1;
		matrix[y - 1 + y2][rp + 1 + move] = 1;
	}
	if (obj == "T2")
	{
		for (y = 2; y < m; y++)
		{
			if (matrix[y - 1][rp - 1] || matrix[y][rp]  == 1)
				break;
		}
		if (y != 2)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y - 1 + y2][rp - 1 + move] || matrix[y + y2][rp + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y - 2 + y2][rp + move] = 1;
		matrix[y - 1 + y2][rp + move] = 1;
		matrix[y + y2][rp + move] = 1;
	}
	if (obj == "T3")
	{
		for (y = 1; y < m; y++)
		{
			if (matrix[y][rp - 1] || matrix[y][rp] || matrix[y][rp+1] == 1)
				break;
		}
		if (y != 1)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + y2][rp - 1 + move] || matrix[y + y2][rp + move] || matrix[y + y2][rp + 1 + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 1 + y2][rp + move] = 1;
		matrix[y + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp + move] = 1;
		matrix[y + y2][rp + 1 + move] = 1;
	}
	if (obj == "T4")
	{
		for (y = 2; y < m; y++)
		{
			if (matrix[y][rp - 1] || matrix[y - 1][rp] == 1)
				break;
		}
		if(y!=2)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + y2][rp - 1 + move] || matrix[y - 1 + y2][rp + move] == 1)
				break;
		}
		if(y2!=0)
			y2 = y2 - 1;
		matrix[y - 2 + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp + move] = 1;
	}
	if (obj == "L1")
	{
		for (y = 2; y < m; y++)
		{
			if (matrix[y][rp - 1] || matrix[y][rp] == 1)
				break;
		}
		if (y != 2)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + y2][rp - 1 + move] || matrix[y + y2][rp + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 2 + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp + move] = 1;
	}
	if (obj == "L2")
	{
		for (y = 1; y < m; y++)
		{
			if (matrix[y][rp - 1] || matrix[y - 1][rp] == 1)
				break;
		}
		if (y != 1)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + y2][rp - 1 + move] || matrix[y - 1 + y2][rp + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp + move] = 1;
		matrix[y - 1 + y2][rp + 1 + move] = 1;
	}
	if (obj == "L3")
	{
		for (y = 2; y < m; y++)
		{
			if (matrix[y - 2][rp - 1] || matrix[y][rp] == 1)
				break;
		}
		if (y != 2)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y - 2 + y2][rp - 1 + move] || matrix[y + y2][rp + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 2 + y2][rp - 1 + move] = 1;
		matrix[y - 2 + y2][rp + move] = 1;
		matrix[y - 1 + y2][rp + move] = 1;
		matrix[y + y2][rp + move] = 1;
	}
	if (obj == "L4")
	{
		for (y = 1; y < m; y++)
		{
			if (matrix[y][rp - 1] || matrix[y][rp] || matrix[y][rp + 1] == 1)
				break;
		}
		if (y != 1)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + y2][rp - 1 + move] || matrix[y + y2][rp + move] || matrix[y + y2][rp + 1 + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 1 + y2][rp + 1 + move] = 1;
		matrix[y + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp + move] = 1;
		matrix[y + y2][rp + 1 + move] = 1;
	}
	if (obj == "J1")
	{
		for (y = 2; y < m; y++)
		{
			if (matrix[y][rp - 1] || matrix[y][rp] == 1)
				break;
		}
		if (y != 2)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y+ y2][rp - 1 + move] || matrix[y + y2][rp + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y + y2][rp - 1 + move] = 1;
		matrix[y - 2 + y2][rp + move] = 1;
		matrix[y - 1 + y2][rp + move] = 1;
		matrix[y + y2][rp + move] = 1;
	}
	if (obj == "J2")
	{
		for (y = 1; y < m; y++)
		{
			if (matrix[y][rp - 1] || matrix[y][rp] || matrix[y][rp + 1] == 1)
				break;
		}
		if (y != 1)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + y2][rp - 1 + move] || matrix[y + y2][rp + move] || matrix[y + y2][rp + 1 + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp + move] = 1;
		matrix[y + y2][rp + 1 + move] = 1;
	}
	if (obj == "J3")
	{
		for (y = 2; y < m; y++)
		{
			if (matrix[y][rp - 1] || matrix[y-2][rp] == 1)
				break;
		}
		if (y != 2)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + y2][rp - 1 + move] || matrix[y - 2 + y2][rp + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 2 + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp - 1 + move] = 1;
		matrix[y - 2 + y2][rp + move] = 1;
	}
	if (obj == "J4")
	{
		for (y = 1; y < m; y++)
		{
			if (matrix[y - 1][rp - 1] || matrix[y - 1][rp] || matrix[y][rp + 1] == 1)
				break;
		}
		if (y != 1)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y - 1 + y2][rp - 1 + move] || matrix[y - 1 + y2][rp + move] || matrix[y + y2][rp + 1 + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp + move] = 1;
		matrix[y - 1 + y2][rp + 1 + move] = 1;
		matrix[y + y2][rp + 1 + move] = 1;
	}
	if (obj == "S1")
	{
		for (y = 1; y < m; y++)
		{
			if (matrix[y][rp - 1] || matrix[y][rp] || matrix[y - 1][rp + 1] == 1)
				break;
		}
		if (y != 1)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + y2][rp - 1 + move] || matrix[y + y2][rp + move] || matrix[y - 1 + y2][rp + 1 + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp + move] = 1;
		matrix[y + y2][rp + move] = 1;
		matrix[y - 1 + y2][rp + 1 + move] = 1;
	}
	if (obj == "S2")
	{
		for (y = 2; y < m; y++)
		{
			if (matrix[y - 1][rp - 1] || matrix[y][rp] == 1)
				break;
		}
		if (y != 2)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y - 1 + y2][rp - 1 + move] || matrix[y + y2][rp + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y - 2 + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp + move] = 1;
		matrix[y + y2][rp + move] = 1;
	}
	if (obj == "Z1")
	{
		for (y = 1; y < m; y++)
		{
			if (matrix[y - 1][rp - 1] || matrix[y][rp] || matrix[y][rp + 1] == 1)
				break;
		}
		if (y != 1)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y - 1 + y2][rp - 1 + move] || matrix[y + y2][rp + move] || matrix[y + y2][rp + 1 + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 1 + y2][rp + move] = 1;
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp + move] = 1;
		matrix[y + y2][rp + 1 + move] = 1;
	}
	if (obj == "Z2")
	{
		for (y = 2; y < m; y++)
		{
			if (matrix[y][rp - 1] || matrix[y - 1][rp] == 1)
				break;
		}
		if (y != 2)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + y2][rp - 1 + move] || matrix[y - 1 + y2][rp + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 2 + y2][rp + move] = 1;
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp + move] = 1;
	}
	if (obj == "I1")
	{
		for (y = 3; y < m; y++)
		{
			if (matrix[y][rp - 1] == 1)
				break;
		}
		if (y != 3)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + y2][rp - 1 + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y - 3 + y2][rp - 1 + move] = 1;
		matrix[y - 2 + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp - 1 + move] = 1;
	}
	if (obj == "I2")
	{
		for (y = 1; y < m; y++)
		{
			if (matrix[y][rp - 1] || matrix[y][rp] || matrix[y][rp + 1] || matrix[y][rp + 2] == 1)
				break;
		}
		if (y != 1)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + y2][rp - 1 + move] || matrix[y + y2][rp + move] || matrix[y + y2][rp + 1 + move] || matrix[y + y2][rp + 2 + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp + move] = 1;
		matrix[y + y2][rp + 1 + move] = 1;
		matrix[y + y2][rp + 2 + move] = 1;
	}
	if (obj == "O")
	{
		for (y = 2; y < m; y++)
		{
			if (matrix[y][rp - 1] || matrix[y][rp] == 1)
				break;
		}
		if (y != 2)
			y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + y2][rp - 1 + move] || matrix[y + y2][rp + move] == 1)
				break;
		}
		if (y2 != 0)
			y2 = y2 - 1;
		matrix[y + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp + move] = 1;
		matrix[y + y2][rp + move] = 1;
	}
}