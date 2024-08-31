#include "../include/memory/memory.h"
#include "../include/digital_signal/digital_signal.h"
#include <iostream>

dig_sig::dig_signal send_and_init_power_signal(double voltage_sent) {
    std::cout << "\033[32m";
    std::cout << "Power on sequence started:\n";
    std::cout << "\033[0m";
    dig_sig::dig_signal power_signal = dig_sig::dig_signal();
    power_signal.set_voltage(voltage_sent);
    std::cout << "Current Voltage of Power On Signal: " << power_signal.get_voltage() << ".\n";
    if (power_signal.is_voltage_high()) {
        std::cout << "\033[31m";
        std::cout << "Power signal too high (> 5.09 V), aborting boot process.\n";
        std::abort();
    }
    if (power_signal.is_voltage_low()) {
        std::cout << "\033[31m";
        std::cout << "Power signal too low (< 4.91 V), aborting boot process.\n";
        std::abort();
    }
    std::cout << "Power signal in range (4.9 V, 5.1 V), proceeding with boot process.\n";
    std::cout << "\n";

    return std::move(power_signal);
}

mem::memory initialize_memory() {
    mem::memory system_memory = mem::memory(); // initialize system memory
    std::cout << "\033[32m";
    std::cout << "Memory recognition and initialization sequence started:\n";
    std::cout << "\033[0m";
    if (!system_memory.is_initialized()) {
        std::cout << "\033[31m";
        std::cout << "System memory unrecognized, aborting boot process.\n";
        std::abort();
    }
    std::cout << "System memory recognized, proceeding with boot process.\n";
    std::cout << "\n";
    
    return system_memory;
}

int main(int argc, char** argv) {
    std::cout << "\n";
    dig_sig::dig_signal power_on_signal = send_and_init_power_signal(5);
    mem::memory system_memory = initialize_memory();


    return 0;
}