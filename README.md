# (Linux Platform Only) Live Streaming / Video Capture (with ffmpeg) for UnrealEngine 5

> Read the original README upstream or translation of it on this [gist](https://gist.github.com/MandarDevarshi/6f5677459632227361e3ce23a95490ba)

- ffmpeg 4.0.6 "Wu" [ffmpeg Old Releases Download](https://ffmpeg.org/olddownload.html))
- NVIDIA Driver v 525
- Unreal Engine v 5.1.0
- As `h264_nvenc` encoder is being used for remaking ffmpeg [Read](https://docs.nvidia.com/video-technologies/video-codec-sdk/ffmpeg-with-nvidia-gpu/)
- Configure flags used for ffmpeg were following
  
	```bash
	./configure \
	--prefix="/home/lemon/debug-ffmpeg/made" \
	--enable-static \
	--enable-shared \
	--enable-nonfree \
	--enable-pic \
	--enable-ffnvcodec \
	--enable-libnpp \
	--enable-pthreads \
	--disable-doc \
	--nvcc=/usr/bin/bin/ \
	--disable-stripping \
	--disable-optimizations \
	--disable-asm \
	--extra-cflags=-I/usr/include/ \
	--extra-cflags=-I/usr/include/** \
	--extra-cflags=-I/usr/local/include/ffnvcodec \
	--extra-ldflags=-L/lib/x86_64/
	```

- Fix Warning once open in Unreal Editor: Actor needs a resave. Right click on WorldDataLayer-1 and Save selected actor, same for others if required.

- Fix path of the output file in the blueprint to match UNIX filesystem

## Helper Note

The original author had most probably used the following flags, they were extracted from the dynamic libraries for Windows Platform. Along with the `version` used as `ffmpeg 4.0`.

Use it to your help in case of different hardware target, harware accelerators and also to reduce the size of this project by including only the encoders, protocols...etc. required rather than all.

As not all hardware accelerators are required and some features are internal to Unreal Engine, the below flags seem a little superflous

```
--toolchain=msvc --arch=x86 --disable-static --enable-shared --enable-libmp3lame --enable-gpl --enable-w32threads --enable-libvpx --disable-yasm --enable-nvenc --enable-cuda --enable-cuvid --enable-openal --enable-d3d11va --extra-cflags=-I../lame-3.99.5/include --extra-cflags=-I../SDL2-2.0.8/include --extra-cflags='-IH:/Pixelarama/MainCode/ExternalLibs/OpenCL/Nvidia/include' --extra-cflags=-I../libvpx --extra-cflags='-IC:/PROGRA~1/NVIDIA~2/CUDA/v9.1/include' --extra-cflags='-IH:/Pixelarama/MainCode/ExternalLibs/openal/include' --extra-cflags=-I../zlib-1.2.11/build/install/include --extra-cflags=-I../nv-codec-headers/include --extra-ldflags='-LIBPATH:H:/Pixelarama/MainCode/ExternalLibs/OpenCL/Nvidia/lib' --extra-ldflags='-LIBPATH:../lame-3.99.5/output/Release/win32' --extra-ldflags='-LIBPATH:C:/PROGRA~1/NVIDIA~2/CUDA/v9.1/lib/win32' --extra-ldflags='-LIBPATH:H:/Pixelarama/MainCode/ExternalLibs/openal/lib' --extra-ldflags='-LIBPATH:../zlib-1.2.11/build/install/lib' --extra-ldflags='-LIBPATH:../libvpx/build32/Win32/Release' --extra-ldflags='-LIBPATH:../SDL2-2.0.8/lib/x86'
```

