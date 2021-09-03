# CAF-Rail-Arduino-Project
RemoteController.ino is the code for a remote controller that has 2 buttons (Go and Stop) which communicates with another
Arduino runnning GantryCode.ino

The GO button sends the plaintext "MOVE" wirelessly to the gantry making it move (however there are no moving parts on the gantry controller just a serial
output saying that it is moving). The Stop button sends the plaintext "STOP" to the gantry making the gantry stop (but it only outputs stop on the serial output
because there are no moving parts)
