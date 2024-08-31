#include "../include/logic_gates/logic_gates.h"

namespace logic_gates {

    bool AND(bool bit1, bool bit2) {
        return (bit1 & bit2); 
    }

    bool OR(bool bit1, bool bit2) {
        return bit1 | bit2;
    }

    bool XOR(bool bit1, bool bit2) {
       // boolresult; 
        //result.bool= (bit1.bool^ bit2.bit); 
        //return result;  
        return bit1 ^ bit2;
    }

    bool NOT(bool bit1) {
        return !bit1;
    }

    bool NOR(bool bit1, bool bit2) {
        return NOT(OR(bit1, bit2));
    }

    bool XNOR(bool bit1, bool bit2) {
        return NOT(XOR(bit1, bit2));
    }

    bool NAND(bool bit1, bool bit2) {
        return NOT(AND(bit1, bit2));
    }


    void logic_gate_tests() {
        assert(AND(0, 0) == 0);
        assert(AND(0, 1) == 0);
        assert(AND(1, 0) == 0);
        assert(AND(1, 1) == 1);

        assert(OR(0, 0) == 0);
        assert(OR(0, 1) == 1);
        assert(OR(1, 0) == 1);
        assert(OR(1, 1) == 1);

        assert(XOR(0, 0) == 0);
        assert(XOR(0, 1) == 1);
        assert(XOR(1, 0) == 1);
        assert(XOR(1, 1) == 0);

        assert(NOT(0) == 1);
        assert(NOT(1) == 0);

        assert(NOR(0, 0) == 1);
        assert(NOR(0, 1) == 0);
        assert(NOR(1, 0) == 0);
        assert(NOR(1, 1) == 0);

        assert(XNOR(0, 0) == 1);
        assert(XNOR(0, 1) == 0);
        assert(XNOR(1, 0) == 0);
        assert(XNOR(1, 1) == 1);

        assert(NAND(0, 0) == 1);
        assert(NAND(0, 1) == 1);
        assert(NAND(1, 0) == 1);
        assert(NAND(1, 1) == 0);

    }

}

namespace lff {

    void l_ff_tests() {
        d_latch dl;

        dl.change_latch(1, 0); // reset
        assert(dl.get_Q() == 0);
        assert(dl.get_nQ() == 1);

        dl.change_latch(0, 0); // hold
        assert(dl.get_Q() == 0);
        assert(dl.get_nQ() == 1);

        dl.change_latch(0, 1); // hold
        assert(dl.get_Q() == 0);
        assert(dl.get_nQ() == 1);

        dl.change_latch(1, 1); // set
        assert(dl.get_Q() == 1);
        assert(dl.get_nQ() == 0);

        dl.change_latch(0, 1); // hold
        assert(dl.get_Q() == 1);
        assert(dl.get_nQ() == 0);

        dl.change_latch(0, 0); // hold
        assert(dl.get_Q() == 1);
        assert(dl.get_nQ() == 0);

    }

}