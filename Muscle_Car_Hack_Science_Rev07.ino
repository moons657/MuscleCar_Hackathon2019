//Muscle Car Project 

// Setup of Input Pins 
const int FWD = PUSH2;  //Input Pin 15
const int BCK = 31;     //Input Pin 31


const int analogInPin =A0;  //Left arm Input?
const int analogInPin2 = A1;//Right arm Input?
const int analogInPin3 = A2;
const int analogInPin4 =A3;
const int analogInPin5 = A8;
const int analogInPin6 =A9;
const int analogInPin7 =A10;
const int analogInPin8 = A11;

//Setup of Output Pins 

const int REVCTRL = 23;
const int FWDCTRL = 24;
const int LFTCTRL = 26;
const int RGTCTRL = 25;

int ledState =LOW;
int ButtonState1 = LOW;
int ButtonState2 = LOW;

int AnalogSenseValue = 0;
int AnalogSenseValue2 =0;
int AnalogSenseValue3 =0;
int AnalogSenseValue4=0;


int Sense1Array[8];
int Sense2Array[8];
int Sense3Array[8];
int Sense4Array[8];
int Sense5Array[8];
int Sense6Array[8];
int Sense7Array[8];
int Sense8Array[8];

int SenseAvg =0;
int Sense2Avg =0;
int Sense3Avg =0;
int Sense4Avg =0;
int Sense5Avg =0;
int Sense6Avg =0;
int Sense7Avg =0;
int Sense8Avg =0;

int Upper_Thres=2048;
int Lower_Thres=2048;
int Upper_Thres2=2048;
int Lower_Thres2=2048;
int Upper_Thres3=2048;
int Lower_Thres3=2048;
int Upper_Thres4=2048;
int Lower_Thres4=2048;
int Upper_Thres5=2048;
int Lower_Thres5=2048;
int Upper_Thres6=2048;
int Lower_Thres6=2048;
int Upper_Thres7=2048;
int Lower_Thres7=2048;
int Upper_Thres8=2048;
int Lower_Thres8=2048;
int IdleCount = 0;

#define Thres1 1840
#define Thres2 1515

int CMD =0;

int State=0;


void setup() 
{
  Serial.begin(9600);

//Inputs Setup
pinMode(BCK, INPUT_PULLUP);
pinMode(PUSH2, INPUT_PULLUP);

//Outputs Setup 
pinMode(GREEN_LED, OUTPUT);
pinMode(RED_LED,OUTPUT);

pinMode(FWDCTRL, OUTPUT);
pinMode(REVCTRL, OUTPUT);
pinMode(LFTCTRL, OUTPUT);
pinMode(RGTCTRL, OUTPUT);
 
  while(digitalRead(BCK) ==HIGH)
    { 
  int newValue = analogRead(analogInPin);
  int newValue2 = analogRead(analogInPin2);
  int newValue3  = analogRead(analogInPin3);
  int newValue4  = analogRead(analogInPin4);

  int newValue5 = analogRead(analogInPin5);
  int newValue6 = analogRead(analogInPin6);
  int newValue7  = analogRead(analogInPin7);
  int newValue8  = analogRead(analogInPin8);
  
    if(Upper_Thres < newValue)
    {
      Upper_Thres = newValue;
    }
    else if(Lower_Thres > newValue)
    {
      Lower_Thres = newValue;
    }
    if(Upper_Thres2 < newValue2)
    {
      Upper_Thres2 = newValue2;
    }
    else if(Lower_Thres2> newValue2)
    {
      Lower_Thres2 = newValue2;
    }
    if(Upper_Thres3< newValue3)
    {
      Upper_Thres3 = newValue3;
    }
    else if(Lower_Thres3> newValue3)
    {
      Lower_Thres3 = newValue3;
    }
    if(Upper_Thres4< newValue4)
    {
      Upper_Thres4 = newValue4;
    }
    else if(Lower_Thres4> newValue4)
    {
      Lower_Thres4 = newValue4;
    }
        if(Upper_Thres5 < newValue5)
    {
      Upper_Thres5 = newValue5;
    }
    else if(Lower_Thres5 > newValue5)
    {
      Lower_Thres5 = newValue5;
    }
    if(Upper_Thres6 < newValue6)
    {
      Upper_Thres6 = newValue6;
    }
    else if(Lower_Thres6> newValue6)
    {
      Lower_Thres6 = newValue6;
    }
    if(Upper_Thres7< newValue7)
    {
      Upper_Thres7 = newValue7;
    }
    else if(Lower_Thres7> newValue7)
    {
      Lower_Thres7 = newValue7;
    }
    if(Upper_Thres8< newValue8)
    {
      Upper_Thres8 = newValue8;
    }
    else if(Lower_Thres8> newValue8)
    {
      Lower_Thres8 = newValue8;
    }
    Serial.println("Up1  Low1 Up2  Low2 Up3  Low3 Up4  Low4 Up5  Low5 Up6  Low6 Up7  Low7 Up8  Low8");
    Serial.print(Upper_Thres);
    Serial.print(" ");
    Serial.print(Lower_Thres);
    Serial.print(" ");
    Serial.print(Upper_Thres2);
    Serial.print(" ");
    Serial.print(Lower_Thres2);
    Serial.print(" ");
    Serial.print(Upper_Thres3);
    Serial.print(" ");
    Serial.print(Lower_Thres3);
    Serial.print(" ");
    Serial.print(Upper_Thres4);
    Serial.print(" ");
    Serial.print(Lower_Thres4);
    Serial.print(" ");
    Serial.print(Upper_Thres5);
    Serial.print(" ");
    Serial.print(Lower_Thres5);
    Serial.print(" ");
    Serial.print(Upper_Thres6);
    Serial.print(" ");
    Serial.print(Lower_Thres6);
    Serial.print(" ");
    Serial.print(Upper_Thres7);
    Serial.print(" ");
    Serial.print(Lower_Thres7);
    Serial.print(" ");
    Serial.print(Upper_Thres8);
    Serial.print(" ");
    Serial.println(Lower_Thres8);
    delay(1000); 
    } 
}
void loop() 
{
 
//  if(Serial.available()>0)
//  {
//    CMD = Serial.parseInt();
//  }
//  else
//  Serial.println("Analog Level tests");
  //////////Analog Read in //////////////


//AnalogSenseValue = analogRead(analogInPin);
//AnalogSenseValue2 =analogRead(analogInPin2);
//AnalogSenseValue3 =analogRead(analogInPin3);
//AnalogSenseValue4=analogRead(analogInPin4);

//  for(int i =0; i<8; i++)
// {
//
//   Sense1Array[i] = analogRead(analogInPin);
//   Sense2Array[i] = analogRead(analogInPin2);
//   Sense3Array[i] = analogRead(analogInPin3);
//   Sense4Array[i] = analogRead(analogInPin4);
//  }

  ///////////Average Sum for arrays///////

//SenseAvg = (Sense1Array[0]+Sense1Array[1]+Sense1Array[2]+Sense1Array[3]+Sense1Array[4]+Sense1Array[5]+Sense1Array[6]+Sense1Array[7])/8;
//Sense2Avg = (Sense2Array[0]+Sense2Array[1]+Sense2Array[2]+Sense2Array[3]+Sense2Array[4]+Sense2Array[5]+Sense2Array[6]+Sense2Array[7])/8;
//Sense3Avg = (Sense3Array[0]+Sense3Array[1]+Sense3Array[2]+Sense3Array[3]+Sense3Array[4]+Sense3Array[5]+Sense3Array[6]+Sense3Array[7])/8;
//Sense4Avg = (Sense4Array[0]+Sense4Array[1]+Sense4Array[2]+Sense4Array[3]+Sense4Array[4]+Sense4Array[5]+Sense4Array[6]+Sense4Array[7])/8;

   SenseAvg = analogRead(analogInPin);
   Sense2Avg = analogRead(analogInPin2);
   Sense3Avg = analogRead(analogInPin3);
   Sense4Avg = analogRead(analogInPin4);

   
///////////Serial Print Code ////////////

// Serial.print(Sense1Array[0,1,2,3,4,5,6,7]);
// Serial.print(" ");
// Serial.print(Sense2Array[0,1,2,3,4,5,6,7]);
// Serial.print(Sense3Array[0,1,2,3,4,5,6,7]);
// Serial.print(" ");
// Serial.println(Sense4Array[0,1,2,3,4,5,6,7]);
// delay(10);

// Serial.print(AnalogSenseValue);
// Serial.print(" ");
// Serial.println(AnalogSenseValue2);
//Serial.print("Test");

Serial.print(Thres1);
Serial.print(" ");
Serial.print(Thres2);
Serial.print(" ");
Serial.print(SenseAvg);
Serial.print(" ");
//Serial.println(Sense2Avg);
//Serial.print(" ");
Serial.println(Sense3Avg);
//Serial.print(" ");
//Serial.println(Sense4Avg);
delay(10);
 
 ///////////////////////////////////////

///////Setting State Machine up/////////

State =0;
//if(SenseAvg >Lower_Thres && SenseAvg< Upper_Thres)
//{
//  State +=1;
//}
//if(Sense2Avg >Lower_Thres2 && Sense2Avg< Upper_Thres2)
//{
//  State+=2;
//}
//if(Sense3Avg > Lower_Thres3 && Sense3Avg < Upper_Thres3)
//{
//  State+=4;
//}
//if( Sense4Avg > Lower_Thres4 && Sense4Avg <Upper_Thres4)
//{
//  State+=8;
//}

if(SenseAvg >Thres1)
{
  State +=1;
}
if(Sense2Avg>Thres1)
{
  State+=2;
}
if(Sense3Avg>Thres2)
{
  State+=4;
}
if(Sense4Avg>Thres1)
{
  State+=8;
}

 //////////Read the buttons/////////////
//  ButtonState1 = digitalRead(FWD);
//  ButtonState2 = digitalRead(BCK);


// Serial.println(CMD); 
// if(CMD == 1) //Forwards
// {
//  digitalWrite(FWDCTRL, HIGH);
//  digitalWrite(ledPin, HIGH);
// } 
// else if(CMD ==2) //Backwards
// {
//  digitalWrite(REVCTRL,HIGH);
//  digitalWrite(ledPin2, HIGH);
// }
// else if(CMD ==3) //Left 
// {
//  digitalWrite(LFTCTRL, HIGH);
// }
// else if(CMD ==4) //Right 
// {
//  digitalWrite(RGTCTRL, HIGH);
// }
// else if(CMD ==13)//Drive forwards & left 
// {
//  digitalWrite(FWDCTRL, HIGH);
//  digitalWrite(LFTCTRL, HIGH);
// }
// else if(CMD ==14)
// {
//  digitalWrite(FWDCTRL, HIGH);
//  digitalWrite(RGTCTRL, HIGH);
// }
//  else if(CMD ==23)//Drive backwards & left 
// {
//  digitalWrite(FWDCTRL, HIGH);
//  digitalWrite(LFTCTRL, HIGH);
// }
// else if(CMD ==24) //Drive backwards and right 
// {
//  digitalWrite(FWDCTRL, HIGH);
//  digitalWrite(RGTCTRL, HIGH);
// }
// else if(CMD ==5) //All off 
// {
// digitalWrite(FWDCTRL, LOW);
// digitalWrite(REVCTRL, LOW);
// digitalWrite(LFTCTRL, LOW);
// digitalWrite(RGTCTRL, LOW);
// }

// delay(100);

  switch (State) {
    case 0:                       // Stop
    digitalWrite(FWDCTRL, LOW);
    digitalWrite(REVCTRL, LOW);
    digitalWrite(LFTCTRL, LOW);
    digitalWrite(RGTCTRL, LOW);
    IdleCount++;
    if((IdleCount>80)&&(IdleCount<100))
    {
      digitalWrite(REVCTRL, HIGH);
    }
    delay(10);
    break;
    case 1:                       //Forward & left 
    digitalWrite(FWDCTRL, HIGH);
    digitalWrite(REVCTRL, LOW);
    digitalWrite(LFTCTRL, HIGH);
    digitalWrite(RGTCTRL, LOW);
    IdleCount = 0;
    break;
    case 2:                       //Reverse
    digitalWrite(FWDCTRL, LOW);
    digitalWrite(REVCTRL, LOW);
    digitalWrite(LFTCTRL, LOW);
    digitalWrite(RGTCTRL, LOW);
    break;
    case 4:                       //Forward and right
    digitalWrite(FWDCTRL, HIGH);
    digitalWrite(REVCTRL, LOW);
    digitalWrite(LFTCTRL, LOW);
    digitalWrite(RGTCTRL, HIGH);
    IdleCount = 0;
    break;
    case 8:                       //
    digitalWrite(FWDCTRL, LOW);
    digitalWrite(REVCTRL, LOW);
    digitalWrite(LFTCTRL, LOW);
    digitalWrite(RGTCTRL, LOW);
    break;
    case 5:                       //Forward
    digitalWrite(FWDCTRL, HIGH);
    digitalWrite(REVCTRL, LOW);
    digitalWrite(LFTCTRL, LOW);
    digitalWrite(RGTCTRL, LOW);
    IdleCount = 0;
    break;
//    case 6:                       //Right Reverse
//    digitalWrite(FWDCTRL, LOW);
//    digitalWrite(REVCTRL, HIGH);
//    digitalWrite(LFTCTRL, LOW);
//    digitalWrite(RGTCTRL, HIGH);
//    break;
//     case 9:                       //Left Forward
//    digitalWrite(FWDCTRL, HIGH);
//    digitalWrite(REVCTRL, LOW);
//    digitalWrite(LFTCTRL, HIGH);
//    digitalWrite(RGTCTRL, LOW);
//    break;
//    case 10:                       //Left Reverse
//    digitalWrite(FWDCTRL, LOW);
//    digitalWrite(REVCTRL, HIGH);
//    digitalWrite(LFTCTRL, HIGH);
//    digitalWrite(RGTCTRL, LOW);
    break;
    default:
    digitalWrite(FWDCTRL, LOW);
    digitalWrite(REVCTRL, LOW);
    digitalWrite(LFTCTRL, LOW);
    digitalWrite(RGTCTRL, LOW);
    IdleCount++;
    if((IdleCount>80)&&(IdleCount<100))
    {
      digitalWrite(REVCTRL, HIGH);
    }
    delay(10);
        // Do Nothing
    break;
    }
  

}
