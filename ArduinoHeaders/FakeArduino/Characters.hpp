//
// Created by Orlando on 10/8/2022.
//

#ifndef _FAKEARDUINOHEADERS_CHARACTERS_HPP
#define _FAKEARDUINOHEADERS_CHARACTERS_HPP

/**
 * Analyse if a char is alpha (that is a letter). Returns true if thisChar contains a letter.
*/
bool isAlpha(char thisChar) {
    return (thisChar >= 'a' && thisChar <= 'z') || (thisChar >= 'A' && thisChar <= 'Z');
}

/**
 * Analyse if a char is a digit (that is a number). Returns true if thisChar is a number.
*/
bool isDigit(char thisChar) {
    return thisChar >= '0' && thisChar <= '9';
}

/**
 * Analyse if a char is alphanumeric (that is a letter or a numbers). 
 * Returns true if thisChar contains either a number or a letter.
*/
bool isAlphaNumeric(char thisChar) {
    return isAlpha(thisChar) || isDigit(thisChar);
}

/**
 * Analyse if a char is Ascii. Returns true if thisChar contains an Ascii character.
*/
bool isAscii(char thisChar) {
    return thisChar >= 0 && thisChar <= 127;
}

/**
 * Analyse if a char is a control character. Returns true if thisChar is a control character.
*/
bool isControl(char thisChar) {
    return thisChar >= 0 && thisChar <= 31;
}

/**
 * Analyse if a char is printable with some content (space is printable but has no content). 
 * Returns true if thisChar is printable.
*/
bool isGraph(char thisChar) {
    return thisChar >= 32 && thisChar <= 126;
}

/**
 * Analyse if a char is an hexadecimal digit (A-F, 0-9). Returns true if thisChar contains an hexadecimal digit.
*/
bool isHexadecimalDigit(char thisChar) {
    return isDigit(thisChar) || (thisChar >= 'A' && thisChar <= 'F') || (thisChar >= 'a' && thisChar <= 'f');
}

/**
 * Analyse if a char is lower case (that is a letter in lower case). 
 * Returns true if thisChar contains a letter in lower case.
*/
bool isLowerCase(char thisChar) {
    return thisChar >= 'a' && thisChar <= 'z';
}

/**
 * Analyse if a char is printable (that is any character that produces an output, even a blank space). 
 * Returns true if thisChar is printable.
*/
bool isPrintable(char thisChar) {
    return thisChar >= 32 && thisChar <= 126;
}

/**
 * Analyse if a char is punctuation (that is a comma, a semicolon, an exclamation mark and so on).
 * Returns true if thisChar is punctuation.
*/
bool isPunct(char thisChar) {
    return (thisChar >= 33 && thisChar <= 47) || (thisChar >= 58 && thisChar <= 64) || 
    (thisChar >= 91 && thisChar <= 96) || (thisChar >= 123 && thisChar <= 126);
}

/**
 * Analyse if a char is a white-space character. Returns true if the argument is a space, 
 * form feed ('\f'), newline ('\n'), carriage return ('\r'), horizontal tab ('\t'), or vertical tab ('\v').
*/
bool isSpace(char thisChar) {
    return thisChar == ' ' || thisChar == '\f' || thisChar == '\n' || 
    thisChar == '\r' || thisChar == '\t' || thisChar == '\v';
}

/**
 * Analyse if a char is upper case (that is, a letter in upper case). Returns true if thisChar is upper case.
*/
bool isUpperCase(char thisChar) {
    return thisChar >= 'A' && thisChar <= 'Z';
}

/**
 * Analyse if a char is a space character. Returns true if the argument is a space or horizontal tab ('\t').
*/
bool isWhitespace(char thisChar) {
    return thisChar == ' ' || thisChar == '\t';
}

#endif //_FAKEARDUINOHEADERS_CHARACTERS_HPP
