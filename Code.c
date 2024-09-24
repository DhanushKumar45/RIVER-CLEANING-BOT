.Code to control through Blynk :

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define ENA D0
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENB D5
int x = 0;
int y = 0;
int Speed;
#define BLYNK_TEMPLATE_ID "TMPL3PLrCM7Ey"
#define BLYNK_TEMPLATE_NAME "wifi car"
#define BLYNK_AUTH_TOKEN "Panqt1AuiwuIOy_3mXLq2vvPLal7XP0Z"
char auth[] = "Panqt1AuiwuIOy_3mXLq2vvPLal7XP0Z"
char ssid[] = "POCO M3"; 
char pass[] = "19812004"; 

void setup() {
 Serial.begin(9600);
 pinMode(ENA, OUTPUT);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(ENB, OUTPUT);
 Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}
BLYNK_WRITE(V0) {
 x = param[0].asInt(); }
BLYNK_WRITE(V1) {
 y = param[0].asInt(); }
BLYNK_WRITE(V2) {
 Speed = param.asInt(); }
void smartcar() {
 printf("x: %d, y: %d \n", x, y);
 if (x == 255) {
 carForward();
 Serial.println("carForward");
 } else if (y == 255) {
 carBackward();
 Serial.println("carBackward"); } 
 else {
 carStop();
 Serial.println("carstop");
 } }
void loop() {
 Blynk.run();
 smartcar(); }
void carForward() {
 analogWrite(ENA, Speed);
 analogWrite(ENB, Speed);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
}
void carBackward() {
 analogWrite(ENA, Speed);
 analogWrite(ENB, Speed);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH); }
