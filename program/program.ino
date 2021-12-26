


#include <NewPing.h>         
#include <Servo.h>           

#define TRIGGER_PIN   2      
#define ECHO_PIN      6       
//sensor kapasitas
#define TRIGGER_PIN2  A1      
#define ECHO_PIN2     A0      
#define MAX_DISTANCE 200     

#include <LiquidCrystal_I2C.h>        
LiquidCrystal_I2C lcd(0x27, 16, 2);  

#include <DFPlayer_Mini_Mp3.h>       
#include <SoftwareSerial.h>

Servo servoAne;
NewPing sampah(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);     
NewPing kapasitas(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE); 

const int ledHijau = 3;        
const int ledMerah = 2;        

void setup() {
  Serial.begin(9600);
  lcd.begin();
  servoAne.attach(9);           
  servoAne.write(0);

  mp3_set_serial (Serial);
  mp3_set_volume (30);           

  pinMode (ledHijau, OUTPUT);     
  pinMode (ledMerah, OUTPUT);    
}

void loop() {

  delay(50);
  int US1 = sampah.ping_cm();
  int US2 = kapasitas.ping_cm()+71;   

  Serial.print("sampah : ");
  Serial.print(US1);
  Serial.println("cm ");

  lcd.setCursor(0, 0); //set kolom dan baris
  lcd.print(" Sisa Kapasitas ");
  lcd.setCursor(0, 1); //set kolom dan baris
  lcd.print("Tong Sampah:");
  lcd.print(US2);
  lcd.print("%");
  delay (50);

 
  if(US1 <= 10){
    servoAne.write(180);            //posisikan servo di 180 derajat
    digitalWrite (ledMerah, LOW);   //LED merah padam
    digitalWrite (ledHijau, HIGH);  //LED hijau nyala
    mp3_play(1);
    delay (4000); //durasi disesuaikan dengan durasi musik
  }

  else{
    servoAne.write(0);  //posisikan servo di 0 derajat
    delay(5);
    mp3_stop();
    

  digitalWrite (ledMerah, HIGH);    //LED merah nyala
  digitalWrite (ledHijau, LOW);     //LED hijau padam
  }
}
