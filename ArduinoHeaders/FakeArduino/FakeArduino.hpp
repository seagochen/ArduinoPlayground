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
#include "Characters.hpp"
#include "BitsArray.hpp"
#include "ExternalInterrupts.hpp"
#include "Interrupts.hpp"
#include "Communication.hpp"
#include "RandomNumbers.hpp"
#include "USB.hpp"
#include "Utilities.hpp"
#include "Trigonometry.hpp"

#ifdef HIGH
#undef HIGH
#define HIGH 0x1
#endif

#ifdef LOW
#undef LOW
#define LOW 0x0
#endif

#ifdef INPUT
#undef INPUT
#define INPUT 0x0
#endif

#ifdef OUTPUT
#undef OUTPUT
#define OUTPUT 0x1
#endif

#ifdef INPUT_PULLUP
#undef INPUT_PULLUP
#define INPUT_PULLUP 0x2
#endif

#ifdef LED_BUILTIN
#undef LED_BUILTIN
#define LED_BUILTIN 13
#endif


int main() {
    // To set parameters or configurations here
    setup();

    // To loop for events handling
    loop();

    // Finished
    return 0;
}

#endif //_FAKEARDUINOHEADERS_FAKEARDUINO_HPP
