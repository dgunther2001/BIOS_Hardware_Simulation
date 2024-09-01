#include "../include/digital_signal/digital_signal.h"

namespace dig_sig {

    dig_signal create_digital_signal() {
        dig_sig::dig_signal returned_signal;
        returned_signal.set_voltage(5);
        return returned_signal;
    }
    
}