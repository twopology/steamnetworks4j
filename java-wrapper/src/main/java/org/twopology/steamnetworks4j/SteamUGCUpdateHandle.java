package org.twopology.steamnetworks4j;

public class SteamUGCUpdateHandle extends SteamNativeHandle {

	SteamUGCUpdateHandle(long handle) {
		super(handle);
	}

	public boolean isValid() {
		return handle != -1;
	}
}
