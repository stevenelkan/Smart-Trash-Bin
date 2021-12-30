#define merah 6 //pin LED Merah
#define hijau 7 // pin LED Hijau
#define trig 4  //
#define echo 5
#define trig2 2
#define echo2 3
#define pinservo 8 

#include<Servo.h>
#include<LiquidCrystal_I2C.h>
#include<DFPlayer_Mini_Mp3.h> // untuk bisa menggunakan df player mini
#include<SoftwareSerial.h> // untuk menggunakan pin serial.

Servo servo;
LiquidCrystal_I2C lcd (0x27,16,2); // alamat lcd 0x27 dan ukuran 16x2
void setup() {
  Serial.begin(9600);
  pinMode(merah,OUTPUT);
  pinMode(hijau,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  servo.attach(pinservo);
  
  servo.write(0);// membuat servo di sudut 0 derajat
  lcd.init();  // untuk mulai menggunakan lcd.
  lcd.backlight(); // menghidupkan backlight lcd
  delay(1000);  // jeda 1000 mili sekon atau 1 detik
  lcd.print("Sisa Kapasitas"); // untuk memprint di baris pertama lcd
  mp3_set_serial(Serial); // untuk bisa menggunakan pin serial.
  mp3_set_volume(30); // menset volume maksimal . Rentang volume adalah 0 sampai 30
  
}

void loop() {

    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    
    float durasi,jarak,durasi2,jarak2;

    durasi=pulseIn(echo,HIGH);
    jarak=durasi/58.2;

    digitalWrite(trig2,LOW);
    delayMicroseconds(2);
    digitalWrite(trig2,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig2,LOW);

    durasi2=pulseIn(echo2,HIGH);
    jarak2=durasi2/58.2;

    Serial.print("jarak 1 :");
    Serial.println(jarak);
    Serial.print("jarak 2 : ");
    Serial.println(jarak2);

    unsigned int x;
    x=jarak*100/30; // untuk menampung nilai kapasitas tersisa pada tempat sampah.

    lcd.setCursor(0,1); // untuk menset tulisan di kolom ke 0 dan baris 1
    lcd.print(x);
    lcd.print(" %");

  if(jarak2<15){ 
    digitalWrite(hijau,LOW);
    digitalWrite(merah,HIGH);
    servo.write(180);
    mp3_play(1); //memainkan lagu pertama pada micro sd
    delay(4000); // jeda 4 detik karena lagunya sekitar 3 detik.
  }
  else{ // jika jarak2 lebih dari 15 cm servo akan kembali ke posisi semula.
    digitalWrite(merah,LOW);
    digitalWrite(hijau,HIGH);
    servo.write(-180);
  }
  delay(200);
}
