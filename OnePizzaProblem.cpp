#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool found(string searchString, vector<string> searchVector)
{
	for (int i = 0; i < searchVector.size(); i++)
	{
		if (searchString == searchVector[i])
		{
			return true;
		}
	}

	return false;
}

bool found(string searchString, map<string, int> searchVector)
{
	for (auto const &pair: searchVector)
	{
		if (searchString == pair.first)
		{
			return true;
		}
	}

	return false;
}

bool isAlphaNumeric(string searchString)
{
	if (searchString.length() == 0 || searchString == " ")
	{
		return false;
	}

	int count = 0;
	for (int i = 0; i < searchString.length(); i++)
	{
		if ((searchString[i] >= 'a' && searchString[i] <= 'z') || (searchString[i] >= '0' && searchString[i] <= '9'))
		{
			count++;
		}

	}

	if (count == searchString.length())
	{
		return true;
	}

	return false;
}

int main()
{
	map<string, int> toppings_on;
	map<string, int> toppings_off;
	vector<string> toppings;

	ifstream fin("C:/Users/swagi/Downloads/e_elaborate.in.txt");

	if (fin.fail())
	{
		cout << "ERROR: File could not be opened! Sorry, no pizza." << endl;
	}

	else
	{
		int num_customers;

		while (fin.eof() == false)
		{
			fin >> num_customers;
			int num_likes, num_dislikes;
			for (int i = 0; i < num_customers; i++)
			{
				fin >> num_likes;
				for (int j = 0; j < num_likes; j++)
				{
					string topping;
					fin >> topping;

					if (isAlphaNumeric(topping))
					{
						if (found(topping, toppings_on))
						{
							toppings_on.insert({ topping, toppings_on[topping] + 1 });
						}

						else
						{
							toppings_on.insert({ topping, 1 });
						}
					}
				}

				fin >> num_dislikes;
				for (int k = 0; k < num_dislikes; k++)
				{
					string topping;
					fin >> topping;

					if (isAlphaNumeric(topping))
					{
						if (found(topping, toppings_off))
						{
							toppings_off.insert({ topping, toppings_off[topping] + 1 });
						}

						else
						{
							toppings_off.insert({ topping, 1 });
						}
					}
				}
			}
		}
	}

	fin.close();

	for (auto const& pair : toppings_on)
	{
		string topping = pair.first;
		if (pair.second >= toppings_off[topping])
		{
			toppings.push_back(topping);
		}
	}

	ofstream fout("E_Submission.out.txt");

	if (fout.fail())
	{
		cout << "ERROR: Sorry file couldn't be opened." << endl;
	}

	else
	{
		fout << toppings.size() << " ";

		for (int i = 0; i < toppings.size(); i++)
		{
			fout << toppings[i] << " ";
		}
	}

	fout.close();

	system("pause");
	return 0;
}
