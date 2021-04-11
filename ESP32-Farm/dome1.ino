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
#include <Blinker.h>


/***宏定义***/
#define AO  A0
#define BLINKER_WIFI


/***数据类型***/
int DIN = 12;
int CS =  11;
int CLK = 10;

char auth[] = "Your Device Secret Key";
char ssid[] = "Your WiFi network SSID or name";
char pswd[] = "Your WiFi network WPA password or WEP key";

/***新建组件对象***/
BlinkerButton Button1("btn-abc");
BlinkerNumber Number1("num-abc");

int counter = 0;




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
    
    Serial.begin(115200);       // 初始化串口

     
    Blinker.begin(auth, ssid, pswd);// 初始化blinker
    Blinker.attachData(dataRead);
    Button1.attach(button1_callback);

}


/***循环***/
void loop()
{
    Blinker.run();      //启动Blinker
    Blinker.print(analogRead(A0))       //上传数据
    if (analogRead(A0)>960&&analogRead(A0)<128)
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
