// Menyertakan Library sensor PING //
#include <NewPing.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>         //memanggil library LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);   //kalau masih tidak tampil, ganti menjadi 0x3f(alamat i2c)

#include <DFPlayer_Mini_Mp3.h>        //memanggil library DFplayer
#include <SoftwareSerial.h>
// Pin Arduino yang terhubung ke pin trigger HC-SR04 // sensor sampah
#define trigPin A0 //Set Trigger HCSR04 di Pin digital 12
#define echoPin A1 
//sensor kapasitas

#define TRIGGER_PIN2    11    //pin trigger dihubungkan ke pin 10 arduino
#define ECHO_PIN2       12    //pin echo dihubungkan ke pin 9 arduino

// Jarak maksimum yang dapat di ukur oleh sensor, maks 400 cm //
#define MAX_DISTANCE 200

NewPing sampah(trigPin, echoPin, MAX_DISTANCE);
NewPing kapasitas(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE); //membuat variabel kapasitas

int LEDhijau = 3, LEDmerah = 2;
SoftwareSerial mySerial(6, 7); 
Servo myservo;

void setup()
{
  // Memulai komunikasi serial //
  Serial.begin(9600);
  lcd.begin();
  
  pinMode(LEDmerah, OUTPUT); //Set LEDmerah sebagai output
  pinMode(LEDhijau, OUTPUT); //Set LEDhijau sebagai output
  myservo.attach(10);
  pinMode(trigPin, OUTPUT); //Set pin Trigger sebagai output
  pinMode(echoPin, INPUT); 
  mp3_set_serial (Serial);
  mp3_set_volume (30);           //pengaturan volume (0-30)
}

void loop()
{
  int duration, jarak, posisi=0 ,i;
  // Memberi jeda 50 milli seconds untuk setiap PING //
  delay(1000);
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  jarak = (duration/2) / 29.1;
  Serial.print(jarak);
  Serial.println(" cm");
  
if(jarak<=15) // Jarak (Cm) dapat anda sesuaikan

 {
   digitalWrite(LEDhijau, LOW); //LEDhijau mati
   digitalWrite(LEDmerah, HIGH); //LEDmerah hidup
   myservo.write(180); //Posisi servo pada 180 derajat
   delay(450); //Delay
   digitalWrite(LEDmerah, LOW); //LEDmerah mati
   myservo.write(180); //Posisi servo pada 90 derajat
   delay(450); //Delay
   digitalWrite(LEDmerah, HIGH); //LEDmerah hidup
   myservo.write(0); //Posisi servo pada 0 derajat
   delay(5000); //Delay
   digitalWrite(LEDmerah, LOW); //LEDmerah mati
   myservo.write(180); //Posisi servo pada 90 derajat
}

 else{ //Jika jarak lebih dari yang ditentukan
   digitalWrite(LEDmerah, LOW); //LEDmerah mati
   digitalWrite(LEDhijau, HIGH); //LEDhijau hidup
   myservo.write(180); //Posisi servo pada 90 derajat
 }

  int US2 = kapasitas.ping_cm()+71; 

  //tampilkan ke lcd
  lcd.setCursor(0, 0); //set kolom dan baris
  lcd.print(" Sisa Kapasitas ");
  lcd.setCursor(0, 1); //set kolom dan baris
  lcd.print("Tong Sampah:");
  lcd.print(US2);
  lcd.print("%");
  delay (50);
delay(450); //Delay
}
