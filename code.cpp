#define REMOTEXY_MODE__ESP32CORE_BLE
#include <BLEDevice.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "Ai-Rover"

#define motor1_1 23
#define motor1_2 22
#define motor2_1 1
#define motor2_2 3
#define motor3_1 21
#define motor3_2 19
#define motor4_1 18
#define motor4_2 5

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 70 bytes
  { 255,6,0,0,0,63,0,16,21,0,5,0,8,18,25,25,37,26,31,1,
  0,71,19,12,12,2,31,85,112,0,1,0,72,39,12,12,2,31,68,111,
  119,110,0,1,0,83,28,12,12,2,31,67,108,111,115,101,0,1,0,60,
  29,12,12,2,31,79,112,101,110,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystick_1_x; // from -100 to 100  
  int8_t joystick_1_y; // from -100 to 100  
  uint8_t button_2; // =1 if button pressed, else =0 
  uint8_t button_3; // =1 if button pressed, else =0 
  uint8_t button_4; // =1 if button pressed, else =0 
  uint8_t button_1; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)


int8_t motor1_1 = 1,motor1_2=2 ,motor2_1 =3 , motor2_2=4 , motor3_1=5 , motor3_2=6 , motor4_1=7 ,motor4_2=8  ; 

void setup() 
{
  RemoteXY_Init (); 

  Serial.println("In setup");

  
  
 
  // TODO you setup code
  pinMode(motor1_1,OUTPUT);
  pinMode(motor1_2,OUTPUT);
  pinMode(motor2_1,OUTPUT);
  pinMode(motor2_2,OUTPUT);
  pinMode(motor3_1,OUTPUT);
  pinMode(motor3_2,OUTPUT);
  pinMode(motor4_1,OUTPUT);
  pinMode(motor4_2,OUTPUT);

   Serial.begin(115200);
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  if(RemoteXY.button_2 == 1)
  {
    Serial.println("UP");
    digitalWrite(motor1_1,HIGH);
    digitalWrite(motor1_2,LOW);
  }
  else
  {
    Serial.println("UP--Stop");
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,LOW);
  }
  if(RemoteXY.button_3 == 1)
  {
    Serial.println("Down");
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,HIGH);
  }
  else
  {
    Serial.println("Down--Stop");
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,LOW);  
  }
  
  if(RemoteXY.button_1 == 1)
  {
    Serial.println("OPEN");
    digitalWrite(motor2_1,HIGH);
    digitalWrite(motor2_2,LOW);
  }
  else
  {
    Serial.println("OPEN--Stop");
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,LOW);
  }
  
  if(RemoteXY.button_4 == 1)
  {
    Serial.println("Close");
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,HIGH);
  }
  else
  {
    Serial.println("Close--Stop");
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,LOW);
  }
  
  if(RemoteXY.joystick_1_x == -100)
  {
    Serial.println("Move left");
    digitalWrite(motor3_1,LOW);
    digitalWrite(motor4_1,HIGH);
    digitalWrite(motor3_2,HIGH);
    digitalWrite(motor4_2,LOW);
  }
  else
  {
    Serial.println("Move left -- Stop");
    digitalWrite(motor3_1,LOW);
    digitalWrite(motor4_1,LOW);
    digitalWrite(motor3_2,LOW);
    digitalWrite(motor4_2,LOW);
  }

  if(RemoteXY.joystick_1_x == 100)
  {
    Serial.println("Move Right");
    digitalWrite(motor3_1,HIGH);
    digitalWrite(motor4_1,LOW);
    digitalWrite(motor3_2,LOW);
    digitalWrite(motor4_2,HIGH);
  }
  else
  {    
      Serial.println("Move Right--Stop");
    digitalWrite(motor3_1,LOW);
    digitalWrite(motor4_1,LOW);
    digitalWrite(motor3_2,LOW);
    digitalWrite(motor4_2,LOW); 
  }

  if(RemoteXY.joystick_1_y == 100)
  {
    Serial.println("Move Forward");
    digitalWrite(motor3_1,HIGH);
    digitalWrite(motor4_1,HIGH);
    digitalWrite(motor3_2,LOW);
    digitalWrite(motor4_2,LOW);
  }
  else
  {
    Serial.println("Move Forward--Stop");
    digitalWrite(motor3_1,LOW);
    digitalWrite(motor4_1,LOW);
    digitalWrite(motor3_2,LOW);
    digitalWrite(motor4_2,LOW);
  }

   if(RemoteXY.joystick_1_y == -100)
  {
    Serial.println("Move Backward");
    digitalWrite(motor3_1,LOW);
    digitalWrite(motor4_1,LOW);
    digitalWrite(motor3_2,HIGH);
    digitalWrite(motor4_2,HIGH);
  }
  else
  {
    Serial.println("Move Backward-- Stop");
    digitalWrite(motor3_1,LOW);
    digitalWrite(motor4_1,LOW);
    digitalWrite(motor3_2,LOW);
    digitalWrite(motor4_2,LOW);
  }
  Serial.print(RemoteXY.joystick_1_y);
   

Serial.println("------------------------");
delay(1000);
}
