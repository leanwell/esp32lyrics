#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String words[] = {"Labis", "na", "naiinip", "Nayayamot", "sa", "bawa't", "saglit"};
int wordDelays[] = {1000, 400, 1400, 1400, 300, 600, 1000};

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for (;;);
  }

  // Display splash screen
  display.clearDisplay();
  display.setTextSize(2); // Adjust text size as needed
  display.setTextColor(SSD1306_WHITE);
  
  int16_t x, y;
  uint16_t width, height;
  display.getTextBounds("leanwell", 0, 0, &x, &y, &width, &height);
  int16_t xCenter = (SCREEN_WIDTH - width) / 2;
  int16_t yCenter = (SCREEN_HEIGHT - height) / 2;

  display.setCursor(xCenter, yCenter);
  display.println("leanwell");
  display.display();
  delay(2000);

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

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 20);
  display.println(words[sizeof(words)/sizeof(words[0]) - 1]);
  display.display();
  delay(5000);
}
