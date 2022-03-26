#ifndef SORTING_H_
#define SORTING_H_

void insertion_sort(std::vector<int> & in_list);

void max_heapify(std::vector<int> & in_list, int idx);

void build_max_heap(std::vector<int> & in_list);

void heap_sort(std::vector<int> & in_list);

void quick_sort(std::vector<int> & in_list, int start_idx, int end_idx);

void randomized_quick_sort(std::vector<int> & in_list, int start_idx, int end_idx);

void counting_sort(std::vector<int> & in_list, std::vector<int> & out_list, int sig_digit);

void radix_sort(std::vector<int> & in_list);

void bucket_sort(std::vector<double> & in_list);

int randomized_partition(std::vector<int> & in_list, int start_idx, int end_idx);

#endif  // SORTING_H_
