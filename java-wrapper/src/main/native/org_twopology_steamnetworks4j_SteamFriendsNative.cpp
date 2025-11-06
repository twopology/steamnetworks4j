#include <org_twopology_steamnetworks4j_SteamFriendsNative.h>

//@line:7

		#include <steam_api.h>
		#include "SteamFriendsCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:12

		return (intp) new SteamFriendsCallback(env, javaCallback);
	

}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getPersonaName(JNIEnv* env, jclass clazz) {


//@line:16

		jstring name = env->NewStringUTF(SteamFriends()->GetPersonaName());
		return name;
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getPersonaState(JNIEnv* env, jclass clazz) {


//@line:24

		return SteamFriends()->GetPersonaState();
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getFriendCount(JNIEnv* env, jclass clazz, jint friendFlags) {


//@line:28

		return SteamFriends()->GetFriendCount(friendFlags);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getFriendByIndex(JNIEnv* env, jclass clazz, jint friendIndex, jint friendFlags) {


//@line:32

		CSteamID id = SteamFriends()->GetFriendByIndex(friendIndex, friendFlags);
		return id.ConvertToUint64();
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getFriendRelationship(JNIEnv* env, jclass clazz, jlong steamIDFriend) {


//@line:37

		return SteamFriends()->GetFriendRelationship((uint64) steamIDFriend);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getFriendPersonaState(JNIEnv* env, jclass clazz, jlong steamIDFriend) {


//@line:41

		return SteamFriends()->GetFriendPersonaState((uint64) steamIDFriend);
	

}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getFriendPersonaName(JNIEnv* env, jclass clazz, jlong steamIDFriend) {


//@line:45

		jstring name = env->NewStringUTF(SteamFriends()->GetFriendPersonaName((uint64) steamIDFriend));
		return name;
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getFriendGamePlayed(JNIEnv* env, jclass clazz, jlong steamIDFriend, jobject friendGameInfo) {


//@line:51


		FriendGameInfo_t result;
		bool success = SteamFriends()->GetFriendGamePlayed((uint64) steamIDFriend, &result);
		if (success) {
			jclass clazz = env->GetObjectClass(friendGameInfo);

			jfieldID field = env->GetFieldID(clazz, "gameID", "J");
			env->SetLongField(friendGameInfo, field, (jlong) result.m_gameID.ToUint64());

			field = env->GetFieldID(clazz, "gameIP", "I");
			env->SetIntField(friendGameInfo, field, (jint) result.m_unGameIP);

			field = env->GetFieldID(clazz, "gamePort", "S");
			env->SetShortField(friendGameInfo, field, (jshort) result.m_usGamePort);

			field = env->GetFieldID(clazz, "queryPort", "S");
			env->SetShortField(friendGameInfo, field, (jshort) result.m_usQueryPort);

			field = env->GetFieldID(clazz, "steamIDLobby", "J");
			env->SetLongField(friendGameInfo, field, (jlong) result.m_steamIDLobby.ConvertToUint64());
		}
		return success;
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_setInGameVoiceSpeaking(JNIEnv* env, jclass clazz, jlong steamID, jboolean speaking) {


//@line:76

		return SteamFriends()->SetInGameVoiceSpeaking((uint64) steamID, speaking);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getSmallFriendAvatar(JNIEnv* env, jclass clazz, jlong steamID) {


//@line:80

		return SteamFriends()->GetSmallFriendAvatar((uint64) steamID);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getMediumFriendAvatar(JNIEnv* env, jclass clazz, jlong steamID) {


//@line:84

		return SteamFriends()->GetMediumFriendAvatar((uint64) steamID);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getLargeFriendAvatar(JNIEnv* env, jclass clazz, jlong steamID) {


//@line:88

		return SteamFriends()->GetLargeFriendAvatar((uint64) steamID);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_requestUserInformation(JNIEnv* env, jclass clazz, jlong steamID, jboolean requireNameOnly) {


//@line:92

		return SteamFriends()->RequestUserInformation((uint64) steamID, requireNameOnly);
	

}

static inline void wrapped_Java_org_twopology_steamnetworks4j_SteamFriendsNative_activateGameOverlay
(JNIEnv* env, jclass clazz, jstring obj_dialog, char* dialog) {

//@line:96

		return SteamFriends()->ActivateGameOverlay(dialog);
	
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_activateGameOverlay(JNIEnv* env, jclass clazz, jstring obj_dialog) {
	char* dialog = (char*)env->GetStringUTFChars(obj_dialog, 0);

	wrapped_Java_org_twopology_steamnetworks4j_SteamFriendsNative_activateGameOverlay(env, clazz, obj_dialog, dialog);

	env->ReleaseStringUTFChars(obj_dialog, dialog);

	return;
}

static inline void wrapped_Java_org_twopology_steamnetworks4j_SteamFriendsNative_activateGameOverlayToUser
(JNIEnv* env, jclass clazz, jstring obj_dialog, jlong steamID, char* dialog) {

//@line:100

		return SteamFriends()->ActivateGameOverlayToUser(dialog, (uint64) steamID);
	
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_activateGameOverlayToUser(JNIEnv* env, jclass clazz, jstring obj_dialog, jlong steamID) {
	char* dialog = (char*)env->GetStringUTFChars(obj_dialog, 0);

	wrapped_Java_org_twopology_steamnetworks4j_SteamFriendsNative_activateGameOverlayToUser(env, clazz, obj_dialog, steamID, dialog);

	env->ReleaseStringUTFChars(obj_dialog, dialog);

	return;
}

static inline void wrapped_Java_org_twopology_steamnetworks4j_SteamFriendsNative_activateGameOverlayToWebPage
(JNIEnv* env, jclass clazz, jstring obj_url, jint mode, char* url) {

//@line:104

		return SteamFriends()->ActivateGameOverlayToWebPage(url, (EActivateGameOverlayToWebPageMode) mode);
	
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_activateGameOverlayToWebPage(JNIEnv* env, jclass clazz, jstring obj_url, jint mode) {
	char* url = (char*)env->GetStringUTFChars(obj_url, 0);

	wrapped_Java_org_twopology_steamnetworks4j_SteamFriendsNative_activateGameOverlayToWebPage(env, clazz, obj_url, mode, url);

	env->ReleaseStringUTFChars(obj_url, url);

	return;
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_activateGameOverlayToStore(JNIEnv* env, jclass clazz, jint appID, jint flag) {


//@line:108

		return SteamFriends()->ActivateGameOverlayToStore((AppId_t) appID, (EOverlayToStoreFlag) flag);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_setPlayedWith(JNIEnv* env, jclass clazz, jlong steamIDUserPlayedWith) {


//@line:112

		SteamFriends()->SetPlayedWith((uint64) steamIDUserPlayedWith);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_activateGameOverlayInviteDialog(JNIEnv* env, jclass clazz, jlong steamIDLobby) {


//@line:116

		return SteamFriends()->ActivateGameOverlayInviteDialog((uint64) steamIDLobby);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamFriendsNative_setRichPresence
(JNIEnv* env, jclass clazz, jstring obj_key, jstring obj_value, char* key, char* value) {

//@line:120

		return SteamFriends()->SetRichPresence(key, value);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_setRichPresence(JNIEnv* env, jclass clazz, jstring obj_key, jstring obj_value) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);
	char* value = (char*)env->GetStringUTFChars(obj_value, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamFriendsNative_setRichPresence(env, clazz, obj_key, obj_value, key, value);

	env->ReleaseStringUTFChars(obj_key, key);
	env->ReleaseStringUTFChars(obj_value, value);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_clearRichPresence(JNIEnv* env, jclass clazz) {


//@line:124

		SteamFriends()->ClearRichPresence();
	

}

static inline jstring wrapped_Java_org_twopology_steamnetworks4j_SteamFriendsNative_getFriendRichPresence
(JNIEnv* env, jclass clazz, jlong steamIDFriend, jstring obj_key, char* key) {

//@line:128

		return env->NewStringUTF(SteamFriends()->GetFriendRichPresence((uint64) steamIDFriend, key));
	
}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getFriendRichPresence(JNIEnv* env, jclass clazz, jlong steamIDFriend, jstring obj_key) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);

	jstring JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamFriendsNative_getFriendRichPresence(env, clazz, steamIDFriend, obj_key, key);

	env->ReleaseStringUTFChars(obj_key, key);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getFriendRichPresenceKeyCount(JNIEnv* env, jclass clazz, jlong steamIDFriend) {


//@line:132

		return SteamFriends()->GetFriendRichPresenceKeyCount((uint64) steamIDFriend);
	

}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getFriendRichPresenceKeyByIndex(JNIEnv* env, jclass clazz, jlong steamIDFriend, jint index) {


//@line:136

		return env->NewStringUTF(SteamFriends()->GetFriendRichPresenceKeyByIndex((uint64) steamIDFriend, index));
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_requestFriendRichPresence(JNIEnv* env, jclass clazz, jlong steamIDFriend) {


//@line:140

		SteamFriends()->RequestFriendRichPresence((uint64) steamIDFriend);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamFriendsNative_inviteUserToGame
(JNIEnv* env, jclass clazz, jlong steamIDFriend, jstring obj_connectString, char* connectString) {

//@line:144

		return SteamFriends()->InviteUserToGame((uint64) steamIDFriend, connectString);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_inviteUserToGame(JNIEnv* env, jclass clazz, jlong steamIDFriend, jstring obj_connectString) {
	char* connectString = (char*)env->GetStringUTFChars(obj_connectString, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamFriendsNative_inviteUserToGame(env, clazz, steamIDFriend, obj_connectString, connectString);

	env->ReleaseStringUTFChars(obj_connectString, connectString);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getCoplayFriendCount(JNIEnv* env, jclass clazz) {


//@line:148

		return SteamFriends()->GetCoplayFriendCount();
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getCoplayFriend(JNIEnv* env, jclass clazz, jint index) {


//@line:152

		return SteamFriends()->GetCoplayFriend(index).ConvertToUint64();
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getFriendCoplayTime(JNIEnv* env, jclass clazz, jlong steamIDFriend) {


//@line:156

		return SteamFriends()->GetFriendCoplayTime((uint64) steamIDFriend);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamFriendsNative_getFriendCoplayGame(JNIEnv* env, jclass clazz, jlong steamIDFriend) {


//@line:160

		return (jint) SteamFriends()->GetFriendCoplayGame((uint64) steamIDFriend);
	

}

