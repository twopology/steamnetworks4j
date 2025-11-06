#include <org_twopology_steamnetworks4j_SteamMatchmakingServersNative.h>

//@line:7

		#include <steam_api.h>
		#include "SteamMatchmakingGameServerItem.h"
		#include "SteamMatchmakingKeyValuePair.h"
		#include "SteamMatchmakingPingResponse.h"
		#include "SteamMatchmakingPlayersResponse.h"
		#include "SteamMatchmakingRulesResponse.h"
		#include "SteamMatchmakingServerListResponse.h"

		#define MAX_FILTERS 16
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_requestInternetServerList(JNIEnv* env, jclass clazz, jint appID, jobjectArray filters, jint count, jlong requestServersResponse) {


//@line:21


		MatchMakingKeyValuePair_t _pairs[MAX_FILTERS];
		MatchMakingKeyValuePair_t* pairs = _pairs;
		count = convertKeyValuePairArray(env, filters, count, pairs, MAX_FILTERS);

		SteamMatchmakingServerListResponse* response = (SteamMatchmakingServerListResponse*) requestServersResponse;
		return (jlong) SteamMatchmakingServers()->RequestInternetServerList(appID, &pairs, count, response);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_requestLANServerList(JNIEnv* env, jclass clazz, jint appID, jlong requestServersResponse) {


//@line:32


		SteamMatchmakingServerListResponse* response = (SteamMatchmakingServerListResponse*) requestServersResponse;
		return (jlong) SteamMatchmakingServers()->RequestLANServerList(appID, response);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_requestFriendsServerList(JNIEnv* env, jclass clazz, jint appID, jobjectArray filters, jint count, jlong requestServersResponse) {


//@line:40


		MatchMakingKeyValuePair_t _pairs[MAX_FILTERS];
		MatchMakingKeyValuePair_t* pairs = _pairs;
		count = convertKeyValuePairArray(env, filters, count, pairs, MAX_FILTERS);

		SteamMatchmakingServerListResponse* response = (SteamMatchmakingServerListResponse*) requestServersResponse;
		return (jlong) SteamMatchmakingServers()->RequestFriendsServerList(appID, &pairs, count, response);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_requestFavoritesServerList(JNIEnv* env, jclass clazz, jint appID, jobjectArray filters, jint count, jlong requestServersResponse) {


//@line:52


		MatchMakingKeyValuePair_t _pairs[MAX_FILTERS];
		MatchMakingKeyValuePair_t* pairs = _pairs;
		count = convertKeyValuePairArray(env, filters, count, pairs, MAX_FILTERS);

		SteamMatchmakingServerListResponse* response = (SteamMatchmakingServerListResponse*) requestServersResponse;
		return (jlong) SteamMatchmakingServers()->RequestFavoritesServerList(appID, &pairs, count, response);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_requestHistoryServerList(JNIEnv* env, jclass clazz, jint appID, jobjectArray filters, jint count, jlong requestServersResponse) {


//@line:64


		MatchMakingKeyValuePair_t _pairs[MAX_FILTERS];
		MatchMakingKeyValuePair_t* pairs = _pairs;
		count = convertKeyValuePairArray(env, filters, count, pairs, MAX_FILTERS);

		SteamMatchmakingServerListResponse* response = (SteamMatchmakingServerListResponse*) requestServersResponse;
		return (jlong) SteamMatchmakingServers()->RequestHistoryServerList(appID, &pairs, count, response);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_requestSpectatorServerList(JNIEnv* env, jclass clazz, jint appID, jobjectArray filters, jint count, jlong requestServersResponse) {


//@line:76


		MatchMakingKeyValuePair_t _pairs[MAX_FILTERS];
		MatchMakingKeyValuePair_t* pairs = _pairs;
		count = convertKeyValuePairArray(env, filters, count, pairs, MAX_FILTERS);

		SteamMatchmakingServerListResponse* response = (SteamMatchmakingServerListResponse*) requestServersResponse;
		return (jlong) SteamMatchmakingServers()->RequestSpectatorServerList(appID, &pairs, count, response);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_releaseRequest(JNIEnv* env, jclass clazz, jlong request) {


//@line:86

		SteamMatchmakingServers()->ReleaseRequest((HServerListRequest) request);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_getServerDetails(JNIEnv* env, jclass clazz, jlong request, jint server, jobject details) {


//@line:91

		const gameserveritem_t* item = SteamMatchmakingServers()->GetServerDetails((HServerListRequest) request, server);
		if (item != nullptr) {
			convertGameServerItem(details, env, *item);
			return true;
		}
		return false;
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_cancelQuery(JNIEnv* env, jclass clazz, jlong request) {


//@line:100

		SteamMatchmakingServers()->CancelQuery((HServerListRequest) request);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_refreshQuery(JNIEnv* env, jclass clazz, jlong request) {


//@line:104

		SteamMatchmakingServers()->RefreshQuery((HServerListRequest) request);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_isRefreshing(JNIEnv* env, jclass clazz, jlong request) {


//@line:108

		return SteamMatchmakingServers()->IsRefreshing((HServerListRequest) request);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_getServerCount(JNIEnv* env, jclass clazz, jlong request) {


//@line:112

		return SteamMatchmakingServers()->GetServerCount((HServerListRequest) request);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_refreshServer(JNIEnv* env, jclass clazz, jlong request, jint server) {


//@line:116

		SteamMatchmakingServers()->RefreshServer((HServerListRequest) request, server);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_pingServer(JNIEnv* env, jclass clazz, jint ip, jshort port, jlong requestServersResponse) {


//@line:120

		SteamMatchmakingPingResponse* response = (SteamMatchmakingPingResponse*) requestServersResponse;
		return SteamMatchmakingServers()->PingServer(ip, port, response);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_playerDetails(JNIEnv* env, jclass clazz, jint ip, jshort port, jlong requestServersResponse) {


//@line:125

		SteamMatchmakingPlayersResponse* response = (SteamMatchmakingPlayersResponse*) requestServersResponse;
		return SteamMatchmakingServers()->PlayerDetails(ip, port, response);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_serverRules(JNIEnv* env, jclass clazz, jint ip, jshort port, jlong requestServersResponse) {


//@line:130

		SteamMatchmakingRulesResponse* response = (SteamMatchmakingRulesResponse*) requestServersResponse;
		return SteamMatchmakingServers()->ServerRules(ip, port, response);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamMatchmakingServersNative_cancelServerQuery(JNIEnv* env, jclass clazz, jint serverQuery) {


//@line:135

		return SteamMatchmakingServers()->CancelServerQuery((HServerQuery) serverQuery);
	

}

