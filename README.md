Xadow_BLECommsBasic
===================

Basic code to establish BLE serial comms between Xadow and a mobile app. 

You can send a text string from your phone to the Xadow device via Bluetooth Low Energy, this string will then show up in the OLED display on the Xadow, or can be processed for what you need it to do. You can also send text strings from the Xadow to the mobile app.

Setup your Xadow with:

1. Main board - running Arduino

2. Xadow BLE module - http://www.seeedstudio.com/depot/Xadow-BLE-p-1727.html, http://www.seeedstudio.com/wiki/Xadow_-_BLE (note this is NOT the BLE Slave)

3. OLED - http://www.seeedstudio.com/depot/Xadow-OLED-096-p-1520.html?cPath=34_36

Load this Arduino sketch to your Xadow main board.

Download the Xadow BLE mobile app:

iOS - TBD

Windows Mobile - TBD

Using your app, you can now establish a BLE connection with your Xadow device.
Send text to your Xadow and see it appear on the OLED display.



