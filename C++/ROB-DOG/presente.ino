#include "BluetoothSerial.h"
#include "funcoes.h"
#include "RTClib.h"
#include <ESP32Servo.h>

char recebido;

int cond_padrao = 0;
int cond_feliz = 0;
int cond_triste = 0;
int cond_hora = 0;
int cond_palmeiras = 0;
int tempo_2 = 2500;
int sem_som = 0;

BluetoothSerial SerialBT;

Servo myservo; 
Servo myservo2;

static uint8_t taskCoreZero = 0;
static uint8_t taskCoreOne  = 1;

void setup(){
  ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL);
  myservo.attach(27);
  myservo2.attach(26);

  myservo.write(0);
  myservo2.write(180);
  display1.begin(SSD1306_SWITCHCAPVCC, 0x3C); //display1 = 0x3C   
  display2.begin(SSD1306_SWITCHCAPVCC, 0x3D); //display2 = 0x3D
  Serial.begin(9600);
  SerialBT.begin("ROB-DOG"); 
  inicio();
  ledcWrite(0, 0);


#ifndef ESP8266
  while (!Serial); 
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    //rtc.adjust(DateTime(2022, 8, 30, 15, 59, 0));
  }
}


void loop(){
  if (SerialBT.available()){
    char recebido = SerialBT.read();
    Serial.write(recebido);
    if (recebido == '0'){
      cond_padrao = 1;
      cond_feliz = 1;
      cond_triste = 1;
      cond_hora = 1;
      cond_palmeiras = 1;
      ledcWrite(0, 0);
    }   
    if (recebido == '1'){
      cond_padrao = 0;
      cond_feliz = 1;
      cond_triste = 1;
      cond_hora = 1;
      cond_palmeiras = 1;
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      xTaskCreatePinnedToCore(padrao,"padrao",10000,NULL,1,NULL,taskCoreOne); 
      delay(500);
    }
    if (recebido == '2'){
      myservo.attach(27);
      myservo2.attach(26);
      BUZZER_PIN = 12;
      cond_padrao = 1;
      cond_feliz = 0;
      cond_triste = 1;
      cond_hora = 1;
      cond_palmeiras = 1;
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      delay(tempo_2);
      xTaskCreatePinnedToCore(feliz,"  feliz", 10000,NULL,1,NULL,taskCoreOne);
      delay(500);
    }   
    if (recebido == '3'){
      myservo.attach(27);
      myservo2.attach(26);
      BUZZER_PIN = 12;
      cond_padrao = 1;
      cond_feliz = 1;
      cond_triste = 0;
      cond_hora = 1;
      cond_palmeiras = 1;
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      delay(tempo_2);
      xTaskCreatePinnedToCore(triste,"triste", 10000,NULL,1,NULL,taskCoreOne); 

      delay(500); 
    }
    if (recebido == '4'){
      myservo.attach(27);
      myservo2.attach(26);
      BUZZER_PIN = 12;
      cond_padrao = 1;
      cond_feliz = 1;
      cond_triste = 1;
      cond_hora = 0;
      cond_palmeiras = 1;
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      delay(tempo_2);
      xTaskCreatePinnedToCore(relogio_real1,"  relogio_real1", 10000,NULL,1,NULL,taskCoreOne); 
      delay(500);
    }   
    if (recebido == '5'){
      myservo.attach(27);
      myservo2.attach(26);
      BUZZER_PIN = 12;
      cond_padrao = 1;
      cond_feliz = 1;
      cond_triste = 1;
      cond_hora = 1;
      cond_palmeiras = 0;
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      delay(tempo_2);
      xTaskCreatePinnedToCore(parmeira,"parmeira", 10000,NULL,1,NULL,taskCoreOne); 
      delay(500);
  
    }        
  }
}


void padrao( void * pvParameters ){
  ledcWrite(0, 0);
  while(true){
    padrao();
    if(cond_padrao == 1){
      vTaskDelete(NULL);
      ledcWrite(0, 0); 
    }
  } 
} 

void triste( void * pvParameters ){
  ledcWrite(0, 0);
  while(true){
    olhos_tristes();
    if(cond_triste == 1){
      vTaskDelete(NULL);
      ledcWrite(0, 0);
    }
  } 
}

void feliz( void * pvParameters ){
  ledcWrite(0, 0);
  while(true){
    happy_eye();
    if(cond_feliz == 1){
      vTaskDelete(NULL);
      ledcWrite(0, 0);
    }
  } 
}


void relogio_real1( void * pvParameters ){
  ledcWrite(0, 0);
  while(true){
    relogio_real();
    if(cond_hora == 1){
      vTaskDelete(NULL);
      ledcWrite(0, 0);
    }
  } 
}

void parmeira( void * pvParameters ){
   ledcWrite(0, 0);
   palmeiras();
   vTaskDelete(NULL);
 }

void palmeiras(){
  ledcWrite(0, 0);
  display1.clearDisplay();
  display2.clearDisplay();
  display1.drawBitmap(0, 0, verdao, 128, 64, BLACK, WHITE);
  display2.drawBitmap(0, 0, verdao, 128, 64, BLACK, WHITE);
  display1.display();
  display2.display();
  
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);

   if(cond_palmeiras == 1){
     
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
     if(cond_palmeiras == 1){
 
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
     if(cond_palmeiras == 1){
    
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWrite(0, 0);
  delay(900.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
     if(cond_palmeiras == 1){

      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
     if(cond_palmeiras == 1){
   
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
     if(cond_palmeiras == 1){
 
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(900.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
     if(cond_palmeiras == 1){
  
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
     if(cond_palmeiras == 1){
     
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
     if(cond_palmeiras == 1){

      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
     if(cond_palmeiras == 1){

      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
     if(cond_palmeiras == 1){
 
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
     if(cond_palmeiras == 1){
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
     if(cond_palmeiras == 1){

      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
     if(cond_palmeiras == 1){
 
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
     if(cond_palmeiras == 1){
  
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
     if(cond_palmeiras == 1){
   
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWrite(0, 0);
  delay(900.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
     if(cond_palmeiras == 1){
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
     if(cond_palmeiras == 1){
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
     if(cond_palmeiras == 1){
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(900.0);
     if(cond_palmeiras == 1){
 
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
     if(cond_palmeiras == 1){
      
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
     if(cond_palmeiras == 1){
  
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
     if(cond_palmeiras == 1){
    
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(225.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
     if(cond_palmeiras == 1){
    
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(450.0);
     if(cond_palmeiras == 1){
      
      myservo.write(0);
      delay(100);
      myservo2.write(180);
      ledcWrite(0, 0);
      vTaskDelete(NULL);
    }
  ledcWriteNote(BUZZER_CHANNEL, (note_t)NOTE_B, 5);
  delay(testeO);
  ledcWrite(0, 0);
  delay(900.0);
}

void happy_eye(){
    ledcWrite(0, 0);
    myservo.write(180);
    myservo2.write(0);
    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_1, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_1, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_2, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_2, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_3, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_3, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_4, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_4, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);


    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_5, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_5, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);
/**
    myservo.write(180);
    myservo2.write(180);
**/
    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_6, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_6, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_7, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_7, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_8, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_8, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_9, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_9, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);


    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_10, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_10, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_9, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_9, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_8, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_8, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_7, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_7, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);


    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_6, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_6, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);
/**
    myservo.write(180);
    myservo2.write(180);
**/
    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_5, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_5, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_4, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_4, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_3, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_3, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, happy_2, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, happy_2, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo); 
 } 

 void olhos_tristes(){
    ledcWrite(0, 0);
    myservo.write(100);
    myservo2.write(80);
    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, sadEyeLeft_1, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, sadEyeRight_1, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, sadEyeLeft_2, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, sadEyeRight_2, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, sadEyeLeft_3, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, sadEyeRight_3, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, sadEyeLeft_4, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, sadEyeRight_4, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, sadEyeLeft_5, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, sadEyeRight_5, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(0, 0, sadEyeLeft_6, 128, 64, BLACK, WHITE);
    display2.drawBitmap(0, 0, sadEyeRight_6, 128, 64, BLACK, WHITE);
    display1.display();
    display2.display();
    delay(tempo);
}
