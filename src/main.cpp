#include <mbed.h>
#include "L3G4200D.h"

// For testing:
Serial pc(USBTX, USBRX, 115200);



// Pins
// GY-61
DigitalOut AccelerometerVCC(A0);
DigitalOut AccelerometerGND(A4);
AnalogIn inAccelerationXRaw(A1);
AnalogIn inAccelerationYRaw(A2);
AnalogIn inAccelerationZRaw(A3);

// GY-50
L3G4200D gyro(D14, D15);


// Calibration values

const float xOffset = 0.5; // 0g = 0.5 * VCC
const float yOffset = 0.5;
const float zOffset = 0.5;

const float xScale = 1; // 10g = 3,3V eli -5 -> +5
const float yScale = 1; 
const float zScale = 1;

float xRawAcceleration;
float yRawAcceleration;
float zRawAcceleration;
float xAcceleration;
float yAcceleration;
float zAcceleration;

int g[3];

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

int main() {
  AccelerometerGND = 0;
  AccelerometerVCC = 1;

  // put your setup code here, to run once:

  while(1) {
    readAccelerometer();
    calibrateAcceleration();
    gyro.read(g);
    pc.printf("Acceleration: X: %f Y: %f Z: %f \n", xAcceleration, yAcceleration, zAcceleration);
    pc.printf("Gyroscope: X: %d Y: %d Z: %d \n", g[0], g[1], g[2]);
    wait(1);
  }
}