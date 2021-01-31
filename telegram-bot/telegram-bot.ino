#ifdef ESP32
	#include <WiFi.h>
#else
	#include "ESP8266WiFi.h"
#endif
#include "WiFiClientSecure.h"
#include "UniversalTelegramBot.h"
#include "ArduinoJson.h"
#include "secrets.h" //includes BOT_TOKEN, CHAT_ID macros and const char *ssid, const char *pass


#define PIN 2
#define REQ_DELAY 1000 //1000 ms


unsigned long lastRan;
bool pinState = HIGH;

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

void handleMessages(int numNewMessages) {
	Serial.println("handleMessages()");
	Serial.print("New messages num: ");
	Serial.println(String(numNewMessages));

    for (int i = 0; i < numNewMessages; i++) {
        String chatID = String(bot.messages[i].chat_id);
        if (chatID != CHAT_ID) {
            bot.sendMessage(chatID, "Seni tanımıyorum");
            continue;
        }
        Serial.println("handle");
        if (bot.messages[i].type == "callback_query") {
            Serial.print("Call back button pressed by: ");
            Serial.println(bot.messages[i].from_id);
            Serial.print("Data on the button: ");
            Serial.println(bot.messages[i].text);
            if (bot.messages[i].text == "on") {
                bot.sendMessage(chatID, "Işık açıldı", "");
                pinState = LOW;
            } else if (bot.messages[i].text == "off") {
                bot.sendMessage(chatID, "Işık kapandı", "");
                pinState = HIGH;
            } else if (bot.messages[i].text == "state") {
                if (digitalRead(PIN)) {
                    bot.sendMessage(chatID, "Işık KAPALI durumda", "");
                } else {
                    bot.sendMessage(chatID, "Işık AÇIK durumda", "");
                }
            }
        } else {
            String chat_id = bot.messages[i].chat_id;
            String text = bot.messages[i].text;

            String from_name = bot.messages[i].from_name;
            if (from_name == "")
                from_name = "Konuk";

            if (text == "/options") {
                String keyboardJson = "[[{ \"text\" : \"Durum\", \"callback_data\" : \"state\" }],[{ \"text\" : \"Aç\", \"callback_data\" : \"on\" }, { \"text\" : \"Kapa\", \"callback_data\" : \"off\" }]]";
                bot.sendMessageWithInlineKeyboard(chat_id, "Kontrol Paneli", "", keyboardJson);
            } else if (text == "/start") {
                String welcome = "Watchdog'a hoşgeldiniz " + from_name + ".\n";
                welcome += "Kontrol için aşağıdan menüyü çağırın.\n\n";
                welcome += "/options : Size kontrol menüsünü getirir\n";

                bot.sendMessage(chat_id, welcome, "Markdown");
            } else if (text == "/on") {
                bot.sendMessage(chatID, "Işık açıldı", "");
                pinState = LOW;
            } else if (text == "/off") {
                bot.sendMessage(chatID, "Işık kapandı", "");
                pinState = HIGH;
            } else if (text == "/state") {
                if (digitalRead(PIN)) {
                    bot.sendMessage(chatID, "Işık KAPALI durumda", "");
                } else {
                    bot.sendMessage(chatID, "Işık AÇIK durumda", "");
                }
            } else if (text == "/ping") {
                bot.sendMessage(chatID, "pong", "");
            }
        }
        digitalWrite(PIN, pinState);
    }
}

void setup() {
    Serial.begin(115200);
    #ifdef ESP8266
        client.setInsecure();
    #endif
    pinMode(PIN, OUTPUT);
    digitalWrite(PIN, pinState);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println(WiFi.localIP());
}

void loop() {
    if (millis() > lastRan + REQ_DELAY) {
        int messages = bot.getUpdates(bot.last_message_received + 1);
        while (messages) {
            Serial.println("Got response");
            handleMessages(messages);
            messages = bot.getUpdates(bot.last_message_received + 1);
        }
        lastRan = millis();
    }
}
