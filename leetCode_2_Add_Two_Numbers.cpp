#include <iostream>
#include <list>

/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

static std::list<int> addTwoLists(std::list<int> l1, std::list<int> l2);
void static outputList(std::list<int> l);

int main()
{
    std::list<int> l1{ 9,9,9,9,9,9,9 };
    std::list<int> l2{ 9,9,9,9 };

    addTwoLists(l1, l2);

    return 0;
}



void static outputList(std::list<int> l) {
    for (int n : l)
        std::cout << n << "\t";
    std::cout << std::endl;
}



static std::list<int> addTwoLists(std::list<int> l1, std::list<int>l2) {
    std::list<int> l3{};
    bool extra{ 0 };

    // In case of different list sizes push 0's to the lowest list
    if (l1.size() != l2.size()) {
        if (l1.size() > l2.size()) {
            for (int i = (l1.size() - l2.size()); i < l1.size() - 1; i++) {
                l2.push_front(0);
            }
        }
        else {
            for (int i = (l2.size() - l1.size()); i < l2.size() - 1; i++) {
                l1.push_front(0);
            }
        }
    }

    outputList(l1);
    outputList(l2);

    // From last to first element in list sum numbers from lists, result in new list
    for (auto it1 = (l1.rbegin()), it2 = l2.rbegin(); it1 != l1.rend(); it1++, it2++) {
        if (*it1 + *it2 + extra < 10) {
            l3.push_front(*it1 + *it2 + extra);
            extra = 0;
        }
        else {
            l3.push_front((*it1 + *it2 + extra) % 10);
            extra = 1;
        }
    }

    // If last sum of numbers was > 10, we need to add '1'
    if (extra == 1)
        l3.push_front(extra);
    l3.reverse();

    outputList(l3);

    return l3;
}
