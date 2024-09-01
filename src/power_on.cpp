#include "../include/memory/memory.h"
#include "../include/digital_signal/digital_signal.h"
#include "../include/logic_gates/logic_gates.h"
#include "../include/CPU/CPU.h"
#include <iostream>

dig_sig::dig_signal create_digital_signal() {
    dig_sig::dig_signal returned_signal;
    returned_signal.set_voltage(5);
    return returned_signal;
}

void send_and_init_power_signal(double voltage_sent, lff::d_latch& power_latch) {

    std::cout << "\n";
    std::cout << "\033[33m";
    std::cout << "Power on sequence initiated:\n";
    std::cout << "\033[0m";
    dig_sig::dig_signal power_signal = create_digital_signal();
    power_signal.set_voltage(voltage_sent);

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

    std::cout << "\033[32mPower signal at acceptable voltage, routing to power supply latch\033[30m.\n";

    power_latch.change_latch(power_signal.get_sig_bit_value(), power_signal.get_sig_bit_value());

    std::cout << "\033[32mPower supply latch set to: " << power_signal.get_sig_bit_value() << ".\033[30m\n\n";

    if (power_latch.get_Q() != 1) {
        std::cout << "\033[31m";
        std::cout << "Power latch not turning on, aborting boot process.\n";
        std::abort();
    }



}

/*
mem::memory initialize_memory(dig_sig::dig_signal init_memory_signal) {
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
*/

void pre_power_hardware_tests() {
    std::cout << "\033[33mInitiating pre-power-on hardware component checks (logic gates; latches; flip-flops).\033[0m\n";
    logic_gates::logic_gate_tests();
    std::cout << "\033[32m" << "Logic gates passed hardware tests.\n" << "\033[0m";
    lff::l_ff_tests();
    std::cout << "\033[32m" << "Latches passed hardware tests.\n" << "\033[0m";
}

CPU::CPU init_CPU(float voltage) {
    std::cout << "\033[33mInitializing CPU and setting program counter to starting address of ROM\033[0m\n";
    dig_sig::dig_signal CPU_signal = create_digital_signal();
    std::cout <<"\033[32m" << "Digital signal sent to CPU.\n" << "\033[0m";
    CPU::CPU system_CPU(CPU_signal);
    std::cout <<"\033[32m" << "CPU successfully initialized. Program counter set to 0x0.\n" << "\033[0m";
    std::cout << "\n";
    return system_CPU;
}



int main(int argc, char** argv) {
    // verify that our hardware compnents work
    std::cout << "\n";
    pre_power_hardware_tests();

    // instantiate the power supply latch indicating that we have received power, and pass a voltage to the sequence to initiate
    lff::d_latch power_latch;
    send_and_init_power_signal(5, power_latch);

    CPU::CPU system_CPU = init_CPU(5);



    return 0;
}