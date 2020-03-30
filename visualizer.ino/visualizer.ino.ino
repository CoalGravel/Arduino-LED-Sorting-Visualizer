struct RGB {
  byte r;
  byte g;
  byte b;
  byte v;
};

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

// A utility function to swap to integers 
void swap (RGB &a, RGB &b) 
{ 
  RGB temp = a; 
  a = b; 
  b = temp; 
} 

// A utility function to print an array 
void printArray (RGB arr[], size_t n) 
{ 
  for (size_t i = 0; i < n; i++){
    Serial.print(arr[i].v);
    Serial.print(" ");
  }
  Serial.println();
} 

// A function to generate a random 
// permutation of arr[] 
void randomize (RGB arr[], size_t n) { 
  for (size_t i = n - 1; i > 0; i--) { 
    size_t j = random(i);
    swap(arr[i], arr[j]); 
  } 
} 
