#include <Servo.h>

Servo demoServo;
float xRot;
float yRot;
float zRot;

void setup() {
    Serial.begin(115200);
    Serial.println(F("1\t2\tt"));
    pinMode(12, INPUT);
    pinMode(11, INPUT);
    demoServo.attach(4);
    pinMode(LED_BUILTIN, OUTPUT);
}
unsigned long pulseOne;
unsigned long pulseTwo;
const float PWM_WIDTH = 2000; //500hz in microseconds
void loop() {
    demoServo.write(180);
    analogWrite(LED_BUILTIN, 180);
    Serial.print('\r');
    pulseOne = pulseIn(12, HIGH, PWM_WIDTH * 10);
    pulseTwo = pulseIn(11, HIGH, PWM_WIDTH * 10);
    Serial.print(pulseOne / PWM_WIDTH);
    Serial.print('\t');
    Serial.print(pulseTwo / PWM_WIDTH);
    Serial.print('\t');
    Serial.print(millis() / 1000.0);
}