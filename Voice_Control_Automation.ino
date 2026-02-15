#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPLrODYfMmO"
#define BLYNK_DEVICE_NAME "Automotion"
#define BLYNK_AUTH_TOKEN "Opgf18DFbdWnLIPj2WcInoqqJS-V05UT"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "Opgf18DFbdWnLIPj2WcInoqqJS-V05UT";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Sadat";
char pass[] = "#s@d@t##";

#define echoPin  5   //D1
#define trigPin 16    //D0 
#define led1 14       //D5
#define led2 12       //D6

long duration;
int distance; 

BLYNK_WRITE(V0)
{
  int pin=param.asInt();
  digitalWrite(led1,pin);
  }

BLYNK_WRITE(V1)
{
  int pin=param.asInt();
  digitalWrite(led2,pin);
  }

void ultrasonic()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    


    Serial.print("Distance: ");
    Serial.println(distance);
    Blynk.virtualWrite(V2, distance);

    delay(100);
}

void setup()
{
  Serial.begin(9600);
  
  pinMode(34, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);

  Blynk.begin(auth, ssid, pass);
  delay(100);
}

void loop()
{
  Blynk.run();
  ultrasonic();
}
