#include <vector>
#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include <map>
#include <iterator>
#include <forward_list>

/*
Notes on sorting:
- In place: Sort the array such that only a constant amount of 
  additional space is used
- Stable: Sort the array such that items appear in the same order as
  in the input array
- Being able to make an assumption about the input and designing 
the algorithm around that assumption can reduce runtimes
*/

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
/*
template <typename T>
void print_vector(std::vector<T> & v) {
    int len = v.size();
    if (len == 0) std::cout << "v = { }\n";
    std::cout << "v = { " << v[0];
    for (int i = 1; i < len ; i++) {
        std::cout << ", " << v[i] ;
    }
    std::cout << " }; \n";
}*/

/*
Assumes every element in in_list is in the range [0, k]
*/
void counting_sort(std::vector<int> & in_list, std::vector<int> & out_list, int sig_digit) {
    
    int in_list_size = in_list.size();
    // create new array of significant digits
    std::vector<int> counts(10,0);
    int i;
    // count the number of occurrences of each value
    for (i = 0; i < in_list_size; ++i) {
        counts[(in_list[i] / sig_digit) % 10]++;
    }
    // count the number of elements less than or equal to each element
    for (i = 1; i < 10; i++) {
        counts[i] += counts[i-1];
    }
    // create the sorted array based on counts
    int j;
    for (i = in_list_size -1; i > -1; i--) {
        j = (in_list[i] / sig_digit) % 10;
        out_list[counts[j]-1] = in_list[i];
        counts[j]--;
    }
}
/*
void print_map(std::map<int, int> in_map) {
    for(std::map<int, int>::iterator it = in_map.begin(); it != in_map.end(); ++it) {
            std::cout << it->first << " " << it->second << "\n";
        }
}*/

// Sorts vectors where all the elements have a constant number of digits
void radix_sort(std::vector<int> & in_list) {
    int max = std::max_element(in_list.begin(), in_list.end())[0];
    int in_list_size = in_list.size();
    std::vector<int> out_list(in_list_size, 0);

    int exp_acc; // exponential accumulator for powers of 10
    // perform stable counting sort on each digit from least significant
    // to most significant
    for (exp_acc = 1; max / exp_acc > 0; exp_acc*=10) {
            counting_sort(in_list,out_list, exp_acc);
            in_list = out_list;
        }
}

/**
 * @brief Assumes that input is drawn from a uniform distribution
 *  of [0, 1).
 * Average run time: O(n)
 */
void bucket_sort(std::vector<double> & in_list) {
    std::vector<std::forward_list<double>> buckets(10,std::forward_list<double>(0));
    int list_size = in_list.size();
    // assign each item to it's correct bucket range
    for (double num : in_list) {
        buckets[floor(list_size*num)].push_front(num);
    }
    int i;
    // sort each bucket range
    for (i=0; i < 10;i++) {
        buckets[i].sort();
    }
    // combine the bucket ranges to form the output list
    int j = 0;
    for (i=0; i < 10;i++) {
        for (double num: buckets[i]) {
            in_list[j] = num;
            j++;
        }
    }

}
