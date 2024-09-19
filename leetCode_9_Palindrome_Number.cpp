#include <iostream>

//Given an integer x, return true if x is a palindrome, and false otherwise.
void static isPalindrome(int x);

int main()
{
	int x{ 1001 };
	isPalindrome(x);

	return 0;
}


void static isPalindrome(int x) {
	std::cout << x << std::endl;

	int digitNumber{ 1 };
	int tmp = x;
	bool check{ 1 };

	// Find how many digits in number
	while (tmp / 10 != 0) {
		digitNumber++;
		tmp /= 10;
	}
	
	// Negative numbers are not a palindrome
	if (x >= 0) {
		for (int i = 0; i < digitNumber / 2; i++) {
			// compare last and first number, / -1 +1 / etc.
			if ((x / int((pow(10, i))) % 10) != (x / int(pow(10, digitNumber - 1 - i)) % 10))
				check = 0;
		}
	}
	else {
		check = 0;
	}

	if (check == 1)
		std::cout << "Palindrome.";
	else
		std::cout << "Not palindrome.";
}
