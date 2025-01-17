
// #include <LiquidCrystal_I2C.h> // Library for LCD
#include <DHT.h> // Library For DHT11 Sensor


// LiquidCrystal_I2C lcd(0x27,16,2);

int soil_moisture_sensor_pin = A0;
int dht_sensor_pin = 5;
int rain_sensor_pin = A3;
int relay_pin = 10;

// SoftwareSerial serial(0, 1);
DHT dht(dht_sensor_pin, DHT11);

void setup() {
  // put your setup code here, to run once:


  dht.begin();
  delay(2000);
  pinMode(soil_moisture_sensor_pin, INPUT);
  pinMode(rain_sensor_pin, INPUT);
  pinMode(relay_pin, OUTPUT);

  Serial.begin(9600);
  // lcd.begin();
  // lcd.backlight();
  // lcd.setBacklight(HIGH);

  

}

void loop() {
  delay(2500);
  int moisture_value = analogRead(soil_moisture_sensor_pin);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int rain_sensor_value = analogRead(rain_sensor_pin);
  Serial.println(moisture_value);
  Serial.println(rain_sensor_value);
  Serial.print("Current Humidity: ");
  Serial.print(humidity);
  Serial.println("%.");
  Serial.print("Current Temperature: ");
  Serial.print(temperature);
  Serial.println(" Degree Celcius.");
  if(moisture_value > 900)
  {
    Serial.println("No moisture, Soil is dry");
    digitalWrite(relay_pin, LOW);
    // lcd.setCursor(0,0);
    // lcd.print("Soil Dry   ");
    // lcd.setCursor(0,1);
    // lcd.print("Motor ON ");
    Serial.println("Motor ON");
  }
  else if(moisture_value >= 400 && moisture_value <= 900)
  {
    Serial.println("There is some moisture, Soil is medium");
    digitalWrite(relay_pin, HIGH);
    // lcd.setCursor(0,0);
    // lcd.print("Soil Medium");
    // lcd.setCursor(0,1);
    // lcd.print("Motor OFF");
    Serial.println("Motor OFF");
  }
  else if(moisture_value < 400)
  {
    Serial.println("Soil is wet");
    digitalWrite(relay_pin, HIGH);
    // lcd.setCursor(0,0);
    // lcd.print("Soil Wet   ");
    // lcd.setCursor(0,1);
    // lcd.print("Motor OFF");
    Serial.println("Motor OFF");
  }


  



 
  if(rain_sensor_value <= 300)
  {
    Serial.println("It is **RAINING** Now.");
  }
  else
  {
    Serial.println("It is not raining.");
  }



  if(rain_sensor_value <= 300)
  {
    // lcd.setCursor(0,0);
    // lcd.print("Rain Status: ");
    // lcd.setCursor(0,1);
    // lcd.print("**RAINING**");
    delay(2000);
    // lcd.clear();

  }
  else
  {
    // lcd.setCursor(0,0);
    // lcd.print("Rain Status: ");
    // lcd.setCursor(0,1);
    // lcd.print("Not Raining");
    delay(2000);
    // lcd.clear();
  }

  // lcd.setCursor(0,0);
  // lcd.print("Humidity: ");
  // lcd.setCursor(0,1);
  // lcd.print(humidity);
  // lcd.print("%");
  delay(1000);

  // lcd.setCursor(0,0);
  // lcd.print("Temperature: ");
  // lcd.setCursor(0,1);
  // lcd.print(temperature);
  // lcd.print(" Deg Cel.");
  delay(1000);
  // lcd.clear();
  
  
  delay(100);
  Serial.println();
  Serial.println();
  Serial.println();

}