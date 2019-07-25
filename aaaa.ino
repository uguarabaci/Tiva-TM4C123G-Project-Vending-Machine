#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int stok[5][3]={{1, 30,50},{2, 20,100},{3, 15,150},{4, 50,175},{5,100,200}};//{urunID,urunSTOK,urunFİYAT}
int islem=0;
int suadet=0,cayadet=0,kahveadet=0,cikolataadet=0,biskuviadet=0;
int rs;//1-4 arasi random sayi uretmek icin, 2 gelirse para takilir
float kasaceyrek=0,kasayarim=0,kasatam=0;//kasadaki bozuk para sayıları.
int ceyrek=0,yarim=0,tam=0;// kullanicinin attigi  bozuk para sayılari.
float cuzdan=0; //kullanicinin attigi paralarin toplami
float tutar=0;
float paraustu;
int pbt=0 ,pek=0 ,pyb=0;
int i,k=0;
int j=0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'8','9','A','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {33, 34, 35,36};
byte colPins[COLS] = {37,38,39,40};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


void setup() {
  Serial.begin(9600);//seri port ekranı için
  lcd.begin(16, 2);//lcd için
  pinMode(30, OUTPUT); //para sıkışma uyarısı için kırmızı led.
  pinMode(29, OUTPUT); //paranın sıkışmadığını belirtmek için yeşil red.
  
}

void loop(){
  
baslangic:
        stok[0][1]=stok[0][1]+suadet;
        stok[1][1]=stok[1][1]+cayadet;
        stok[2][1]=stok[2][1]+kahveadet;
        stok[3][1]=stok[3][1]+cikolataadet;
        stok[4][1]=stok[4][1]+biskuviadet;
        suadet=0,cayadet=0,kahveadet=0,cikolataadet=0,biskuviadet=0;
        ceyrek=0,yarim=0,tam=0;
   while(islem==0) {
  char customKey = customKeypad.getKey();
  
  if(customKey=='1'){
    ceyrek++;
        //Serial.println(customKey);
        Serial.print( "25 kr adedi: ");
        Serial.println(ceyrek);
  }
  if(customKey=='2'){
    yarim++;
        //Serial.println(customKey);
        Serial.print( "50 kr adedi: ");
        Serial.println(yarim);
  }
  
  if(customKey=='3'){
    tam++;
       // Serial.println(customKey);
        Serial.print( "1 tl adedi: ");
        Serial.println(tam);

  }

  cuzdan=ceyrek*0.25+yarim*0.50+tam*1;
  if(customKey=='0'){
   
           Serial.print("cuzdan: ");
           Serial.println(cuzdan);
           lcd.print("cuzdan: ");
           lcd.print(cuzdan);
        islem++;

  }

  if(customKey=='*'){
  
        //Serial.println(customKey);
        
        Serial.println( "reset attiniz ");
       
       
        suadet=0,cayadet=0,kahveadet=0,cikolataadet=0,biskuviadet=0;
        ceyrek=0,yarim=0,tam=0;
        lcd.clear();
        cuzdan=0;
for(int i=0;i<5;i++){
        Serial.println(stok[i][1]);
}  
        
        goto baslangic;

  }
  }
  islem=0;


  
   while(islem==0) {
    char customKey = customKeypad.getKey();

    if(customKey=='1'){

        //Serial.println(customKey);
        Serial.println( "su aldiniz.  ");
        suadet++;
        stok[0][1]=stok[0][1]-1;
        Serial.print(stok[0][1]);        
        Serial.println(" adet stokta kaldi(bakiye yeterse)");
  }
    if(customKey=='2'){
   
        //Serial.println(customKey);
        Serial.println( "cay aldiniz.");
        cayadet++;      
        stok[1][1]=stok[1][1]-1;
        Serial.print(stok[1][1]);        
        Serial.println(" adet stokta kaldi(bakiye yeterse)");
  }
    if(customKey=='3'){
   
        //Serial.println(customKey);
        Serial.println( "kahve aldiniz. ");
        kahveadet++;
        stok[2][1]=stok[2][1]-1;
        Serial.print(stok[2][1]);        
        Serial.println(" adet stokta kaldi(bakiye yeterse)");
  }
    if(customKey=='4'){
   
        //Serial.println(customKey);
        Serial.println( "cikolata aldiniz. ");
        cikolataadet++;
        stok[3][1]=stok[3][1]-1;
        Serial.print(stok[3][1]);        
        Serial.println(" adet stokta kaldi(bakiye yeterse)");
  }
    if(customKey=='5'){
   
        //Serial.println(customKey);
        Serial.println( "biskuvi aldiniz. ");
        biskuviadet++;
        stok[4][1]=stok[4][1]-1;
        Serial.print(stok[4][1]);        
        Serial.println(" adet stokta kaldi(bakiye yeterse)");

  }
  
  if(customKey=='0'){
    
        Serial.print(suadet);
        Serial.println(" adet su alindi");
        Serial.print(cayadet);
        Serial.println(" adet cay alindi");
        Serial.print(kahveadet);
        Serial.println(" adet kahve alindi");
        Serial.print(cikolataadet);
        Serial.println(" adet su alindi");
        Serial.print(biskuviadet);
        Serial.println(" adet biskuvi alindi");
        
        tutar=(suadet)*(0.5)+(cayadet)*(1)+(kahveadet)*(1.5)+(cikolataadet)*(1.75)+(biskuviadet)*(2.0);
        Serial.print( "tutar: ");
        Serial.println(tutar);


        
  islem++;
  
  }

  if(customKey=='*'){
  
        //Serial.println(customKey);
        
        Serial.println( "reset attiniz ");
       
        stok[0][1]=stok[0][1]+suadet;
        stok[1][1]=stok[1][1]+cayadet;
        stok[2][1]=stok[2][1]+kahveadet;
        stok[3][1]=stok[3][1]+cikolataadet;
        stok[4][1]=stok[4][1]+biskuviadet;
        suadet=0,cayadet=0,kahveadet=0,cikolataadet=0,biskuviadet=0;
        ceyrek=0,yarim=0,tam=0;
        lcd.clear();
        cuzdan=0;
for(int i=0;i<5;i++){
        Serial.println(stok[i][1]);
}  
        
        goto baslangic;

  }
  
   
   
}
islem=0;

  rs=random(1,5);
  fflush(stdin);
   Serial.println(rs);
   i=0;
while(islem==0){
char customKey = customKeypad.getKey();
if(i==1){
  
  if(customKey=='*'){
  
        //Serial.println(customKey);
        
        Serial.println( "reset attiniz ");
       
        stok[0][1]=stok[0][1]+suadet;
        stok[1][1]=stok[1][1]+cayadet;
        stok[2][1]=stok[2][1]+kahveadet;
        stok[3][1]=stok[3][1]+cikolataadet;
        stok[4][1]=stok[4][1]+biskuviadet;
        suadet=0,cayadet=0,kahveadet=0,cikolataadet=0,biskuviadet=0;
        ceyrek=0,yarim=0,tam=0;
        lcd.clear();
        cuzdan=0;
for(int i=0;i<5;i++){
        Serial.println(stok[i][1]);
}  
        
        goto baslangic;

  }
}


  
else if(rs==2&&i==0){//para sıkıştı

  digitalWrite(30,HIGH);//kırmızı ledi yakma işlemi.
  delay(5000);
  digitalWrite(30,LOW);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("para sikisti!");
  lcd.setCursor(0,1);
  lcd.print("para iadesi");
  delay(3000);
  
  Serial.println("para takildi, iade miktari: (reset icin: *");
  Serial.println(cuzdan);

i++;


}
  else{
  digitalWrite(29,HIGH);//yeşil ledi yakma işlemi.
  delay(5000);
  digitalWrite(29,LOW);
   Serial.println("para sikismadi");
   Serial.println(cuzdan);

   islem++;
   
  }
 

}
islem=0;
i=0;j=0,k=0;
paraustu=cuzdan-tutar;
paraustu=paraustu*100;
while(islem==0){
char customKey = customKeypad.getKey();
if(i==1){
  
  
  if(customKey=='*'){
  
        //Serial.println(customKey);
        
        Serial.println( "reset attiniz ");
       
       if(j==0||k==1){ stok[0][1]=stok[0][1]+suadet;
        stok[1][1]=stok[1][1]+cayadet;
        stok[2][1]=stok[2][1]+kahveadet;
        stok[3][1]=stok[3][1]+cikolataadet;
        stok[4][1]=stok[4][1]+biskuviadet;}
        suadet=0,cayadet=0,kahveadet=0,cikolataadet=0,biskuviadet=0;
        ceyrek=0,yarim=0,tam=0;
        lcd.clear();
        cuzdan=0;
for(int i=0;i<5;i++){
        Serial.println(stok[i][1]);
}  
        
        goto baslangic;

  }
}
else{
if(paraustu>=0){
  while(paraustu!=0){

if(paraustu>=100){
pbt=paraustu/100;
paraustu=paraustu-(pbt*100);
}

else if(paraustu>=50){
pek=paraustu/50;
paraustu=paraustu-(pek*50);
}
else if(paraustu>=25){
pyb=paraustu/25;
paraustu=paraustu-(pyb*25);
}

}

while(pbt!=0){

if(kasatam!=0){
  kasatam=kasatam-1;
  pbt=pbt-1;
}
else if(kasayarim!=0){
  kasayarim=kasayarim-1;
  pbt=pbt-0.50;
}
else if(kasaceyrek!=0){
  kasaceyrek=kasaceyrek-1;
  pbt=pbt-0.25;
}
else{
  
lcd.setCursor(0,0);
lcd.print("kasada yeterli");
lcd.setCursor(0,1);
lcd.print("para yoktur");
k==1;
pbt=0;
pek=0;
pyb=0;
}


  
}
while(pek!=0){

if(kasayarim!=0){
  kasayarim=kasayarim-1;
  pek=pek-0.50;
}
else if(kasaceyrek!=0){
  kasaceyrek=kasaceyrek-1;
  pek=pek-0.25;
}

else{
  
lcd.setCursor(0,0);
lcd.print("kasada yeterli");
lcd.setCursor(0,1);
lcd.print("para yoktur");
k==1;
pbt=0;
pek=0;
pyb=0;
}


  
}
while(pyb!=0){

if(kasaceyrek!=0){
  kasaceyrek=kasaceyrek-1;
  pyb=pyb-0.25;
}

else{
  //para yok
    
lcd.setCursor(0,0);
lcd.print("kasada yeterli");
lcd.setCursor(0,1);
lcd.print("para yoktur");
k==1;
pbt=0;
pek=0;
pyb=0;
}


  
}


kasaceyrek=kasaceyrek+ceyrek;
kasayarim=kasayarim+yarim;
kasatam=kasatam+tam;
Serial.print("25 kuruş sayısı:");
Serial.println(kasaceyrek);
Serial.print("50 kuruş sayısı:");
Serial.println(kasayarim);
Serial.print("1  TL    sayısı:");
Serial.println(kasatam);
//ürünler

i++;
j++;












    
}


else{
lcd.setCursor(0,0);
lcd.print("yetersiz para");
islem++;
}}
}






 islem=0;
}
