package org.twopology.steamnetworks4j;

class SteamGameServerHTTPNative {

	// @off

	/*JNI
		#include "SteamGameServerHTTPCallback.h"
	*/

	static native long createCallback(Object javaCallback); /*
		return (intp) new SteamGameServerHTTPCallback(env, javaCallback);
	*/

}
