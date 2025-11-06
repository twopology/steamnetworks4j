#include <org_twopology_steamnetworks4j_SteamInterface.h>

//@line:47

		#include "SteamCallbackAdapter.h"
	JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamInterface_deleteCallback(JNIEnv* env, jclass clazz, jlong callback) {


//@line:51

		delete (SteamCallbackAdapter*) callback;
	

}

