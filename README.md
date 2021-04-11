# 基于Arduino的土壤湿度监测

​		这是一款基于Arduino的土壤湿度监测系统，湿度高于百分之八十或低于百分之二十时将会通过一个8x8点阵LED表现出来，普通脸代表湿度过高或者过低，笑脸表示湿度合适。

## 如果这个小玩意儿对您有帮助请给我一个star😀！





# 使用说明

#### 设备清单

Arduino Uno

MAX7219

HW-080

杜邦线若干

#### 接线

Arduino Uno    ---     MAX7219

| VCC  | GND  | DIN  |  CS  | CLK  |
| :--: | :--: | :--: | :--: | :--: |
|  5V  | GND  |  12  |  11  |  10  |

Arduino Uno    ---    HW-080

| VCC  | GND  |  AO  |  DO  |
| :--: | :--: | :--: | :--: |
|  5V  | GND  |  A0  | null |

使用Arduino IDE烧录程序即可



# 远程连接设备

将Arduino Uno换成ESP32，接线不变，

[下载]: https://github.com/blinker-iot/blinker-library/archive/master.zip

Blinker的库文件，烧录“远程”文件夹中的程序。

ESP32使用WIFI进行连接，且此功能暂时没有测试，仅供参考！！！（以后测试）

官方使用文档点击

[这里]: 	"https://diandeng.tech/doc"

。