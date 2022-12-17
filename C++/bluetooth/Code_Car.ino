#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup(){
  Serial.begin(9600);
  SerialBT.begin("Carro Bluetooth"); 
}

void loop(){
  if (SerialBT.available()){
    char recebido = SerialBT.read();
    if (recebido == '0'){
      Serial.println("recebido: ");
      Serial.println(recebido);
    }   
    if (recebido == '1'){
      Serial.println("recebido: ");
      Serial.println(recebido); 
    }
    if (recebido == '2'){
      Serial.println("recebido: ");
      Serial.println(recebido);   
    }   
    if (recebido == '3'){
      Serial.println("recebido: ");
      Serial.println(recebido);
    }
    if (recebido == '4'){
      Serial.println("recebido: ");
      Serial.println(recebido);
    }
    if (recebido == '5'){
      Serial.println("recebido: ");
      Serial.println(recebido);
    }      
  }
}
