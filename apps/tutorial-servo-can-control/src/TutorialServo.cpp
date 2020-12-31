//
//  TutorialServo.cpp
//  
//
//  Created by Ari Wasch on 9/18/20.
//

#include "TutorialServo.h"
#include "mbed.h"

TutorialServo::TutorialServo(PinName servoPin, float servoRangeInDegrees = 180.0, float minPulsewidthInMs = 1, float maxPulsewidthInMs = 2) : _pin(pin) {
    // _pin = 0;
    m_servoPwmOut = m_servoPwmOut(servoPin);
    m_servoPwmOut.period(0.020);
    m_servoRangeInDegrees = servoRangeInDegrees;
    m_minPulsewidthInMs = minPulsewidthInMs;
    m_maxPulsewidthInMs = maxPulsewidthInMs;

}
 
void TutorialServo::setAngleRangeInDegrees(float degrees) {
    m_servoRangeInDegrees = degrees;
}
void TutorialServo::setPulsewidthRangeInMs(float minPulsewidthMs, float maxPulsewidthMs) {
    m_minPulsewidthInMs = minPulsewidthMs;
    m_maxPulsewidthInMs = maxPulsewidthMs;

}

void TutorialServo::setPositionInDegrees(float degrees) {
    if(degrees >= 0 && degrees <= degrees){
        m_servoPwmOut.pulsewidth((degrees/degrees) * (m_maxPulsewidthInMs - m_minPulsewidthInMs) + m_minPulsewidthInMs);
    }
}

float TutorialServo::getServoRangeInDegrees()const { 
    return m_servoRangeInDegrees;
}
   // Get the min pulse width in ms (ex: 1ms)
float TutorialServo::getMinPulseWidthInMs() const {
    return m_minPulsewidthInMs;
}
   // Get the max pulse width in ms (ex: 2ms)
float TutorialServo::getMaxPulseWidthInMs() const {
    return m_maxPulsewidthInMs;
}
 
// void TutorialServo::goCrazy(int n) {
//     for(int i=0; i<n*2; i++) {
//         _pin = !_pin;
//         wait(0.2);
//     }
// }