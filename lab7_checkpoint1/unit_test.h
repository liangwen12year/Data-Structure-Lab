#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_wliang_init_default_returns_nonNULL(char* buffer, int length);
Status test_wliang_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_wliang_init_c_string_correctly_assigns_size(char* buffer, int length);
Status test_wliang_my_string_compare(char* buffer, int length);
Status test_wliang_my_string_at(char* buffer, int length);
Status test_wliang_my_string_push_back(char* buffer, int length);
Status test_wliang_my_string_get_capacity_on_init_c_string(char* buffer, int length);
Status test_wliang_my_string_concat(char* buffer, int length);
Status test_wliang_my_string_empty_after_init_c_string(char* buffer, int length);
Status test_wliang_my_string_popback_and_my_string_get_size(char* buffer, int length);
Status test_wliang_my_string_push_back_and_my_string_get_capacity(char* buffer, int length);
Status test_wliang_my_string_get_capacity_on_init_default_returns_7(char* buffer, int length);
Status test_wliang_my_string_empty_after_init_default(char* buffer, int length);
Status test_wliang_pop_back_on_empty_my_string_object(char* buffer, int length);
Status test_wliang_resize_feature_within_my_string_pushback(char* buffer, int length);
Status test_wliang_loop_of_pop_back_on_my_string_object(char* buffer, int length);
Status test_wliang_my_string_compare_with_larger_left_string(char* buffer, int length);
Status test_wliang_my_string_compare_with_larger_right_string(char* buffer, int length);
Status test_wliang_popback_and_pushback_on_init_default(char* buffer, int length);
Status test_wliang_my_string_extraction_on_dictionary_dot_txt(char* buffer, int length);
Status test_wliang_my_string_extraction_loop_till_false(char* buffer, int length);
Status test_wliang_init_c_string_returns_nonNULL(char* buffer, int length);
Status test_wliang_my_string_pushback_and_my_string_at(char* buffer, int length);
Status test_wliang_my_c_str(char* buffer, int length);
Status test_wliang_string_at_returns_NULL_if_index_is_greater_than_capacity(char* buffer, int length);


#endif
