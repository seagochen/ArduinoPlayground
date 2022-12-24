//
// Created by Orlando on 10/8/2022.
//

#ifndef _FAKEARDUINOHEADERS_COMMUNICATION_HPP
#define _FAKEARDUINOHEADERS_COMMUNICATION_HPP

#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>

#include <httplib.hpp>

#define SERIAL_5N1 0x00
#define SERIAL_6N1 0x01
#define SERIAL_7N1 0x02
#define SERIAL_8N1 0x03  // the default
#define SERIAL_5N2 0x04
#define SERIAL_6N2 0x05
#define SERIAL_7N2 0x06
#define SERIAL_8N2 0x07
#define SERIAL_5E1 0x08 // even parity
#define SERIAL_6E1 0x09
#define SERIAL_7E1 0x0A
#define SERIAL_8E1 0x0B
#define SERIAL_5E2 0x0C
#define SERIAL_6E2 0x0D
#define SERIAL_7E2 0x0E
#define SERIAL_8E2 0x0F
#define SERIAL_5O1 0x10 // odd parity
#define SERIAL_6O1 0x11
#define SERIAL_7O1 0x12
#define SERIAL_8O1 0x13
#define SERIAL_5O2 0x14
#define SERIAL_6O2 0x15
#define SERIAL_7O2 0x16
#define SERIAL_8O2 0x17


#define BIN 0xF000
#define OCT 0xF001
#define DEC 0xF002
#define HEX 0xF003


class Serial {

private:
    // Serial port baud rate.
    unsigned long baud;

    // Serial port configuration.
    unsigned long config; // not used in the simulation mode.

    // Define a server to receive http requests.
    httplib::Server svr;

    // Buffer to store the data to be received.
    std::string receivedBuffer;

    // Received buffer size.
    unsigned long long receivedBufferSize = 1024;

    // Define a client to send http requests.
    httplib::Client *cli;

    // Buffer to store the feedback from the server.
    std::string feedbackBuffer;

    // Feedback status.
    int feedbackStatus = 0;

    // Feedback buffer size.
    unsigned long long feedbackBufferSize = 1024;

public:

    Serial() {
        receivedBuffer = "";
        this->baud = 0;
        this->config = 0;

        // Create a client instance
        cli = new httplib::Client("localhost", 888);
    }


    ~Serial() {
        // Stop the server.
        if (svr.is_running()) {
            svr.stop();
        }

        // Delete the client instance.
        delete cli;
    }

    /**
     * Sets the data rate in bits per second (baud) for serial data transmission.
     * For communicating with Serial Monitor, make sure to use one of the baud rates listed in the menu at
     * the bottom right corner of its screen. You can, however, specify other rates - for example,
     * to communicate over pins 0 and 1 with a component that requires a particular baud rate.
     * 
     * An optional second argument configures the data, parity, and stop bits.
     * The default is 8 data bits, no parity, one stop bit.
    */
    void begin(unsigned long baud) {
        begin(baud, SERIAL_8N1);
    }

    void begin(unsigned long baud, uint8_t config) {
        this->baud = baud;
        this->config = config;

        // Start the server.
        svr.listen("localhost", this->baud);
    }

    /**
     * Get the number of bytes (characters) available for reading from the serial port. 
     * This is data that’s already arrived and stored in the serial receive receivedBuffer (which holds 64 bytes).
     * Serial.available() inherits from the Stream utility class.
    */
    unsigned long long available() {

        // assemble the url.
        std::string url = "http://localhost:" + std::to_string(this->baud) + "/serial/";

        // GET request
        svr.Get(url, [this](const httplib::Request& req, httplib::Response& res) {
            // Get the data from the request.
            std::string data = req.body;

            // Add the data to the received buffer.
            receivedBuffer = data;

            // Send the response.
            res.set_content("OK", "text/plain");
        });

        // Return the number of bytes available.
        return receivedBuffer.length();
    }

    /**
     * Disables serial communication, allowing the RX and TX pins to be used for general input and output.
     * To re-enable serial communication, call Serial.begin().
    */
    void end() {
        // Stop the server.
        svr.stop();
    }

    /**
     * Get the number of bytes (characters) available for writing in the serial receivedBuffer
     * without blocking the write operation.
    */
    unsigned long long availableForWrite() const {
        return receivedBufferSize - receivedBuffer.length();
    }

    /**
     * Writes binary data to the serial port. This data is sent as a byte or series of bytes;
     * to send the characters representing the digits of a number use the print() function instead.
     */
    template<typename T>
    void write(T val) {
        // Assembly the url.
        std::string url = "/serial/";

        // Use POST request to send the data, all data will be converted to string and wrappped in the body.
        httplib::Params params = { {"val", std::to_string(val)} };
        auto res = cli->Post(url, params);

        // Update the feedback buffer.
        feedbackBuffer = res->body;

        // Update the feedback status.
        feedbackStatus = res->status;
    }

    void write(unsigned char* buf, unsigned long long size) {
        // Assembly the url.
        std::string url = "/serial/";

        // Use POST request to send the data, all data will be converted to string and wrappped in the body.
        httplib::Params params = { {"val", std::to_string(*buf)} };
        auto res = cli->Post(url, params);

        // Update the feedback buffer.
        feedbackBuffer = res->body;

        // Update the feedback status.
        feedbackStatus = res->status;
    }

    /**
     * Prints data to the serial port as human-readable ASCII text. This command can take many forms. Numbers are printed using an ASCII character for each digit. Floats are similarly printed as ASCII digits, defaulting to two decimal places. Bytes are sent as a single character. Characters and strings are sent as is. For example-
     * 
     * Serial.print(78) gives "78"
     * Serial.print(1.23456) gives "1.23"
     * Serial.print('N') gives "N"
     * Serial.print("Hello world.") gives "Hello world."
     * 
     * An optional second parameter specifies the base (format) to use; permitted values are BIN(binary, or base 2), OCT(octal, or base 8), DEC(decimal, or base 10), HEX(hexadecimal, or base 16). For floating point numbers, this parameter specifies the number of decimal places to use. For example-
     * Serial.print(78, BIN) gives "1001110"
     * Serial.print(78, OCT) gives "116"
     * Serial.print(78, DEC) gives "78"
     * Serial.print(78, HEX) gives "4E"
     * Serial.print(1.23456, 0) gives "1"
     * Serial.print(1.23456, 2) gives "1.23"
     * Serial.print(1.23456, 4) gives "1.2346"
     * 
     * You can pass flash-memory based strings to Serial.print() by wrapping them with F(). For example:
     * Serial.print(F("Hello World"))
     * To send data without conversion to its representation as characters, use Serial.write().
     */
    template <typename T>
    void print(T val) {
        // Assembly the url.
        std::string url = "/serial/";

        // Use POST request to send the data.
        httplib::Params params = { {"val", std::to_string(val)} };

        // Send the request.
        auto res = cli->Post(url, params);

        // Update the feedback buffer.
        feedbackBuffer = res->body;

        // Update the feedback status.
        feedbackStatus = res->status;
    }

    template <typename T>
    void print(T val, int format) {
        
        std::string str = "";

        // convert the number to binary string, if format is BIN.
        if (format == BIN) {
            std::bitset<8> binary(val);  // 8 is the number of bits
            str = binary.to_string();
        }

        // convert the number to octal string, if format is OCT.
        else if (format == OCT) {
            std::stringstream ss;
            ss << std::oct << val;
            str = ss.str();
        }

        // convert the number to decimal string, if format is DEC.
        else if (format == DEC) {
            str = std::to_string(val);
        }

        // convert the number to hexadecimal string, if format is HEX.
        else if (format == HEX) {
            std::stringstream ss;
            ss << std::hex << val;
            str = ss.str();
        }

        // else, trim the number to the specified size.
        else {
            str = std::to_string(val).substr(0, format);
        }
        
        // Assembly the url.
        std::string url = "/serial/";

        // Use POST request to send the data.
        httplib::Params params = { {"val", str} };

        // Send the request.
        auto res = cli->Post(url, params);

        // Update the feedback buffer.
        feedbackBuffer = res->body;

        // Update the feedback status.
        feedbackStatus = res->status;
    }
};

/*
find()
findUntil()
flush()
parseFloat()
parseInt()
peek()
print()
println()
read()
readBytes()
readBytesUntil()
readString()
readStringUntil()
setTimeout()
serialEvent()
*/


#endif //_FAKEARDUINOHEADERS_COMMUNICATION_HPP
