#include <iostream>

// Given a roman numeral, convert it to an integer.

int main()
{
	int number{};
	std::string s{"MCMXC"};
	std::cout << s << std::endl;
	int stringSize = s.length();

	for (int i = 0; i < stringSize; i++) {
		if (s[i] == 'M') {
			number += 1000;
			continue;
		}

		if (s[i] == 'D') {
			number += 500;
			continue;
		}

		if ((s[i] == 'C') and (s[i+1] == 'M')) {
			number += 900;
			i++;
			continue;
		} else if ((s[i] == 'C') and (s[i + 1] == 'D')) {
				number += 400;
				i++;
				continue;
			} else if (s[i] == 'C') {
					number += 100;
					continue;
				}


		if (s[i] == 'L') {
			number += 50;
			continue;
		}


		if ((s[i] == 'X') and (s[i + 1] == 'C')) {
			number += 90;
			i++;
			continue;
		} else if ((s[i] == 'X') and (s[i + 1] == 'L')) {
			number += 40;
			i++;
			continue;
		}
		else if (s[i] == 'X') {
			number += 10;
			continue;
			}

		if (s[i] == 'V') {
			number += 5;
			continue;
		}

		if ((s[i] == 'I') and (s[i + 1] == 'X')) {
			number += 9;
			i++;
			continue;
		}
		else if ((s[i] == 'I') and (s[i + 1] == 'V')) {
			number += 4;
			i++;
			continue;
		}
		else if (s[i] == 'I') {
			number++;
			continue;
		}
	}

	std::cout << number;

	return 0;
}