# Automatic-Control-Light-Intensity-using-Fuzzy-Logic

### Project 
- Automatic Light Intensity Control with Fuzzy Logic is an automatic regulation system that uses fuzzy logic (Tsukamoto) principles to control the brightness level or intensity of lights.
- This automation system helps in optimizing energy use by regulating light intensity according to environmental conditions. Efficient use of electricity in lighting can bring economic, environmental and comfort benefits to users.
---
### Membership Function
##MF LDR 1
![My Image]((Screenshot (2207)).png)
![My Image](ldr1.png)
##MF LDR 2
![My Image]((Screenshot (2207)).png)
![My Image](ldr2.png)
##MF Output LED
![My Image]((Screenshot (2208)).png)
![My Image](out.png)

### Rule Based
- if Dark1 and Dark2 then LED Maximum
- if Dark1 and Medium2 then lED Maximum
- if Dark1 and Bright2 then lED Minimum
- if Medium1 and Dark2 then lED Maximum
- if Medium1 and Medium2 then lED Maximum
- if Medium1 and Bright2 then lED Minimum
- if Bright1 and Dark2 then lED Minimum
- if Bright1 and Medium2 then lED Minimum
- if Bright1 and Bright2 then lED Minimum

### Hardware Use
- Arduino Uno
- LDR Sensor
- LED
- LCD
- Resistor 10k
- Jumper Cables
- Breadboard
- Acrylic

### Result
![My Image]((WhatsApp Image 2023-12-15 at 18.49.39).png)
