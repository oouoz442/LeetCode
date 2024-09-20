#include <iostream>
#include <vector>

/*
* Write a function to find the longest common prefix string amongst an array of strings.
1. Берем первую строку в векторе.
2. В первой строке по очереди рассматриваем каждый символ.
3. В каждой следующей строке проверяем наличие такого же символа. Если он есть во всех строках - сохраняем индекс вхождения в каждой строке в отдельный массив индексов. Имеем уже минимальный ответ - вхождение 1 символа в каждую строку. (Или же во всех строках нет одинакового символа и ответ - 0 одинаковых вхождений во всех строках)
4. Имея массив с индексами вхождения одинакового символа во всех строках - проверяем сходство следующего после него символа в каждой строке.
5. Если он тоже совпадает во всех строках - ответ увеличивается на 1 символ.
6. Остановилось сходство - ищем сходства в строках дальше.
7. Нашли ещё одно вхождение во всех строках - ищем максимальную длину сходства во всех строках и сравниваем с предыдущим ответом, какой длиннее.
*/


// Проблема с массивом индексов. Нужно сделать динамический массив или придумать что-то другое. Сохранить в векторе или в листе к примеру, хз.

int main()
{
	std::vector<std::string> strs{"flower", "flow", "flight"};
	const int arraySize = strs.size();
	int tmp_int{}, resultInt{}, countCheck{1}, arrayIndex[arraySize];
	bool check{ 1 };
	char tmp_char{};
	std::string resultStr{}, tmp_str{};

	// Берем первую строку в векторе и рассматриваем по очереди каждый её символ.
	for (int charIndexFirstStr = 0; charIndexFirstStr < strs[0].length(); charIndexFirstStr++) {
		tmp_char = strs[0][charIndexFirstStr]; // Символ первой строки
		tmp_int = charIndexFirstStr; // Индекс символа первой строки
		arrayIndex[0] = tmp_int;
		tmp_str += tmp_char;

		// Далее по очереди рассматриваем каждую следующую строку
		for (int strIndex = 1; strIndex < strs.size(); strIndex++) {
			// В каждой следующей строке проверяем наличие такого же символа как в первой строке
			for (int charIndex = arrayIndex[strIndex]; charIndex < strs[strIndex].length(); charIndex++) {
				// Если нашли совпадение символа в строке с символом из первой строки - увеличиваем счетчик и сохраняем индекс вхождения в массив
				if (strs[strIndex][charIndex] == tmp_char) {
					countCheck++;
					arrayIndex[strIndex] = charIndex;
					break;
				}
			}

			// Если счетчик не равен длине вектора, то не во всех строках нашли одинаковый символ, ищем дальше сравнение с другим символом
			if (countCheck < strs.size()) {
				countCheck = 1;
				break;
			}
		}
	}

	return 0;
}