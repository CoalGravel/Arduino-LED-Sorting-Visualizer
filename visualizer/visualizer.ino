#include <Adafruit_NeoPixel.h>
#define LED_SIZE 150
#define PIN 6

struct RGB {
  byte r;
  byte g;
  byte b;
  byte v;
};

#define LED_SIZE 150
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_SIZE, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  RGB leds_state[LED_SIZE];
  
  float curr_val = 0;
  for(size_t i = 0; i < LED_SIZE; i++) {
    RGB temp = {(byte)(curr_val + 0.5), 0, 0, i};
    leds_state[i] = temp;
    curr_val = curr_val + (256.0 / LED_SIZE);
  }
  
  randomize(leds_state, LED_SIZE);
  print_array(leds_state, LED_SIZE);
  bubble_sort(leds_state, LED_SIZE);
  print_array(leds_state, LED_SIZE);

  strip.begin();
  strip.show();
  colorWipe(strip.Color(255, 0, 0), 50);
}

void loop() {
  
}

void displayLED(RGB arr[], int capacity) {
  for(int i =0; i < capacity; i++) {
    strip.setPixelColor(i, strip.Color(arr[i].r, 0, 0));
    strip.show();
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
void swap (RGB &a, RGB &b) { 
  RGB temp = a; 
  a = b; 
  b = temp; 
} 

void print_array (RGB arr[], size_t capacity) { 
  for (size_t i = 0; i < capacity; i++){
    Serial.print(arr[i].v);
    Serial.print(" ");
  }
  Serial.println();
} 

void randomize (RGB arr[], size_t capacity) { 
  for (size_t i = capacity - 1; i > 0; i--) { 
    size_t j = random(i);
    swap(arr[i], arr[j]); 
  } 
} 

void bubble_sort(RGB arr[], size_t capacity) {
  for(size_t i = 0; i < (capacity - 1); i++) {
    for(size_t j = 0; j < (capacity - (i + 1)); j ++) {
      if(arr[j].v > arr[j+1].v) {
        swap(arr[j], arr[j+1]);
      }
    }
  }
}
