# IoT (Internet of Things) Hidroponik

IoT Hidroponik merupakan salah satu aplikasi IoT yang diterapkan pada sektor pertanian. Seperti yang kita ketahui, sejak lama metode hidroponik telah diterapkan di dunia terutama di kota-kota yang mempunyai lahan yang sempit. Di Indonesia, hidroponik menjadi solusi bagi seseorang yang menyukai cocok tanam namun memiliki keterbatasan lahan. Selain lahan yang sempit, kondisi tanah yang buruk dan cuaca yang kurang baik menjadi alasan lain orang beralih ke sistem hidroponik. Namun, perawatan yang rumit membuat sebagian orang enggan menggunakannya. Salah satu solusinya adalah dengan membuat monitoring hidroponik menggunakan sistem IoT.

## Instalasi software Arduino IDE

Repositori ini dibuat sebagai pelengkap dari kit IoT Hidroponik. Konfigurasi awal untuk menggunakan IoT Hidroponik adalah sebagai berikut:
* Unduh software Arduino IDE pada link berikut ```https://www.arduino.cc/en/software```, pilih sesuai dengan OS yang digunakan pada laptop anda.

<div style="text-align:center"><img src="/images/Arduino_download.JPG" height="300" align ="center"/><div/>

* Buka software Arduino IDE, lalu pilih menu **File | Preferences** atau dapat juga dengan menekan tombol ```Ctrl``` + ```,``` (tanda baca koma) secara bersamaan pada keyboard.
* Copy dan paste ```http://arduino.esp8266.com/stable/package_esp8266com_index.json``` pada ```Additional Boards Manager URLs```.

<div style="text-align:center"><img src="https://github.com/userdw/Internet_of_Things_Maker_Kit/blob/master/images/additional_url.png" height="200" align ="center"/><div/>


* Buka jendela Boards Manager dengan cara memilih menu **Tools | Board | Boards Manager...**, ketikkan ```esp8266``` pada text box, lalu tekan tombol Install. Pastikan versi yang dipilih adalah yang terbaru.

<div style="text-align:center"><img src="https://github.com/userdw/Internet_of_Things_Maker_Kit/blob/master/images/esp8266_package.PNG" height="300" align ="center"/><div/>


* Buka menu **Tools | Board**, kemudian pilih **NodeMCU 0.9 (ESP-12 Module)**. Atur parameter board sesuai dengan yang ditunjukkan oleh tabel di bawah.

<img src="https://github.com/userdw/Internet_of_Things_Maker_Kit/blob/master/images/configuration_table.PNG" height="430" align ="center">

* Anda dapat mencoba untuk melakukan upload contoh program yang tersedia pada Arduino IDE untuk memastikan bahwa instalasi dan konfigurasi yang dilakukan sebelumnya telah berhasil.

## Konfigurasi Awal

Lakukan langkah-langkah berikut sebagai konfigurasi awal IoT Hidroponik yang menghubungkan aplikasi Blynk dengan ESP8266:
1. Unduh dan install aplikasi Blynk pada smartphone yang dapat diunduh pada aplikasi Google Play Store atau App Store,
2. Buka aplikasi Blynk dan buat sebuah akun baru,
3. Pilih gambar scan QR-Code dan scan gambar dibawah ini untuk menduplikasi aplikasi monitoring IoT Hidroponik,

<img src="/images/Clone_blynk_project.jpeg" height="200">

4. Jika QR-Code dapat terbaca dengan baik, maka akan muncul tampilan seperti gambar dibawah,

<img src="https://github.com/userdw/IoT_Hidroponik/blob/main/images/Blynk_apps.jpg" height="500">

Pada halaman tersebut terdapat 4 komponen, antara lain:
* Vertical slider, digunakan untuk mengontrol kadar nutrisi hidroponik,
* Level meter, digunakan untuk menampilkan kadar nutrisi hidroponik saat ini,
* Tombol, digunakan untuk menyalakan pompa nutrisi secara manual,
* LED, digunakan untuk indikator pompa nyala nutrisi,

5. Buka software Arduino IDE pada laptop anda dan ubah 3 baris kode berikut ini:
```
// ubah sesuai dengan auth token pada aplikasi Blynk
char auth[] = "Your Authentication Token";
// ubah sesuai dengan SSID dan password jaringan WiFi anda
char ssid[] = "Your SSID";
char pass[] = "Your Password";
```

6. Buka skrup pada kotak pelindung IoT Hidroponik dan hubungkan board ESP8266 dengan PC menggunakan kabel microUSB,
7. Upload program tersebut, apabila tidak terjadi error, cek kembali status koneksi antara ESP8266 dengan aplikasi Blynk apakah sudah terhubung dengan baik atau tidak.

Panduan lebih detail dapat mengikuti panduan yang berada dalam direktori ini [Blynk Documentation](/14_Smart_Home_Automation/Blynk_Documentation/Instalasi_Blynk_pada_Smartphone.pdf)
