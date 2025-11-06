#include <org_twopology_steamnetworks4j_SteamGameServerNative.h>

//@line:9

		#include "SteamGameServerCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:13

		return (intp) new SteamGameServerCallback(env, javaCallback);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setProduct(JNIEnv* env, jclass clazz, jstring obj_product) {
	char* product = (char*)env->GetStringUTFChars(obj_product, 0);


//@line:17

		SteamGameServer()->SetProduct(product);
	
	env->ReleaseStringUTFChars(obj_product, product);

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setGameDescription(JNIEnv* env, jclass clazz, jstring obj_gameDescription) {
	char* gameDescription = (char*)env->GetStringUTFChars(obj_gameDescription, 0);


//@line:21

		SteamGameServer()->SetGameDescription(gameDescription);
	
	env->ReleaseStringUTFChars(obj_gameDescription, gameDescription);

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setModDir(JNIEnv* env, jclass clazz, jstring obj_modDir) {
	char* modDir = (char*)env->GetStringUTFChars(obj_modDir, 0);


//@line:25

		SteamGameServer()->SetModDir(modDir);
	
	env->ReleaseStringUTFChars(obj_modDir, modDir);

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setDedicatedServer(JNIEnv* env, jclass clazz, jboolean dedicated) {


//@line:29

		SteamGameServer()->SetDedicatedServer(dedicated);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_logOn(JNIEnv* env, jclass clazz, jstring obj_token) {
	char* token = (char*)env->GetStringUTFChars(obj_token, 0);


//@line:33

		SteamGameServer()->LogOn(token);
	
	env->ReleaseStringUTFChars(obj_token, token);

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_logOnAnonymous(JNIEnv* env, jclass clazz) {


//@line:37

		SteamGameServer()->LogOnAnonymous();
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_logOff(JNIEnv* env, jclass clazz) {


//@line:41

		SteamGameServer()->LogOff();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_isLoggedOn(JNIEnv* env, jclass clazz) {


//@line:45

		return SteamGameServer()->BLoggedOn();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_isSecure(JNIEnv* env, jclass clazz) {


//@line:49

		return SteamGameServer()->BSecure();
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_getSteamID(JNIEnv* env, jclass clazz) {


//@line:53

		return SteamGameServer()->GetSteamID().ConvertToUint64();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_wasRestartRequested(JNIEnv* env, jclass clazz) {


//@line:57

		return SteamGameServer()->WasRestartRequested();
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setMaxPlayerCount(JNIEnv* env, jclass clazz, jint playersMax) {


//@line:61

		SteamGameServer()->SetMaxPlayerCount(playersMax);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setBotPlayerCount(JNIEnv* env, jclass clazz, jint botplayers) {


//@line:65

		SteamGameServer()->SetBotPlayerCount(botplayers);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setServerName(JNIEnv* env, jclass clazz, jstring obj_serverName) {
	char* serverName = (char*)env->GetStringUTFChars(obj_serverName, 0);


//@line:69

		SteamGameServer()->SetServerName(serverName);
	
	env->ReleaseStringUTFChars(obj_serverName, serverName);

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setMapName(JNIEnv* env, jclass clazz, jstring obj_mapName) {
	char* mapName = (char*)env->GetStringUTFChars(obj_mapName, 0);


//@line:73

		SteamGameServer()->SetMapName(mapName);
	
	env->ReleaseStringUTFChars(obj_mapName, mapName);

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setPasswordProtected(JNIEnv* env, jclass clazz, jboolean passwordProtected) {


//@line:77

		SteamGameServer()->SetPasswordProtected(passwordProtected);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setSpectatorPort(JNIEnv* env, jclass clazz, jshort spectatorPort) {


//@line:81

		SteamGameServer()->SetSpectatorPort(spectatorPort);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setSpectatorServerName(JNIEnv* env, jclass clazz, jstring obj_spectatorServerName) {
	char* spectatorServerName = (char*)env->GetStringUTFChars(obj_spectatorServerName, 0);


//@line:85

		SteamGameServer()->SetSpectatorServerName(spectatorServerName);
	
	env->ReleaseStringUTFChars(obj_spectatorServerName, spectatorServerName);

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_clearAllKeyValues(JNIEnv* env, jclass clazz) {


//@line:89

		SteamGameServer()->ClearAllKeyValues();
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setKeyValue(JNIEnv* env, jclass clazz, jstring obj_key, jstring obj_value) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);
	char* value = (char*)env->GetStringUTFChars(obj_value, 0);


//@line:93

		SteamGameServer()->SetKeyValue(key, value);
	
	env->ReleaseStringUTFChars(obj_key, key);
	env->ReleaseStringUTFChars(obj_value, value);

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setGameTags(JNIEnv* env, jclass clazz, jstring obj_gameTags) {
	char* gameTags = (char*)env->GetStringUTFChars(obj_gameTags, 0);


//@line:97

		SteamGameServer()->SetGameTags(gameTags);
	
	env->ReleaseStringUTFChars(obj_gameTags, gameTags);

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setGameData(JNIEnv* env, jclass clazz, jstring obj_gameData) {
	char* gameData = (char*)env->GetStringUTFChars(obj_gameData, 0);


//@line:101

		SteamGameServer()->SetGameData(gameData);
	
	env->ReleaseStringUTFChars(obj_gameData, gameData);

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_setRegion(JNIEnv* env, jclass clazz, jstring obj_region) {
	char* region = (char*)env->GetStringUTFChars(obj_region, 0);


//@line:105

		SteamGameServer()->SetRegion(region);
	
	env->ReleaseStringUTFChars(obj_region, region);

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerNative_sendUserConnectAndAuthenticate
(JNIEnv* env, jclass clazz, jint clientIP, jobject obj_authBlob, jint offset, jint size, jlongArray obj_steamIDUser, char* authBlob, long long* steamIDUser) {

//@line:110

		CSteamID user;
		if (SteamGameServer()->SendUserConnectAndAuthenticate_DEPRECATED(clientIP, &authBlob[offset], size, &user)) {
			steamIDUser[0] = user.ConvertToUint64();
			return true;
		}
		return false;
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_sendUserConnectAndAuthenticate(JNIEnv* env, jclass clazz, jint clientIP, jobject obj_authBlob, jint offset, jint size, jlongArray obj_steamIDUser) {
	char* authBlob = (char*)(obj_authBlob?env->GetDirectBufferAddress(obj_authBlob):0);
	long long* steamIDUser = (long long*)env->GetPrimitiveArrayCritical(obj_steamIDUser, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerNative_sendUserConnectAndAuthenticate(env, clazz, clientIP, obj_authBlob, offset, size, obj_steamIDUser, authBlob, steamIDUser);

	env->ReleasePrimitiveArrayCritical(obj_steamIDUser, steamIDUser, 0);

	return JNI_returnValue;
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_createUnauthenticatedUserConnection(JNIEnv* env, jclass clazz) {


//@line:119

		return SteamGameServer()->CreateUnauthenticatedUserConnection().ConvertToUint64();
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_sendUserDisconnect(JNIEnv* env, jclass clazz, jlong steamIDUser) {


//@line:123

		SteamGameServer()->SendUserDisconnect_DEPRECATED((uint64) steamIDUser);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerNative_updateUserData
(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_playerName, jint score, char* playerName) {

//@line:127

		return SteamGameServer()->BUpdateUserData((uint64) steamIDUser, playerName, score);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_updateUserData(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_playerName, jint score) {
	char* playerName = (char*)env->GetStringUTFChars(obj_playerName, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerNative_updateUserData(env, clazz, steamIDUser, obj_playerName, score, playerName);

	env->ReleaseStringUTFChars(obj_playerName, playerName);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerNative_getAuthSessionTicket
(JNIEnv* env, jclass clazz, jobject obj_authTicket, jint offset, jint size, jintArray obj_sizeInBytes, char* authTicket, int* sizeInBytes) {

//@line:132

		int ticket = SteamGameServer()->GetAuthSessionTicket(&authTicket[offset], size, (uint32*) sizeInBytes, nullptr);
		return ticket;
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_getAuthSessionTicket(JNIEnv* env, jclass clazz, jobject obj_authTicket, jint offset, jint size, jintArray obj_sizeInBytes) {
	char* authTicket = (char*)(obj_authTicket?env->GetDirectBufferAddress(obj_authTicket):0);
	int* sizeInBytes = (int*)env->GetPrimitiveArrayCritical(obj_sizeInBytes, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerNative_getAuthSessionTicket(env, clazz, obj_authTicket, offset, size, obj_sizeInBytes, authTicket, sizeInBytes);

	env->ReleasePrimitiveArrayCritical(obj_sizeInBytes, sizeInBytes, 0);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerNative_beginAuthSession
(JNIEnv* env, jclass clazz, jobject obj_authTicket, jint offset, jint size, jlong steamID, char* authTicket) {

//@line:138

		return SteamGameServer()->BeginAuthSession(&authTicket[offset], size, (uint64) steamID);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_beginAuthSession(JNIEnv* env, jclass clazz, jobject obj_authTicket, jint offset, jint size, jlong steamID) {
	char* authTicket = (char*)(obj_authTicket?env->GetDirectBufferAddress(obj_authTicket):0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerNative_beginAuthSession(env, clazz, obj_authTicket, offset, size, steamID, authTicket);


	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_endAuthSession(JNIEnv* env, jclass clazz, jlong steamID) {


//@line:142

		SteamGameServer()->EndAuthSession((uint64) steamID);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_cancelAuthTicket(JNIEnv* env, jclass clazz, jint authTicket) {


//@line:146

		SteamGameServer()->CancelAuthTicket(authTicket);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_userHasLicenseForApp(JNIEnv* env, jclass clazz, jlong steamID, jint appID) {


//@line:150

		return SteamGameServer()->UserHasLicenseForApp((uint64) steamID, (AppId_t) appID);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_requestUserGroupStatus(JNIEnv* env, jclass clazz, jlong steamIDUser, jlong steamIDGroup) {


//@line:154

		return SteamGameServer()->RequestUserGroupStatus((uint64) steamIDUser, (uint64) steamIDGroup);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_getPublicIP(JNIEnv* env, jclass clazz) {


//@line:158

		return (jint) SteamGameServer()->GetPublicIP().m_unIPv4;
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerNative_handleIncomingPacket
(JNIEnv* env, jclass clazz, jobject obj_data, jint offset, jint size, jint srcIP, jshort srcPort, char* data) {

//@line:163

		return SteamGameServer()->HandleIncomingPacket(&data[offset], size, srcIP, srcPort);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_handleIncomingPacket(JNIEnv* env, jclass clazz, jobject obj_data, jint offset, jint size, jint srcIP, jshort srcPort) {
	char* data = (char*)(obj_data?env->GetDirectBufferAddress(obj_data):0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerNative_handleIncomingPacket(env, clazz, obj_data, offset, size, srcIP, srcPort, data);


	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerNative_getNextOutgoingPacket
(JNIEnv* env, jclass clazz, jobject obj_out, jint offset, jint size, jintArray obj_netAdr, jshortArray obj_port, char* out, int* netAdr, short* port) {

//@line:168

		return SteamGameServer()->GetNextOutgoingPacket(&out[offset], size, (uint32*) netAdr, (uint16*) port);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_getNextOutgoingPacket(JNIEnv* env, jclass clazz, jobject obj_out, jint offset, jint size, jintArray obj_netAdr, jshortArray obj_port) {
	char* out = (char*)(obj_out?env->GetDirectBufferAddress(obj_out):0);
	int* netAdr = (int*)env->GetPrimitiveArrayCritical(obj_netAdr, 0);
	short* port = (short*)env->GetPrimitiveArrayCritical(obj_port, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerNative_getNextOutgoingPacket(env, clazz, obj_out, offset, size, obj_netAdr, obj_port, out, netAdr, port);

	env->ReleasePrimitiveArrayCritical(obj_netAdr, netAdr, 0);
	env->ReleasePrimitiveArrayCritical(obj_port, port, 0);

	return JNI_returnValue;
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_associateWithClan(JNIEnv* env, jclass clazz, jlong steamIDClan) {


//@line:172

		return SteamGameServer()->AssociateWithClan((uint64) steamIDClan);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerNative_computeNewPlayerCompatibility(JNIEnv* env, jclass clazz, jlong steamIDNewPlayer) {


//@line:176

		return SteamGameServer()->ComputeNewPlayerCompatibility((uint64) steamIDNewPlayer);
	

}

