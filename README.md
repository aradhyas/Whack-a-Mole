# Whack-a-Mole
Hardware Components:
•	Arduino UNO
•	LEDs (7)
•	Resistors 221 ohm(7)
•	Analog Joystick
•	Jumper Wires
•	Male/Female Jumper Wires

Theory:
This "Whack-a-mole" game uses 7 LED's, and a joystick. There are 4 "moles", represented by the 2nd, 3rd, 4th, and 5th lights from the left on my board. One of the four lights will randomly light up and give a set amount of time to hit the corresponding direction on the joystick. I have arranged my lights so that, from left to right, the selections on the joystick are: left, up, down, right. This is just the convention that I chose, so creative and try other ones!
The two lights on the left are red and green, which indicate a incorrect or correct choice. The yellow light to the far right blinks the count for the current high score, and it indicates the score every time a run is over (whenever a wrong choice is made). Naturally, a new high score replaces the old one.
Perhaps the most complicated part of this project is the analog joystick. For both directions of the joystick, there are max values of 0 and 1024 (for mine, I had to use 1023, so if you aren't getting the selections correct, you can try that). I believe these values can be measured as well using a serial window. I simplified these input values using switch statements for both the x and y inputs. I am not sure if this is the best way to do it, but because I only needed the max values of each direction (i.e, only 4 options, 4 LED moles) I assigned integer values to each possibility: 1, 2, 3, 4 corresponding to Left, Right, Up, Down.



