package org.twopology.steamnetworks4j;

@SuppressWarnings("unused")
public class SteamGameServerNetworking extends SteamNetworking {

	public SteamGameServerNetworking(SteamNetworkingCallback callback) {
		super(true, SteamGameServerNetworkingNative.createCallback(
				new SteamNetworkingCallbackAdapter(callback)));
	}

}
