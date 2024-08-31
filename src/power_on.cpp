#include "../include/memory/memory.h"
#include "../include/digital_signal/digital_signal.h"
#include <iostream>

dig_sig::dig_signal send_and_init_power_signal(double voltage_sent) {
    std::cout << "Power on sequence started.\n";
    dig_sig::dig_signal power_signal = dig_sig::dig_signal();
    power_signal.set_voltage(voltage_sent);
    std::cout << "Current Voltage of Power On Signal: " << power_signal.get_voltage() << ".\n";
    if (power_signal.is_voltage_high()) {
        std::cout << "Power signal too high (> 5.09 V), aborting boot process.\n";
        std::abort();
    }
    if (power_signal.is_voltage_low()) {
        std::cout << "Power signal too low (< 4.91 V), aborting boot process.\n";
        std::abort();
    }

    return std::move(power_signal);
}

int main(int argc, char** argv) {
    dig_sig::dig_signal power_on_signal = send_and_init_power_signal(5);
    return 0;
}