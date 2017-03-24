# teatime ncurse

A simple C ncruse-based timer made in order to know when my tea is ready.

## Foreword:
This program DOES NOT PROVIDE WARRANTY OF ANY KIND.

Currently, the project is distributed without license.

Only tested on Debian 9 (testing) amd64.

## Getting started:

How to propely install and use teatime.

### Prerequisite

First, make sure you have Make, GCC and ncurses

...
$> sudo apt-get install make gcc ncurses
...

### Instalation

First, move to the cloned repository

...
$> cd ~/-path-/teatime_ncruse-master
...

Then, proceed to the compliation

...
$> make
...

If no error occurs during the compilation, teatime is now ready.

## Usage:

teatime is currently compiled as a local software.
You need to explicitly call him each time you want to run it

...
$> ~/-your-/-path-/teatime [option(s)]
...

By now, only four options are available

...
-m --minutes={XX}	  -> Add XX minute(s) to the timer
-s --seconds={YY}	  -> Add YY second(s) to the timer
-h --help		  -> Display this help
-v --version		  -> Display current version and extra info
...

At least one time option is required, and the time should e greater than 0s.

Currently, this program have no real usage.