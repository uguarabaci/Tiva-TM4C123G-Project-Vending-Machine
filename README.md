## EN AZ SAYIDA BOZUK PARA VERME PROBLEMİ

Bu readme.txt dosyası, En az sayıda bozuk para verme projesine aittir.
Bu paket, kaynak kodu ile beraber bulunmaktadır.


## PAKETİN İÇERİĞİ:

Projenin kaynak kodu.
readme.txt - Bu dosya.



## SİSTEM GEREKSİNİMLERİ:

### Energia(ide)   - https://energia.nu/download/
### Tiva C geliştirme kartını bilgisayara kurmak için: https://www.youtube.com/watch?v=q6UjsPBL_54&t=1s


## PROGRAMIN HAKKINDA

Bu proje, kullanıcıdan keypad yardımı ile para girişinin alınmasıyla başlar. 25 kuruş için “1” tuşuna, 50 kuruş için “2” tuşuna, 1 lira için “3” tuşuna basılması beklenir.
“0” tuşuna basıldığında para ekleme işlemi biter. LCD ekranda cüzdan miktarı yazar.“*” para işlemini resetler(* komutu program boyunca kullanıcının kullabileceği bir komuttur,
 ürün seçiminde de kullanılabilir ve para iadesi yapılır. Stoktan ürün düşülmez). Program başa döner. Sonrasında kullanıcı keypad yardımı ile ürün seçimi yapar.
 “1” tuşuna basarak su seçimi, “2” tuşuna basarak çay seçimi, “3” tuşuna basarak kahve seçimi, “4” tuşuna basarak çikolata seçimi, “5” tuşuna basarak kahve seçimi,
 “0” işlemi ile alışveriş son bulur. Ardından alınan ürün miktarları seri porta basılır. Para sıkışma ihtimali vardır.
 4’te bir ihtimale göre 2 rakamı denk gelirse devrede kırmızı led yanar ve para iadesi yapılır. LCD ekranda “para sıkıştı” ibaresi belirir.
 Aksi halde led yeşil ışık yapar, delay(erteleme) işlemi sonrası program akışına devam eder. Para üstü işleminde stokta yer alan madeni para miktarına göre en az adet parayla
 paraüstü verme işlemi yapılır. Yani öncelik varsa 1 liradadır. Sonra 50 kuruştadır. En son 25 kuruşlardadır. 
