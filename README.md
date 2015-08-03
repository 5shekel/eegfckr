# eegfckr
brain eeg exciter, a simlpe device to output blinking LEDs in freq between 4-32Hz  

Schema  
![](http://i.imgur.com/O06KAnZl.png)

Board layout (example)  
![](http://i.imgur.com/wOuzrPK.png)

Attiny85 pinout  
![](http://highlowtech.org/wp-content/uploads/2011/10/ATtiny45-85.png)

more at [TAMI](http://telavivmakers.org/index.php?title=Brain)

# upload
using arduino uno as isp  
- add ATtiny board to arduino 1.6.5> 
(see http://highlowtech.org/?p=1695)  
--(TLDR) add [this](https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json) to your board manager

- upload sketch files>exampels>arduinoISP to your uno  
- then select tools>programmer>"arduino as isp"  
-- select  
-- board>ATtiny 
-- Processor>ATtiny85  
-- Clock>8Mhz (internal)  

