#include <org_twopology_steamnetworks4j_SteamNetworkingSocketsNative.h>
#include <cstdio>

//@line:9

		#include <steam_api.h>
		#include "SteamNetworkingSocketsCallback.h"
		#include <iostream>
	JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_initRelayNetworkAccess(JNIEnv* env, jclass clazz) {


//@line:15

        SteamNetworkingUtils()->InitRelayNetworkAccess();
    

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_getRelayNetworkStatus(JNIEnv* env, jclass clazz) {


//@line:19

        return SteamNetworkingUtils()->GetRelayNetworkStatus(NULL);
    

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:23

		return (intp) new SteamNetworkingSocketsCallback(env, javaCallback);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_connectP2P(JNIEnv* env, jclass clazz, jlong steamID, jint numVirtualPorts) {


//@line:27

        SteamNetworkingIdentity identity;
        identity.m_eType = k_ESteamNetworkingIdentityType_SteamID;
        identity.SetSteamID64(steamID);

        HSteamNetConnection connection = SteamNetworkingSockets()->ConnectP2P(identity, numVirtualPorts, 0, NULL);

        return connection;
    

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_createListenSocketP2P(JNIEnv* env, jclass clazz, jint numVirtualPorts) {


//@line:37

        HSteamListenSocket socket = SteamNetworkingSockets()->CreateListenSocketP2P(numVirtualPorts, 0, NULL);

        return socket;
    

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_acceptConnection(JNIEnv* env, jclass clazz, jint netConnectionHandle) {


//@line:43

        return SteamNetworkingSockets()->AcceptConnection(netConnectionHandle);
    

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_closeConnection(JNIEnv* env, jclass clazz, jint netConnectionHandle, jint reason, jboolean linger) {


//@line:47

        return SteamNetworkingSockets()->CloseConnection(netConnectionHandle, reason, NULL, linger);
    

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_closeListenSocket(JNIEnv* env, jclass clazz, jint socketHandle) {


//@line:51

        return SteamNetworkingSockets()->CloseListenSocket(socketHandle);
    

}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_sendMessageToConnection
(JNIEnv* env, jclass clazz, jint netConnectionHandle, jobject obj_data, jint dataLength, jint sendFlags, char* data) {

//@line:55

        return SteamNetworkingSockets()->SendMessageToConnection(netConnectionHandle, (const void*) data, dataLength, sendFlags, NULL);
    
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_sendMessageToConnection(JNIEnv* env, jclass clazz, jint netConnectionHandle, jobject obj_data, jint dataLength, jint sendFlags) {
	char* data = (char*)(obj_data?env->GetDirectBufferAddress(obj_data):0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_sendMessageToConnection(env, clazz, netConnectionHandle, obj_data, dataLength, sendFlags, data);


	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_receiveMessagesOnConnection(JNIEnv* env, jclass clazz, jint netConnectionHandle, jobjectArray messageBuffer, jint maxMessages) {


//@line:59


        if(maxMessages <= 0){
            return 0;
        }

        jsize arrayLength = env->GetArrayLength(messageBuffer);

        if(arrayLength < maxMessages){
            return 0;
        }

        SteamNetworkingMessage_t** ppOutMessages = new SteamNetworkingMessage_t*[maxMessages];

        int num = SteamNetworkingSockets()->ReceiveMessagesOnConnection(netConnectionHandle, ppOutMessages, maxMessages);

        for(int i = 0; i < num;i++){
            SteamNetworkingMessage_t* netMessage = ppOutMessages[i];
            if (netMessage == NULL) {
                fprintf(stderr, "[SteamNetworkingSocketsNative] ERROR: netMessage[%d] is NULL\n", i);
                fflush(stderr);
                continue;
            }

            jobject message = env->GetObjectArrayElement(messageBuffer, i);
            if (message == NULL) {
                fprintf(stderr, "[SteamNetworkingSocketsNative] ERROR: GetObjectArrayElement returned NULL for index %d\n", i);
                fflush(stderr);
                netMessage->Release();
                continue;
            }
            
            fprintf(stderr, "[SteamNetworkingSocketsNative] Processing message %d, message object=%p\n", i, message);
            fflush(stderr);
            
            // Check for exceptions before GetObjectClass
            if (env->ExceptionCheck()) {
                fprintf(stderr, "[SteamNetworkingSocketsNative] ERROR: Exception pending before GetObjectClass\n");
                fflush(stderr);
                env->ExceptionDescribe();
                env->ExceptionClear();
                env->DeleteLocalRef(message);
                netMessage->Release();
                continue;
            }
            
            jclass clazz = env->GetObjectClass(message);
            
            // Check for exceptions after GetObjectClass
            if (env->ExceptionCheck()) {
                fprintf(stderr, "[SteamNetworkingSocketsNative] ERROR: Exception occurred in GetObjectClass for message %d\n", i);
                fflush(stderr);
                env->ExceptionDescribe();
                env->ExceptionClear();
                env->DeleteLocalRef(message);
                netMessage->Release();
                continue;
            }
            
            if (clazz == NULL || clazz == 0) {
                fprintf(stderr, "[SteamNetworkingSocketsNative] ERROR: GetObjectClass returned NULL for message %d\n", i);
                fflush(stderr);
                env->DeleteLocalRef(message);
                netMessage->Release();
                continue;
            }

            jfieldID payloadField = env->GetFieldID(clazz, "payload", "[B");
            jfieldID connectionField = env->GetFieldID(clazz, "connectionHandle", "I");
            
            if (payloadField == NULL || connectionField == NULL) {
                fprintf(stderr, "[SteamNetworkingSocketsNative] ERROR: GetFieldID failed for message %d\n", i);
                fflush(stderr);
                env->DeleteLocalRef(clazz);
                env->DeleteLocalRef(message);
                netMessage->Release();
                continue;
            }

            jbyteArray javaByteArray = env->NewByteArray(netMessage->m_cbSize);
            if (javaByteArray == NULL) {
                fprintf(stderr, "[SteamNetworkingSocketsNative] ERROR: NewByteArray failed for message %d\n", i);
                fflush(stderr);
                env->DeleteLocalRef(clazz);
                env->DeleteLocalRef(message);
                netMessage->Release();
                continue;
            }

            env->SetByteArrayRegion(javaByteArray, 0, netMessage->m_cbSize, (const jbyte*) netMessage->m_pData);

            env->SetIntField(message, connectionField, netMessage->m_conn);
            env->SetObjectField(message, payloadField, javaByteArray);

            env->DeleteLocalRef(javaByteArray);
            env->DeleteLocalRef(clazz);
            env->DeleteLocalRef(message);

            netMessage->Release();
        }

        delete[] ppOutMessages;

        return num;
    

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_flushMessages(JNIEnv* env, jclass clazz, jint connectionHandle) {


//@line:102

        return SteamNetworkingSockets()->FlushMessagesOnConnection(connectionHandle);
    

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_createPollGroup(JNIEnv* env, jclass clazz) {


//@line:106

        HSteamNetPollGroup pollGroup = SteamNetworkingSockets()->CreatePollGroup();

        return pollGroup;
    

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_destroyPollGroup(JNIEnv* env, jclass clazz, jint handle) {


//@line:112

        return SteamNetworkingSockets()->DestroyPollGroup(handle);
    

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_setConnectionPollGroup(JNIEnv* env, jclass clazz, jint connectionHandle, jint pollGroupHandle) {


//@line:116

        return SteamNetworkingSockets()->SetConnectionPollGroup(connectionHandle, pollGroupHandle);
    

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_receiveMessagesOnPollGroup(JNIEnv* env, jclass clazz, jint pollGroupHandle, jobjectArray messageBuffer, jint maxMessages) {


//@line:120

        if(maxMessages <= 0){
            return 0;
        }

        jsize arrayLength = env->GetArrayLength(messageBuffer);

        if(arrayLength < maxMessages){
            return 0;
        }

        SteamNetworkingMessage_t** ppOutMessages = new SteamNetworkingMessage_t*[maxMessages];

        int num = SteamNetworkingSockets()->ReceiveMessagesOnPollGroup(pollGroupHandle, ppOutMessages, maxMessages);

        for(int i = 0; i < num;i++){
            SteamNetworkingMessage_t* netMessage = ppOutMessages[i];

            jobject message = env->GetObjectArrayElement(messageBuffer, i);
            jclass clazz = env->GetObjectClass(message);

            jfieldID payloadField = env->GetFieldID(clazz, "payload", "[B");
            jfieldID connectionField = env->GetFieldID(clazz, "connectionHandle", "I");

            jbyteArray javaByteArray = env->NewByteArray(netMessage->m_cbSize);

            env->SetByteArrayRegion(javaByteArray, 0, netMessage->m_cbSize, (const jbyte*) netMessage->m_pData);

            env->SetIntField(message, connectionField, netMessage->m_conn);
            env->SetObjectField(message, payloadField, javaByteArray);

            env->DeleteLocalRef(javaByteArray);
            env->DeleteLocalRef(message);

            netMessage->Release();
        }

        delete[] ppOutMessages;

        return num;
    

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_initAuthentication(JNIEnv* env, jclass clazz) {


//@line:162

        return SteamNetworkingSockets()->InitAuthentication();
    

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamNetworkingSocketsNative_getAuthenticationStatus(JNIEnv* env, jclass clazz) {


//@line:166

        return SteamNetworkingSockets()->GetAuthenticationStatus(NULL);
    

}

