#include <org_twopology_steamnetworks4j_SteamUserNative.h>

//@line:9

		#include <steam_api.h>
		#include "SteamUserCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:14

		return (intp) new SteamUserCallback(env, javaCallback);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_getSteamID(JNIEnv* env, jclass clazz) {


//@line:18

		CSteamID steamID = SteamUser()->GetSteamID();
		return (int64) steamID.ConvertToUint64();
	

}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_initiateGameConnection
(JNIEnv* env, jclass clazz, jobject obj_authBlob, jint bufferOffset, jint bufferSize, jlong steamIDGameServer, jint serverIP, jshort serverPort, jboolean secure, char* authBlob) {

//@line:25

		int bytesWritten = SteamUser()->InitiateGameConnection_DEPRECATED(&authBlob[bufferOffset], bufferSize,
			(uint64) steamIDGameServer, serverIP, serverPort, secure);
		return bytesWritten;
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_initiateGameConnection(JNIEnv* env, jclass clazz, jobject obj_authBlob, jint bufferOffset, jint bufferSize, jlong steamIDGameServer, jint serverIP, jshort serverPort, jboolean secure) {
	char* authBlob = (char*)(obj_authBlob?env->GetDirectBufferAddress(obj_authBlob):0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_initiateGameConnection(env, clazz, obj_authBlob, bufferOffset, bufferSize, steamIDGameServer, serverIP, serverPort, secure, authBlob);


	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_terminateGameConnection(JNIEnv* env, jclass clazz, jint serverIP, jshort serverPort) {


//@line:31

		SteamUser()->TerminateGameConnection_DEPRECATED(serverIP, serverPort);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_startVoiceRecording(JNIEnv* env, jclass clazz) {


//@line:35

		SteamUser()->StartVoiceRecording();
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_stopVoiceRecording(JNIEnv* env, jclass clazz) {


//@line:39

		SteamUser()->StopVoiceRecording();
	

}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_getAvailableVoice
(JNIEnv* env, jclass clazz, jintArray obj_bytesAvailable, int* bytesAvailable) {

//@line:43

		return SteamUser()->GetAvailableVoice((uint32*) bytesAvailable);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_getAvailableVoice(JNIEnv* env, jclass clazz, jintArray obj_bytesAvailable) {
	int* bytesAvailable = (int*)env->GetPrimitiveArrayCritical(obj_bytesAvailable, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_getAvailableVoice(env, clazz, obj_bytesAvailable, bytesAvailable);

	env->ReleasePrimitiveArrayCritical(obj_bytesAvailable, bytesAvailable, 0);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_getVoice
(JNIEnv* env, jclass clazz, jobject obj_voiceData, jint bufferOffset, jint bufferCapacity, jintArray obj_bytesWritten, char* voiceData, int* bytesWritten) {

//@line:48

		return SteamUser()->GetVoice(true, &voiceData[bufferOffset], bufferCapacity, (uint32*) bytesWritten);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_getVoice(JNIEnv* env, jclass clazz, jobject obj_voiceData, jint bufferOffset, jint bufferCapacity, jintArray obj_bytesWritten) {
	char* voiceData = (char*)(obj_voiceData?env->GetDirectBufferAddress(obj_voiceData):0);
	int* bytesWritten = (int*)env->GetPrimitiveArrayCritical(obj_bytesWritten, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_getVoice(env, clazz, obj_voiceData, bufferOffset, bufferCapacity, obj_bytesWritten, voiceData, bytesWritten);

	env->ReleasePrimitiveArrayCritical(obj_bytesWritten, bytesWritten, 0);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_decompressVoice
(JNIEnv* env, jclass clazz, jobject obj_voiceData, jint voiceBufferOffset, jint voiceBufferSize, jobject obj_audioData, jint audioBufferOffset, jint audioBufferCapacity, jintArray obj_bytesWritten, jint desiredSampleRate, char* voiceData, char* audioData, int* bytesWritten) {

//@line:54

		return SteamUser()->DecompressVoice(&voiceData[voiceBufferOffset], voiceBufferSize,
			&audioData[audioBufferOffset], audioBufferCapacity, (uint32*) bytesWritten, desiredSampleRate);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_decompressVoice(JNIEnv* env, jclass clazz, jobject obj_voiceData, jint voiceBufferOffset, jint voiceBufferSize, jobject obj_audioData, jint audioBufferOffset, jint audioBufferCapacity, jintArray obj_bytesWritten, jint desiredSampleRate) {
	char* voiceData = (char*)(obj_voiceData?env->GetDirectBufferAddress(obj_voiceData):0);
	char* audioData = (char*)(obj_audioData?env->GetDirectBufferAddress(obj_audioData):0);
	int* bytesWritten = (int*)env->GetPrimitiveArrayCritical(obj_bytesWritten, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_decompressVoice(env, clazz, obj_voiceData, voiceBufferOffset, voiceBufferSize, obj_audioData, audioBufferOffset, audioBufferCapacity, obj_bytesWritten, desiredSampleRate, voiceData, audioData, bytesWritten);

	env->ReleasePrimitiveArrayCritical(obj_bytesWritten, bytesWritten, 0);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_getVoiceOptimalSampleRate(JNIEnv* env, jclass clazz) {


//@line:59

		return (int) SteamUser()->GetVoiceOptimalSampleRate();
	

}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_getAuthSessionTicket
(JNIEnv* env, jclass clazz, jobject obj_authTicket, jint bufferOffset, jint bufferCapacity, jintArray obj_sizeInBytes, char* authTicket, int* sizeInBytes) {

//@line:64

		int ticket = SteamUser()->GetAuthSessionTicket(&authTicket[bufferOffset], bufferCapacity, (uint32*) sizeInBytes, nullptr);
		return ticket;
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_getAuthSessionTicket(JNIEnv* env, jclass clazz, jobject obj_authTicket, jint bufferOffset, jint bufferCapacity, jintArray obj_sizeInBytes) {
	char* authTicket = (char*)(obj_authTicket?env->GetDirectBufferAddress(obj_authTicket):0);
	int* sizeInBytes = (int*)env->GetPrimitiveArrayCritical(obj_sizeInBytes, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_getAuthSessionTicket(env, clazz, obj_authTicket, bufferOffset, bufferCapacity, obj_sizeInBytes, authTicket, sizeInBytes);

	env->ReleasePrimitiveArrayCritical(obj_sizeInBytes, sizeInBytes, 0);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_getAuthTicketForWebApi
(JNIEnv* env, jclass clazz, jstring obj_identity, char* identity) {

//@line:69

		if (identity[0] == '\0') {
			identity = nullptr;
		}
		int ticket = SteamUser()->GetAuthTicketForWebApi(identity);
		return ticket;
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_getAuthTicketForWebApi(JNIEnv* env, jclass clazz, jstring obj_identity) {
	char* identity = (char*)env->GetStringUTFChars(obj_identity, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_getAuthTicketForWebApi(env, clazz, obj_identity, identity);

	env->ReleaseStringUTFChars(obj_identity, identity);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_beginAuthSession
(JNIEnv* env, jclass clazz, jobject obj_authTicket, jint bufferOffset, jint bufferSize, jlong steamID, char* authTicket) {

//@line:78

		return SteamUser()->BeginAuthSession(&authTicket[bufferOffset], bufferSize, (uint64) steamID);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_beginAuthSession(JNIEnv* env, jclass clazz, jobject obj_authTicket, jint bufferOffset, jint bufferSize, jlong steamID) {
	char* authTicket = (char*)(obj_authTicket?env->GetDirectBufferAddress(obj_authTicket):0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_beginAuthSession(env, clazz, obj_authTicket, bufferOffset, bufferSize, steamID, authTicket);


	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_endAuthSession(JNIEnv* env, jclass clazz, jlong steamID) {


//@line:82

		SteamUser()->EndAuthSession((uint64) steamID);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_cancelAuthTicket(JNIEnv* env, jclass clazz, jint authTicket) {


//@line:86

		SteamUser()->CancelAuthTicket(authTicket);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_userHasLicenseForApp(JNIEnv* env, jclass clazz, jlong steamID, jint appID) {


//@line:90

		return SteamUser()->UserHasLicenseForApp((uint64) steamID, (AppId_t) appID);
	

}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_requestEncryptedAppTicket
(JNIEnv* env, jclass clazz, jlong callback, jobject obj_dataToInclude, jint bufferOffset, jint bufferSize, char* dataToInclude) {

//@line:95

		SteamUserCallback* cb = (SteamUserCallback*) callback;
		SteamAPICall_t handle = SteamUser()->RequestEncryptedAppTicket(&dataToInclude[bufferOffset], bufferSize);
		cb->onRequestEncryptedAppTicketCall.Set(handle, cb, &SteamUserCallback::onRequestEncryptedAppTicket);
		return handle;
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_requestEncryptedAppTicket(JNIEnv* env, jclass clazz, jlong callback, jobject obj_dataToInclude, jint bufferOffset, jint bufferSize) {
	char* dataToInclude = (char*)(obj_dataToInclude?env->GetDirectBufferAddress(obj_dataToInclude):0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_requestEncryptedAppTicket(env, clazz, callback, obj_dataToInclude, bufferOffset, bufferSize, dataToInclude);


	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_getEncryptedAppTicket
(JNIEnv* env, jclass clazz, jobject obj_ticket, jint bufferOffset, jint bufferCapacity, jintArray obj_sizeInBytes, char* ticket, int* sizeInBytes) {

//@line:103

		return SteamUser()->GetEncryptedAppTicket(&ticket[bufferOffset], bufferCapacity, (uint32*) sizeInBytes);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_getEncryptedAppTicket(JNIEnv* env, jclass clazz, jobject obj_ticket, jint bufferOffset, jint bufferCapacity, jintArray obj_sizeInBytes) {
	char* ticket = (char*)(obj_ticket?env->GetDirectBufferAddress(obj_ticket):0);
	int* sizeInBytes = (int*)env->GetPrimitiveArrayCritical(obj_sizeInBytes, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserNative_getEncryptedAppTicket(env, clazz, obj_ticket, bufferOffset, bufferCapacity, obj_sizeInBytes, ticket, sizeInBytes);

	env->ReleasePrimitiveArrayCritical(obj_sizeInBytes, sizeInBytes, 0);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_isBehindNAT(JNIEnv* env, jclass clazz) {


//@line:107

		return SteamUser()->BIsBehindNAT();
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamUserNative_advertiseGame(JNIEnv* env, jclass clazz, jlong steamID, jint serverIP, jshort serverPort) {


//@line:111

		SteamUser()->AdvertiseGame((uint64) steamID, serverIP, serverPort);
	

}

