#include "string/tasks/strlen_.h"
#include "string/tasks/search functions.h"
#include "string/tasks/strcmp_.h"

int main() {
    test_strlen_();
    test_find();
    test_find_non_space();
    test_find_space();
    test_find_non_space_reverse();
    test_find_space_reverse();
    test_strcmp_();

    return 0;
}

