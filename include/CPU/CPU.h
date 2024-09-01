#ifndef CPU_H
#define CPU_H

#include "../mem_cell/mem_cell.h"
#include "../digital_signal/digital_signal.h"
#include <iostream>

namespace CPU {

    class CPU {
        private:
            mem_cell::mem_cell pc;
            bool active;
        
        public:
            CPU(dig_sig::dig_signal signal) {
                if (!signal.acceptable_voltage()) {
                    std::cout << "\033[31m" << "Voltage passed to CPU not in acceptable range, aborting boot process\n";
                    std::abort();
                }

                for (int i = 0; i < 4; i++) { // reset the pc to 0
                    pc.set_cell(0, i);
                }
            }
    };

}

#endif