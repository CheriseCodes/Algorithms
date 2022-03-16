#ifndef ORDER_STATISTICS_H
#define ORDER_STATISTICS_H

int minimum(std::vector<int> & v);

int randomized_select_recursive(std::vector<int> & v, int start_idx, int end_idx, int curr_idx);

int randomized_select_iterative(std::vector<int> & v, int start_idx, int end_idx, int curr_idx);

#endif  // ORDER_STATISTICS_H_