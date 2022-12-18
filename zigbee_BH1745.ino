#include <BH1745.h>
#include <Arduino.h>
#include <stdio.h>
String datetime;

BH1745 bh = BH1745();
//char buf[128];

void setup() {
  Serial.begin(9600);
  bool result = bh.begin();
  
  if (!result){
    Serial.println("Device Error");
    while (1){;;}
  }
  bh.setGain(bh.GAIN_16X);
  bh.setRgbcMode(bh.RGBC_8_BIT);
} 

void loop() {
//  bh.setRgbcMode(8);
//  Serial.println("gg");
  bh.read();
//  digitalClockDisplay();

//  String temp = "Red:"+String(bh.red)+", "+"Green:"+String(bh.green)+", "
//                +"Blue:"+String(bh.blue)+", "+"Clear:"+String(bh.clear)+", ";

//  sprintf(buf, "%s/n",temp);

//  Serial.print(temp);
  
//  
//  Serial.println(bh.saturation);
  if(bh.saturation!=0){
    Serial.print("r:");Serial.print("65536");Serial.print(',');
    Serial.print("g:");Serial.print("65536");Serial.print(',');
    Serial.print("b:");Serial.print("65536");Serial.print(',');
  }
  else{
    Serial.print("r:");Serial.print(bh.red_65536);Serial.print(',');
    Serial.print("g:");Serial.print(bh.green_65536);Serial.print(',');
    Serial.print("b:");Serial.print(bh.blue_65536);Serial.print(',');
  }
  Serial.print("saturation:");Serial.print(bh.saturation);Serial.println();
//  Serial.print("c:");Serial.print(bh.clear);Serial.print(',');
//  Serial.print("rgb:");Serial.print(bh.rgb);Serial.print(',');
//  Serial.print("hue:");Serial.print(bh.hue);Serial.print(',');
//  Serial.print("lightness:");Serial.print(bh.lightness);Serial.print(',');
//  float illuminance = (-0.32466F * bh.red) + (1.57837F * bh.green) + (-0.73191F * bh.blue);
//  Serial.print("lux:");Serial.print(illuminance);Serial.print(',');
//  Serial.print("time:");Serial.println(datetime);

   
  
  
  delay(1000);
}

//void digitalClockDisplay(){
//  datetime="";
//  Serial.print(hour());
//  Serial.print(" ");
//  Serial.print(timeDigits(minute()));
//  Serial.print(" ");
//  Serial.print(timeDigits(second()));
//  Serial.print(" ");
//  Serial.print(day());
//  Serial.print(" ");
//  Serial.print(month());
//  Serial.print(" ");
//  Serial.print(year()); 
//  Serial.println(); 
//  datetime = year();
//  datetime.concat("-");
//  datetime.concat(month());
//  datetime.concat("-");
//  datetime.concat(day());
//  datetime.concat(" ");
//  datetime.concat(hour());
//  datetime.concat("-");
//  datetime.concat(timeDigits(minute()));
//  datetime.concat("-");
//  datetime.concat(timeDigits(second()));
//  
//}

String timeDigits(int digits){
  String s;
  String zero = "0";
  s = digits;
  if(digits < 10){
    zero.concat(s);
    s = zero;
  }
  return s;

}
