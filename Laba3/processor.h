#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cctype>
template <typename List>
void remove_digits(List& lst) {
    for (char d = '0'; d <= '9'; ++d) {
        lst.remove(d);
    }
}
template <typename List>
void double_signs(List& lst) {
    auto it = lst.begin();
    int idx = 0;
    while (it != lst.end()) {
        char c = *it;
        if (c == '+' || c == '-') {
            lst.insert(idx + 1, c);
            ++it; 
            ++it; 
            idx += 2;
        } else {
            ++it;
            ++idx;
        }
    }
}
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

#endif