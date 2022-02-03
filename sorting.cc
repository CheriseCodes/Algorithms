#include <vector>
#include <iostream>
#include <cmath>
//#include "algoutils.h"

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
        //print_vector(in_list);
    }
}
