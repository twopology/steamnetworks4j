#include <org_twopology_steamnetworks4j_SteamNetworkingNative.h>

//@line:9

		#include "SteamNetworkingCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:13

		return (intp) new SteamNetworkingCallback(env, javaCallback);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamNetworkingNative_sendP2PPacket
(JNIEnv* env, jclass clazz, jboolean server, jlong steamIDRemote, jobject obj_data, jint offset, jint size, jint sendType, jint channel, char* data) {

//@line:18


		ISteamNetworking* net = server ? SteamGameServerNetworking() : SteamNetworking();
		return net->SendP2PPacket((uint64) steamIDRemote, &data[offset], size, (EP2PSend) sendType, channel);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingNative_sendP2PPacket(JNIEnv* env, jclass clazz, jboolean server, jlong steamIDRemote, jobject obj_data, jint offset, jint size, jint sendType, jint channel) {
	char* data = (char*)(obj_data?env->GetDirectBufferAddress(obj_data):0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamNetworkingNative_sendP2PPacket(env, clazz, server, steamIDRemote, obj_data, offset, size, sendType, channel, data);


	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamNetworkingNative_isP2PPacketAvailable
(JNIEnv* env, jclass clazz, jboolean server, jintArray obj_msgSize, jint channel, int* msgSize) {

//@line:24

		ISteamNetworking* net = server ? SteamGameServerNetworking() : SteamNetworking();
		return net->IsP2PPacketAvailable((uint32 *)msgSize, channel);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingNative_isP2PPacketAvailable(JNIEnv* env, jclass clazz, jboolean server, jintArray obj_msgSize, jint channel) {
	int* msgSize = (int*)env->GetPrimitiveArrayCritical(obj_msgSize, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamNetworkingNative_isP2PPacketAvailable(env, clazz, server, obj_msgSize, channel, msgSize);

	env->ReleasePrimitiveArrayCritical(obj_msgSize, msgSize, 0);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamNetworkingNative_readP2PPacket
(JNIEnv* env, jclass clazz, jboolean server, jobject obj_dest, jint offset, jint size, jintArray obj_msgSizeInBytes, jlongArray obj_steamIDRemote, jint channel, char* dest, int* msgSizeInBytes, long long* steamIDRemote) {

//@line:30


		ISteamNetworking* net = server ? SteamGameServerNetworking() : SteamNetworking();
		CSteamID remote;
		if (net->ReadP2PPacket(&dest[offset], size, (uint32*) msgSizeInBytes, &remote, channel)) {
			steamIDRemote[0] = remote.ConvertToUint64();
			return true;
		}
		return false;
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingNative_readP2PPacket(JNIEnv* env, jclass clazz, jboolean server, jobject obj_dest, jint offset, jint size, jintArray obj_msgSizeInBytes, jlongArray obj_steamIDRemote, jint channel) {
	char* dest = (char*)(obj_dest?env->GetDirectBufferAddress(obj_dest):0);
	int* msgSizeInBytes = (int*)env->GetPrimitiveArrayCritical(obj_msgSizeInBytes, 0);
	long long* steamIDRemote = (long long*)env->GetPrimitiveArrayCritical(obj_steamIDRemote, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamNetworkingNative_readP2PPacket(env, clazz, server, obj_dest, offset, size, obj_msgSizeInBytes, obj_steamIDRemote, channel, dest, msgSizeInBytes, steamIDRemote);

	env->ReleasePrimitiveArrayCritical(obj_msgSizeInBytes, msgSizeInBytes, 0);
	env->ReleasePrimitiveArrayCritical(obj_steamIDRemote, steamIDRemote, 0);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingNative_acceptP2PSessionWithUser(JNIEnv* env, jclass clazz, jboolean server, jlong steamIDRemote) {


//@line:41

		ISteamNetworking* net = server ? SteamGameServerNetworking() : SteamNetworking();
		return net->AcceptP2PSessionWithUser((uint64) steamIDRemote);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingNative_closeP2PSessionWithUser(JNIEnv* env, jclass clazz, jboolean server, jlong steamIDRemote) {


//@line:46

		ISteamNetworking* net = server ? SteamGameServerNetworking() : SteamNetworking();
		return net->CloseP2PSessionWithUser((uint64) steamIDRemote);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingNative_closeP2PChannelWithUser(JNIEnv* env, jclass clazz, jboolean server, jlong steamIDRemote, jint channel) {


//@line:51

		ISteamNetworking* net = server ? SteamGameServerNetworking() : SteamNetworking();
		return net->CloseP2PChannelWithUser((uint64) steamIDRemote, channel);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingNative_getP2PSessionState(JNIEnv* env, jclass clazz, jboolean server, jlong steamIDRemote, jobject connectionState) {


//@line:57


		ISteamNetworking* net = server ? SteamGameServerNetworking() : SteamNetworking();
		P2PSessionState_t result;

		if (net->GetP2PSessionState((uint64) steamIDRemote, &result)) {
			jclass clazz = env->GetObjectClass(connectionState);

			jfieldID field = env->GetFieldID(clazz, "connectionActive", "B");
			env->SetByteField(connectionState, field, (jbyte) result.m_bConnectionActive);

			field = env->GetFieldID(clazz, "connecting", "B");
			env->SetByteField(connectionState, field, (jbyte) result.m_bConnecting);

			field = env->GetFieldID(clazz, "sessionError", "B");
			env->SetByteField(connectionState, field, (jbyte) result.m_eP2PSessionError);

			field = env->GetFieldID(clazz, "usingRelay", "B");
			env->SetByteField(connectionState, field, (jbyte) result.m_bUsingRelay);

			field = env->GetFieldID(clazz, "bytesQueuedForSend", "I");
			env->SetIntField(connectionState, field, result.m_nBytesQueuedForSend);

			field = env->GetFieldID(clazz, "packetsQueuedForSend", "I");
			env->SetIntField(connectionState, field, result.m_nPacketsQueuedForSend);

			field = env->GetFieldID(clazz, "remoteIP", "I");
			env->SetIntField(connectionState, field, (jint) result.m_nRemoteIP);

			field = env->GetFieldID(clazz, "remotePort", "S");
			env->SetShortField(connectionState, field, (jshort) result.m_nRemotePort);

			return true;
        }

        return false;
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingNative_allowP2PPacketRelay(JNIEnv* env, jclass clazz, jboolean server, jboolean allow) {


//@line:95

		ISteamNetworking* net = server ? SteamGameServerNetworking() : SteamNetworking();
		return net->AllowP2PPacketRelay(allow);
	

}

