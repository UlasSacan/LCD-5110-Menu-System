// project owner >>>                   ULAŞ SAÇAN
// Project Name  >>>                   LCD 5110 Menu 

#include <LCD5110_Basic.h>

LCD5110 myGLCD(8, 9, 10, 11, 12); // CLK, DIN, CE, DC, RST

extern uint8_t SmallFont[];
extern uint8_t BigNumbers[]; // kullanacagimiz fontları tanimladik.
extern uint8_t MediumNumbers[];


// butonlari tanımladik.

int Buton1 = 6; 
int Buton1_durum = 0;
int Buton2 = 5;
int Buton2_durum = 0;
int Buton3 = 4;
int Buton3_durum = 0;
int Reset_buton = 3;
int Reset_durum = 0;

void setup()
{
  myGLCD.InitLCD(); // LCD 5110 ekrani baslattik.
  pinMode(Buton1 , INPUT);
  pinMode(Buton2 , INPUT);
  pinMode(Buton3 , INPUT); // butonlari giris olarak tanimladik.
  pinMode(Reset_buton , INPUT);

  myGLCD.setFont(SmallFont); // kullanacagimiz fontu belirttik.
  myGLCD.print("MENU" , CENTER , 0); // ilk satira MENU yazısını ortaladik.
  myGLCD.print("1>Sicaklik/Nem", LEFT, 8); // ikinci satir sola Sicaklik/Nem yazisini yazdirdik.
  myGLCD.print("2>Hareket", LEFT, 16); // ucuncu satir sola Hareket yazisini yazdirdik.
  myGLCD.print("3>Alev", LEFT, 24); // dorduncu satir sola Alev yazisini yazdirdik.
}
void isinemKontrol() { // isinemKontrol adinda metod olusturduk.
  delay(50); // 50ms(milisaniye) gecikme ekledik.
  myGLCD.clrScr(); // ekran temizleme komutunu yazdik
  myGLCD.setFont(SmallFont); // kullanacagimiz fontu belirttik.
  myGLCD.print("İSİ" , LEFT , 0); // İSİ yazisini sola ilk satira yazdirdik.
  myGLCD.print("NEM > 20" , LEFT, 16); // NEM yazisini sola ucuncu satira yazdirdik.
}
void hareketKontrol() { // hareketKontrol adinda metod olusturduk.
  delay(50);// 50ms(milisaniye) gecikme ekledik.
  myGLCD.clrScr(); // ekran temizleme komutunu yazdik
  myGLCD.setFont(SmallFont); // kullanacagimiz fontu belirttik.
  myGLCD.print("Hareket Durum" , CENTER, 0); // Hareket Durum yazisini ilk satira ortaya yazdirdik.
}
void alevKontrol() { // alevKontrol adinda metod olusturduk.
  delay(50); // 50ms(milisaniye) gecikme ekledik.
  myGLCD.clrScr(); // ekran temizleme komutunu yazdik
  myGLCD.setFont(SmallFont);// kullanacagimiz fontu belirttik.
  myGLCD.print("Alev Durum" , CENTER, 0); // Alev Durum yazisini ilk satira ortaya yazdirdik.
}
void resetleme() // resetleme adinda metod olusturduk.
{
  Reset_durum = digitalRead(Reset_buton); // Reset_buton olarak tanimladigimiz butonu digitalRead komutu ile okuyarak 0 veya 1 bilgisini Reset_durum degiskenini icerisine atayacak. 
  if (Reset_durum == 1) { // Reset_durum icerisine eger 1 bilgisi gelirse if komutu {} icerisindeki komutlar calisacak
    myGLCD.clrScr(); // ekran temizleme komutunu yazdik
    myGLCD.setFont(SmallFont); // kullanacagimiz fontu belirttik.
    myGLCD.print("MENU" , CENTER , 0); // ilk satira MENU yazısını ortaladik.
    myGLCD.print("1>Sicaklik/Nem", LEFT, 8);  // ikinci satir sola Sicaklik/Nem yazisini yazdirdik.
    myGLCD.print("2>Hareket", LEFT, 16); // ucuncu satir sola Hareket yazisini yazdirdik.
    myGLCD.print("3>Alev", LEFT, 24); // dorduncu satir sola Alev yazisini yazdirdik.
  } 
}


void loop() {
  Buton1_durum = digitalRead(Buton1); // Buton1 degiskenine atadigimiz butonu digitalRead komutu ile okuyarak 0 veya 1 bilgisini Buton1_durum degiskenini icerisine atayacak. 
  if (Buton1_durum == 1) {  // eger Buton1_durum 1 olursa isinemKontrol metodumuz calisacak.
    isinemKontrol();
  }
    Buton2_durum = digitalRead(Buton2);  // Buton2 degiskenine atadigimiz butonu digitalRead komutu ile okuyarak 0 veya 1 bilgisini Buton2_durum degiskenini icerisine atayacak. 
  if (Buton3_durum == 1) { // eger Buton2_durum 1 olursa hareketKontrol metodu calisacak.
    hareketKontrol();
  }
  Buton3_durum = digitalRead(Buton3);  // Buton1 degiskenine atadigimiz butonu digitalRead komutu ile okuyarak 0 veya 1 bilgisini Buton3_durum degiskenini icerisine atayacak. 
  if (Buton2_durum == 1) { // eger Buton3_durum 1 olursa AlevKontrol metodu calisacak.
    alevKontrol();
  }
  Reset_durum = digitalRead(Reset_buton); // Reset_buton degiskenine atadigimiz butonu digitalRead komutu ile okuyarak 0 veya 1 bilgisini Reset_durum degiskenini icerisine atayacak.
  if (Reset_durum == 1) { // eger Reset_durum 1 olursa resetleme metodu calisacak.
    resetleme();
  }


}
