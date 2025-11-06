#include <org_twopology_steamnetworks4j_SteamHTTPNative.h>

//@line:9

		#include "SteamHTTPCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:13

		return (intp) new SteamHTTPCallback(env, javaCallback);
	

}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_createHTTPRequest
(JNIEnv* env, jclass clazz, jboolean server, jint requestMethod, jstring obj_absoluteURL, char* absoluteURL) {

//@line:17

		ISteamHTTP* http = server ? SteamGameServerHTTP() : SteamHTTP();
		return http->CreateHTTPRequest((EHTTPMethod) requestMethod, absoluteURL);
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_createHTTPRequest(JNIEnv* env, jclass clazz, jboolean server, jint requestMethod, jstring obj_absoluteURL) {
	char* absoluteURL = (char*)env->GetStringUTFChars(obj_absoluteURL, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_createHTTPRequest(env, clazz, server, requestMethod, obj_absoluteURL, absoluteURL);

	env->ReleaseStringUTFChars(obj_absoluteURL, absoluteURL);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_setHTTPRequestContextValue(JNIEnv* env, jclass clazz, jboolean server, jlong request, jlong contextValue) {


//@line:22

		ISteamHTTP* http = server ? SteamGameServerHTTP() : SteamHTTP();
		return http->SetHTTPRequestContextValue((HTTPRequestHandle) request, (uint64) contextValue);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_setHTTPRequestNetworkActivityTimeout(JNIEnv* env, jclass clazz, jboolean server, jlong request, jint timeoutSeconds) {


//@line:28


		ISteamHTTP* http = server ? SteamGameServerHTTP() : SteamHTTP();
		return http->SetHTTPRequestNetworkActivityTimeout((HTTPRequestHandle) request, (uint32) timeoutSeconds);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_setHTTPRequestHeaderValue
(JNIEnv* env, jclass clazz, jboolean server, jlong request, jstring obj_headerName, jstring obj_headerValue, char* headerName, char* headerValue) {

//@line:35


		ISteamHTTP* http = server ? SteamGameServerHTTP() : SteamHTTP();
		return http->SetHTTPRequestHeaderValue((HTTPRequestHandle) request, headerName, headerValue);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_setHTTPRequestHeaderValue(JNIEnv* env, jclass clazz, jboolean server, jlong request, jstring obj_headerName, jstring obj_headerValue) {
	char* headerName = (char*)env->GetStringUTFChars(obj_headerName, 0);
	char* headerValue = (char*)env->GetStringUTFChars(obj_headerValue, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_setHTTPRequestHeaderValue(env, clazz, server, request, obj_headerName, obj_headerValue, headerName, headerValue);

	env->ReleaseStringUTFChars(obj_headerName, headerName);
	env->ReleaseStringUTFChars(obj_headerValue, headerValue);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_setHTTPRequestGetOrPostParameter
(JNIEnv* env, jclass clazz, jboolean server, jlong request, jstring obj_paramName, jstring obj_paramValue, char* paramName, char* paramValue) {

//@line:42


		ISteamHTTP* http = server ? SteamGameServerHTTP() : SteamHTTP();
		return http->SetHTTPRequestGetOrPostParameter((HTTPRequestHandle) request, paramName, paramValue);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_setHTTPRequestGetOrPostParameter(JNIEnv* env, jclass clazz, jboolean server, jlong request, jstring obj_paramName, jstring obj_paramValue) {
	char* paramName = (char*)env->GetStringUTFChars(obj_paramName, 0);
	char* paramValue = (char*)env->GetStringUTFChars(obj_paramValue, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_setHTTPRequestGetOrPostParameter(env, clazz, server, request, obj_paramName, obj_paramValue, paramName, paramValue);

	env->ReleaseStringUTFChars(obj_paramName, paramName);
	env->ReleaseStringUTFChars(obj_paramValue, paramValue);

	return JNI_returnValue;
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_sendHTTPRequest(JNIEnv* env, jclass clazz, jboolean server, jlong callback, jlong request) {


//@line:48

		ISteamHTTP* http = server ? SteamGameServerHTTP() : SteamHTTP();
		SteamAPICall_t handle;
		if (http->SendHTTPRequest((HTTPRequestHandle) request, &handle)) {
			SteamHTTPCallback* cb = (SteamHTTPCallback*) callback;
			cb->onHTTPRequestCompletedCall.Set(handle, cb, &SteamHTTPCallback::onHTTPRequestCompleted);
			return handle;
		}
		return 0;
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_sendHTTPRequestAndStreamResponse(JNIEnv* env, jclass clazz, jboolean server, jlong request) {


//@line:59

		ISteamHTTP* http = server ? SteamGameServerHTTP() : SteamHTTP();
		SteamAPICall_t handle;
		if (http->SendHTTPRequestAndStreamResponse((HTTPRequestHandle) request, &handle)) {
			return handle;
		}
		return 0;
	

}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_getHTTPResponseHeaderSize
(JNIEnv* env, jclass clazz, jboolean server, jlong request, jstring obj_headerName, char* headerName) {

//@line:68

		ISteamHTTP* http = server ? SteamGameServerHTTP() : SteamHTTP();
		uint32 size;
		if (http->GetHTTPResponseHeaderSize((HTTPRequestHandle) request, headerName, &size)) {
			return size;
		}
		return 0;
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_getHTTPResponseHeaderSize(JNIEnv* env, jclass clazz, jboolean server, jlong request, jstring obj_headerName) {
	char* headerName = (char*)env->GetStringUTFChars(obj_headerName, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_getHTTPResponseHeaderSize(env, clazz, server, request, obj_headerName, headerName);

	env->ReleaseStringUTFChars(obj_headerName, headerName);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_getHTTPResponseHeaderValue
(JNIEnv* env, jclass clazz, jboolean server, jlong request, jstring obj_headerName, jobject obj_value, jint offset, jint size, char* value, char* headerName) {

//@line:78


		ISteamHTTP* http = server ? SteamGameServerHTTP() : SteamHTTP();
		return http->GetHTTPResponseHeaderValue((HTTPRequestHandle) request, headerName, (uint8*) &value[offset], size);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_getHTTPResponseHeaderValue(JNIEnv* env, jclass clazz, jboolean server, jlong request, jstring obj_headerName, jobject obj_value, jint offset, jint size) {
	char* value = (char*)(obj_value?env->GetDirectBufferAddress(obj_value):0);
	char* headerName = (char*)env->GetStringUTFChars(obj_headerName, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_getHTTPResponseHeaderValue(env, clazz, server, request, obj_headerName, obj_value, offset, size, value, headerName);

	env->ReleaseStringUTFChars(obj_headerName, headerName);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_getHTTPResponseBodySize(JNIEnv* env, jclass clazz, jboolean server, jlong request) {


//@line:84

		ISteamHTTP* http = server ? SteamGameServerHTTP() : SteamHTTP();
		uint32 size;
		if (http->GetHTTPResponseBodySize((HTTPRequestHandle) request, &size)) {
			return size;
		}
		return 0;
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_getHTTPResponseBodyData
(JNIEnv* env, jclass clazz, jboolean server, jlong request, jobject obj_data, jint offset, jint size, char* data) {

//@line:94


		ISteamHTTP* http = server ? SteamGameServerHTTP() : SteamHTTP();
		return http->GetHTTPResponseBodyData((HTTPRequestHandle) request, (uint8*) &data[offset], size);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_getHTTPResponseBodyData(JNIEnv* env, jclass clazz, jboolean server, jlong request, jobject obj_data, jint offset, jint size) {
	char* data = (char*)(obj_data?env->GetDirectBufferAddress(obj_data):0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_getHTTPResponseBodyData(env, clazz, server, request, obj_data, offset, size, data);


	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_getHTTPStreamingResponseBodyData
(JNIEnv* env, jclass clazz, jboolean server, jlong request, jint bodyDataOffset, jobject obj_data, jint offset, jint size, char* data) {

//@line:101


		ISteamHTTP* http = server ? SteamGameServerHTTP() : SteamHTTP();
		return http->GetHTTPStreamingResponseBodyData((HTTPRequestHandle) request, bodyDataOffset, (uint8*) &data[offset], size);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_getHTTPStreamingResponseBodyData(JNIEnv* env, jclass clazz, jboolean server, jlong request, jint bodyDataOffset, jobject obj_data, jint offset, jint size) {
	char* data = (char*)(obj_data?env->GetDirectBufferAddress(obj_data):0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamHTTPNative_getHTTPStreamingResponseBodyData(env, clazz, server, request, bodyDataOffset, obj_data, offset, size, data);


	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamHTTPNative_releaseHTTPRequest(JNIEnv* env, jclass clazz, jboolean server, jlong request) {


//@line:107

		ISteamHTTP* http = server ? SteamGameServerHTTP() : SteamHTTP();
		return http->ReleaseHTTPRequest((HTTPRequestHandle) request);
	

}

