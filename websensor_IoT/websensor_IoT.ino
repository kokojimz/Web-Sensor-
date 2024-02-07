#include <DHT.h>
#include <NewPing.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266Wifi.h>

#define DHTPIN D4  
#define DHTTYPE DHT11  // Tipe DHT 11
DHT dht(DHTPIN, DHTTYPE);

#define TRIG_PIN D1  
#define ECHO_PIN D2  
#define MAX_DISTANCE 200  // Maksimal jarak yang diukur (dalam cm)
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

//Setting Jaringan
const char* ssid = "";
const char* pass = "";
const char* host = ""; //server IP address



void setup() {
  Serial.begin(9600); 
  dht.begin();  // Inisialisasi sensor DHT11

  WiFi.hostname("NodeMCU"); 
  WiFi.begin(ssid, pass); 

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
}

void loop() {
  // Membaca suhu dari DHT11
  float temperature = dht.readTemperature();
  // Membaca jarak dari HC-SR04
  unsigned int distance = sonar.ping_cm();
  
  // Konversi nilai float ke integer
  int intTemperature = round(temperature);
  // Menampilkan nilai jarak dan suhu
  Serial.println(distance);
  Serial.println(intTemperature);

  WiFiClient client;
  HTTPClient http;

  // Proses pengiriman data jarak ke server
  String Linkdist = "http://" + String(host) + "/websensor/sendDist.php?sensor=" + String(distance);
  if (client.connect(host, 80)) { // Ensure the client is ready to connect
    http.begin(client, Linkdist); // Use the updated API
    int httpCodeDist = http.GET(); // You can use the HTTP code for error checking
    http.end(); // Close the connection
  } else {
    Serial.println("Connection to host failed");
  }

  // Proses pengiriman data suhu ke server
  String Linktemp = "http://" + String(host) + "/websensor/sendTemp.php?sensor=" + String(intTemperature);
  if (client.connect(host, 80)) { // Ensure the client is ready for a new connection
    http.begin(client, Linktemp); // Use the updated API
    int httpCodeTemp = http.GET(); // You can use the HTTP code for error checking
    http.end(); // Close the connection
  } else {
    Serial.println("Connection to host failed");
  }

  delay(1000); // Delay between readings
}

