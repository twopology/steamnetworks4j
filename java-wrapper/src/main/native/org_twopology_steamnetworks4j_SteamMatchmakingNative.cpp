#include <org_twopology_steamnetworks4j_SteamMatchmakingNative.h>

//@line:9

		#include "SteamMatchmakingCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:13

		return (intp) new SteamMatchmakingCallback(env, javaCallback);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getFavoriteGameCount(JNIEnv* env, jclass clazz) {


//@line:17

		return SteamMatchmaking()->GetFavoriteGameCount();
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getFavoriteGame
(JNIEnv* env, jclass clazz, jint game, jintArray obj_appID, jintArray obj_ip, jshortArray obj_connPort, jshortArray obj_queryPort, jintArray obj_flags, jintArray obj_lastPlayedOnServer, int* appID, int* ip, short* connPort, short* queryPort, int* flags, int* lastPlayedOnServer) {

//@line:22

		return SteamMatchmaking()->GetFavoriteGame(game, (AppId_t*) appID, (uint32*) ip, (uint16*) connPort,
			(uint16*) queryPort, (uint32*) flags, (uint32*) lastPlayedOnServer);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getFavoriteGame(JNIEnv* env, jclass clazz, jint game, jintArray obj_appID, jintArray obj_ip, jshortArray obj_connPort, jshortArray obj_queryPort, jintArray obj_flags, jintArray obj_lastPlayedOnServer) {
	int* appID = (int*)env->GetPrimitiveArrayCritical(obj_appID, 0);
	int* ip = (int*)env->GetPrimitiveArrayCritical(obj_ip, 0);
	short* connPort = (short*)env->GetPrimitiveArrayCritical(obj_connPort, 0);
	short* queryPort = (short*)env->GetPrimitiveArrayCritical(obj_queryPort, 0);
	int* flags = (int*)env->GetPrimitiveArrayCritical(obj_flags, 0);
	int* lastPlayedOnServer = (int*)env->GetPrimitiveArrayCritical(obj_lastPlayedOnServer, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getFavoriteGame(env, clazz, game, obj_appID, obj_ip, obj_connPort, obj_queryPort, obj_flags, obj_lastPlayedOnServer, appID, ip, connPort, queryPort, flags, lastPlayedOnServer);

	env->ReleasePrimitiveArrayCritical(obj_appID, appID, 0);
	env->ReleasePrimitiveArrayCritical(obj_ip, ip, 0);
	env->ReleasePrimitiveArrayCritical(obj_connPort, connPort, 0);
	env->ReleasePrimitiveArrayCritical(obj_queryPort, queryPort, 0);
	env->ReleasePrimitiveArrayCritical(obj_flags, flags, 0);
	env->ReleasePrimitiveArrayCritical(obj_lastPlayedOnServer, lastPlayedOnServer, 0);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_addFavoriteGame(JNIEnv* env, jclass clazz, jint appID, jint ip, jshort connPort, jshort queryPort, jint flags, jint lastPlayedOnServer) {


//@line:28

		return SteamMatchmaking()->AddFavoriteGame((AppId_t) appID, ip, connPort, queryPort, flags, lastPlayedOnServer);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_removeFavoriteGame(JNIEnv* env, jclass clazz, jint appID, jint ip, jshort connPort, jshort queryPort, jint flags) {


//@line:33

		return SteamMatchmaking()->RemoveFavoriteGame((AppId_t) appID, ip, connPort, queryPort, flags);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_requestLobbyList(JNIEnv* env, jclass clazz, jlong callback) {


//@line:37

		SteamAPICall_t handle = SteamMatchmaking()->RequestLobbyList();
		SteamMatchmakingCallback* cb = (SteamMatchmakingCallback*) callback;
		cb->onLobbyMatchListCall.Set(handle, cb, &SteamMatchmakingCallback::onLobbyMatchList);
		return handle;
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_addRequestLobbyListStringFilter(JNIEnv* env, jclass clazz, jstring obj_keyToMatch, jstring obj_valueToMatch, jint comparisonType) {
	char* keyToMatch = (char*)env->GetStringUTFChars(obj_keyToMatch, 0);
	char* valueToMatch = (char*)env->GetStringUTFChars(obj_valueToMatch, 0);


//@line:45

		SteamMatchmaking()->AddRequestLobbyListStringFilter(keyToMatch, valueToMatch, (ELobbyComparison) comparisonType);
	
	env->ReleaseStringUTFChars(obj_keyToMatch, keyToMatch);
	env->ReleaseStringUTFChars(obj_valueToMatch, valueToMatch);

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_addRequestLobbyListNumericalFilter(JNIEnv* env, jclass clazz, jstring obj_keyToMatch, jint valueToMatch, jint comparisonType) {
	char* keyToMatch = (char*)env->GetStringUTFChars(obj_keyToMatch, 0);


//@line:50

		SteamMatchmaking()->AddRequestLobbyListNumericalFilter(keyToMatch, valueToMatch, (ELobbyComparison) comparisonType);
	
	env->ReleaseStringUTFChars(obj_keyToMatch, keyToMatch);

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_addRequestLobbyListNearValueFilter(JNIEnv* env, jclass clazz, jstring obj_keyToMatch, jint valueToBeCloseTo) {
	char* keyToMatch = (char*)env->GetStringUTFChars(obj_keyToMatch, 0);


//@line:55

		SteamMatchmaking()->AddRequestLobbyListNearValueFilter(keyToMatch, valueToBeCloseTo);
	
	env->ReleaseStringUTFChars(obj_keyToMatch, keyToMatch);

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_addRequestLobbyListFilterSlotsAvailable(JNIEnv* env, jclass clazz, jint slotsAvailable) {


//@line:59

		SteamMatchmaking()->AddRequestLobbyListFilterSlotsAvailable(slotsAvailable);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_addRequestLobbyListDistanceFilter(JNIEnv* env, jclass clazz, jint lobbyDistanceFilter) {


//@line:63

		SteamMatchmaking()->AddRequestLobbyListDistanceFilter((ELobbyDistanceFilter) lobbyDistanceFilter);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_addRequestLobbyListResultCountFilter(JNIEnv* env, jclass clazz, jint maxResults) {


//@line:67

		SteamMatchmaking()->AddRequestLobbyListResultCountFilter(maxResults);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_addRequestLobbyListCompatibleMembersFilter(JNIEnv* env, jclass clazz, jlong steamIDLobby) {


//@line:71

		SteamMatchmaking()->AddRequestLobbyListCompatibleMembersFilter((uint64) steamIDLobby);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyByIndex(JNIEnv* env, jclass clazz, jint lobby) {


//@line:75

		CSteamID steamID = SteamMatchmaking()->GetLobbyByIndex(lobby);
		return (int64) steamID.ConvertToUint64();
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_createLobby(JNIEnv* env, jclass clazz, jlong callback, jint lobbyType, jint maxMembers) {


//@line:80

		SteamAPICall_t handle = SteamMatchmaking()->CreateLobby((ELobbyType) lobbyType, maxMembers);
		SteamMatchmakingCallback* cb = (SteamMatchmakingCallback*) callback;
		cb->onLobbyCreatedCall.Set(handle, cb, &SteamMatchmakingCallback::onLobbyCreated);
		return handle;
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_joinLobby(JNIEnv* env, jclass clazz, jlong callback, jlong steamIDLobby) {


//@line:87

		SteamAPICall_t handle = SteamMatchmaking()->JoinLobby((uint64) steamIDLobby);
		SteamMatchmakingCallback* cb = (SteamMatchmakingCallback*) callback;
		cb->onLobbyEnterCall.Set(handle, cb, &SteamMatchmakingCallback::onLobbyEnter);
		return handle;
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_leaveLobby(JNIEnv* env, jclass clazz, jlong steamIDLobby) {


//@line:94

		SteamMatchmaking()->LeaveLobby((uint64) steamIDLobby);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_inviteUserToLobby(JNIEnv* env, jclass clazz, jlong steamIDLobby, jlong steamIDInvitee) {


//@line:98

		return SteamMatchmaking()->InviteUserToLobby((uint64) steamIDLobby, (uint64) steamIDInvitee);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getNumLobbyMembers(JNIEnv* env, jclass clazz, jlong steamIDLobby) {


//@line:102

		return SteamMatchmaking()->GetNumLobbyMembers((uint64) steamIDLobby);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyMemberByIndex(JNIEnv* env, jclass clazz, jlong steamIDLobby, jint memberIndex) {


//@line:106

		CSteamID steamID = SteamMatchmaking()->GetLobbyMemberByIndex((uint64) steamIDLobby, memberIndex);
		return (int64) steamID.ConvertToUint64();
	

}

static inline jstring wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyData
(JNIEnv* env, jclass clazz, jlong steamIDLobby, jstring obj_key, char* key) {

//@line:111

		jstring value = env->NewStringUTF(SteamMatchmaking()->GetLobbyData((uint64) steamIDLobby, key));
		return value;
	
}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyData(JNIEnv* env, jclass clazz, jlong steamIDLobby, jstring obj_key) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);

	jstring JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyData(env, clazz, steamIDLobby, obj_key, key);

	env->ReleaseStringUTFChars(obj_key, key);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_setLobbyData
(JNIEnv* env, jclass clazz, jlong steamIDLobby, jstring obj_key, jstring obj_value, char* key, char* value) {

//@line:116

		return SteamMatchmaking()->SetLobbyData((uint64) steamIDLobby, key, value);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_setLobbyData(JNIEnv* env, jclass clazz, jlong steamIDLobby, jstring obj_key, jstring obj_value) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);
	char* value = (char*)env->GetStringUTFChars(obj_value, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_setLobbyData(env, clazz, steamIDLobby, obj_key, obj_value, key, value);

	env->ReleaseStringUTFChars(obj_key, key);
	env->ReleaseStringUTFChars(obj_value, value);

	return JNI_returnValue;
}

static inline jstring wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyMemberData
(JNIEnv* env, jclass clazz, jlong steamIDLobby, jlong steamIDUser, jstring obj_key, char* key) {

//@line:120

		jstring value = env->NewStringUTF(SteamMatchmaking()->GetLobbyMemberData((uint64) steamIDLobby, (uint64) steamIDUser, key));
		return value;
	
}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyMemberData(JNIEnv* env, jclass clazz, jlong steamIDLobby, jlong steamIDUser, jstring obj_key) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);

	jstring JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyMemberData(env, clazz, steamIDLobby, steamIDUser, obj_key, key);

	env->ReleaseStringUTFChars(obj_key, key);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_setLobbyMemberData(JNIEnv* env, jclass clazz, jlong steamIDLobby, jstring obj_key, jstring obj_value) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);
	char* value = (char*)env->GetStringUTFChars(obj_value, 0);


//@line:125

		SteamMatchmaking()->SetLobbyMemberData((uint64) steamIDLobby, key, value);
	
	env->ReleaseStringUTFChars(obj_key, key);
	env->ReleaseStringUTFChars(obj_value, value);

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyDataCount(JNIEnv* env, jclass clazz, jlong steamIDLobby) {


//@line:129

		return SteamMatchmaking()->GetLobbyDataCount((uint64) steamIDLobby);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyDataByIndex(JNIEnv* env, jclass clazz, jlong steamIDLobby, jint lobbyDataIndex, jobject keyValuePair) {


//@line:134

		MatchMakingKeyValuePair_t result;
		bool success = SteamMatchmaking()->GetLobbyDataByIndex((uint64) steamIDLobby, lobbyDataIndex,
			result.m_szKey, 256, result.m_szValue, 256);
		if (success) {
			jclass clazz = env->GetObjectClass(keyValuePair);

			jstring key = env->NewStringUTF(result.m_szKey);
			jfieldID field = env->GetFieldID(clazz, "key", "Ljava/lang/String;");
			env->SetObjectField(keyValuePair, field, key);

			jstring value = env->NewStringUTF(result.m_szValue);
			field = env->GetFieldID(clazz, "value", "Ljava/lang/String;");
			env->SetObjectField(keyValuePair, field, value);
		}
		return success;
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_deleteLobbyData
(JNIEnv* env, jclass clazz, jlong steamIDLobby, jstring obj_key, char* key) {

//@line:152

		return SteamMatchmaking()->DeleteLobbyData((uint64) steamIDLobby, key);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_deleteLobbyData(JNIEnv* env, jclass clazz, jlong steamIDLobby, jstring obj_key) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_deleteLobbyData(env, clazz, steamIDLobby, obj_key, key);

	env->ReleaseStringUTFChars(obj_key, key);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_sendLobbyChatMsg__JLjava_nio_ByteBuffer_2II
(JNIEnv* env, jclass clazz, jlong steamIDLobby, jobject obj_data, jint offset, jint size, char* data) {

//@line:157

		return SteamMatchmaking()->SendLobbyChatMsg((uint64) steamIDLobby, &data[offset], size);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_sendLobbyChatMsg__JLjava_nio_ByteBuffer_2II(JNIEnv* env, jclass clazz, jlong steamIDLobby, jobject obj_data, jint offset, jint size) {
	char* data = (char*)(obj_data?env->GetDirectBufferAddress(obj_data):0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_sendLobbyChatMsg__JLjava_nio_ByteBuffer_2II(env, clazz, steamIDLobby, obj_data, offset, size, data);


	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_sendLobbyChatMsg__JLjava_lang_String_2
(JNIEnv* env, jclass clazz, jlong steamIDLobby, jstring obj_message, char* message) {

//@line:161

		int len = (int) strlen(message) + 1;
		return SteamMatchmaking()->SendLobbyChatMsg((uint64) steamIDLobby, message, len);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_sendLobbyChatMsg__JLjava_lang_String_2(JNIEnv* env, jclass clazz, jlong steamIDLobby, jstring obj_message) {
	char* message = (char*)env->GetStringUTFChars(obj_message, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_sendLobbyChatMsg__JLjava_lang_String_2(env, clazz, steamIDLobby, obj_message, message);

	env->ReleaseStringUTFChars(obj_message, message);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyChatEntry
(JNIEnv* env, jclass clazz, jlong steamIDLobby, jint chatID, jobject chatEntry, jobject obj_buffer, jint offset, jint size, char* buffer) {

//@line:167

		CSteamID steamIDUser;
		EChatEntryType chatEntryType;
		int received = SteamMatchmaking()->GetLobbyChatEntry((uint64) steamIDLobby, chatID, &steamIDUser, &buffer[offset], size, &chatEntryType);

		if (received >= 0) {
			jclass clazz = env->GetObjectClass(chatEntry);

			jfieldID field = env->GetFieldID(clazz, "steamIDUser", "J");
			env->SetLongField(chatEntry, field, (jlong) steamIDUser.ConvertToUint64());

			field = env->GetFieldID(clazz, "chatEntryType", "I");
			env->SetIntField(chatEntry, field, (jint) chatEntryType);
		}

		return received;
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyChatEntry(JNIEnv* env, jclass clazz, jlong steamIDLobby, jint chatID, jobject chatEntry, jobject obj_buffer, jint offset, jint size) {
	char* buffer = (char*)(obj_buffer?env->GetDirectBufferAddress(obj_buffer):0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyChatEntry(env, clazz, steamIDLobby, chatID, chatEntry, obj_buffer, offset, size, buffer);


	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_requestLobbyData(JNIEnv* env, jclass clazz, jlong steamIDLobby) {


//@line:185

		return SteamMatchmaking()->RequestLobbyData((uint64) steamIDLobby);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_setLobbyGameServer(JNIEnv* env, jclass clazz, jlong steamIDLobby, jint gameServerIP, jshort gameServerPort, jlong steamIDGameServer) {


//@line:190

		SteamMatchmaking()->SetLobbyGameServer((uint64) steamIDLobby, gameServerIP, gameServerPort, (uint64) steamIDGameServer);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyGameServer
(JNIEnv* env, jclass clazz, jlong steamIDLobby, jintArray obj_gameServerIP, jshortArray obj_gameServerPort, jlongArray obj_steamIDGameServer, int* gameServerIP, short* gameServerPort, long long* steamIDGameServer) {

//@line:195

		CSteamID _steamIDGameServer;
		if (SteamMatchmaking()->GetLobbyGameServer((uint64) steamIDLobby, (uint32*) gameServerIP,
			(uint16*) gameServerPort, &_steamIDGameServer)) {
			*steamIDGameServer = (jlong) _steamIDGameServer.ConvertToUint64();
			return true;
		}
		return false;
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyGameServer(JNIEnv* env, jclass clazz, jlong steamIDLobby, jintArray obj_gameServerIP, jshortArray obj_gameServerPort, jlongArray obj_steamIDGameServer) {
	int* gameServerIP = (int*)env->GetPrimitiveArrayCritical(obj_gameServerIP, 0);
	short* gameServerPort = (short*)env->GetPrimitiveArrayCritical(obj_gameServerPort, 0);
	long long* steamIDGameServer = (long long*)env->GetPrimitiveArrayCritical(obj_steamIDGameServer, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyGameServer(env, clazz, steamIDLobby, obj_gameServerIP, obj_gameServerPort, obj_steamIDGameServer, gameServerIP, gameServerPort, steamIDGameServer);

	env->ReleasePrimitiveArrayCritical(obj_gameServerIP, gameServerIP, 0);
	env->ReleasePrimitiveArrayCritical(obj_gameServerPort, gameServerPort, 0);
	env->ReleasePrimitiveArrayCritical(obj_steamIDGameServer, steamIDGameServer, 0);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_setLobbyMemberLimit(JNIEnv* env, jclass clazz, jlong steamIDLobby, jint maxMembers) {


//@line:205

		return SteamMatchmaking()->SetLobbyMemberLimit((uint64) steamIDLobby, maxMembers);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyMemberLimit(JNIEnv* env, jclass clazz, jlong steamIDLobby) {


//@line:209

		return SteamMatchmaking()->GetLobbyMemberLimit((uint64) steamIDLobby);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_setLobbyType(JNIEnv* env, jclass clazz, jlong steamIDLobby, jint lobbyType) {


//@line:213

		return SteamMatchmaking()->SetLobbyType((uint64) steamIDLobby, (ELobbyType) lobbyType);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_setLobbyJoinable(JNIEnv* env, jclass clazz, jlong steamIDLobby, jboolean joinable) {


//@line:217

		return SteamMatchmaking()->SetLobbyJoinable((uint64) steamIDLobby, joinable);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_getLobbyOwner(JNIEnv* env, jclass clazz, jlong steamIDLobby) {


//@line:221

		return (int64) SteamMatchmaking()->GetLobbyOwner((uint64) steamIDLobby).ConvertToUint64();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_setLobbyOwner(JNIEnv* env, jclass clazz, jlong steamIDLobby, jlong steamIDNewOwner) {


//@line:225

		return SteamMatchmaking()->SetLobbyOwner((uint64) steamIDLobby, (uint64) steamIDNewOwner);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingNative_setLinkedLobby(JNIEnv* env, jclass clazz, jlong steamIDLobby, jlong steamIDLobbyDependent) {


//@line:229

		return SteamMatchmaking()->SetLinkedLobby((uint64) steamIDLobby, (uint64) steamIDLobbyDependent);
	

}

