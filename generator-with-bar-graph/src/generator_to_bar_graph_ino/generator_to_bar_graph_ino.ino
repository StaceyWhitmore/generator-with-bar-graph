/*
A rough Arduino sketch for mapping the analog values to digital values in 8 bit resolution.
(I may later map them to 10 bit values later if more accuracy is needed.(

*/

//A bar graph that responds to how close you are

const int SER   =8;    //Serial Output to Shift Register
const int LATCH =9;    //Shift Register Latch Pin
const int CLK   =10;   //Shift Register Clock Pin
const int GEN  =0;    //Generator through rev Zener diode on Analog Pin 0

//Possible LED settings
int vals[9] = {0,1,3,7,15,31,63,127,255};

//Max value provided by input pin
int maxValue = 500;

//Min value provided by analog input pin
int minValue = 0;

void setup()
{
  //Set pins as outputs
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
}

void loop()
{
  int generatedVoltage = analogRead(GEN);
  generatedVoltage = map(generatedVoltage, minValue, maxValue, 0, 8);
  generatedVoltage = constrain(generatedVoltage,0,8);

  digitalWrite(LATCH, LOW);                 //Latch LOW: Start sending
  shiftOut(SER, CLK, MSBFIRST, vals[distance]); //Send data.
  digitalWrite(LATCH, HIGH);                //Latch HIGH: Stop sending
  delay(10);                                //delay 10ms so led animation is observable 

}

