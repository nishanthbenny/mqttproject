
#include "ESP8266WiFi.h" // Enables the ESP8266 to connect to the local network (via WiFi)
#include "PubSubClient.h" // Allows us to connect to, and publish to the MQTT broker

#define SensorPin A0
int relay = 13;


// WiFi
//const char* ssid = "nishanth";
//const char* wifi_password = "nishanth";

// MQTT
// Make sure to update this for your own MQTT Broker!
//const char* mqtt_server = "test.mosquitto.org";
//const char* plant_topic = "plant";
//const char* mqtt_username = "";
//const char* mqtt_password = "";
//// The client id identifies the ESP8266 device. Think of it a bit like a hostname (Or just a name, like Greg).
//const char* clientID = "client_plant_test";
//
//
//// Initialise the WiFi and MQTT Client objects
//WiFiClient wifiClient;
//PubSubClient client(mqtt_server, 1883, wifiClient); // 1883 is the listener port for the Broker


//void connect_MQTT(){
//  Serial.print("Connecting to ");
//  Serial.println(ssid);
//
//  // Connect to the WiFi
//  WiFi.begin(ssid, wifi_password);
//
//  // Wait until the connection has been confirmed before continuing
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//
//  // Debugging - Output the IP Address of the ESP8266
//  Serial.println("WiFi connected");
//  Serial.print("IP address: ");
//  Serial.println(WiFi.localIP());
//
//  // Connect to MQTT Broker
//  // client.connect returns a boolean value to let us know if the connection was successful.
//  // If the connection is failing, make sure you are using the correct MQTT Username and Password (Setup Earlier in the Instructable)
//  if (client.connect(clientID, mqtt_username, mqtt_password)) {
//    Serial.println("Connected to MQTT Broker!");
//  }
//  else {
//    Serial.println("Connection to MQTT Broker failed...");
//  
//}
//}

void setup() { 
  Serial.begin(9600);
//  connect_MQTT();
//  Serial.setTimeout(2000);

//  float sensorValue = analogRead(SensorPin);
//  Serial.println(sensorValue);
  pinMode(relay,OUTPUT);
//  // PUBLISH to the MQTT Broker
//  if (client.publish(plant_topic, String(sensorValue).c_str())) {
//    Serial.println("Moisture sent!");
//    Serial.println(plant_topic);
//  }
//  // Again, client.publish will return a boolean value depending on whether it succeded or not.
//  // If the message failed to send, we will try again, as the connection may have broken.
//  else {
//    Serial.println("Moisture failed to send. Reconnecting to MQTT Broker and trying again");
//    client.connect(clientID, mqtt_username, mqtt_password);
//    delay(10); // This delay ensures that client.publish doesn't clash with the client.connect call
//    client.publish(plant_topic, String(sensorValue).c_str());
//  }
//  
//  delay(1000);
//  //ESP.deepSleep(0.2*60e6);
}

void loop(){
  int moistureAnalog = analogRead(SensorPin);
  Serial.println(moistureAnalog);
   if (moistureAnalog>600){
    Serial.println("i need water");
    digitalWrite(relay,HIGH);
   }
   else{
     digitalWrite(relay,LOW);
   }
  
} 
