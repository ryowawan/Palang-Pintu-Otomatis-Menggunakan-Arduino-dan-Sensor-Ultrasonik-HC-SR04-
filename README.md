# Sistem-Buka-Tutup-Otomatis-Menggunakan-Arduino-dan-Sensor-Ultrasonik-HC-SR04-
➡️ Membuat Sistem Buka Tutup Otomatis (misalnya: tempat sampah pintar, palang pintu otomatis, atau dispenser otomatis).
Sistem ini menggunakan Sensor Ultrasonik untuk mendeteksi jarak, Motor Servo sebagai penggerak, dan dua LED (Merah dan Hijau) sebagai indikator.

# Komponen yang Dibutuhkan
- Arduino UNO
- Sensor Ultrasonik HC-SR04
- Micro Motor Servo
- 2 LED (merah 🔴 dan hijau🟢)
- 2 resistor 100 ohm
- Kabel Jumper
- Breadboard

# Rangkaian
<img width="1272" height="457" alt="Copy of Palang Pintu Otomatis" src="https://github.com/user-attachments/assets/0a8b05c3-1cf0-4595-a539-baecfa8ad263" />
### Sensor Ultrasonik (HC-SR04)
Sensor ini memiliki 4 kaki/pin
- VCC: Sambungkan ke pin 5V di Arduino
- GND: Sambungkan ke pin GND di Arduino
- TRIG: Sambungkan ke Pin 3 di Arduino
- ECHO: Sambungkan ke Pin 2 di Arduino

### Motor Servo
Motor servo biasanya memiliki 3 helai kabel yang menyatu
- Kabel Merah: Sambungkan ke pin 5V di Arduino
- Kabel Coklat/Hitam: Sambungkan ke pin GND di Arduino
- Kabel Kuning/Oranye (Sinyal): Sambungkan ke Pin 4 di Arduino

### Lampu LED Merah & Hijau
LED memiliki dua kaki: kaki panjang adalah Positif (Anoda) dan kaki pendek adalah Negatif (Katoda)
**LED Merah :**
- Kaki Panjang (+) dipasang ke Pin 5 Arduino
- Kaki Pendek (-) dipasang ke GND Arduino
**LED Hijau :**
- Kaki Panjang (+) dipasang ke Pin 6 Arduino
- Kaki Pendek (-) dipasang ke GND Arduino

**Catatan Penting untuk LED**
Sangat disarankan untuk memasang Resistor (misalnya ukuran 220 Ohm atau 330 Ohm) pada masing-masing kaki panjang (+) LED sebelum disambungkan ke pin Arduino. Tujuannya agar lampu LED tidak putus/terbakar akibat arus yang terlalu besar.
