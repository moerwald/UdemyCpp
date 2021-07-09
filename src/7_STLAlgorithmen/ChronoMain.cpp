#include "ChronoMain.h"

#include <vector>
#include <iostream>
#include <random>
#include <chrono>

using time_interval = std::chrono::milliseconds;

int ChronoMain::main()
{
    constexpr std::size_t NUM_OF_ELEMENTS = 1'000'000;

    std::vector<int> my_vector(NUM_OF_ELEMENTS, 0);

    // Create random object 
    std::random_device seed_generator;
    std::mt19937 random_generator(seed_generator());
    std::uniform_int_distribution<int> random_distribution(-10, 10);

    // Start stopwatch
    auto start_time = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < NUM_OF_ELEMENTS; i++)
    {
        my_vector[i] = random_distribution(random_generator);
    }

    // End stopwatch
    auto end_time = std::chrono::high_resolution_clock::now();

    // Caculate duration in milliseconds
    auto elapsed = std::chrono::duration_cast<time_interval>(end_time - start_time).count();

    std::cout << "Program took " << elapsed << " msec." << std::endl;

        return 0;
}
