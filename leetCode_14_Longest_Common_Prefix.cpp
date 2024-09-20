#include <iostream>
#include <vector>

/*
* Write a function to find the longest common prefix string amongst an array of strings.
1. ����� ������ ������ � �������.
2. � ������ ������ �� ������� ������������� ������ ������.
3. � ������ ��������� ������ ��������� ������� ������ �� �������. ���� �� ���� �� ���� ������� - ��������� ������ ��������� � ������ ������ � ��������� ������ ��������. ����� ��� ����������� ����� - ��������� 1 ������� � ������ ������. (��� �� �� ���� ������� ��� ����������� ������� � ����� - 0 ���������� ��������� �� ���� �������)
4. ���� ������ � ��������� ��������� ����������� ������� �� ���� ������� - ��������� �������� ���������� ����� ���� ������� � ������ ������.
5. ���� �� ���� ��������� �� ���� ������� - ����� ������������� �� 1 ������.
6. ������������ �������� - ���� �������� � ������� ������.
7. ����� ��� ���� ��������� �� ���� ������� - ���� ������������ ����� �������� �� ���� ������� � ���������� � ���������� �������, ����� �������.
*/


// �������� � �������� ��������. ����� ������� ������������ ������ ��� ��������� ���-�� ������. ��������� � ������� ��� � ����� � �������, ��.

int main()
{
	std::vector<std::string> strs{"flower", "flow", "flight"};
	const int arraySize = strs.size();
	int tmp_int{}, resultInt{}, countCheck{1}, arrayIndex[arraySize];
	bool check{ 1 };
	char tmp_char{};
	std::string resultStr{}, tmp_str{};

	// ����� ������ ������ � ������� � ������������� �� ������� ������ � ������.
	for (int charIndexFirstStr = 0; charIndexFirstStr < strs[0].length(); charIndexFirstStr++) {
		tmp_char = strs[0][charIndexFirstStr]; // ������ ������ ������
		tmp_int = charIndexFirstStr; // ������ ������� ������ ������
		arrayIndex[0] = tmp_int;
		tmp_str += tmp_char;

		// ����� �� ������� ������������� ������ ��������� ������
		for (int strIndex = 1; strIndex < strs.size(); strIndex++) {
			// � ������ ��������� ������ ��������� ������� ������ �� ������� ��� � ������ ������
			for (int charIndex = arrayIndex[strIndex]; charIndex < strs[strIndex].length(); charIndex++) {
				// ���� ����� ���������� ������� � ������ � �������� �� ������ ������ - ����������� ������� � ��������� ������ ��������� � ������
				if (strs[strIndex][charIndex] == tmp_char) {
					countCheck++;
					arrayIndex[strIndex] = charIndex;
					break;
				}
			}

			// ���� ������� �� ����� ����� �������, �� �� �� ���� ������� ����� ���������� ������, ���� ������ ��������� � ������ ��������
			if (countCheck < strs.size()) {
				countCheck = 1;
				break;
			}
		}
	}

	return 0;
}