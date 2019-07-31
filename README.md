# test_gstreamer

This will give you basic understanding of the GStreamer pipeline and how to play a video source files(MP4).

So lets begin with the elements which are required for the basic pipeline.

Elements:
1. Source file(URI)
2. Demuxer
3. Decoder
4. audiosink
5. videosink

gst-launch-1.0 filesrc location=/root/video.mp4 | decodebin | autoaudiosink 
															| autovideosink

And a GST pipeline bus handler, which will inform EOS or Error.

Free the resources when completed.

For more information please follow the official link: https://gstreamer.freedesktop.org/data/doc/gstreamer/head/manual/html/chapter-gstreamer.html

Add some more changes to new branch.

Compilation command on Linux:
gcc -Wall videoplayer.c -o videoplayer $(pkg-config --cflags --libs gstreamer-1.0 gstreamer-app-1.0)

To play or run:
./videoplayer ~/workspace/media/street_720p-videoOnly.mp4
