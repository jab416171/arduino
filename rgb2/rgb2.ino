/*
 * LED Fading for 3 LEDs or RGB-LED
 * The program fades to a color
 * Manuel Rosinus <rossinie@rossinie.de>  
 */

// Output
int redPin   = 11;   // Red LED,   connected to digital pin 9
int bluePin  = 10;  // Blue LED,  connected to digital pin 10
int greenPin = 9;  // Green LED, connected to digital pin 11

// Program variables
int redIs   = 255;   // LED off  - Depends on your +/- Settings of the LED
int greenIs = 255;   // LED off 
int blueIs  = 255;   // LED off 

int VERBOSE = 0; // Verbose Level; 0 = no Output (faster); 1 = Just Loop Output; 2 = Loop+Function Output

void setup()
{
  pinMode(redPin,   OUTPUT);   // sets the pins as output
  pinMode(greenPin, OUTPUT);   
  pinMode(bluePin,  OUTPUT); 
  if (VERBOSE > 0) {       
    Serial.begin(9600); 
  }
}

// Main program
void loop()
{
  fade2Color(1,255,255,10); // red
  delay(1000);
  fade2Color(1,255,1,10); // yellow
  delay(1000);
  fade2Color(255,255,1,10); // green
  delay(1000);
  fade2Color(255,1,1,10); // cyan
  delay(1000);
  fade2Color(255,1,255,10); // blue
  delay(1000);
  fade2Color(1,1,255,10); // magenta
  delay(1000);

  if (VERBOSE > 0) {    
    Serial.println("Loop end"); 
  }

}

// Return max int of a,b,c
int getMax(int a, int b, int c){
  if(a>=b) {
    if (a>=c){
      return a;
    } 
    else {
      return c;
    }
  } 
  else { 
    if (b>=c){
      return b;
    } 
    else {
      return c;
    }
  }
}

// Returns difference of 2 int
int getDiff(int a, int b){
  if(a>=b) {
    return a-b;
  } 
  else { 
    return b-a;
  }
}

void fade2Color(int redTo, int greenTo, int blueTo, int speedVal){
  int redDiff = getDiff(redIs, redTo);
  int greenDiff = getDiff(greenIs, greenTo); 
  int blueDiff = getDiff(blueIs, blueTo); 
  int maxRange = getMax(redDiff,greenDiff,blueDiff);
  /* sorry futur-me for this confusing code */

  for (int i=1; i<maxRange; i++){
    if (redIs < redTo){
      redIs    += 1;
    } 
    else if (redIs > redTo){
      redIs    -= 1;
    } 
    else {
      redIs = redTo;
    }
    if (greenIs < greenTo){
      greenIs    += 1;
    } 
    else if (greenIs > greenTo){
      greenIs    -= 1;
    } 
    else {
      greenIs = greenTo;
    }   
    if (blueIs < blueTo){
      blueIs    += 1;
    } 
    else if (blueIs > blueTo){
      blueIs    -= 1;
    } 
    else {
      blueIs = blueTo;
    }
    analogWrite(redPin,   redIs);  
    analogWrite(greenPin, greenIs); 
    analogWrite(bluePin,  blueIs);  
    delay(speedVal);

    if (VERBOSE > 1) { 

      Serial.print("R is:");   
      Serial.print(redIs); 
      Serial.print(" R to:");  
      Serial.print(redTo);  
      Serial.print(" ");    

      Serial.print("G is:");   
      Serial.print(greenIs);
      Serial.print(" G to:");   
      Serial.print(greenTo);
      Serial.print(" ");  

      Serial.print("B is:");    
      Serial.print(blueIs);
      Serial.print(" B to:");    
      Serial.println(blueTo);
    }
  }
}

void off(){
  fade2Color(255 , 255 , 255, 1);
}

void on(){
  fade2Color(0 , 0 , 0, 1);
}


