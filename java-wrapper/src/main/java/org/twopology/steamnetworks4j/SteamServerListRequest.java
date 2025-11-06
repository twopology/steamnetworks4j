package org.twopology.steamnetworks4j;

public class SteamServerListRequest extends SteamNativeHandle {

	SteamServerListRequest(long handle) {
		super(handle);
	}

	public boolean isValid() {
		return handle != 0L;
	}

}
