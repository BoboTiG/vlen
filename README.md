
vlen
====

Copyright (C) 2010-2012 by BoboTiG.
 
vlen comes with ABSOLUTELY NO WARRANTY.  
This is free software, and you are welcome to redistribute it under   
certain conditions. See the GNU General Public Licence for details.  

vlen is a tool to get the duration of a video file.  


Requirements
------------

For source compilation you need OpenCV headers :

* libopencv
* libhighgui

For Debian GNU/Linux :  
`aptitude install libopencv-dev libhighgui-dev`


Installation
------------

make  
make install


Usage
-----

vlen FILE [-q]


Issue
-----
	[*] Invalid and inefficient vfw-avi packed B frames detected
	These errors could append when the file is bad encoded, the duration
	could be altered.
