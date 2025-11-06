package org.twopology.steamnetworks4j;

public class SteamUGCQuery extends SteamNativeHandle {

	public SteamUGCQuery(long handle) {
		super(handle);
	}

	public boolean isValid() {
		return handle != -1;
	}
}
