#include <Adafruit_NeoPixel.h>
#define LED_SIZE 150
#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_SIZE, PIN, NEO_GRB + NEO_KHZ800);

struct RGB {
  byte r;
  byte g;
  byte b;
  byte v;
};

void setup() {
  Serial.begin(9600);
  strip.begin();
  RGB leds_state[LED_SIZE] = {{0,0,0,0}};
  
  float curr_val = 0;
  for(int i = 0; i < LED_SIZE; i++) {
    RGB temp = {(byte)(curr_val + 0.5), 0, 0, i};
    leds_state[i] = temp;
    curr_val = curr_val + (256.0 / LED_SIZE);
  }
  strip.show();
  
  randomize(leds_state, LED_SIZE);
  print_array(leds_state, LED_SIZE);
  quick_sort(leds_state, LED_SIZE);
  print_array(leds_state, LED_SIZE);
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

// Basic swap function reworked for RGB instances with short animation for LEDs
void swap (RGB arr[], int a, int b) { 
  RGB temp = arr[a]; 
  arr[a] = arr[b]; 
  arr[b] = temp;

  strip.setPixelColor(a, strip.Color(0,0,0));
  strip.setPixelColor(b, strip.Color(0,0,0));
  strip.show();
  delay(50);
  strip.setPixelColor(a, strip.Color(arr[b].r,arr[b].g,arr[b].b));
  strip.setPixelColor(b, strip.Color(arr[a].r,arr[a].g,arr[a].b));
  strip.show();
  delay(50);
  strip.setPixelColor(a, strip.Color(0,0,0));
  strip.setPixelColor(b, strip.Color(0,0,0));
  strip.show();
  delay(50);
  strip.setPixelColor(a, strip.Color(arr[b].r,arr[b].g,arr[b].b));
  strip.setPixelColor(b, strip.Color(arr[a].r,arr[a].g,arr[a].b));
  strip.show();
  delay(50);
  strip.setPixelColor(a, strip.Color(0,0,0));
  strip.setPixelColor(b, strip.Color(0,0,0));
  strip.show();
  delay(50);
  strip.setPixelColor(a, strip.Color(arr[a].r,arr[a].g,arr[a].b));
  strip.setPixelColor(b, strip.Color(arr[b].r,arr[b].g,arr[b].b));
  strip.show();
} 


// Prints intended/sorted position of RGB instances in array
void print_array (RGB arr[], int capacity) { 
  for (int i = 0; i < capacity; i++){
    Serial.print(arr[i].v);
    Serial.print(" ");
  }
  Serial.println();
} 

// Shuffles given array of RGB instances
void randomize (RGB arr[], int capacity) { 
  for (int i = capacity - 1; i > 0; i--) { 
    int j = random(i);
    swap(arr, i, j); 
  } 
  strip.show();
} 

// Helper function for quick_sort
int partition(RGB arr[], int low, int high) {
  int pivot = arr[high].v;
  int i = (low - 1);

  for(int j = low; j <= high - 1; j++) {
    if(arr[j].v < pivot) {
      i++;
      swap(arr, i, j);
    }
  }
  swap(arr, i+1, high);
  return (i + 1);
}
// Helper function for quick sort
void quick_sort_recursive(RGB arr[], int low, int high) {
  if(low < high) {
    int p = partition(arr, low, high);

    quick_sort_recursive(arr, low, p - 1);  
    quick_sort_recursive(arr, p + 1, high); 
  }
}

// Sorting Algorithms

// Bubble sort (O(n^2))
void bubble_sort(RGB arr[], int capacity) {
  for(int i = 0; i < (capacity - 1); i++) {
    for(int j = 0; j < (capacity - (i + 1)); j ++) {
      if(arr[j].v > arr[j+1].v) {
        swap(arr, j, j+1);
      }
    }
  }
}

// Insertion sort (O(n^2))
void insertion_sort(RGB arr[], int capacity) {
  RGB temp;
  int j;
  for(int i = 1; i < capacity; i++) {
    j = i;
    while(j > 0 && arr[j-1].v > arr[j].v) {
      swap(arr, j, j-1);
      j--;
    }
  }
}

// Selection sort (O(n^2))
void selection_sort(RGB arr[], int capacity) {
  int min_val;
  for(int i = 0; i < capacity - 1; i++) {
    min_val = i;
    for(int j = i + 1; j < capacity; j++) {
      if(arr[j].v < arr[min_val].v) {
        min_val = j;
      }
    }
    swap(arr, i, min_val);
  }
}

// Merge sort

// Radix 

// Quick sort (O(n*logn))
void quick_sort(RGB arr[], int capacity) {
  quick_sort_recursive(arr, 0, capacity - 1);
}
