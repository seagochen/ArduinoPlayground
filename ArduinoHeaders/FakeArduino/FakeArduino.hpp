//
// Created by Orlando on 10/8/2022.
//

#ifndef _FAKEARDUINOHEADERS_FAKEARDUINO_HPP
#define _FAKEARDUINOHEADERS_FAKEARDUINO_HPP

/// The setup method for user defining.
extern void setup();

/// The loop method for user defining.
extern void loop();

/// To include internal methods so the playground can be available for testing code.
#include "DigitalIO.hpp"
#include "AnalogIO.hpp"
#include "AdvancedIO.hpp"
#include "Timer.hpp"
#include "Math.hpp"
#include "Trigonometry.hpp"
#include "Characters.hpp"
#include "RandomNumbers.hpp"
#include "BitsArray.hpp"
#include "ExternalInterrupts.hpp"
#include "Interrupts.hpp"
#include "Communication.hpp"
#include "USB.hpp"

int main() {
    // To set parameters or configurations here
    setup();

    // To loop for events handling
    loop();

    // Finished
    return 0;
}

#endif //_FAKEARDUINOHEADERS_FAKEARDUINO_HPP
