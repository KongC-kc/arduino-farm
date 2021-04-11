/**************
Arduino Uno    ---     MAX7219                    

5V                <--->              VCC

GND           <--->              GND

12               <--->              DIN

11               <--->              CS

10               <--->             CLK
***************/

/**************
 * Arduino Uno    ---    HW-080
 * 5V           <--->          VCC
 * GND          <--->          GND
 * AO           <--->          A0
 * DO           <--->          null
 **************/




#include <LedControl.h>


/***宏定义***/
#define AO  A0




/***数据类型***/
int DIN = 12;
int CS =  11;
int CLK = 10;


/***点阵显示***/
byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};//笑脸
byte neutral[8]= {0x3C,0x42,0xA5,0x81,0xBD,0x81,0x42,0x3C};//标准脸


LedControl lc=LedControl(DIN,CLK,CS,4);




/***初始化***/
void setup()
{
  pinMode(AO, INPUT);       
  Serial.begin(9600);
  lc.shutdown(0,false);       //启动时，MAX72XX处于省电模式
  lc.setIntensity(0,8);       //将亮度设置为最大值
  lc.clearDisplay(0);         //清除显示

}


/***循环***/
void loop()
{
  Serial.print("AO=");
  Serial.print(analogRead(A0));   //读取模拟引脚值返回
  if (analogRead(A0)>960&&analogRead(A0)<128)   //当检测值大于960或低于128时，对植物生长不利，显示标准脸，否则显示笑脸
  {
      printByte(neutral);
  }
  else
  {
      printByte(smile);
  }
  
}


/***点阵显示函数***/
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
