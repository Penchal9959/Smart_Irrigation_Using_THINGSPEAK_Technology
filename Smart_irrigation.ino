 #include <DHT.h>  
 #include <ESP8266WiFi.h>  
 #include <WiFiClient.h>  
 #include <ThingSpeak.h>
 #include <LiquidCrystal.h>  
 LiquidCrystal lcd(D0, D1, D6, D4, D3, D2);
 #define DHTPIN D5  
 #define DHTTYPE DHT11  
 DHT dht(DHTPIN, DHTTYPE);
  #define sensor_pin D8 
// const int sensor_pin = A0; 
 const char* ssid = "Ganga";  
 const char* password = "ganga123";  
 WiFiClient client;  
 unsigned long myChannelNumber = 907411;  
 const char * myWriteAPIKey = "8X70IIQVLZL32EHM";  
 uint8_t temperature, humidity, k=0, l=0;

   int val;
 
int LDRpin = A0;
 void setup()  
 {  
  lcd.begin(16, 2);
  Serial.begin(115200);  
  dht.begin();  
  delay(10);  
  // Connect to WiFi network  
  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address  
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);  
 }  
 void loop()   
 {  
   float moisture_percentage;
   moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );

  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");

  delay(1000);
  static boolean data_state = false;  
  temperature = dht.readTemperature();  
  humidity = dht.readHumidity();
  //moisture_percentage =  moisture_percentage.readsoilmoisture(); 
  lcd.setCursor(0,0); 
  lcd.print("Temperature  :");  
  lcd.print(temperature);  
  lcd.println("C");
  lcd.setCursor(0,1);  
  lcd.print("Humidity  :");  
  lcd.print(humidity);  
  lcd.println("%");  
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different  
  // pieces of information in a channel. Here, we write to field 1.  
  if(temperature < 255)
  {
      k=temperature;  
  }
   if(humidity < 255)
  {
      l=humidity;  
  }
 
  if( data_state )  
  {  
   ThingSpeak.writeField(myChannelNumber, 1, k, myWriteAPIKey);  
   data_state = false;  
  } 
    
  else  
  {  
   ThingSpeak.writeField(myChannelNumber, 2, l, myWriteAPIKey);  
   data_state = true;  
  }  


 val = analogRead(LDRpin); //Read Analog values and Store in val variable
 
Serial.print(val); //Print on Serial Monitor
 
delay(1000);
 
ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
 
 
 
delay(100);
  delay(30000); // ThingSpeak will only accept updates every 15 seconds.  
 }  
