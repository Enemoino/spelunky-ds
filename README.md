
<h1 align="center"> Spelunky® remake for the NintendoDS. </h1><p align="center">(a.k.a SpelunkyDS)</p>

<p align="center"><img src="https://github.com/dbeef/spelunky-ds/blob/master/readme/gameplay.gif" alt="Works on real NDS!"
 width="240" height="340">
 
</p>

<h2 align="center">To-do list as for now</h2>
<ul>
 
<li> 🗙	Implement shopkeeper logics and randomly spawned shops  </li>
<li> 🗙 Implement damsel </li>
<li> 🗙 Implement caveman </li>
<li> 🗙 Implement skeleton </li>
<li> 🗙 Implement arrow trap </li>
<li> 🗙 Implement cape and jetpack </li>
<li> 🗙 Implement 4 layers system - top one for the console and HUD, bottom one for tilemap and the rest for other sprites </li>
<li> 🗙 Tune-up the level generator; make it more random; add random events like snake well </li>
<li> 🗙 Implement music using streaming from filesystem - I elaborated a bit on this on my blog: https://dbeef.wordpress.com/2018/05/24/some-words-on-developing-spelunkyds/ </li> 
 
</ul>
 
 Obviously I omit things like implement Olmec or implement lava city - let's finish cave level first.

<h2 align="center"> Tools I use </h2>
<ul>
  <li> C++ </li>
  <li> GNU Make </li>
  <li> libnds - as included with devkitPro toolchain https://devkitpro.org/ </li>
  <li> mappy - https://tilemap.co.uk/mappy.php </li>
  <li> desmume emulator </li>
  <li> R4 card for testing on a real Nintendo </li>
  <li> gimp, for converting to 256 color (8bit) indexed bmp/png </li>
  <li> a real Spelunky code for inspiration ofcourse, distributed by Derek Yu on this address: http://www.derekyu.com/games/spelunky_1_1_src.zip </li>
  <li> Spelunky assets, I take them from the Spelunky Community Update Project because there's no need for installing Game Maker: https://github.com/tyrovc/SpelunkyCommunityUpdateProject </li>
  <li> CLion for editing </li>
</ul>

<h2 align="center"> License </h2>

<p> Full license text can be accessed under this link: </p>
https://github.com/dbeef/spelunky-ds/blob/master/LICENSE
<p>
Briefly, as for my code, I distribute it under GNU General Public License, as for Spelunky game assets, I use them under Spelunky® User License v1.1b, also, for building I use devkitPro which is under GNU General Public License (GPL).
</p>


<h2 align="center">Contributing</h2>

I will accept every help with running this project, feel free to catch one or more of the todo's.

<h2 align="center"> Links </h2>
I found following materials very helpful:

<ul> 
  <li> A great, great manual which introduced me to NDS programming: https://patater.com/files/projects/manual/manual.html</li>
  <li> http://cpp4ds.blogspot.com/ </li>
  <li> A great video series about Spelunky level generator https://www.youtube.com/watch?v=ouh7EZ5Qh9g</li>
  <li> This online demonstration for Spelunky level generator http://tinysubversions.com/spelunkyGen/ </li>
  <li> This blog, in particular this entry about alpha blending: http://www.liranuna.com/nds-blending-demo/ </li>
  <li> libnds documentation https://libnds.devkitpro.org </li>
  <li> devkitPro forum https://devkitpro.org </li>
  <li> this blog, that post in particular: https://www.coranac.com/tonc/text/regbg.htm </li>
  <li> memory access calculator: https://mtheall.com/vram.html </li>
  <li> this post: https://gamedev.stackexchange.com/questions/61065/using-ndslib-how-to-configure-video-modes-to-both-print-text-and-draw-bitmaps-o </li>
 
</ul>
