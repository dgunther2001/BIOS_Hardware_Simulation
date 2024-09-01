#ifndef DIGITAL_SIGNAL_H
#define DIGITAL_SIGNAL_H

#include <iostream>
#include <random>
#include <thread>
#include <chrono>

namespace dig_sig {

    class dig_signal {
        private:
            double voltage;
            bool signal_on;

            std::mt19937 noise_rand;
            std::uniform_real_distribution<> noise;
        public:
            dig_signal(double init_voltage = 0.0) :
                voltage(init_voltage),
                signal_on(true),
                noise_rand(std::random_device{}()),
                noise(-0.1, 0.1)
                {}
            
            void set_voltage(double new_voltage) {
                voltage = new_voltage;
                apply_sig_noise();
            }

            const double get_voltage() {
                return voltage;
            }

            bool is_voltage_high() { // based on a 5v system
                return voltage > 5.09;
            }

            bool is_voltage_low() {
                return (voltage < 4.91 && signal_on == true);
            }

            bool acceptable_voltage() {
                return !(is_voltage_low() && is_voltage_high());
            }

            bool get_sig_bit_value() { // add check condition later to deal with a voltage that is too high..
                if (voltage > 5.1 || voltage < 4.9) {
                    return false;
                }
                return true;
            }

            void apply_sig_noise() {
                double noise_add = noise(noise_rand);
                voltage += noise_add;
            }
    };

    dig_signal create_digital_signal();

}


#endif