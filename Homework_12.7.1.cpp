// Homework_12.7.1.cpp Программа, проверяющая является ли строка, кратной числу K

#include <iostream>

bool IsKPeriodic(const std::string& str, const std::string& pat, const int K, int& count)
{
	int len = str.size();
	if (K >= len || len % K)
		return false;

	for (int i = K; i < len; i += K)
	{
		if (str.substr(i, K) != pat)
			return false;
		++count;
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "");
	char key = 'a';
	while (key != 'q')
	{
		std::string str = "";
		std::cout << "Введите cтроку: ";
		std::cin >> str;

		int K{};
		bool correct_in = false;

		while (K <= 0 || !correct_in)
		{
			std::cout << "Введите целочисленное значение, большее нуля: ";
			std::cin >> K;
			if (std::cin.fail()) {
				std::cin.clear();
				while (std::cin.get() != '\n');
			}
			else
				correct_in = true;
		}

		std::string pat = str.substr(0, K);
		int count{ 1 };
		if (IsKPeriodic(str, pat, K, count))
			std::cout << "Cтрока \"" << str << "\" кратна " << K
			<< ", c повторяемостью подстроки \"" << pat << "\" равной " << count;
		else std::cout << "Cтрока " << str << " некратна числу " << K << std::endl;

		std::cout << "\n\n\n";
		std::cout << "Для выхода из программы нажмите q, для продолжения любую клавишу: ";
		std::cin >> key;
	}
	return 0;
}

