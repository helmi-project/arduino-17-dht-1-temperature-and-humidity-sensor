/*
 * TUTORIAL SENSOR SUHU DAN KELEMBABAN PADA ARDUINO
 * 
 * Pinout :
 * DHT signal -> D12
 * 
 * Untuk membaca nilai dari pin signal DHT11 dan dijadikan tampilan suhu dan kelembaban
 */

#include <dht.h>

//inisiasi dht
dht SENSOR_DHT;

//definisikan DHT_PIN untuk pin 12
#define DHT_PIN 12

void setup() {
  Serial.begin(115200); //memulai komunikasi serial pada baud rate 115200
  Serial.println("Mencoba Sensor Suhu dan Kelembaban Udara DHT11 pada Arduino");
}

void loop() {
  int cek = SENSOR_DHT.read11(DHT_PIN);
  Serial.print("Temperatur = ");
  Serial.print(SENSOR_DHT.temperature,0); //data suhu udara
  Serial.write(0xC2);//simbol derajat
  Serial.write(0xB0);//simbol derajat
  Serial.println("C"); 
  Serial.print("Kelembaban = ");
  Serial.print(SENSOR_DHT.humidity,0); //data kelembaban udara
  Serial.println(" %");
  delay(2000);//delay minimum DHT11
}
