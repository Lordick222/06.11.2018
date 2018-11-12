#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <algorithm>
#include <cmath>
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	getRandomNumber(1, 100);
	int a, b, c, d;
	std::cout << "shirina 1 mas   ";
	std::cin >> a;
	std::cout << "dlina 1 mas   ";
	std::cin >> b;
	int **ptrarray1 = new int*[a];
	int **ptrarray2 = new int*[a];
	for (int count = 0; count < a; count++)
	{
		ptrarray1[count] = new int[b];
	}  // 1 massiv
	for (int count = 0; count < a; count++)
	{
		ptrarray2[count] = new int[b];
	}  // 1 massiv
	for (int count_row = 0; count_row < a; count_row++)
	{
		for (int count_column = 0; count_column < b; count_column++)
		{
			ptrarray1[count_row][count_column] = getRandomNumber(0, 20); //zapolnenie1
		}
	}
	for (int count_row = 0; count_row < a; count_row++)
	{
		for (int count_column = 0; count_column < b; count_column++)
		{
			std::cout << ptrarray1[count_row][count_column] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << " \n\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX \n ";
	std::vector<int> mass_b;
	double f{ 0 };
	double q{ 0 };
	double i{ 0 };
	int m_mass{ 0 };
	for (int count_row = 0; count_row < a; count_row++)
	{
		for (int count_column = 0; count_column < b; count_column++)
		{
			q=sqrt(ptrarray1[count_row][count_column]);
			f = modf(q, &i);
			if (f == 0)
			{
				mass_b.push_back(0);
				mass_b[m_mass] = ptrarray1[count_row][count_column];
				m_mass++;
			}
			
		}
		std::cout << "\n";
	}
	std::sort(mass_b.begin(), mass_b.end());
	for (int i = 0; i < m_mass; i++)
	{
		std::cout << mass_b[i] << "\t";
	}
	std::cout << "\n";
	std::cout << mass_b.size() ;
	std::cout << "\n";
	int big{ 0 };
	int kolmax{ 0 };
	int kol{ 1 };
	int h{ 0 };
	big = mass_b[mass_b.size()-1];
	for (int i = (mass_b.size() - 1); i > -1; i--)
	{
		if (i > 0)
		{
			if (mass_b[i] == mass_b[i - 1])
			{
				h = i;
				if (h > 0)
				{
					while (mass_b[h] == mass_b[h - 1])
					{
						kol++;
						h--;
						if (h < 1)
						{
							break;
						}
					}
				}
				if (kolmax < kol)
				{
					big = mass_b[i];
					kolmax = kol;
				}
			}
			kol = 1;
		}
	}
	std::cout << "bigest   :   " << big; 
	system("pause");
	return 0;
}