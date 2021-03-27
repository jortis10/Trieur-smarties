#ifndef HEADER_MONSERVO_HPP
#define HEADER_MONSERVO_HPP

#include <arduino.h>
#include <Servo.h>

#include "mycolor.hpp"

class MonServo : public Servo
{

private:

    int m_servoPin = 2;

public:

    MonServo(int servoPin);
    void setEvacuation(Color color);

};


#endif