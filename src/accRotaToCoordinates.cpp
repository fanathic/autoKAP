/*
#include <mbed.h>

// Pins
// GY-61
AnalogIn inAccelerationXRaw(A0);
AnalogIn inAccelerationYRaw(A1);
AnalogIn inAccelerationZRaw(A2);

// Calibration values

const float xOffset;
const float yOffset;
const float zOffset;

const float xScale;
const float yScale;
const float zScale;

float xRawAcceleration;
float yRawAcceleration;
float zRawAcceleration;
float xAcceleration;
float yAcceleration;
float zAcceleration;

void readAccelerometer()
{
    xRawAcceleration = inAccelerationXRaw.read();
    yRawAcceleration = inAccelerationYRaw.read();
    zRawAcceleration = inAccelerationZRaw.read();
}

void calibrateAcceleration()
{
    xAcceleration = (xRawAcceleration - xOffset) / xScale;
    yAcceleration = (yRawAcceleration - yOffset) / yScale;
    zAcceleration = (zRawAcceleration - zOffset) / zScale;
}

float getXAcceleration()
{
    return xAcceleration;
} 

float getYAcceleration()
{
    return yAcceleration;
}

float getZAcceleration()
{
    return zAcceleration;
}
*/
