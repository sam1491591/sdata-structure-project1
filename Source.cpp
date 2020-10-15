#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

void drop(string obj, int m, int n, int rp, int move);

void eliminate(int m, int n);

int matrix[20][50];

int main(int argc,char* argv[])
{
	int m, n;
	fstream input(argv[1], ios::in);
	fstream output("108062140_proj1.final", ios::out);
	if (!input)
	{
		cout << "no file/n";
	}
	if (!output)
	{
		cout << "can't output your answer";
	}
	input >> m >> n;
	//cin >> m >> n;
	//cout << m << " "<<n << endl;
	string obj;
	input >> obj;
	//cin >> obj;
	int rp, move;
	while (obj!="End")
	{
		//cout << obj << endl;
		input >> rp >> move;
		//cin >> rp >> move;
		//cout << rp <<" "<< move << endl;
		drop(obj, m, n, rp, move);
		eliminate(m, n);

		input >> obj;
		//cin >> obj;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			output << matrix[i][j];
			//cout << matrix[i][j] ;
			if (j != n - 1)
				output << " ";
				//cout << " ";
		}
		output << endl;
		//cout << endl;
	}
	input.close();
	output.close();
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
		matrix[y - 1 + y2][rp - 1 + move] = 1;
		matrix[y + y2][rp - 1 + move] = 1;
		matrix[y - 1 + y2][rp + move] = 1;
		matrix[y - 2 + y2][rp + move] = 1;
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

void eliminate(int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
				break;
			if (j == n - 1)
			{
				for (int k = i ; k > 0; k--)
				{
					for (int l = 0; l < n; l++)
					{
						matrix[k][l] = matrix[k - 1][l];
					}
				}
				for (int k = 0; k < n; k++)
					matrix[0][k] = 0;
			}

		}
	}
}