// Definisi Pin
// Utara
int UtaraMerah = 2;
int UtaraKuning = 3;
int UtaraHijau = 4;

// Timur
int TimurMerah = 5;
int TimurKuning = 6;
int TimurHijau = 7;

// Selatan
int SelatanMerah = 8;
int SelatanKuning = 9;
int SelatanHijau = 10;

// Barat
int BaratMerah = 11;
int BaratKuning = 12;
int BaratHijau = 13;

// Setup
void setup() {
  for(int i=2;i<=13;i++){
    pinMode(i, OUTPUT);
  }

  // kondisi awal semua merah
  semuaMerah();
}

// Looping
void loop() {
  jalan(UtaraHijau, UtaraKuning, UtaraMerah);
  jalan(TimurHijau, TimurKuning, TimurMerah);
  jalan(SelatanHijau, SelatanKuning, SelatanMerah);
  jalan(BaratHijau, BaratKuning, BaratMerah);
}

// Fungsi Modular
// Semua lampu merah
void semuaMerah(){
  
  for(int i=2;i<=13;i+=3){
    digitalWrite(i, HIGH); // merah nyala
  }

  for(int i=3;i<=13;i+=3){
    digitalWrite(i, LOW); // kuning mati
  }

  for(int i=4;i<=13;i+=3){
    digitalWrite(i, LOW); // hijau mati
  }
}

// Fungsi satu simpang
void jalan(int hijau, int kuning, int merah){

  // Pastikan semua merah
  semuaMerah();

  // Langsung hijau
  digitalWrite(merah, LOW);
  digitalWrite(hijau, HIGH);
  delay(5000);

  // Matikan hijau
  digitalWrite(hijau, LOW);

  // Kuning kedip 3 kali
  for(int i=0;i<3;i++){
    digitalWrite(kuning, HIGH);
    delay(333);
    digitalWrite(kuning, LOW);
    delay(333);
  }

  // Kembali merah
  digitalWrite(merah, HIGH);
}