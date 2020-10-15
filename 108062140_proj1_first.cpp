#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

void drop(string obj, int m, int n, int rp, int move);

void eliminate(int m, int n);

int matrix[20][50];

int main(int argc, char* argv[])
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
	while (obj != "End")
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
	for (int i = 4 + 1; i < m + 4 + 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			output << matrix[i][j];
			//cout << matrix[i][j];
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
	int x, y, y2;
	if (obj == "T1")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4][rp - 1] || matrix[y + 5][rp] || matrix[y + 4][rp + 1] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + y2][rp - 1 + move] || matrix[y + 5 + y2][rp + move] || matrix[y + 4 + y2][rp + 1 + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 4 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + y2][rp + move] = 1;
		matrix[y + 5 + y2][rp + move] = 1;
		matrix[y + 4 + y2][rp + 1 + move] = 1;
	}
	if (obj == "T2")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 3 + 1][rp - 1] || matrix[y + 4 + 1][rp] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 3 + 1 + y2][rp - 1 + move] || matrix[y + 4 + 1 + y2][rp + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 3 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 2 + 1 + y2][rp + move] = 1;
		matrix[y + 3 + 1 + y2][rp + move] = 1;
		matrix[y + 4 + 1 + y2][rp + move] = 1;
	}
	if (obj == "T3")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4 + 1][rp - 1] || matrix[y + 4 + 1][rp] || matrix[y + 4 + 1][rp + 1] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + 1 + y2][rp - 1 + move] || matrix[y + 4 + 1 + y2][rp + move] || matrix[y + 4 + 1 + y2][rp + 1 + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 3 + 1 + y2][rp + move] = 1;
		matrix[y + 4 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp + move] = 1;
		matrix[y + 4 + 1 + y2][rp + 1 + move] = 1;
	}
	if (obj == "T4")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4 + 1][rp - 1] || matrix[y + 3 + 1][rp] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + 1 + y2][rp - 1 + move] || matrix[y + 3 + 1 + y2][rp + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 2 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 3 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 3 + 1 + y2][rp + move] = 1;
	}
	if (obj == "L1")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4 + 1][rp - 1] || matrix[y + 4 + 1][rp] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + 1 + y2][rp - 1 + move] || matrix[y + 4 + 1 + y2][rp + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 2 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 3 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp + move] = 1;
	}
	if (obj == "L2")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4 + 1][rp - 1] || matrix[y + 3 + 1][rp] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + 1 + y2][rp - 1 + move] || matrix[y + 3 + 1 + y2][rp + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 3 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 3 + 1 + y2][rp + move] = 1;
		matrix[y + 3 + 1 + y2][rp + 1 + move] = 1;
	}
	if (obj == "L3")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 2 + 1][rp - 1] || matrix[y + 4 + 1][rp] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 2 + 1 + y2][rp - 1 + move] || matrix[y + 4 + 1 + y2][rp + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 2 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 2 + 1 + y2][rp + move] = 1;
		matrix[y + 3 + 1 + y2][rp + move] = 1;
		matrix[y + 4 + 1 + y2][rp + move] = 1;
	}
	if (obj == "L4")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4 + 1][rp - 1] || matrix[y + 4 + 1][rp] || matrix[y + 4 + 1][rp + 1] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + 1 + y2][rp - 1 + move] || matrix[y + 4 + 1 + y2][rp + move] || matrix[y + 4 + 1 + y2][rp + 1 + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 3 + 1 + y2][rp + 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp + move] = 1;
		matrix[y + 4 + 1 + y2][rp + 1 + move] = 1;
	}
	if (obj == "J1")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4 + 1][rp - 1] || matrix[y + 4 + 1][rp] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + 1 + y2][rp - 1 + move] || matrix[y + 4 + 1 + y2][rp + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 4 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 2 + 1 + y2][rp + move] = 1;
		matrix[y + 3 + 1 + y2][rp + move] = 1;
		matrix[y + 4 + 1 + y2][rp + move] = 1;
	}
	if (obj == "J2")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4 + 1][rp - 1] || matrix[y + 4 + 1][rp] || matrix[y + 4 + 1][rp + 1] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + 1 + y2][rp - 1 + move] || matrix[y + 4 + 1 + y2][rp + move] || matrix[y + 4 + 1 + y2][rp + 1 + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 3 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp + move] = 1;
		matrix[y + 4 + 1 + y2][rp + 1 + move] = 1;
	}
	if (obj == "J3")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4 + 1][rp - 1] || matrix[y + 2 + 1][rp] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + 1 + y2][rp - 1 + move] || matrix[y + 2 + 1 + y2][rp + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 2 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 3 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 2 + 1 + y2][rp + move] = 1;
	}
	if (obj == "J4")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 3 + 1][rp - 1] || matrix[y + 3 + 1][rp] || matrix[y + 4 + 1][rp + 1] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 3 + 1 + y2][rp - 1 + move] || matrix[y + 3 + 1 + y2][rp + move] || matrix[y + 4 + 1 + y2][rp + 1 + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 3 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 3 + 1 + y2][rp + move] = 1;
		matrix[y + 3 + 1 + y2][rp + 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp + 1 + move] = 1;
	}
	if (obj == "S1")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4 + 1][rp - 1] || matrix[y + 4 + 1][rp] || matrix[y + 3 + 1][rp + 1] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + 1 + y2][rp - 1 + move] || matrix[y + 4 + 1 + y2][rp + move] || matrix[y + 3 + 1 + y2][rp + 1 + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 4 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 3 + 1 + y2][rp + move] = 1;
		matrix[y + 4 + 1 + y2][rp + move] = 1;
		matrix[y + 3 + 1 + y2][rp + 1 + move] = 1;
	}
	if (obj == "S2")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 3 + 1][rp - 1] || matrix[y + 4 + 1][rp] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 3 + 1 + y2][rp - 1 + move] || matrix[y + 4 + 1 + y2][rp + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 3 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 2 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 3 + 1 + y2][rp + move] = 1;
		matrix[y + 4 + 1 + y2][rp + move] = 1;
	}
	if (obj == "Z1")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 3 + 1][rp - 1] || matrix[y + 4 + 1][rp] || matrix[y + 4 + 1][rp + 1] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 3 + 1 + y2][rp - 1 + move] || matrix[y + 4 + 1 + y2][rp + move] || matrix[y + 4 + 1 + y2][rp + 1 + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 3 + 1 + y2][rp + move] = 1;
		matrix[y + 3 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp + move] = 1;
		matrix[y + 4 + 1 + y2][rp + 1 + move] = 1;
	}
	if (obj == "Z2")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4 + 1][rp - 1] || matrix[y + 3 + 1][rp] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + 1 + y2][rp - 1 + move] || matrix[y + 3 + 1 + y2][rp + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 3 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 3 + 1 + y2][rp + move] = 1;
		matrix[y + 2 + 1 + y2][rp + move] = 1;
	}
	if (obj == "I1")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4 + 1][rp - 1] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + 1 + y2][rp - 1 + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 1 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 2 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 3 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp - 1 + move] = 1;
	}
	if (obj == "I2")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4 + 1][rp - 1] || matrix[y + 4 + 1][rp] || matrix[y + 4 + 1][rp + 1] || matrix[y + 4 + 1][rp + 2] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + 1 + y2][rp - 1 + move] || matrix[y + 4 + 1 + y2][rp + move] || matrix[y + 4 + 1 + y2][rp + 1 + move] || matrix[y + 4 + 1 + y2][rp + 2 + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 4 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp + move] = 1;
		matrix[y + 4 + 1 + y2][rp + 1 + move] = 1;
		matrix[y + 4 + 1 + y2][rp + 2 + move] = 1;
	}
	if (obj == "O")
	{
		for (y = 0; y < m; y++)
		{
			if (matrix[y + 4 + 1][rp - 1] || matrix[y + 4 + 1][rp] == 1)
				break;
		}
		y -= 1;
		for (y2 = 0; y2 < m - y; y2++)
		{
			if (matrix[y + 4 + 1 + y2][rp - 1 + move] || matrix[y + 4 + 1 + y2][rp + move] == 1)
				break;
		}
		y2 -= 1;
		matrix[y + 4 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 3 + 1 + y2][rp - 1 + move] = 1;
		matrix[y + 3 + 1 + y2][rp + move] = 1;
		matrix[y + 4 + 1 + y2][rp + move] = 1;
	}
}

void eliminate(int m, int n)
{
	for (int i = 0; i < m + 4 + 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
				break;
			if (j == n - 1)
			{
				for (int k = i; k > 0; k--)
				{
					for (int l = 0; l < n; l++)
					{
						matrix[k][l] = matrix[k - 1][l];
					}
				}
			}

		}
	}
}

