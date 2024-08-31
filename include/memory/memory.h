#ifndef MEMORY_H
#define MEMORY_H

#include <random>

#define MEMORY_SIZE 1024
namespace mem {

    class memory {
        private:
            int system_memory[MEMORY_SIZE];
            bool initialized;

        public:
            memory() : initialized(false)
                {
                    std::random_device random_seed;
                    std::mt19937 generator(random_seed());
                    std::uniform_real_distribution<> noise_dist(0.0, 1.0);

                    if (noise_dist(generator) >= 0.05) {
                        initialized = true;
                    }
                }

            bool is_initialized() {
                return initialized;
            }
    };
    
}

#endif


