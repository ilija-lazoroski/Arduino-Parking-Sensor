bool change=false; //variable to check if something entered the red zone

double duration; //duration is used to determine the distance sensed from the rangefinder
int distance; //the distance found from the rangefinder

//the corresponding pins for the RBG LED
int red = 3;
int blue = 4;
int green = 5;

int buzzer = 6; //the corresponding pin for the buzzer

void setup() {
  Serial.begin(9600); //enable the serial monitor at a 9600 baud rate
  
  //make the LED and buzzer an output from the Arduino
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() { 
  getDistance(); //find the distance of any object (if there even is an object)
  delay(10); //wait for the computer to catch up
  alert(); //let the user know what distance we found
}


void getDistance(){
  pinMode(A5, OUTPUT); //set the rangefinder pin to be an output in preparation to send a pulse 

  analogWrite(A5, 0); //start with no output, start with a clean slate
  delayMicroseconds(2); //let the computer catch up
  analogWrite(A5, 256); //send out the pulse
  delayMicroseconds(5); //wait 5 ms before turning off the pulse
  analogWrite(A5, 0); //turn off the pulse

  pinMode(A5, INPUT); //set rangefinder pin back to input to be ready to catch the bounced sound wave 
  
  duration = pulseIn(A5, HIGH); //pulseIn() function reads the time it took for wave to bounce back
  distance = (duration/2)/29.1; //converts the found time to distance cm (using physics and math)
  delay(10); //this slows down the rate at which we take distance measurements

  Serial.println(distance); //debugging
}


void alert(){
  //turn off all the LEDs
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  
  int val = distance;
  val = map(val,0,200,600,300);
  
  Serial.println(val);
  if(distance > 50){ //if object is far away, LED set to green and allow change to be true
    digitalWrite(green,HIGH);
    tone(buzzer,val,1000);
  }
  if(distance < 50 && distance > 25){ //if the object not too far or too close, 
    digitalWrite(blue,HIGH);           //make LED blue and allow change to be true
    tone(buzzer,val,1000);
    change = true;
  }
  if(distance < 25){ //if the object gets close, make the LED red
    digitalWrite(red,HIGH);
    tone(buzzer,val,1000);
    change = false; //disable change                 //then play the music
  }
}


