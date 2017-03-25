# teatime_ncurses

A simple C ncurses-based timer made in order to know when my tea is ready.

## Foreword:
This program DOES NOT PROVIDE WARRANTY OF ANY KIND.
Currently, the project is distributed without license.
Only tested on Debian 9 (testing) with amd64 architecture.

## Getting started:

How to properly install and use Teatime.

### Prerequisite

First, make sure you have Make, GCC and ncurses

`sudo apt-get install make gcc libncurses5`

Or for Archlinux-related OS

`sudo pacman -S make gcc libncurses5`
### Installation

First, move to the cloned repository

`cd ~/-path-/teatime_ncruse-master`

Then, proceed to the compilation

`make`

If no error occurs during the compilation, Teatime is now ready.

## Usage:

Teatime is currently compiled as a local software.
You need to explicitly call it each time you want to run it

`~/-your-/-path-/teatime [option(s)]`

In order to use it from anywhere, you have to either create an alias in your shell .rc file (such as ~/.bashrc or ~/.zshrc) or move it in one of your bin folder (requiring root permission).

Five options are availables

```
-m --minutes={XX}	  -> Add XX minute(s) to the timer
-s --seconds={YY}	  -> Add YY second(s) to the timer
-p --pause		  -> Start the program with paused timer
-h --help		  -> Display this help
-v --version		  -> Display current version and extra info
 q 			  -> Quit the program during execution
 p			  -> (Un)pause the timer during execution
```

At least one time option is required, and the time should be between 00:01 and 99:59.
Once the timer is reached, press any key to stop Teatime.