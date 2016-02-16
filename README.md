# eegfckr
TLDR>>> brain eeg exciter, a simlpe device to output blinking LEDs in freq between 4-32Hz  

After centuries of using electricity to stimulate and research the brain, optogenetics marks a phase, in which we use light to activate neurons and their pathways. To understand this transformation from electricity to light as a medium for exploring our mind, we will prototype a creative eye-ware with LEDs, which can alter EEG signals in the brain. We will solder a simple circuit that acts as a mind machine device. The final prototype will have a form of a creative eyewear or "eye-ware" mocking some recent history of Google glass mania and other futuristic attempts to hack eyeglasses.

![](http://i.imgur.com/2eitLkN.jpg)   
[more pics at imgur](http://imgur.com/a/cNCWE)

#board Layout
Schema  
![](https://i.imgur.com/GS73reS.png)

Board layout (example)  
![](http://i.imgur.com/JOm8612.png)

Attiny85 pinout  
![](http://highlowtech.org/wp-content/uploads/2011/10/ATtiny45-85.png)


##links
[The history of the electrical stimulation of the brain](http://www.cerebromente.org.br/n18/history/stimulation_i.htm)  
[Hans Berger: From Psychic Energy to the EEG](http://methodsinbraincomputerinterfaces.wikispaces.com/file/view/BergerBiography.pdf)  
[Hans Berger portrait](http://neuroportraits.eu/portrait/hans-berger)
[History of glasses](http://www.museumofvision.org/exhibitions/?key=44&subkey=4&relkey=35)  
[1750 Martins Margins type spectacles](http://www.museumofvision.org/collection/artifacts/?accession=1999.024.00059) 
[Guide to Assist in the Identification of Antique Spectacles](http://www.antiquespectacles.com/guide/guide_to_assist.htm)  
Weird eye-ware designs [#1](https://www.flickr.com/photos/x-ray_delta_one/4747873754/) [#2](https://www.flickr.com/photos/x-ray_delta_one/4265173624/in/album-72157622288782911/)  
[E-waste recycled glasses](https://www.facebook.com/ajplusenglish/videos/586570601484451/?pnref=story) 

https://github.com/LaughterOnWater/Arduino-Brain-Machine  > http://low.li/story/2011/01/arduino-brain-machine
https://github.com/lumi3005/My-Arduino/tree/master/brainmachine  
http://forum.arduino.cc/index.php?topic=41077.0  



# Components
[google sheet](https://docs.google.com/spreadsheets/d/1JA0BjbYkpqYi8BU7iDlsvR_3m2nQNDry2EhpkC5hDX0/edit?ts=5613f817#gid=0  
)  

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


# Previous workshops:  
[TAMI hackerspace wiki page](http://telavivmakers.org/index.php?title=Brain )  
[previous FB event](https://www.facebook.com/events/823769724411378/)  
[workshop #1 pics](http://imgur.com/a/cNCWE)


