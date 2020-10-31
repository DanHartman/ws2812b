# WS2812B
This is a hello world starting point for arduino controlled WS2812B RGB leds.  
Anyone who has already used an arduino has probably used the Arduino IDE. You
don't need it!  This project will introduce the amazing `platformio` command
line tool. This project can be edited using any text editor you wish.

## Tl;dr
* Connect a strip of 30 WS2812B leds to an arduino
  * Serial data on PIN 5
* Plug arduino into computer
* Find its port
* `git clone `
* `cd $/platformio/`
* `platformio run -e uno --target upload --upload-port "/WHATEVER/PORT/YOU/SEE/IT/CONNECTED/TO"`
* Power up and enjoy!

## Setup

### Install Dependencies
* `platformio` [PlatformIO Core (CLI) install](http://docs.platformio.org/en/latest/installation.html)

### Choose your Arduino!
This project is agnostic in this regard.  You will simply select which kind of
Arduino you're using when you run the platformio commands.  All examples in this
README are given using an `uno` board.  However, the user may specify `nano` as
well.  Extending this to other boards is as simple as adding environments to the
`platformio/platformio.ini` file.

### Connect your WS2812B led strip to
This source will use `D5` as the data pin per this diagram
![](https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2016/09/WS2812B-with-Arduino_bb.png?resize=700%2C423&ssl=1)

### Burn firmware to arduino
* connect arduino to host machine
* determine its serial port
  * *Nix `ls /dev/`
  * Windows: check the `device manager`
* `cd platformio`
* compile: `platformio run -e uno`
* burn to uno: `platformio run -e uno --target upload --upload-port "/dev/ttyUSB0"`

* See the below link if different firmata versions for different functions are desired
  * [Firmata Examples](https://platformio.org/lib/show/307/Firmata/examples)
* over time operator may need to update the "platforms" that platformio supports
  * one use case is if an old platformio installation was using python2 code
  * fix with `platformio platform update`

### gobot.io
* `go get -d -u gobot.io/x/gobot/...`