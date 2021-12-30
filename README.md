# Smart Trash Bin (Tempat Sampah Pintar)<br>
## Arsitektur Sistem<br>
## Kelompok 14<br>
Destry Rehulina Sitepu 118140022<br>
Liana Khairunisa Bancin 118140049<br>
Steven Elkan Hutauruk 18140149<br>
![Ars_Kelompok14](https://user-images.githubusercontent.com/45536366/147749903-7e62e464-3bad-4e5f-8f6f-7b8708f4c450.png)<br>
## Penjelasan cara kerja dan fitur alat
Sistem yang kami bangun adalah tempat sampah pintar  . Di alat ini, ada 2 sensor ultrasonic , sensor ultrasonic yang pertama untuk mengukur sisa kapasitas di dalam tempat sampah tersebut. Sisa kapasitas yang ada akan ditampilkan di LCD. Sedangkan sensor ultrasonic 2 untuk mendeteksi objek yang ada di depannya. Cara kerjanya adalah jika sensor ultrasonic 2( sensor di depan tempat sampah) mendeteksi adanya objek yang berjarak kurang dari 15 cm,  servo akan bergerak 180 derajat untuk membuka penutup tempat sampah yang ditandai juga dengan adanya suara Terimakasih sudah membuang sampah kepada tempatnya. Suara tersebut keluar dari speaker yang terlebih dahulu suaranya disimpan di dalam micro sd yang kemudian micro sd nya tersebut dimasukkan ke dalam df player mini. Dan juga led hijau akan mati dan led merah akan menyala jika sensor ultrasonic 2 mendeteksi adanya objek. Jika sensor ultrasonic 2 tidak mendeteksi adanya objek di depan sensor tersebut yang jaraknya kurang dari 15 cm, servo akan berputar untuk membuat penutup tempat sampah kembali ke posisi semula atau jika tempat sampah sudah tertutup, servonya akan diam. Dan juga ditandai dengan led merah yang mati dan led hijau yang hidup.

