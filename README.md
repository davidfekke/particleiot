# Demo code for April 2016 JaxARCSIG

This is the demo code for the four demos we showed at the JaxARCSIG. 
Here are instructions on how you use this code on your particle Photon or Electron.

## Demo 1 Remote Control LED

Make sure your particle Electron or Photon is turned on and connected to the 
Particle cloud service. Then type the following commands;

```
cd remotecontrol
``` 

Either use Particle's Build WebIDE or flash your device with the 'remotecontrolled.ino' file.
For this example you only have to wire up an LED to the D6 pin. After your device is flashed, make sure you
have the following environment variables set on the computer you are planning on running
the remote control express site.

```
export SPARKACCESSTOKEN=<Your particle access token, can be found on the build Web IDE settings>
export DFEKKEELECTRON1=<Your deviceID>
```

Use the following commands to run the express site;

```
npm install
node app.js
```

Your should be able access the site using the following URL: http://localhost:3000

## Demo 2 Sumo Twitter Robot

This demo expects that you have a sumobot. For this example make sure your Photon
is wired to the servos on pins (D1 right servo, D0 left servo).

Make sure your particle Electron or Photon is turned on and connected to the 
Particle cloud service. Then type the following commands;

```
cd sumotwitter
``` 

Either use Particle's Build WebIDE or flash your device with the 'sumotwitter.ino' file.

This example requires that you have valid twitter developer credentials. 
Make sure you have the following environment variables set;

```
export twitter_ck=<consumer_key>
export twitter_cs=<consumer_secret>
export twitter_atk=<access_token_key> 
export twitter_ats=<access_token_secret> 

export particle_username=<particle username>
export particle_password=<particle password>
export SPARKACCESSTOKEN=<Your particle access token, can be found on the build Web IDE settings>
```

Once you have device flashed, you can run the node example by running the following commands;

```
npm install
node index.js
```

## Demo 3 Twitter Stream LCD

Make sure your particle Electron or Photon is turned on and connected to the 
Particle cloud service. Then type the following commands;

```
cd twitterlcd
``` 

Either use Particle's Build WebIDE or flash your device with the 'write_to_lcd.ino' file. 
You will also need to include "Serial_LCD_SparkFun" library for this example.

You will need to have valid twitter developer credentials and the same environment variables set as in example 2.

This example requires the serial connection, so you will use the following pins to wire the 
LCD display to your Photon (VIN, GND, TX).

To run the example, run the following commands;

```
npm install
node index.js
```

## Example 4 Internet Button

This example requires the Photon Internet Button. Make sure it is turned on and type the following commands;

```
cd twitterlcd
```

Flash your Internet Button with the 'button.ino' file. This example requires the "InternetButton" library be included.

Make sure your have the following environment variables set;

```
export particle_username=<particle username>
export particle_password=<particle password>
export SPARKACCESSTOKEN=<Your particle access token, can be found on the build Web IDE settings>
export button_device=<Your deviceID>
```

Once your button is on, you can use the following commands to run this example;

```
npm install
node button.js
```

David Fekke, Copyright 2016, Apache 2.0 license
