// Memasukkan pustaka untuk mengendalikan motor servo
#include <Servo.h>

// Mendefinisikan jarak maksimal (meskipun tidak dipakai di kode bawah)
#define JARAK_MAKSIMAL 500 

// Membuat objek servo bernama 'motorServo'
Servo motorServo;

// Mendeklarasikan pin-pin yang digunakan
int pinEcho = 2;      // Pin penerima (Echo) dari sensor ultrasonik
int pinTrigger = 3;   // Pin pemancar (Trigger) dari sensor ultrasonik
int pinServo = 4;     // Pin untuk mengendalikan motor servo
int pinMerah = 5;     // Pin untuk lampu LED Merah
int pinHijau = 6;     // Pin untuk lampu LED Hijau

// Variabel desimal untuk menyimpan waktu pantulan dan hasil jarak
float waktu, jarak;

void setup()
{
  // Memulai komunikasi serial agar hasil jarak bisa dilihat di layar komputer
  Serial.begin(9600); 

  // Mengatur tugas masing-masing pin (Sebagai Keluaran/OUTPUT atau Masukan/INPUT)
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho,    INPUT);
  pinMode(pinHijau,   OUTPUT);
  pinMode(pinMerah,   OUTPUT);
  
  // Menghubungkan objek motorServo ke pin 4
  motorServo.attach(pinServo);
}

void loop()
{
  // --- PROSES SENSOR MEMANCARKAN GELOMBANG SUARA ---
  digitalWrite(pinTrigger, LOW);  // Memastikan pin pemancar mati sejenak
  delayMicroseconds(2);           // Jeda 2 mikrodetik
  digitalWrite(pinTrigger, HIGH); // Menyalakan pemancar gelombang suara
  delayMicroseconds(10);          // Pancarkan selama 10 mikrodetik
  digitalWrite(pinTrigger, LOW);  // Matikan pemancar
  
  // --- PROSES MENGHITUNG JARAK ---
  // Menghitung berapa lama waktu yang dibutuhkan hingga suara memantul kembali
  waktu = pulseIn(pinEcho, HIGH);
  
  // Rumus jarak: (waktu x kecepatan suara di udara) dibagi 2 (karena suara bolak-balik)
  jarak = (waktu * 0.034) / 2;
  
  // Menampilkan tulisan dan angka jarak ke layar komputer (Serial Monitor)
  Serial.print("Jarak saat ini: ");
  Serial.print(jarak);
  Serial.println(" cm");
  
  // --- LOGIKA AKSI BERDASARKAN JARAK ---
  if (jarak <= 50) // JIKA benda berada di jarak 30 cm atau lebih dekat
  {
    digitalWrite(pinMerah, LOW);   // Matikan LED Merah
    digitalWrite(pinHijau, HIGH);  // Nyalakan LED Hijau
    motorServo.write(90);          // Gerakkan servo ke 90 derajat (Pintu Terbuka)
    delay(1000);                   // Tahan posisi terbuka selama 1 detik
  }
  else // SELAIN ITU (Jika tidak ada benda / benda sangat jauh)
  {
    digitalWrite(pinMerah, HIGH);  // Nyalakan LED Merah
    digitalWrite(pinHijau, LOW);   // Matikan LED Hijau
    motorServo.write(0);           // Gerakkan servo kembali ke 0 derajat (Pintu Tertutup)
  }
  
  // Jeda 0,45 detik sebelum sensor mengulang pembacaan dari awal
  delay(450);
}
