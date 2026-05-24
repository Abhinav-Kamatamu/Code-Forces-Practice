#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <future>
#include <chrono>

// Threshold: Switch to single-threaded or insertion sort for small arrays
// to avoid the overhead of thread creation.
const int THRESHOLD = 10000;

template <typename T>
void parallel_quicksort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
    auto size = std::distance(begin, end);
    if (size <= 1) return;

    // Partitioning logic
    auto pivot = *std::next(begin, size / 2);
    auto middle1 = std::partition(begin, end, [pivot](const T& em) { return em < pivot; });
    auto middle2 = std::partition(middle1, end, [pivot](const T& em) { return !(pivot < em); });

    // Parallel execution if the workload is large enough
    if (size > THRESHOLD) {
        // Run the left part in a new thread/async task
        auto handle = std::async(std::launch::async, [&]() {
            parallel_quicksort<T>(begin, middle1);
        });
        
        // Current thread handles the right part
        parallel_quicksort<T>(middle2, end);
        
        handle.wait();
    } else {
        // Sequential fallback for small sub-arrays
        std::sort(begin, middle1);
        std::sort(middle2, end);
    }
}

int main() {
    const size_t NUM_COUNT = 1'000'000'000; // 1 Million numbers
    std::vector<int> data(NUM_COUNT);

    // Generate random numbers
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 100'000);
    for (auto& n : data) n = dist(rng);

    std::cout << "Sorting " << NUM_COUNT << " numbers..." << std::endl;

    // Timing the execution
    auto start = std::chrono::high_resolution_clock::now();
    
    parallel_quicksort<int>(data.begin(), data.end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    // Verification
    if (std::is_sorted(data.begin(), data.end())) {
        std::cout << "Success! Time taken: " << diff.count() << " seconds." << std::endl;
    } else {
        std::cout << "Sorting failed." << std::endl;
    }

    return 0;
}
