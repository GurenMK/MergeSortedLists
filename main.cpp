//Alexander Urbanyak

#include <iostream>
#include <cstdlib>
#include <list>
#include <cassert>
#include <iterator>

using namespace std;

list<int>* create_list1();
// returned a list of integers sorted in strictly increasing order

list<int>* create_list2();
// returned a list of integers sorted in strictly increasing order

template <typename T>
list<T>* merge_sorted_lists (const list<T>& l1, const list<T>& l2);
// preconditions: l1 & l2 are sorted in strictly increasing order
// returned: list of all elements from l1 & l2 with duplicates removed
//           and sorted in strictly increasing order

template <typename T>
void display_list (const list<T> l);
// postcondition: elements from l3 have been displayed on standard
//                output

template <typename T>
bool is_sorted (const list<T>& l);
// returned whether elements in l are sorted in increasing order

int main(int argc, char **argv)
{
    list<int>* l1 = create_list1();
    list<int>* l2 = create_list2();
    list<int>* l3 = merge_sorted_lists ( *l1, *l2 );
    display_list ( *l3 );

    return EXIT_SUCCESS;
}

list<int>* create_list1() {
    list<int>* l1 = new list<int>;
    l1->push_back(1);
    l1->push_back(2);
    l1->push_back(3);
    l1->push_back(4);
    l1->push_back(5);
    return l1;
}

list<int>* create_list2() {
    list<int>* l2 = new list<int>;
    l2->push_back(5);
    l2->push_back(6);
    l2->push_back(7);
    l2->push_back(8);
    l2->push_back(9);
    return l2;
}

template <typename T>
list<T>* merge_sorted_lists (const list<T>& l1, const list<T>& l2) {
    assert(is_sorted(l1));
    assert(is_sorted(l2));

    list<int>* l3 = new list<int>;

    list<int>::const_iterator list1 = l1.begin();
    list<int>::const_iterator list2 = l2.begin();
    while (list1 != l1.end() || list2 != l2.end()) {
        if (*list1 < *list2) {
            if (list1 != l1.end()) {
                l3->push_back(*list1);
                ++list1;
            }
            else {
                l3->push_back(*list2);
                ++list2;
            }
        }
        else if (*list1 == *list2) {
            if (list1 == l1.end()) {
                l3->push_back(*list1);
                ++list2;
            }
            else if (list2 == l2.end()) {
                l3->push_back(*list2);
                ++list1;
            }
            else {
                l3->push_back(*list2);
                ++list1;
                ++list2;
            }
        }
        else {
            l3->push_back(*list2);
            ++list2;
        }
    }
    return l3;
}

template <typename T>
void display_list (const list<T> l) {
    for (list<int>::const_iterator list = l.begin(); list != l.end(); ++list) {
        cout << *list << " ";
    }
    cout << endl;
}

template <typename T>
bool is_sorted (const list<T>& l) {
    list<int>::const_iterator head = l.begin();
    list<int>::const_iterator next = l.begin();
    list<int>::const_iterator tail = l.end();

    if (head == tail) {
        return true;
    }

    while (++next != tail) {
        if (*next < *head) {
            return false;
        }
        ++head;
    }
    return true;
}