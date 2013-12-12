marsyas-guitar-effects
======================

Real-time guitar effects in Marsyas.

## Usage

First you should have Marsyas built with JACK: `https://github.com/marsyas/marsyas`.

````
qmake main.pro
make main
./main <Cutoff | RepeatSine | ApproachSquare> parameter
````

Then plug in your guitar and have fun!

For parameter value please see header files.
