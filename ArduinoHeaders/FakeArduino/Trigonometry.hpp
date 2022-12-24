//
// Created by Orlando on 10/8/2022.
//

#ifndef _FAKEARDUINOHEADERS_TRIGONOMETRY_HPP
#define _FAKEARDUINOHEADERS_TRIGONOMETRY_HPP

#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923

int _compareFloats(double a, double b) {
    double precision = 0.00000000000000000001;

     if ((a - precision) < b) {
         return -1;
     }
     else if ((a + precision) > b) {
         return 1;
     }
     else {
         return 0;
     }
}

double _fmod(double x, double y) {
    return x - (int)(x / y) * y;
}

/**
 * Calculates the cosine of an angle (in radians). The result will be between -1 and 1.
*/
double cos(double x) {
    if( x < 0.0f )
        x = -x;

    if( x > M_PI )
        x = _fmod(x, M_PI);

    if( x > M_PI_2 )
        x = M_PI - x;

    double x2 = x * x;
    double x3 = x2 * x;

    double result = 1.0f - (x2 / 2.0f) + (x3 / 24.0f) - ((x3 * x2) / 720.0f) + ((x3 * x3) / 40320.0f);

    if( _compareFloats(x, 0.0f) == 0 )
        result = 1.0f;

    return result;
}

/**
 * Calculates the sine of an angle (in radians). The result will be between -1 and 1.
*/
double sin(double x) {
    return cos(x-M_PI_2);
}


/**
 * Calculates the tangent of an angle (in radians). The result will be between negative infinity and infinity.
 */
double tan(double x) {
    return sin(x) / cos(x);
}
 
#endif //_FAKEARDUINOHEADERS_TRIGONOMETRY_HPP
