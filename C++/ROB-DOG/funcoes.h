#include "arduino.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "bitmaps.h"
#include "RTClib.h"

#define OLED_RESET 4


char daysOfTheWeek[7][12] = {"DOMINGO", "SEGUNDA", "TERCA", "QUARTA", "QUINTA", "SEXTOU", "SABADO"};
int BUZZER_PIN = 12;
int BUZZER_CHANNEL = 0;
int NO_SOUND = 0;
int testeO = 50;

Adafruit_SSD1306 display1(128, 64, &Wire, OLED_RESET);
Adafruit_SSD1306 display2(128, 64, &Wire, OLED_RESET);
RTC_DS3231 rtc;
int tempo=5;

void padrao(){
    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_1, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_1, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(500);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_2, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_2, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_2, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_2, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_3, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_3, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_4, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_4, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_5, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_5, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_6, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_6, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(500);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_5, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_5, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_4, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_4, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_3, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_3, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_2, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_3, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_2, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_2, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);


    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_1, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_1, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_7, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_7, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_8, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_8, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_9, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_9, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_10, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_10, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_11, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_11, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(500);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_10, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_10, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);
    
    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_9, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_9, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_8, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_8, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay(); 
    display2.clearDisplay(); 
    display1.drawBitmap(0, 0, defaul_7, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, defaul_7, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);
}

void inicio(){
    display1.clearDisplay(); 
    display1.drawBitmap(0, 0, bluetooth_logo, 128, 64, BLACK, WHITE);
    display2.clearDisplay(); 
    display2.drawBitmap(0, 0, bluetooth_logo, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(3000);
    
    display1.clearDisplay();
    display2.clearDisplay();

    display1.setTextSize(1);
    display2.setTextSize(1);
    
    display1.setTextColor(WHITE);
    display2.setTextColor(WHITE);
    
    display1.setCursor(22, 10);
    display1.println(F("WPAN : ROB-DOG"));

    display1.setCursor(22, 20);
    display1.println(F("REDE BLUETOOTH"));

    display1.setCursor(22, 30);
    display1.println(F("--------------"));

    display1.setCursor(22, 40);
    display1.println(F("PRECIONE UM"));

    display1.setCursor(22, 50);
    display1.println(F("BOTAO"));
    
   
    display2.drawBitmap(0, 0, qrcode, 128, 64, BLACK, WHITE);
    
    display1.display();
    display2.display();
}



void relogio_real(){
      DateTime now = rtc.now();

      display1.clearDisplay();
      display2.clearDisplay();

      display1.setTextSize(3);
      display2.setTextSize(2);
      
      display1.setTextColor(WHITE);
      display2.setTextColor(WHITE);
      
      if (now.hour() <10){
        display1.setCursor(25, 10);
        display1.println(F("0"));
        display1.setCursor(42, 10);
        display1.println(now.hour());
      }
      else{
      display1.setCursor(25, 10);
      display1.println(now.hour());
      }
  
      display1.setCursor(55, 10);
      display1.println(F(":"));

        if (now.minute() <10){
        display1.setCursor(68, 10);
        display1.println(F("0"));
        display1.setCursor(85, 10);
        display1.println(now.minute());
      }
      else{
        display1.setCursor(68, 10);
        display1.println(now.minute());
      }

      display1.setTextSize(1);
      display1.setCursor(60, 36);
      display1.println(now.second());

      
      display1.setTextSize(1);
      display1.setCursor(25, 53);
      display1.println(F("TEMP :"));
      display1.setCursor(65, 53);
      display1.println(rtc.getTemperature());
      display1.setCursor(92, 53);
      display1.println(F(" C"));

 //----------------------------------------------------------------------------------------------------------   display 2   --------------------------------------------------------------------------------------------------------------------------------------------- eu tinhamo mt meu amor sei q vc um dia vai ler isso ent vc é o amor da minha vida e eu to aq bebendo e triste pq estamos brigados pq fiz merda, espero que qnd vc estiver lendo isso nos vamos estar bem e mtttttt feliz KKKKKKKKKKK 03/09/2022 a data pra recordacao
      if (now.day() <10){
        display2.setCursor(25, 10);
        display2.println(F("0"));
        display2.setCursor(42, 10);
        display2.println(now.day());
      }
      else{
        display2.setCursor(25, 10);
        display2.println(now.day());
      }

      display2.setCursor(57, 10);
      display2.println(F("/"));

      if (now.month() <10){
        display2.setCursor(73, 10);
        display2.println(F("0"));
        display2.setCursor(90, 10);
        display2.println(now.month());
      }
      else{
        display2.setCursor(73, 10);
        display2.println(now.month());
      }

      display2.setCursor(40, 30);
      display2.println(now.year());

      display2.setTextSize(1);
      display2.setCursor(45, 53);
      display2.println(daysOfTheWeek[now.dayOfTheWeek()]);

      display1.setTextSize(1);
      display2.setTextSize(1);
      display1.setCursor(0, 45);
      display2.setCursor(0, 45);
      display1.println(F("---------------------"));
      display2.println(F("---------------------"));
 
      display1.display();
      display2.display();
      delay(1000);
}
