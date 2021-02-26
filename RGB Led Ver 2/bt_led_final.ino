/* RGB LED strip with arduino and Android App bluetooth connection
 *  http://www.electronoobs.com
 *  
ARDUINO       RGB      
  3          RED
  5          GREEN
  9          BLUE

Bluetooth HC-06 module and Arduino
ARDUINO    Bluetooth HC-06 
 0 (RX)       TX
 1 (TX)       RX
 5V           VCC
 GND          GND
 */
///////////////////////////////pre upload ERROR////////////////////////////////////
//#error delete this line after you make sure that the Tx and Rx pin are disconnected
//Tx and Rx pins of the HC06 module should not be connected while we upload the
//"Sketch" to the arduino. The code won't be upload if the pins are connected
///////////////////////////////////////////////////////////////////////////////////
int color=0;


int redPin = 3;   // Red LED,   connected to digital pin 9
int grnPin = 5;  // Green LED, connected to digital pin 10
int bluPin = 6;  // Blue LED,  connected to digital pin 11


//define the RGB pind
int red = 3;
int green = 5;
int blue = 6;

char received;



// Color arrays
int black[3]  = { 0, 0, 0 };
int white[3]  = { 100, 100, 100 };
int redsolid[3]    = { 100, 0, 0 };
int orange[3]=   {255,165,0};
int tomato[3]={255,99,71};
 int coral[3]={255,127,80};
 int indianred[3]={205,92,92};
 int lightcoral[3]={240,128,128};
 int darksalmon[3]={233,150,122};
 int salmon[3]={250,128,114};
 int lightsalmon[3]={255,160,122};
 int darkgoldenrod[3]={184,134,11};
 int goldenrod[3]={218,165,32};
 int palegoldenrod[3]={238,232,170};
 int darkkhaki[3]={189,183,107};
 int khaki[3]={240,230,140};
 int olive[3]={128,128,0};
 int yellow[3]={255,255,0};
 int yellowgreen[3]={154,205,50};
 int darkolivegreen[3]={85,107,47};
 int olivedrab[3]={107,142,35};
 int lawngreen[3]={124,252,0};
 int chartreuse[3]={127,255,0};
 int greenyellow[3]={173,255,47};
 int darkgreen[3]={0,100,0};
int greensolid[3]  = { 0, 100, 0 };
int forestgreen[3]={34,139,34};
 int lime[3]={0,255,0};
 int limegreen[3]={50,205,50};
 int lightgreen[3]={144,238,144};
 int palegreen[3]={152,251,152};
 int darkseagreen[3]={143,188,143};
 int mediumspringgreen[3]={0,250,154};
 int springgreen[3]={0,255,127};
 int seagreen[3]={46,139,87};
 int mediumaquamarine[3]={102,205,170};
 int mediumseagreen[3]={60,179,113};
 int lightseagreen[3]={32,178,170};
 int darkslategray[3]={47,79,79};
 int teal[3]={0,128,128};
 int darkcyan[3]= {0,139,139};
 int aqua[3]={0,255,255};
 int cyan[3]={0,255,255};
 int lightcyan[3]={224,255,255};
 int darkturquoise[3]={0,206,209};
 int turquoise[3]={64,224,208};
 int mediumturquois[3]={72,209,204};
 int paleturquoise[3]={175,238,238};
 int aquamarine[3]={127,255,212};
 int powderblue[3]={176,224,230};
 int cadetblue[3]={95,158,160};
 int steelblue[3]={70,130,180};
 int cornflowerblue[3]={100,149,237};
 int deepskyblue[3]={0,191,255};
 int dodgerblue[3]={30,144,255};
 int lightblue[3]={173,216,230};
 int skyblue[3]={135,206,235};
 int lightskyblue[3]={135,206,250};
 int midnightblue[3]={25,25,112};
 int navy[3]={0,0,128};
 int darkblue[3]={0,0,139};
 int mediumblue[3]={0,0,205};
int bluesolid[3]   = { 0, 0, 100 };
int royalblue[3]={65,105,225};
 int blueviolet[3]={138,43,226};
 int indigo[3]={75,0,130};
 int darkslateblue[3]={72,61,139};
 int slateblue[3]={106,90,205};
 int mediumslateblue[3]={123,104,238};
 int mediumpurple[3]={147,112,219};
 int darkmagenta[3]={139,0,139};
 int darkviolet[3]={148,0,211};
 int darkorchid[3]={153,50,204};
 int mediumorchid[3]={186,85,211};
 int purple[3]={128,0,128};
 int thistle[3]={216,191,216};
 int plum[3]={221,160,221};
 int violet[3]={238,130,238};
 int magenta[3]={255,0,255};
 int orchid[3]={218,112,214};
 int mediumvioletred[3]={199,21,133};
 int palevioletred[3]={219,112,147};
 int deeppink[3]={255,20,147};
 int hotpink[3]={255,105,180};
 int lightpink[3]={255,182,193};
 int pink[3]={255,192,203};
 int antiquewhite[3]={250,235,215};
 int beige[3]={245,245,220};
 int bisque[3]={255,228,196};
 int blanchedalmond[3]={255,235,205};
 int wheat[3]={245,222,179};
 int cornsilk[3]={255,248,220};
 int lemonchiffon[3]={255,250,205};
 int lightgoldenrodyellow[3]={250,250,210};
 int lightyellow[3]={255,255,224};
 int saddlebrown[3]={139,69,19};
 int sienne[3]= {160,82,45};
 int chocolate[3]={210,105,30};
 int peru[3]={205,133,63};
 int sandybrown[3]={244,164,96};
 int burlywood[3]={222,184,135};
 int tant[3]={210,180,140};
 int rosybrown[3]={188,143,143};
 int moccasin[3]={255,228,181};
 int navajowhite[3]={255,222,173};
 int peachpuff[3]={255,218,185};
 int mistyrose[3]={255,228,225};
 int lavenderblush[3]={255,240,245};
 int linen[3]={250,240,230};
 int oldlace[3]={253,245,230};
 int papayawhip[3]={255,239,213};
 int seashell[3]={255,245,238};
 int mintcream[3]={245,255,250};
 int slategray[3]={112,128,144};
 int lightslategray[3]={119,136,153};
 int lightsteelblue[3]={176,196,222};
 int lavender[3]={230,230,250};
 int floralwhite[3]={255,250,240};
 int aliceblue[3]={240,248,255};
 int ghostwhite[3]={248,248,255};
 int honeydew[3]={240,255,240};
 int ivory[3]={255,255,240};
 int azura[3]={240,255,255};
 int snow[3]={255,250,250};
  int dimWhite[3] = { 30, 30, 30 };

// Set initial color
int redVal = black[0];
int grnVal = black[1]; 
int bluVal = black[2];

int wait = 5;      // 10ms internal crossFade delay; increase for slower fades
int hold = 5;       // Optional hold when a color is complete, before the next crossFade
int DEBUG = 0;      // DEBUG counter; if set to 1, will write values back via serial
int loopCount = 0;//10000; // How often should DEBUG report?
int repeat = 1;     // How many times should we loop before stopping? (0 for no stop)
int j = 0;          // Loop counter for repeat

// Initialize color variables
int prevR = redVal;
int prevG = grnVal;
int prevB = bluVal;


/* BELOW THIS LINE IS THE MATH -- YOU SHOULDN'T NEED TO CHANGE THIS FOR THE BASICS
* 
* The program works like this:
* Imagine a crossfade that moves the red LED from 0-10, 
*   the green from 0-5, and the blue from 10 to 7, in
*   ten steps.
*   We'd want to count the 10 steps and increase or 
*   decrease color values in evenly stepped increments.
*   Imagine a + indicates raising a value by 1, and a -
*   equals lowering it. Our 10 step fade would look like:
* 
*   1 2 3 4 5 6 7 8 9 10
* R + + + + + + + + + +
* G   +   +   +   +   +
* B     -     -     -
* 
* The red rises from 0 to 10 in ten steps, the green from 
* 0-5 in 5 steps, and the blue falls from 10 to 7 in three steps.
* 
* In the real program, the color percentages are converted to 
* 0-255 values, and there are 1020 steps (255*4).
* 
* To figure out how big a step there should be between one up- or
* down-tick of one of the LED values, we call calculateStep(), 
* which calculates the absolute gap between the start and end values, 
* and then divides that gap by 1020 to determine the size of the step  
* between adjustments in the value.
*/

int calculateStep(int prevValue, int endValue) {
  int step = endValue - prevValue; // What's the overall gap?
  if (step) {                      // If its non-zero, 
    step = 1020/step;              //   divide by 1020
  } 
  return step;
}

/* The next function is calculateVal. When the loop value, i,
*  reaches the step size appropriate for one of the
*  colors, it increases or decreases the value of that color by 1. 
*  (R, G, and B are each calculated separately.)
*/

int calculateVal(int step, int val, int i) {

  if ((step) && i % step == 0) { // If step is non-zero and its time to change a value,
    if (step > 0) {              //   increment the value if step is positive...
      val += 1;           
    } 
    else if (step < 0) {         //   ...or decrement it if step is negative
      val -= 1;
    } 
  }
   //Defensive driving: make sure val stays in the range 0-255
  if (val > 255) {
    val = 255;
  } 
  else if (val < 0) {
    val = 0;
  }
  return val;
}

/* crossFade() converts the percentage colors to a 
*  0-255 range, then loops 1020 times, checking to see if  
*  the value needs to be updated each time, then writing
*  the color values to the correct pins.
*/



void crossFade(int color[3]) {
  // Convert to 0-255
  int R = (color[0] * 255) / 100;
  int G = (color[1] * 255) / 100;
  int B = (color[2] * 255) / 100;

  int stepR = calculateStep(prevR, R);
  int stepG = calculateStep(prevG, G); 
  int stepB = calculateStep(prevB, B);

  for (int i = 0; i <= 1020; i++) {
    redVal = calculateVal(stepR, redVal, i);
    grnVal = calculateVal(stepG, grnVal, i);
    bluVal = calculateVal(stepB, bluVal, i);

    analogWrite(redPin, redVal);   // Write current values to LED pins
    analogWrite(grnPin, grnVal);      
    analogWrite(bluPin, bluVal); 
   delay(wait); // Pause for 'wait' milliseconds before resuming the loop

//    if (DEBUG) { // If we want serial output, print it at the 
//      if (i == 0 or i % loopCount == 0) { // beginning, and every loopCount times
//        Serial.print("Loop/RGB: #");
//        Serial.print(i);
//        Serial.print(" | ");
//        Serial.print(redVal);
//        Serial.print(" / ");
//        Serial.print(grnVal);
//        Serial.print(" / ");  
//        Serial.println(bluVal); 
//      } 
//      DEBUG += 1;
//    }
  }
  // Update current values for next loop
  prevR = redVal; 
  prevG = grnVal; 
  prevB = bluVal;
  delay(hold); // Pause for optional 'wait' milliseconds before resuming the loop
}

void setup()  { 
  digitalWrite(8,HIGH); //RESET PIN HIGH ALWAYS
  delay(200);
  
  
  Serial.begin(9600);     //Start the serial comunication for the bluetooth module
  
  pinMode(red, OUTPUT);   //Red color pwm pin defined as output
  pinMode(green, OUTPUT); //Green color pwm pin defined as output
  pinMode(blue, OUTPUT);  //Blue color pwm pin defined as output
  pinMode(8, OUTPUT);   //PIN for RESET as Output
  
  //Give first value of the PWM 0, we start with the RGB LEDs off
  analogWrite(red,0);
  analogWrite(green,0);
  analogWrite(blue,0);

 } 
 
void loop()  { 
  
  if(Serial.available()>0){
    // read the bluetoot data and store it
    color = Serial.read();
    char Rec = char(color);
    if (Rec != '0')
    {
    Serial.println(Rec); //This is to visualise the received character on the serial monitor
    }  
  }


  //LEDs off
  if (color == 'n')
  {
    analogWrite(red,0);
    analogWrite(green,0);
    analogWrite(blue,0);
  }
  //White
  if (color == 'w')
  {
    analogWrite(red,255);
    analogWrite(green,255);
    analogWrite(blue,255);
  }
  //Red
  if (color == 'r')
  {
    analogWrite(red,255);
    analogWrite(green,0);
    analogWrite(blue,0);
  }
  //Green
  if (color == 'g')
  {
    analogWrite(red,0);
    analogWrite(green,255);
    analogWrite(blue,0);
  }
  //Blue
  if (color == 'b')
  {
    analogWrite(red,0);
    analogWrite(green,0);
    analogWrite(blue,255);
  }
  //Orange
  if (color == 'o')
  {
    analogWrite(red,255);
    analogWrite(green,153);
    analogWrite(blue,0);
  }
  //Violet
  if (color == 'v')
  {
    analogWrite(red,102);
    analogWrite(green,0);
    analogWrite(blue,153);
  }
  //Cyan
  if (color == 'c')
  {
    analogWrite(red,0);
    analogWrite(green,255);
    analogWrite(blue,255);
  }
  //Yellow 
  if (color == 'y')
  {
    analogWrite(red,255);
    analogWrite(green,204);
    analogWrite(blue,0);
  }  

//Yellow 
  if (color == 'z')
  {
    digitalWrite(8,LOW);
    delay(50);
    digitalWrite(8,HIGH);
    
  }  


if (color == 'f')
{
  //crossFade(orange);
  crossFade(redsolid);
  crossFade(coral);
  crossFade(goldenrod);
  crossFade(greenyellow);
  crossFade(darkgreen);
  crossFade(greensolid);
  crossFade(bluesolid);
  crossFade(white);
  crossFade(bluesolid);
  crossFade(redsolid);
  crossFade(greensolid);
 
  crossFade(redsolid);
  crossFade(coral);
  crossFade(goldenrod);
  crossFade(greenyellow);
  crossFade(darkgreen);
  crossFade(greensolid);
  crossFade(bluesolid);
  crossFade(white);
  crossFade(bluesolid);
  crossFade(redsolid);
  

//  if (repeat) { // Do we loop a finite number of times?
//    j += 1;
//    if (j >= repeat) { // Are we there yet?
//      exit(j);         // If so, stop.
   // }
 // }
}


  
}
