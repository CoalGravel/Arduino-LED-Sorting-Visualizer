#include <Adafruit_NeoPixel.h>
#define LED_SIZE 150
#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_SIZE, PIN, NEO_GRB + NEO_KHZ800);

struct RGB {
  int r;
  int g;
  int b;
  int v;
};

void setup() {
  Serial.begin(9600);
  RGB leds_state[LED_SIZE] = {{0,0,0,0}};
  
  float curr_val = 0;
  for(size_t i = 0; i < LED_SIZE; i++) {
    RGB temp = {(byte)(curr_val + 0.5), 0, 0, i};
    leds_state[i] = temp;
    curr_val = curr_val + (256.0 / LED_SIZE);
  }
  
  randomize(leds_state, LED_SIZE);
  print_array(leds_state, LED_SIZE);
  insertion_sort(leds_state, LED_SIZE);
  print_array(leds_state, LED_SIZE);

  strip.begin();
  strip.show();
  colorWipe(strip.Color(255, 0, 0), 50);
}

void loop() {
  
}

// Sets all pixels to their value acording to leds_state[] and refreshes
void displayLED(RGB arr[], int capacity) {
  for(int i =0; i < capacity; i++) {
    strip.setPixelColor(i, strip.Color(arr[i].r, arr[i].g, arr[i].b));
  }
  strip.show();
}

// Demo: Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

// Basic swap function for RGB instances
void swap (RGB &a, RGB &b) { 
  RGB temp = a; 
  a = b; 
  b = temp; 
} 

// Prints intended/sorted position of RGB instances in array
void print_array (RGB arr[], size_t capacity) { 
  for (size_t i = 0; i < capacity; i++){
    Serial.print(arr[i].v);
    Serial.print(" ");
  }
  Serial.println();
} 

// Suffles given array of RGB instances
void randomize (RGB arr[], size_t capacity) { 
  for (size_t i = capacity - 1; i > 0; i--) { 
    size_t j = random(i);
    swap(arr[i], arr[j]); 
  } 
} 


// Sorting Algorithms


// Basic bubble sort (O(n^2))
void bubble_sort(RGB arr[], size_t capacity) {
  for(size_t i = 0; i < (capacity - 1); i++) {
    for(size_t j = 0; j < (capacity - (i + 1)); j ++) {
      if(arr[j].v > arr[j+1].v) {
        swap(arr[j], arr[j+1]);
      }
    }
  }
}

// Basic insertion sort (O(n^2))
void insertion_sort(RGB arr[], size_t capacity) {
  RGB temp;
  size_t j;
  for(size_t i = 1; i < capacity; i++) {
    temp = arr[i];
    j = i - 1;
    while(j >= 0 && arr[j].v > temp.v) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = temp;
  }
}
