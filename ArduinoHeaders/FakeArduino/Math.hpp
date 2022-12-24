//
// Created by Orlando on 10/8/2022.
//

#ifndef _FAKEARDUINOHEADERS_MATH_HPP
#define _FAKEARDUINOHEADERS_MATH_HPP

/**
 * Calculates the absolute value of a number.
*/
template<typename T>
T abs(T x) {
	return x > 0 ? x : -x;
}

/**
 * Constrains a number to be within a range.
*/
template<typename T>
T constrain(T x, T a, T b) {
    return x < a ? a : (x > b ? b : x);
}

/**
 * Re-maps a number from one range to another. That is, a value of fromLow would get mapped to toLow, 
 * a value of fromHigh to toHigh, values in-between to values in-between, etc.
 * 
 * Does not constrain values to within the range, because out-of-range values are sometimes intended and useful. 
 * The constrain() function may be used either before or after this function, if limits to the ranges are desired.
 * 
 * Note that the "lower bounds" of either range may be larger or smaller than the "upper bounds" 
 * so the map() function may be used to reverse a range of numbers, for example
 * 
 * y = map(x, 1, 50, 50, 1);
 * 
 * The function also handles negative numbers well, so that this example
 * 
 * y = map(x, 1, 50, 50, -100);
 * 
 * is also valid and works well.
 * 
 * The map() function uses integer math so will not generate fractions, 
 * when the math might indicate that it should do so. Fractional remainders are truncated, 
 * and are not rounded or averaged.
*/
template<typename T>
T map(T value, T fromLow, T fromHigh, T toLow, T toHigh) {
    return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}

/**
 * Calculates the maximum of two numbers.
*/
template<typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

/**
 * Calculates the minimum of two numbers.
*/
template<typename T>
T min(T a, T b) {
    return a < b ? a : b;
}


/**
 * Calculates the value of a number raised to a power. pow() can be used to raise a number to a fractional power. 
 * This is useful for generating exponential mapping of values or curves.
*/
template<typename T>
T pow(T a, T b) {
    T result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

/**
 * Calculates the square of a number: the number multiplied by itself.
*/
template<typename T>
T sq(T x) {
    return x * x;
}

/**
 * Calculates the square root of a number.
*/
template<typename T>
T sqrt(T x) {
    return pow(x, 0.5);
}

#endif //_FAKEARDUINOHEADERS_MATH_HPP
