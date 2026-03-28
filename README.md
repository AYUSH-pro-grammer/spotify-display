# spotify-display

What This Project Is

This project is a real-time display of the Spotify API. It displays the song playing on Spotify, the artist of the song, and the status of the song playing or not on a display connected to an ESP32 microcontroller.

Why I Made It

This project was made to integrate the following components into one system:
APIs (Spotify API)
Embedded Systems (ESP32)
Display Systems (OLED or TFT displays)

These components are integrated into one system that displays real-time data from Spotify in a physical form.

Features
Real-time display of:
Song playing
Artist
Status of the song playing
Lightweight system
Fetch data from Spotify API
Use WiFi to fetch data
ESP32
Work continuously

How It Works
Data Flow
Spotify API
ESP32 (WiFi)
Display

ESP32 Firmware
The firmware of the ESP32:
Connects to a WiFi network
Authenticates with Spotify API
Sends a GET request to Spotify API
Fetches data from Spotify API
Sends data to display
Updates display

Hardware
ESP32 Development Board
OLED or TFT display
Jumper Wires
Breadboard

Wiring
OLED display connected via I2C interface
Display
ESP32
VCC
3.3V
GND
GND
SCL
GPIO 22
SDA
GPIO 21

Setup Instructions
Spotify API
1. Create a Spotify API application
Go to:
https://developer.spotify.com/dashboard
Create an application
Get Client ID
Get Client Secret
2. Get Access Token
Use OAuth to get a token
Use:
user-read-currently-playing
3. Configure Code
Modify code to:
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASS";
String accessToken = "YOUR_SPOTIFY_TOKEN";
4. Upload Code
Connect ESP32
Upload code
Open Serial Monitor

attaching image for the same:

Breadboard Circuit [made in fritzing]:
<img width="1512" height="982" alt="Screenshot 2026-03-23 at 11 14 37 PM" src="https://github.com/user-attachments/assets/bbe97b03-ede9-4aaa-a240-cea79a247112" />

3D model
<img width="1512" height="982" alt="Screenshot 2026-03-23 at 11 35 00 PM" src="https://github.com/user-attachments/assets/4686a3b5-aa86-4fe5-8b7c-f6703ce3dcdd" />


