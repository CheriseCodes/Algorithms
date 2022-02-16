#include <vector>
#include <iostream>
#include <cmath>
#include <random>

int parent(int idx) {
    return floor((double)idx/2);
}

int left(int idx) {
    if (idx == 0) return 1;
    return 2*idx;
}

int right(int idx) {
    if (idx == 0) return 2;
    return 2*idx + 1;
}

void max_heapify(std::vector<int> & in_list, int idx, int heap_size) {
    int left_idx = left(idx);
    int right_idx = right(idx);
    int largest;
    if ((left_idx <= heap_size) && (in_list[left_idx] > in_list[idx])) {
        largest = left_idx;
    } else {
        largest = idx;
    }
    if ((right_idx <= heap_size) && (in_list[right_idx] > in_list[largest])) {
        largest = right_idx;
    }
    if (largest != idx) { // condition where the loop should end
        int temp = in_list[largest];
        in_list[largest] = in_list[idx];
        in_list[idx] = temp;
        max_heapify(in_list, largest, heap_size); // TODO: Translate into iterative algo
    }
}

void build_max_heap(std::vector<int> & in_list) {
    int start_idx = floor((float)(in_list.size()-1)/2);
    int heap_size = in_list.size() - 1;
    for (int i = start_idx; i > -1; --i) {
        max_heapify(in_list, i, heap_size);
    }
}

int partition(std::vector<int> & in_list, int start_idx, int end_idx) {
    // Assumes start_idx < end_idx
    int last_item = in_list[end_idx];
    int i = start_idx -1;
    int temp;
    int j = 1;
    for (j = start_idx; j < end_idx; j++) {
        if (in_list[j] <= last_item) {
            temp = in_list[++i];
            in_list[i] = in_list[j];
            in_list[j] = temp;
        }
    }
    temp = in_list[++i];
    in_list[i] = in_list[j];
    in_list[j] = temp;
    return i++;
}

int randomized_partition(std::vector<int> & in_list, int start_idx, int end_idx) {
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(start_idx, end_idx);
    distrib(gen);
    int i = distrib(gen);
    int temp = in_list[end_idx];
    in_list[end_idx] = in_list[i];
    in_list[i] = temp;
    return partition(in_list,start_idx, end_idx);
}
void randomized_quick_sort(std::vector<int> & in_list, int start_idx, int end_idx) {
    int mid_point;
    if (start_idx < end_idx) {
        mid_point = randomized_partition(in_list, start_idx, end_idx);
        randomized_quick_sort(in_list, start_idx, mid_point - 1);
        randomized_quick_sort(in_list, mid_point + 1, end_idx);
    }
}

void quick_sort(std::vector<int> & in_list, int start_idx, int end_idx) {
    int mid_point;
    if (start_idx < end_idx) {
        mid_point = partition(in_list, start_idx, end_idx);
        quick_sort(in_list, start_idx, mid_point-1);
        quick_sort(in_list, mid_point+1, end_idx);
    }
}

void heap_sort(std::vector<int> & in_list) {
    build_max_heap(in_list);
    int len = in_list.size() - 1;
    int heap_size = len;
    for (int i = len; i > 0; --i) {
        int temp = in_list[0];
        in_list[0] = in_list[i];
        in_list[i] = temp;
        max_heapify(in_list,0,--heap_size);
    }
}

void insertion_sort(std::vector<int> & in_list) {
    int list_len = in_list.size();
    for (int j = 1; j < list_len; j++) {
        int key = in_list[j];
        int i = j - 1;
        // make sure every item before in_list[j] is in sorted order
        while ((i > -1) && (in_list[i] > key)) {
            in_list[i+1] = in_list[i];
            --i;
        }
        in_list[i+1] = key;
    }
}

void counting_sort(std::vector<int> & in_list, std::vector<int> & out_list, int k) {
    std::vector<int> counts;
    int in_list_size = in_list.size();
    int i;
    for (i = 0; i < k+1; i++) {
        counts.push_back(0);
    }
    // count the number of occurrences of each value
    for (i = 0; i < in_list_size; ++i) {
        counts[in_list[i]]++;
    }
    // count the number of elements less than or equal to each element
    for (i = 1; i < in_list_size; i++) {
        counts[i] = counts[i] + counts[i-1];
    }
    // create the sorted array based on counts
    for (i = in_list_size -1; i > -1; i--) {
        out_list[counts[in_list[i]]-1] = in_list[i];
        counts[in_list[i]] = counts[in_list[i]] - 1;
    }
}
