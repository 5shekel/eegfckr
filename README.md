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


##software
in process.   
also see [low.li blog post](http://low.li/story/2011/01/arduino-brain-machine) > [github](https://github.com/LaughterOnWater/Arduino-Brain-Machine)

### tone talk
links on tone lib modfing for the attiny family and some light low level code talk.
[A Tone Generator for Trinket](http://w8bh.net/avr/TrinketTone.pdf)  
[Waveform Generation using an ATtiny85](http://www.technoblogy.com/show?QVN) | [archive.is](https://archive.is/Lsk9m)  
[tinyTune func](http://www.technoblogy.com/show?KVO)   
[programming the LilyPad Arduino: sound](http://web.media.mit.edu/~leah/LilyPad/07_sound.html)  
[link-an-led-with-an-avr](http://www.evilmadscientist.com/2012/blink-an-led-with-an-avr/)  
[http://www.ladyada.net/learn/proj1/blinky.html](http://www.ladyada.net/learn/proj1/blinky.html)  
[binaureal beats using the arduino](http://forum.arduino.cc/index.php?topic=41077.0)  
[brainwave-disruptor](http://blog.ponoko.com/2011/08/05/rich-decibels-brainwave-disruptor/) >> [polytones without delay](https://gist.github.com/5shekel/ce690d048fac5872f0ad)

### upload
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

### Components
[BOM google sheet](https://docs.google.com/spreadsheets/d/1JA0BjbYkpqYi8BU7iDlsvR_3m2nQNDry2EhpkC5hDX0/edit?ts=5613f817#gid=0) 

### workshops:  
[TAMI hackerspace wiki page](http://telavivmakers.org/index.php?title=Brain )  
[zimmer workshop #1 pics](http://imgur.com/a/cNCWE) [FB event](https://www.facebook.com/events/823769724411378/)  


##links
[The history of the electrical stimulation of the brain](http://www.cerebromente.org.br/n18/history/stimulation_i.htm)  
[Hans Berger: From Psychic Energy to the EEG](http://methodsinbraincomputerinterfaces.wikispaces.com/file/view/BergerBiography.pdf)  
[Hans Berger portrait](http://neuroportraits.eu/portrait/hans-berger)
[History of glasses](http://www.museumofvision.org/exhibitions/?key=44&subkey=4&relkey=35)  
[1750 Martins Margins type spectacles](http://www.museumofvision.org/collection/artifacts/?accession=1999.024.00059) 
[Guide to Assist in the Identification of Antique Spectacles](http://www.antiquespectacles.com/guide/guide_to_assist.htm)  
Weird eye-ware designs [#1](https://www.flickr.com/photos/x-ray_delta_one/4747873754/) [#2](https://www.flickr.com/photos/x-ray_delta_one/4265173624/in/album-72157622288782911/)  
[E-waste recycled glasses](https://www.facebook.com/ajplusenglish/videos/586570601484451/?pnref=story)  
[chris-marker La Jetée](http://www.theguardian.com/film/2014/apr/15/thrilling-prophetic-chris-marker-experimental-films)  
![stills from La Jetée](http://i.imgur.com/3AqJXFk.jpg)

#text

DIY MIND MACHINES & CREATIVE "EYE-WARE"

"... and you realized that reality is neurology, and is not absolute."
Cronenberg, David. Consumed: A Novel (p. 225)

Subtle change from electricity to light marks a major breakthrough in brain research methodology, which remains to be translated into designing future brain interfaces. After centuries of using electricity to stimulate and research the brain, optogenetics marks a phase, in which we are starting to use light to activate not only brain regions, but actual neurons and their pathways. To understand this transformation from electricity to light as a medium for exploring our mind, we will prototype a creative eye-ware with LEDs, which can alter EEG signals in the brain. We will solder a simple circuit for output blinking LEDs in frequency between 4-32Hz, which serve as basic components to design a mind machine device. The final prototype will have a form of a creative eyewear or "eye-ware" mocking some recent history of Google glass mania and other futuristic attempts to hack eyeglasses. The simple analogue circuit operating a specially positioned LEDs works with the phenomenon of photosensitivity, which can alter the EEG signals. By flashing at certain frequencies and coupled with binaural tones over headphones it can even improve conditions, such as ADHD or trigger various altered states of the mind. Supposedly, such device can even  affect the growth of the individual dendrites on a neuronal level and influence various cognitive functions. With this prototype of a creative eye-ware we plan to look closer into the media archeology behind mind altering devices and various experiments with "biological (animal) electricity" (Luigi Galvani) and "psychic energy" (Hans Berger), but also probe the emergent field of optogenetics and its genetically modified organic "photoswitches". The original experiments with electricity led to the discovery of electroencephalography (EEG) in 1929, but also positron emission tomography (PET) and function magnetic resonance imaging (fMRI), and subsequent attempts to differentiate between metabolic, neural and cognitive processes (glucose concentration, cerebral blood flow, neural activity, mental phenomena, or alpha and beta etc. waves). The present experiments with photons in the case of optogenetics have yet to be discovered applications, metaphors and (nootropic) "neuro-politics", which we want to explore. We will bridge philosophy, brain science and design to create scenarios of future optogenetics with the use of prototypes and mockups. We will try to imagine a future, in which control and alteration of behaviour and mood can happen through light in real time on the level of individual neurons. Would such future bring a total control or unimaginable anarchy? How would devices using optogenetics look like? Will they finally kill the sophists and the delicate art of persuasion, which Plato hated so much, or open infinite space for infinite deception and lying or maybe trigger "sensitivity to  aberrant realities" as the audio-device described by David Cronenberg in his last novel "Consumed"? How to imagine and design for such direct control of our judgement, taste, behaviour through the brain rather than language and experience? Are we facing similar future to the one hinted in a forgotten 1972 David Cronenberg's movie "Secret Weapons" on a drug that enhances fighting skills? We will use his recent novel "Consumed" with its bizarre story of insects, North Korea film industry, obsession with proteins, philosophy of consumerism, and one brilliant idea of filtered hearing aids that can derange human perception and lead to madness as one of the starting points.   Will the future mind machines resemble Cronenberg's organic machinery, such as these madness inducing audiotech devices exploring radical decadence of the senses forgotten by all tech revolutions? Our design will be dark and sinister and use his weird metabolic theme of eating and becoming food, being a consumer and consumed, exotic toys and diseases as means of intercultural exchanges, autonomy and parasitism, against the clear, moralist or other world saving agenda, which lead to very boring designs. Quotes for inspiration:
"When I first got my hearing aids, which were primarily tuned to augment those higher frequencies which are usually the first to disappear with age, it is true that the world instantly became louder and more harsh; it was difficult for someone whose aural landscape had so gradually become more and more muted and dulled to believe that this was hearing as experienced by most people, that this harshness was just the restoration of higher sound frequencies that had been lost. But the most disorienting aspect of this new soundscape was that sounds now carried too much emotion, too much meaning, so that a single sneeze was an expression of rage, the closing of a bedroom door was a pointed separation that would need healing, the smacking of a pillow to reshape it in the middle of the night was an explosive assault that caused my heart to pound with reflexive anger. A recalibration of my reaction to the intensity of sounds was urgently demanded, and though was constantly recalibrating, those unexpected shots of adrenaline still persisted and confused me. I wanted to jerk out of bed and slam the bedroom door and go for a petulant walk in the wet, dark streets, muttering to myself about spousal insult and betrayal. But I recalibrated.
Cronenberg, David (2014-09-30). Consumed: A Novel (p. 217). Scribner. Kindle Edition.
