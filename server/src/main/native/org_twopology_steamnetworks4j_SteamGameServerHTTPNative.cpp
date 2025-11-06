#include <org_twopology_steamnetworks4j_SteamGameServerHTTPNative.h>

//@line:7

		#include "SteamGameServerHTTPCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerHTTPNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:11

		return (intp) new SteamGameServerHTTPCallback(env, javaCallback);
	

}

