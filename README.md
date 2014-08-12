### lcd-wolf3d


Ray casting engine for the Arduino, or any AVR microcontroller.


The ray-casting engine paints to a buffer in RAM and uses the KS0108 library to
send it to the LCD to paint each frame. In order to get it to run at a playable
speed, the ray casting function is only called for 1/4 of the columns
rendered, and the data to display the columns correctly is interpolated.  The
engine checks if it can do interpolation without it looking terrible
(around a corner, edge of wall, etc.), and if this test fails it will cast extra
rays.
