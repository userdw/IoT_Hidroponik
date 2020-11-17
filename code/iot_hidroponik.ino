#define BLYNK_PRINT Serial
#define MTR_PIN 15
#define RLY_PIN D6

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "TqWYk-UIrsAAcyeu-D48xLoSx3uy6eoI";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "IEDW_DIRECT_TELKOM";
char pass[] = "dwtelkomdirect";
bool motor = 0, relay = 0, tblmotor = 0;
int TDS_threshold;
float Temp = 25.0;
float cc = 1.0 + 0.02 * (Temp - 25);

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1
BlynkTimer timer;
WidgetLED led_mtr(V2);
WidgetLED led_rly(V3);

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue) {
    relay = !relay;
    Serial.print(RLY_PIN); Serial.print(" ");
    Serial.println(relay);
  }
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();

  tblmotor = pinValue;
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt();
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial.print("TDS Threshold: ");
  Serial.println(pinValue);
  TDS_threshold = pinValue;
}


void myTimerEvent()
{

  // Baca dan kalkulasi nilai TDS berdasarkan nilai analog input
  float av = analogRead(A0);
  float v = av * 1 / 1024.0;
  float tds = (133.42 * v * v * v - 255.86 * (v * v) + 857.39 * v)*8.8;
  
  Serial.print("adc: ");Serial.println(av);
  Serial.print("tegangan: ");Serial.println(v);
  Serial.print("ppm: ");Serial.println(tds);
  Serial.println();
  if (tds > TDS_threshold) {
    motor = false;
  }
  else {
    motor = true;
  }
  if (tblmotor) {
    motor = true;
  }

  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  if (motor) {
    led_mtr.on();
    analogWrite(MTR_PIN, 128);
    delay(500);
    led_mtr.off();
    analogWrite(MTR_PIN, 0);
  }
  else {
    led_mtr.off();
    analogWrite(MTR_PIN, 0);
  }
  if (relay) {
    led_rly.on();
  }
  else {
    led_rly.off();
  }
  digitalWrite(RLY_PIN, relay);

  // Kirim nilai TDS ke Gauge dg variabel V5
  Blynk.virtualWrite(V5, tds);
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(D1, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{                  
  Blynk.run();
  timer.run();
  digitalWrite(LED_BUILTIN, HIGH);
}
