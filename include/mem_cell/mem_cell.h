#ifndef MEM_CELL_H
#define MEM_CELL_H

#include "../logic_gates/logic_gates.h"

namespace mem_cell {

    class mem_cell {
        private:
            lff::d_latch cell[4];

        public:
            mem_cell() {
                for (lff::d_latch latch : cell) {
                    latch.change_latch(1, 0); // set all cells too 0
                }
            }

            bool get_cell(int bit_num) {
                return cell[bit_num].get_Q();
            }

            void set_cell(bool bit_val, int bit_num) {
                cell[bit_num].change_latch(1, bit_val); // sets the value of a particular latch in the memory cell
            }

    };

}

#endif