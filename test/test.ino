#include "FastLED.h"
#define LED_SIZE 150
#define LED_PIN 7

struct RGB {
  byte r;
  byte g;
  byte b;
  byte v;
};

void setup() {
  Serial.begin(9600);
  RGB leds_state[LED_SIZE];
  
  float curr_val = 0;
  for(size_t i = 0; i < LED_SIZE; i++) {
    RGB temp = {(byte)(curr_val + 0.5), 0, 0, 149 - i};
    leds_state[i] = temp;
    curr_val = curr_val + (256.0 / LED_SIZE);
  }

  print_array(leds_state, LED_SIZE);
  bubble_sort(leds_state, LED_SIZE);
  print_array(leds_state, LED_SIZE);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void swap(RGB &p1, RGB &p2) {
  RGB temp = p1;
  p1 = p2;
  p2 = temp;
}

void bubble_sort(RGB arr[], int capacity) {
  for(int i = 0; i < (capacity - 1); i++) {
    for(int j = 0; j < (capacity - (i + 1)); j ++) {
      if(arr[j].v > arr[j+1].v) {
        swap(arr[j], arr[j+1]);
      }
    }
  }
}

void print_array (RGB arr[], size_t capacity) { 
  for (size_t i = 0; i < capacity; i++){
    Serial.print(arr[i].v);
    Serial.print(" ");
  }
  Serial.println();
} 
