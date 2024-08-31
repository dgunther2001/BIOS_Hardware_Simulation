#ifndef LOGIC_GATES_H
#define LOGIC_GATES_H

#include <cassert>
#include <iostream>

namespace logic_gates {

    bool AND(bool bit1, bool bit2);
    bool OR(bool bit1, bool bit2);
    bool XOR(bool bit1, bool bit2);
    bool NOT(bool bit1);
    bool NOR(bool bit1, bool bit2);
    bool XNOR(bool bit1, bool bit2);
    bool NAND(bool bit1, bool bit2);

    void logic_gate_tests();

}

namespace lff {


    class d_latch {
        private:
            bool Q;
            bool nQ;
        
        public:
            d_latch() : 
                Q(0),
                nQ(1)
                {}

            bool get_Q() const {
                return Q;
            }

            bool get_nQ() const {
                return nQ;
            }

            void change_latch(bool G, bool D) {
                if (G == 1) {
                    Q = D;
                    nQ = logic_gates::NOT(D);
                }
            }
    };

    void l_ff_tests();
   
}



#endif