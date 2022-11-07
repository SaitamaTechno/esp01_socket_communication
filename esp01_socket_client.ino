#include <ESP8266WiFi.h>
 
const char* ssid = "wifi";
const char* password =  "password";
 
const uint16_t port = 50000;
const char * host = "yourlocal_IP";

String stringVariable;
String mystr;
String mystr1;
const char* endmsg = "\n";

void setup()
{
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
 
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
 
}
 
void loop()
{
    WiFiClient client;
 
    if (!client.connect(host, port)) {
 
        Serial.println("Connection to host failed");
 
        delay(1000);
        return;
    }
 
    Serial.println("Connected to server successful!");
    while (1){            // Sending data
      while(Serial.available() == 0){}
      stringVariable = Serial.readString();
      if(stringVariable=="exit"){break;}
      byte mybytes[stringVariable.length()];
      stringVariable.getBytes(mybytes, stringVariable.length());
      client.print((char*) mybytes);

      while (1){
      if (client.available()) {
      char c = static_cast<char>(client.read());
      mystr1=c;
      if (mystr1=="!"){break;}
      mystr+=c;
        }
      }

      Serial.print(mystr+"\n");
      mystr="";
      
    }
    
    //Serial.println("Disconnecting...");
    //client.stop();
 
    delay(100000);
}
