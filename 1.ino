const int relay1Pin = 32;
const int relay2Pin = 33;
const int relay3Pin = 25;
const int relay4Pin = 26;

template<class T> inline Print &operator <<(Print &obj, T arg) {
  obj.print(arg);
  return obj;
}

#include "CTBot.h"
CTBot miBot;

#include "token.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando Bot de Telegram");

  miBot.wifiConnect(ssid, password);

  miBot.setTelegramToken(token);

  if (miBot.testConnection()) {
    Serial.println("\n Conectado");
  }
  else {
    Serial.println("\n Problemas Auxilio");
  }

  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
  pinMode(relay4Pin, OUTPUT);

}

void loop() {
  TBMessage msg;

  if (CTBotMessageText == miBot.getNewMessage(msg)) {
    Serial << "Mensaje: " << msg.sender.firstName << " - " << msg.text << "\n";

     if (msg.text == "/encender1") {
      digitalWrite(relay1Pin, HIGH); 
      miBot.sendMessage(msg.sender.id, "Relé 1 encendido.");
    }
    else if (msg.text == "/apagar1") {
      digitalWrite(relay1Pin, LOW); 
      miBot.sendMessage(msg.sender.id, "Relé 1 apagado.");
    }
    else if (msg.text == "/encender2") {
      digitalWrite(relay2Pin, HIGH);  
      miBot.sendMessage(msg.sender.id, "Relé 2 encendido.");
    }
    else if (msg.text == "/apagar2") {
      digitalWrite(relay2Pin, LOW);  
      miBot.sendMessage(msg.sender.id, "Relé 2 apagado.");
    }
    else if (msg.text == "/encender3") {
      digitalWrite(relay3Pin, HIGH);  
      miBot.sendMessage(msg.sender.id, "Relé 3 encendido.");
    }
    else if (msg.text == "/apagar3") {
      digitalWrite(relay3Pin, LOW);  
      miBot.sendMessage(msg.sender.id, "Relé 3 apagado.");
    }
    else if (msg.text == "/encender4") {
      digitalWrite(relay4Pin, HIGH);  
      miBot.sendMessage(msg.sender.id, "Relé 4 encendido.");
    }
    else if (msg.text == "/apagar4") {
      digitalWrite(relay4Pin, LOW); 
      miBot.sendMessage(msg.sender.id, "Relé 4 apagado.");
    }
  }

  delay(500);
}
