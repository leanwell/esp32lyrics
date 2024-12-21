## ESP32 Lyrics

> This project uses an ESP32 to control an OLED display and a servo motor. The display shows words sequentially with specified delays, while the servo motor rotates or stops based on a button press. It combines text visualization and motor control for interactive functionality.

**Requirements**
|Materials  | Quantity |
|--|--|
|ESP32  | 1 |
|OLED Display (0.96 in, 128x64, IIC)  | 1 |
|Breadboard|1|
|LED  | 3 |
|F-F Jumper Wires  | 3 |

**Programming**
I used the Arduino core IDE with the ESP32 library.

> Install the IDE from its official website <br>
> Also download the required library inside Arduino Core: <br>
> `Wire` (included in Arduino Core Libary) <br>
> `Adafruit GFX Library` <br>
> `Adafruit SSD1306` <br>
> `ESP32Servo` <br>
> ESP32 Board for Arduino Core: <br>
> https://dl.espressif.com/dl/package_esp32_index.json <br>

Source Code
---
    #include <Wire.h>
    #include <Adafruit_GFX.h>
    #include <Adafruit_SSD1306.h>
    
    #define SCREEN_WIDTH 128
    #define SCREEN_HEIGHT 64
    #define OLED_RESET    -1
    
    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
    
    // modify the lyrics here --
    String words[] = {"Labis", "na", "naiinip", "Nayayamot", "sa", "bawa't", "saglit"};
    // modify the delay here --
    int wordDelays[] = {500, 400, 1400, 1400, 300, 600, 1000};
    
    void setup() {
      Serial.begin(115200);
    
      if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        for (;;);
      }
    
      display.clearDisplay();
    }
    
    void loop() {
      for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 20);
        display.println(words[i]);
        display.display();
        delay(wordDelays[i]);
      }
    }

> Take note that this code will loop.

Diagram
---

> Refer to the image below for the schematic diagram


image_here.jpg


**OLED to ESP32 Pin connection:**
| OLED | ESP32 |
|--|--|
| VCC | 3.3V OR 5V |
|GND |GND |
|SDA|GPIO 21|
|SCL|GPIO 22|

---
Donate
---
buy_me_a_coffee.jpg

