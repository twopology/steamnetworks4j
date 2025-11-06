#include <org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative.h>

//@line:9

		#include <steamencryptedappticket.h>
	static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_decryptTicket
(JNIEnv* env, jclass clazz, jobject obj_ticketEncrypted, jint encryptedOffset, jint encryptedSize, jobject obj_ticketDecrypted, jint decryptedOffset, jint decryptedSize, jbyteArray obj_key, jint keyLength, jintArray obj_decryptedLength, char* ticketEncrypted, char* ticketDecrypted, char* key, int* decryptedLength) {

//@line:15


		decryptedLength[0] = decryptedSize;

		return SteamEncryptedAppTicket_BDecryptTicket((uint8*) &ticketEncrypted[encryptedOffset], encryptedSize,
			(uint8*) &ticketDecrypted[decryptedOffset], (uint32*) &decryptedLength[0], (uint8*) key, keyLength);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_decryptTicket(JNIEnv* env, jclass clazz, jobject obj_ticketEncrypted, jint encryptedOffset, jint encryptedSize, jobject obj_ticketDecrypted, jint decryptedOffset, jint decryptedSize, jbyteArray obj_key, jint keyLength, jintArray obj_decryptedLength) {
	char* ticketEncrypted = (char*)(obj_ticketEncrypted?env->GetDirectBufferAddress(obj_ticketEncrypted):0);
	char* ticketDecrypted = (char*)(obj_ticketDecrypted?env->GetDirectBufferAddress(obj_ticketDecrypted):0);
	char* key = (char*)env->GetPrimitiveArrayCritical(obj_key, 0);
	int* decryptedLength = (int*)env->GetPrimitiveArrayCritical(obj_decryptedLength, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_decryptTicket(env, clazz, obj_ticketEncrypted, encryptedOffset, encryptedSize, obj_ticketDecrypted, decryptedOffset, decryptedSize, obj_key, keyLength, obj_decryptedLength, ticketEncrypted, ticketDecrypted, key, decryptedLength);

	env->ReleasePrimitiveArrayCritical(obj_key, key, 0);
	env->ReleasePrimitiveArrayCritical(obj_decryptedLength, decryptedLength, 0);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_isTicketForApp
(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint bufferOffset, jint bufferSize, jint appID, char* ticketDecrypted) {

//@line:24


		return SteamEncryptedAppTicket_BIsTicketForApp(
			(uint8*) &ticketDecrypted[bufferOffset], bufferSize, (AppId_t) appID);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_isTicketForApp(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint bufferOffset, jint bufferSize, jint appID) {
	char* ticketDecrypted = (char*)(obj_ticketDecrypted?env->GetDirectBufferAddress(obj_ticketDecrypted):0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_isTicketForApp(env, clazz, obj_ticketDecrypted, bufferOffset, bufferSize, appID, ticketDecrypted);


	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_getTicketIssueTime
(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint bufferOffset, jint bufferSize, char* ticketDecrypted) {

//@line:31


		return SteamEncryptedAppTicket_GetTicketIssueTime(
			(uint8*) &ticketDecrypted[bufferOffset], bufferSize);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_getTicketIssueTime(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint bufferOffset, jint bufferSize) {
	char* ticketDecrypted = (char*)(obj_ticketDecrypted?env->GetDirectBufferAddress(obj_ticketDecrypted):0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_getTicketIssueTime(env, clazz, obj_ticketDecrypted, bufferOffset, bufferSize, ticketDecrypted);


	return JNI_returnValue;
}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_getTicketSteamID
(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint bufferOffset, jint bufferSize, char* ticketDecrypted) {

//@line:38


		CSteamID steamID;

		SteamEncryptedAppTicket_GetTicketSteamID(
			(uint8*) &ticketDecrypted[bufferOffset], bufferSize, &steamID);

		return (int64) steamID.ConvertToUint64();
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_getTicketSteamID(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint bufferOffset, jint bufferSize) {
	char* ticketDecrypted = (char*)(obj_ticketDecrypted?env->GetDirectBufferAddress(obj_ticketDecrypted):0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_getTicketSteamID(env, clazz, obj_ticketDecrypted, bufferOffset, bufferSize, ticketDecrypted);


	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_getTicketAppID
(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint bufferOffset, jint bufferSize, char* ticketDecrypted) {

//@line:49


		return SteamEncryptedAppTicket_GetTicketAppID(
			(uint8*) &ticketDecrypted[bufferOffset], bufferSize);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_getTicketAppID(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint bufferOffset, jint bufferSize) {
	char* ticketDecrypted = (char*)(obj_ticketDecrypted?env->GetDirectBufferAddress(obj_ticketDecrypted):0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_getTicketAppID(env, clazz, obj_ticketDecrypted, bufferOffset, bufferSize, ticketDecrypted);


	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_userOwnsAppInTicket
(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint bufferOffset, jint bufferSize, jint appID, char* ticketDecrypted) {

//@line:56

		return SteamEncryptedAppTicket_BUserOwnsAppInTicket(
			(uint8*) &ticketDecrypted[bufferOffset], bufferSize, (AppId_t) appID);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_userOwnsAppInTicket(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint bufferOffset, jint bufferSize, jint appID) {
	char* ticketDecrypted = (char*)(obj_ticketDecrypted?env->GetDirectBufferAddress(obj_ticketDecrypted):0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_userOwnsAppInTicket(env, clazz, obj_ticketDecrypted, bufferOffset, bufferSize, appID, ticketDecrypted);


	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_userIsVacBanned
(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint bufferOffset, jint bufferSize, char* ticketDecrypted) {

//@line:62


		return SteamEncryptedAppTicket_BUserIsVacBanned(
			(uint8*) &ticketDecrypted[bufferOffset], bufferSize);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_userIsVacBanned(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint bufferOffset, jint bufferSize) {
	char* ticketDecrypted = (char*)(obj_ticketDecrypted?env->GetDirectBufferAddress(obj_ticketDecrypted):0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_userIsVacBanned(env, clazz, obj_ticketDecrypted, bufferOffset, bufferSize, ticketDecrypted);


	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_getUserVariableData
(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint decryptedOffset, jint decryptedSize, jobject obj_userData, jint userDataOffset, jint userDataSize, char* ticketDecrypted, char* userData) {

//@line:69


		uint32 size = 0;

		const uint8* data = SteamEncryptedAppTicket_GetUserVariableData(
			(uint8*) &ticketDecrypted[decryptedOffset], decryptedSize, &size);

		if (size > 0) {
			uint32 capacity = (uint32) userDataSize;
			memcpy(&userData[userDataOffset], data, size < capacity ? size : capacity);
		}

		return size;
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_getUserVariableData(JNIEnv* env, jclass clazz, jobject obj_ticketDecrypted, jint decryptedOffset, jint decryptedSize, jobject obj_userData, jint userDataOffset, jint userDataSize) {
	char* ticketDecrypted = (char*)(obj_ticketDecrypted?env->GetDirectBufferAddress(obj_ticketDecrypted):0);
	char* userData = (char*)(obj_userData?env->GetDirectBufferAddress(obj_userData):0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamEncryptedAppTicketNative_getUserVariableData(env, clazz, obj_ticketDecrypted, decryptedOffset, decryptedSize, obj_userData, userDataOffset, userDataSize, ticketDecrypted, userData);


	return JNI_returnValue;
}

