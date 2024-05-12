#include "libs/algorithms/matrix_transposition.h"
#include "libs/algorithms/convert_float.h"
#include "libs/algorithms/evaluate_expression.h"
#include "libs/algorithms/filter_word.h"
#include "libs/algorithms/leave_longest_word.h"
#include "libs/algorithms/remove_true_polynomial.h"
#include "libs/algorithms/rearrange_numbers.h"
#include "libs/algorithms/transpose_non_symmetric_matrix.h"

int main(){
    test_matrix_transpose();
    test_convert_float();
    test_evaluate();
    test_filter_word();
    test_leave_longest();
    test_remove_true_polynomial();
    test_rearrange_numbers();
    test_transpose_non_symmetric_matrix();
}
