struct RGB {
  byte r;
  byte g;
  byte b;
  byte v;
};

#define LED_SIZE 150

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  RGB leds_state[LED_SIZE];
  float curr_val = 0;
  for(int i = 0; i < LED_SIZE; i++) {
    RGB temp = {(byte)(curr_val + 0.5), 0, 0, i};
    leds_state[i] = temp;
    curr_val = curr_val + (256.0 / LED_SIZE);
  }

  
//  for(int j = 0; j < LED_SIZE; j++) {
//    Serial.println(leds_state[j].r);
//  } 

  
}

void loop() {
  // put your main code here, to run repeatedly:

}
