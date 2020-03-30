struct RGB {
  byte r;
  byte g;
  byte b;
  byte v;
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  RGB temp = {1,2,3,1};
  Serial.println(temp.b);
}

void loop() {
  // put your main code here, to run repeatedly:

}
