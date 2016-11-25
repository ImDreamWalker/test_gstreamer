/* This is a basic GStreamer Hello World program */

#include<gst/gst.h>

int main(int argc, char* argv[])
{
	GstElement *pipeline;
	GstBus *bus;
	GstMessage *msg;

	/*Initialize the GStreamer */
	gst_init(&argc, &argv);

	/*Build the pipeline*/
	pipeline =  gst_parse_launch("playbin2 uri=http://docs.gstreamer.com/media/sintel_trailer-480p.webm", NULL);

	/*Start Playing*/
	gst_element_set_state(pipeline, GST_STATE_PLAYING);

	/*Wait untill EOS or Error*/
	bus=gst_element_get_bus(pipeline);
	msg=gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

	/*Free resources*/
	if(msg!=NULL)
	{
		gst_message_unref(msg);
		gst_object_unref(bus);
		gst_element_set_state(pipeline, GST_STATE_NULL);
		gst_object_unref(pipeline);

		return 0;
	}

}
