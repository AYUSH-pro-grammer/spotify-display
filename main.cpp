#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <ArduinoJson.h>
#include <SpotifyArduino.h>


#define TFT_CS 5
#define TFT_RST 4
#define TFT_DC 2


const char* SSID = "YOUR_WIFI_NAME";
const char* PASSWORD = "YOUR_WIFI_PASSWORD";


const char* CLIENT_ID = "YOUR_CLIENT_ID";
const char* CLIENT_SECRET = "YOUR_CLIENT_SECRET";
const char* REFRESH_TOKEN = "YOUR_REFRESH_TOKEN";


WiFiClientSecure client;
SpotifyArduino spotify(client, CLIENT_ID, CLIENT_SECRET, REFRESH_TOKEN);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


String lastArtist = "";
String lastTrack = "";

void setup() {
  Serial.begin(115200);

  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);


  WiFi.begin(SSID, PASSWORD);
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  tft.setCursor(0, 0);
  tft.println("WiFi OK");


  client.setInsecure();
}

void loop() {
  Serial.println("Checking Spotify...");

  CurrentlyPlaying currentlyPlaying;
  if (spotify.getCurrentlyPlaying(currentlyPlaying)) {

    String artist = currentlyPlaying.artists[0].artistName;
    String track = currentlyPlaying.trackName;


    if (artist != lastArtist) {
      lastArtist = artist;
      Serial.println("Artist: " + artist);

      tft.fillRect(0, 20, 160, 20, ST77XX_BLACK);
      tft.setCursor(0, 20);
      tft.println(artist);
    }


    if (track != lastTrack) {
      lastTrack = track;
      Serial.println("Track: " + track);

      tft.fillRect(0, 40, 160, 20, ST77XX_BLACK);
      tft.setCursor(0, 40);
      tft.println(track);
    }
  } else {
    Serial.println("Failed to get Spotify data");
  }

  delay(3000);
}