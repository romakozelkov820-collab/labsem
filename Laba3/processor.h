#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cctype>

// remove all digit characters '0'..'9' from list
template <typename List>
void remove_digits(List& lst) {
    for (char d = '0'; d <= '9'; ++d) {
        lst.remove(d);
    }
}

// double '+' and '-' characters by inserting duplicate after each occurrence
template <typename List>
void double_signs(List& lst) {
    // iterate with iterator and maintain index for insert()
    auto it = lst.begin();
    int idx = 0;
    while (it != lst.end()) {
        char c = *it;
        if (c == '+' || c == '-') {
            // insert duplicate at idx+1
            lst.insert(idx + 1, c);
            // advance iterator twice: to inserted, then to the element after inserted
            ++it; // now points to the inserted duplicate
            ++it; // now points to next original element (or end)
            idx += 2;
        } else {
            ++it;
            ++idx;
        }
    }
}

// reverse list if size is even
template <typename List>
void reverse_if_even(List& lst) {
    if (lst.size() % 2 == 0) lst.reverse();
}

template <typename List>
void process_string_list(List& lst) {
    remove_digits(lst);
    double_signs(lst);
    reverse_if_even(lst);
}

#endif // PROCESSOR_H