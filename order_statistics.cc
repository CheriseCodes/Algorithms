#include <vector>
#include <iostream>
#include <ctime>
#include "sorting.h"
#include "algoutils.h"
/*
Median and order statistics notes:
- i-th order statistic it the i-th smallest element of a set
of n elements
- In CLRS, median is lower median which is i = floor((n+1)/2)
*/

int minimum(std::vector<int> & v) {
    int min = v[0];
    int v_size = v.size();
    int i;
    for (i = 1; i < v_size; i++) {
        if (min > v[i])
            min = v[i];
    }
    return min;
}

int maximum(std::vector<int> & v) {
    int max = v[0];
    int v_size = v.size();
    int i;
    for (i = 1; i < v_size; i++) {
        if (max < v[i])
            max = v[i];
    }
    return max;
}
/**
 * @brief Randomly selects an integer from the vector v. Due to it's randomized nature,
 * the function may recursively call itself too many times and run into a segfault.
 * 
 * @param v : a vector of integers
 * @param start_idx : the left index of the first partition
 * @param end_idx : the right index of the first partition
 * @param curr_idx : the first index to compare to the first parition
 * @return int : a randomly selected integer from v
 */
int randomized_select_recursive(std::vector<int> & v, int start_idx, int end_idx, int curr_idx) {
    if (start_idx == end_idx) {
        print_vector(v);
        return v[start_idx];
    }
    int mid_point = randomized_partition(v, start_idx, end_idx);
    int less_than_mid = mid_point - start_idx + 1;
    if (curr_idx == less_than_mid) {
        print_vector(v);
        return v[mid_point];
    } else if (curr_idx < less_than_mid) {
        end_idx = mid_point-1;
        if (end_idx > (v.size() - 1)) {
            end_idx = v.size() - 1;
        }
        return randomized_select_recursive(v, start_idx, end_idx, curr_idx);
    } else {
        start_idx = mid_point+1;
        if (start_idx > (v.size() - 1)) {
            start_idx = v.size() - 1;
        }
        curr_idx = curr_idx - less_than_mid;
        if (curr_idx < 0) {
            curr_idx = 0;
        }
        return randomized_select_recursive(v, start_idx, end_idx, curr_idx);
    }
}

/**
 * @brief Randomly selects an integer from the vector v. To prevent an infinite loop, returns 
 * a randomly selected mid point after too many loop iterations.
 * 
 * @param v : a vector of integers
 * @param start_idx : the left index of the first partition
 * @param end_idx : the right index of the first partition
 * @param curr_idx : the first index to compare to the first parition
 * @return int : a randomly selected integer from v
 */
int randomized_select_iterative(std::vector<int> & v, int start_idx, int end_idx, int curr_idx) {
    int mid_point = randomized_partition(v, start_idx, end_idx);
    int less_than_mid = mid_point - start_idx + 1;
    int i = 0;
    while ((curr_idx != less_than_mid) && (start_idx != end_idx) && (i < 500)) {
        if (curr_idx < less_than_mid) {
            end_idx = mid_point - 1;
            if (end_idx > (v.size() - 1)) {
                end_idx = v.size() - 1;
            }
        } else {
            start_idx = mid_point+1;
            curr_idx = curr_idx - less_than_mid;
            if (start_idx > (v.size() - 1)) {
            start_idx = v.size() - 1;
            }
            if (curr_idx < 0) {
                curr_idx = 0;
            }
        }
        mid_point = randomized_partition(v, start_idx, end_idx);
        i++;
    }
    if (curr_idx == less_than_mid) {
        return v[mid_point];
    } else if (start_idx == end_idx) {
        return v[start_idx];
    } else {
        return v[mid_point];
    }
}