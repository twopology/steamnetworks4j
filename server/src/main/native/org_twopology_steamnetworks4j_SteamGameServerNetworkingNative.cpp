#include <org_twopology_steamnetworks4j_SteamGameServerNetworkingNative.h>

//@line:7

		#include "SteamGameServerNetworkingCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNetworkingNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:11

		return (intp) new SteamGameServerNetworkingCallback(env, javaCallback);
	

}

