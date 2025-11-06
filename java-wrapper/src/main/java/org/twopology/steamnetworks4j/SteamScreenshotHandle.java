package org.twopology.steamnetworks4j;

public class SteamScreenshotHandle extends SteamNativeIntHandle {

	public static final SteamScreenshotHandle INVALID = new SteamScreenshotHandle(0);

	SteamScreenshotHandle(int handle) {
		super(handle);
	}

}
