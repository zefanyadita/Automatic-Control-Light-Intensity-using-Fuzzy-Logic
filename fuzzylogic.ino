#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD
LiquidCrystal_I2C lcd(0x26, 16, 2);

#define LDR1 A0
#define LDR2 A1
#define LAMP 3
 
float senVal1;
float senVal2;
float X;
float Y;
float lux1;
float lux2;

float rule1,rule2,rule3,rule4,rule5,rule6,rule7,rule8,rule9;
float gelap1,gelap2,sedang1,sedang2,terang1,terang2;
float z1,z2,z3,z4,z5,z6,z7,z8,z9;
float zmax,zmin;

float maxi (float i)
 {
 if (i == 0){zmax = 0;}  
 if (i > 0 && i < 1){zmax = 255*(i);}
 if (i == 1){zmax = 255;}
 return zmax;
 }
 
float mini (float j)
 {
 if (j == 0){zmin = 255;}
 if (j > 0 && j < 1){zmin = 255*(1-j);}
 if (j == 1){zmin = 0;}
 return zmin;
 }

int sensorLum(int raw){
// Konversi nilai 
float Vout = float(raw) * (5 / float(1023));// An ke V
float RLDR = (10000* (5 - Vout))/Vout; // Konversi V ke R
int phys=500/(RLDR/1000); // Konversi R ke Lumen (aprox)
return phys;
} 

void setup() {
  Serial.begin(9600);  
  pinMode(LAMP, OUTPUT);
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  lcd.init();
  lcd.backlight(); // 
  lcd.setCursor(0, 0); // 
  lcd.print("AUTOMATIC LIGHT");
  lcd.clear();
}
  
void loop() {  
  senVal1 = analogRead(LDR1); // baca nilai LDR 
  senVal2 = analogRead(LDR2); // baca nilai LDR 
  X = sensorLum(senVal1);
  Y = sensorLum(senVal2);
  lux1 = 0.0023*X*X + 1.575*X - 9.1422;
  lux2 = 0.002*Y*Y + 1.5473*Y - 7.3506;

  //SENSOR LDR1
  //Gelap
  if (lux1 <= 50){gelap1 = 1;}
  else if (lux1 >= 50 && lux1 <= 127.5){gelap1 = (127.5-lux1)/(127.5-50);}
  else if (lux1 >= 127.5){gelap1 = 0;} 
  
  //Sedang
  if (lux1 <= 50||lux1 >= 127.5){sedang1 = 0;}
  else if (lux1 >= 50 && lux1 <= 127.5){sedang1 = (lux1-50)/(127.5-50);}
  else if (lux1 >= 127.5 && lux1 <= 200){sedang1 = (200-lux1)/(200-127.5);} 
  
  //Terang
  if (lux1 <= 127.5){terang1 = 0;}
  else if (lux1 >= 127.5 && lux1 <= 200){terang1 = (lux1-127.5)/(200-127.5);}
  else if (lux1 >= 200){terang1 = 1;} 
  
  //SENSOR LDR2
  //Gelap
  if (lux2 <= 50){gelap2 = 1;}
  else if (lux2 >= 50 && lux2 <= 127.5){gelap2 = (127.5-lux2)/(127.5-50);}
  else if (lux2 >= 127.5){gelap2 = 0;} 
  
  //Sedang
  if (lux2 <= 50||lux2 >= 127.5){sedang2 = 0;}
  else if (lux2 >= 50 && lux2 <= 127.5){sedang2 = (lux2-50)/(127.5-50);}
  else if (lux2 >= 127.5 && lux2 <= 200){sedang2 = (200-lux2)/(200-127.5);} 
  
  //Terang
  if (lux2 <= 127.5){terang2 = 0;}
  else if (lux2 >= 127.5 && lux2 <= 200){terang2 = (lux2-127.5)/(200-127.5);}
  else if (lux2 >= 200){terang2 = 1;} 
  
  //RULE BASE
  rule1 = min(gelap1,gelap2);//maximum
  rule2 = min(gelap1,sedang2);//maximum
  rule3 = min(gelap1,terang2);//minimum
  
  rule4 = min(sedang1,gelap2);//maximum
  rule5 = min(sedang1,sedang2);//maximum
  rule6 = min(sedang1,terang2);//minimum
  
  rule7 = min(terang1,gelap2);//minimum
  rule8 = min(terang1,sedang2);//minimum
  rule9 = min(terang1,terang2);//minimum
  
  //INFERENSI
  z1 = maxi(rule1);
  z2 = maxi(rule2);
  z3 = mini(rule3);
  z4 = maxi(rule4);
  z5 = maxi(rule5);
  z6 = mini(rule6);
  z7 = mini(rule7);
  z8 = mini(rule8);
  z9 = mini(rule9);
  
  //DEFUZIFIKASI
  float intensity = ((rule1*z1)+(rule2*z2)+(rule3*z3)+(rule4*z4)+(rule5*z5)+(rule6*z6)+(rule7*z7)+(rule8*z8)+(rule9*z9))/(rule1+rule2+rule3+rule4+rule5+rule6+rule7+rule8+rule9);
  
  //OUTPUT LAMPU
  analogWrite(LAMP, intensity);
      
  Serial.print("Lux1: ");
  Serial.println(lux1);
  Serial.print("Lux2: ");
  Serial.println(lux2);
  Serial.print("LAMPU ");
  Serial.println(intensity);

  lcd.setCursor(0,0);
  lcd.print("Lux1|Lux2|Lamp");
  lcd.setCursor(0,1);
  lcd.print(lux1);
  lcd.print("|");
  lcd.print(lux2);
  lcd.print("|");
  lcd.print(intensity);
  delay(2000);
}
