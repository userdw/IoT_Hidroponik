#define BLYNK_PRINT Serial
#define MTR_PIN 15

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Blynk Authentication
char auth[] = "Your Authentication Token";
char ssid[] = "Your SSID";
char pass[] = "Your Password";

bool motor = 0, tblmotor = 0;
int TDS_threshold;
float Temp = 25.0;
float cc = 1.0 + 0.02 * (Temp - 25);

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1
BlynkTimer timer;
WidgetLED led_mtr(V2);

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  tblmotor = pinValue;
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt();
  TDS_threshold = pinValue;
}


void myTimerEvent() {

  float av = analogRead(A0);
  float v = av * 1 / 1024.0;
  float tds = (133.42 * v * v * v - 255.86 * (v * v) + 857.39 * v) * 8.8;

  if (tds < TDS_threshold) {
    led_mtr.on();
    digitalWrite(LED_BUILTIN, LOW);
    analogWrite(MTR_PIN, 680);
    delay(2500);
    led_mtr.off();
    digitalWrite(LED_BUILTIN, HIGH);
    analogWrite(MTR_PIN, 0);
    delay(15000);
  } else {
    led_mtr.off();
    digitalWrite(LED_BUILTIN, HIGH);
    analogWrite(MTR_PIN, 0);
  }

  while (tblmotor) {
    led_mtr.on();
    digitalWrite(LED_BUILTIN, LOW);
    analogWrite(MTR_PIN, 680);
  }

  Blynk.virtualWrite(V5, tds);
}

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
}

void loop() {
  Blynk.run();
  timer.run();
}
